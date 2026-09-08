"""Contract tests for the focused DeepRacer skill split introduced in PR #7."""

import re
from pathlib import Path

import pytest


SKILLS_ROOT = Path(__file__).resolve().parents[1]
ROBOTICS_ROOT = SKILLS_ROOT / "robotics"
ROUTER_NAME = "deepracer-control"
FOCUSED_SKILLS = {
    "deepracer-motor-control": {
        "tag": "motor-control",
        "topics": (
            "## Movement Control",
            "### ⚠️ Watchdog Timer",
            "## Backend Proxy (Node.js + Express)",
            "## Controlling LEDs",
        ),
    },
    "deepracer-calibration": {
        "tag": "calibration",
        "topics": (
            "### 🎛️ Calibration: Throttle Dead Zone",
            "### 🎯 Steering Trim",
            "### Direction Test (per-boot, obligatorio)",
        ),
    },
    "deepracer-vision": {
        "tag": "vision",
        "topics": (
            "## Camera / Video",
            "### Camera Obstacle Detection",
            "## ArUco Navigation",
            "## LiDAR Status (RPLIDAR)",
        ),
    },
    "deepracer-troubleshooting": {
        "tag": "troubleshooting",
        "topics": (
            "## Connecting",
            "## ROS2 Topics (Read-Only)",
            "## 🚀 Post-Reboot Checklist",
            "## Common Issues",
            "## ESP32 and Microcontrollers — LEGACY ARCHIVE",
        ),
    },
}


def skill_path(name):
    return ROBOTICS_ROOT / name / "SKILL.md"


def read_skill(name):
    return skill_path(name).read_text(encoding="utf-8")


def split_skill(name):
    """Return the frontmatter and Markdown body without requiring PyYAML."""
    text = read_skill(name)
    assert text.startswith("---\n"), f"{name} has no opening frontmatter marker"
    try:
        frontmatter, body = text[4:].split("\n---\n", maxsplit=1)
    except ValueError:
        pytest.fail(f"{name} has no closing frontmatter marker")
    return frontmatter, body


def frontmatter_value(frontmatter, key):
    match = re.search(
        rf"^[ \t]*{re.escape(key)}:\s*(.+)$", frontmatter, re.MULTILINE
    )
    assert match, f"missing frontmatter field: {key}"
    return match.group(1).strip().strip('"')


def frontmatter_list(frontmatter, key):
    value = frontmatter_value(frontmatter, key)
    assert value.startswith("[") and value.endswith("]")
    return [item.strip() for item in value[1:-1].split(",")]


def all_skill_names():
    return [ROUTER_NAME, *FOCUSED_SKILLS]


def test_split_skill_files_exist_and_frontmatter_names_match_directories():
    declared_names = []

    for expected_name in all_skill_names():
        path = skill_path(expected_name)
        assert path.is_file(), f"missing routed skill: {path.relative_to(SKILLS_ROOT)}"
        frontmatter, _ = split_skill(expected_name)
        declared_name = frontmatter_value(frontmatter, "name")
        assert declared_name == path.parent.name
        declared_names.append(declared_name)

    assert len(declared_names) == len(set(declared_names)), "skill names must be unique"


@pytest.mark.parametrize("skill_name", FOCUSED_SKILLS)
def test_focused_skill_metadata_is_complete_and_domain_specific(skill_name):
    frontmatter, _ = split_skill(skill_name)

    assert frontmatter_value(frontmatter, "version") == "1.0.0"
    assert frontmatter_value(frontmatter, "author") == "Hermes Agent"
    assert frontmatter_value(frontmatter, "description")
    assert frontmatter_list(frontmatter, "platforms") == ["linux", "macos", "windows"]
    assert re.search(r"^metadata:\n  hermes:\n", frontmatter, re.MULTILINE)

    tags = frontmatter_list(frontmatter, "tags")
    assert {"deepracer", "robotics", FOCUSED_SKILLS[skill_name]["tag"]} <= set(tags)


def test_router_has_major_version_bump_and_routes_every_domain_once():
    frontmatter, body = split_skill(ROUTER_NAME)
    assert frontmatter_value(frontmatter, "version") == "3.0.0"

    rows = re.findall(r"^\| (.+?) \| `(deepracer-[^`]+)` \|$", body, re.MULTILINE)
    assert len(rows) == len(FOCUSED_SKILLS)
    assert {destination for _, destination in rows} == set(FOCUSED_SKILLS)
    assert len({destination for _, destination in rows}) == len(rows)

    expected_keywords = {
        "deepracer-motor-control": {"Drive", "watchdog", "backend"},
        "deepracer-calibration": {"Dead zone", "trim", "direction test"},
        "deepracer-vision": {"Camera", "ArUco", "LiDAR"},
        "deepracer-troubleshooting": {"SSH", "ROS2", "ESP32"},
    }
    tasks_by_destination = {destination: tasks for tasks, destination in rows}
    for destination, keywords in expected_keywords.items():
        assert all(keyword in tasks_by_destination[destination] for keyword in keywords)


def test_router_stays_an_index_instead_of_reabsorbing_implementation_details():
    _, body = split_skill(ROUTER_NAME)

    assert len(body.splitlines()) <= 25
    assert "```" not in body
    assert "/api/manual_drive" not in body
    assert "sudo " not in body
    assert "curl " not in body
    assert not re.search(r"^## ", body, re.MULTILINE)


def test_skills_readme_indexes_router_and_each_focused_skill_once():
    readme = (SKILLS_ROOT / "README.md").read_text(encoding="utf-8")
    indexed_paths = re.findall(r"^\| `robotics/(deepracer-[^/]+)/` \|", readme, re.MULTILINE)

    for skill_name in all_skill_names():
        assert indexed_paths.count(skill_name) == 1


@pytest.mark.parametrize("skill_name", FOCUSED_SKILLS)
def test_each_focused_skill_owns_its_expected_topics(skill_name):
    _, body = split_skill(skill_name)

    for topic in FOCUSED_SKILLS[skill_name]["topics"]:
        assert topic in body, f"{skill_name} lost topic {topic!r}"


def test_domain_landmarks_are_not_duplicated_between_focused_skills():
    bodies = {name: split_skill(name)[1] for name in FOCUSED_SKILLS}

    for owner, contract in FOCUSED_SKILLS.items():
        for topic in contract["topics"]:
            containing_skills = [name for name, body in bodies.items() if topic in body]
            assert containing_skills == [owner], (
                f"topic {topic!r} must only be owned by {owner}; "
                f"found in {containing_skills}"
            )


def test_shared_asset_references_resolve_from_each_focused_skill():
    reference_pattern = re.compile(
        r"\.\./deepracer-control/(?:references|scripts|templates)/[\w.-]+"
    )
    checked_references = set()
    missing_references = []

    for skill_name in FOCUSED_SKILLS:
        for relative_reference in reference_pattern.findall(read_skill(skill_name)):
            checked_references.add(relative_reference)
            target = skill_path(skill_name).parent / relative_reference
            if not target.is_file():
                missing_references.append((skill_name, relative_reference))

    assert checked_references, "expected the split skills to reuse centralized assets"
    assert not missing_references


def test_shared_assets_remain_centralized_under_the_router_skill():
    router_directory = skill_path(ROUTER_NAME).parent

    for asset_directory in ("references", "scripts", "templates"):
        path = router_directory / asset_directory
        assert path.is_dir()
        assert any(child.is_file() for child in path.iterdir())

    for skill_name in FOCUSED_SKILLS:
        assert sorted(path.name for path in skill_path(skill_name).parent.iterdir()) == [
            "SKILL.md"
        ]


def test_safety_and_hardware_status_survive_the_split():
    _, router = split_skill(ROUTER_NAME)
    _, motor = split_skill("deepracer-motor-control")
    _, calibration = split_skill("deepracer-calibration")
    _, vision = split_skill("deepracer-vision")
    _, troubleshooting = split_skill("deepracer-troubleshooting")

    assert "ALL driving goes through the Node backend" in router
    assert "NEVER SSH for movement" in router
    assert all(
        rule in router
        for rule in ("explicit authorization", "operator present", "clear zone", "limited speed")
    )
    assert "ALL driving goes through the Node backend" in motor
    assert "~200ms watchdog" in motor
    assert "Do not raise the explorer's normalized throttle above 0.20" in motor
    assert "`0` always stays `0`" in calibration
    assert "The throttle convention can flip between reboots" in calibration
    assert "does **not** have a physical RPLIDAR module" in vision
    assert "diagnose read-only first" in troubleshooting
    assert "ESP32 discarded 2026-09-05" in troubleshooting
