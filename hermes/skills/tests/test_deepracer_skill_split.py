"""Contract tests for the focused DeepRacer skill split introduced in PR #7.

These tests are intentionally static: loading a skill must never start services or
exercise the physical robot.  They validate the files Hermes discovers and the
routing, ownership, and retained-resource contracts between those files.
"""

from pathlib import Path
import re

import pytest


SKILLS_ROOT = Path(__file__).resolve().parents[1]
ROBOTICS_ROOT = SKILLS_ROOT / "robotics"

EXPECTED_SKILLS = {
    "deepracer-control": "3.0.0",
    "deepracer-motor-control": "1.0.0",
    "deepracer-calibration": "1.0.0",
    "deepracer-vision": "1.0.0",
    "deepracer-troubleshooting": "1.0.0",
}
FOCUSED_SKILLS = set(EXPECTED_SKILLS) - {"deepracer-control"}

RESPONSIBILITY_MARKERS = {
    "deepracer-motor-control": (
        "## Movement Control",
        "Watchdog Timer",
        "Autonomous Explorer",
        "## Backend Proxy",
        "## Controlling LEDs",
    ),
    "deepracer-calibration": (
        "Throttle Dead Zone",
        "Steering Trim",
        "Real Speed",
        "Direction Test",
        "2026-07-31",
    ),
    "deepracer-vision": (
        "## Camera / Video",
        "Camera Obstacle Detection",
        "## ArUco Navigation",
        "## LiDAR Status",
        "no hardware",
    ),
    "deepracer-troubleshooting": (
        "## Connecting",
        "## Robot Web Dashboards",
        "## ROS2 Topics",
        "Hardware Audit Summary",
        "Post-Reboot Checklist",
        "## Common Issues",
        "LEGACY ARCHIVE",
    ),
}


def skill_path(name: str) -> Path:
    return ROBOTICS_ROOT / name / "SKILL.md"


def read_skill(name: str) -> str:
    return skill_path(name).read_text(encoding="utf-8")


def frontmatter(text: str) -> str:
    assert text.startswith("---\n"), "SKILL.md must start with YAML frontmatter"
    parts = text.split("\n---\n", maxsplit=1)
    assert len(parts) == 2, "SKILL.md must close its YAML frontmatter"
    return parts[0][4:]


def frontmatter_value(text: str, key: str) -> str:
    match = re.search(
        rf"^\s*{re.escape(key)}:\s*(.+)$", frontmatter(text), re.MULTILINE
    )
    assert match, f"missing frontmatter field: {key}"
    return match.group(1).strip().strip('"')


@pytest.mark.parametrize("name,version", EXPECTED_SKILLS.items())
def test_each_skill_has_discoverable_frontmatter(name: str, version: str) -> None:
    text = read_skill(name)

    assert frontmatter_value(text, "name") == name
    assert frontmatter_value(text, "version") == version
    assert frontmatter_value(text, "author") == "Hermes Agent"
    assert frontmatter_value(text, "platforms") == "[linux, macos, windows]"
    assert frontmatter_value(text, "description")

    tags = frontmatter_value(text, "tags")
    assert "deepracer" in tags
    assert "robotics" in tags


def test_skill_names_are_unique() -> None:
    declared_names = [
        frontmatter_value(read_skill(name), "name") for name in EXPECTED_SKILLS
    ]

    assert len(declared_names) == len(set(declared_names))


def test_router_points_to_every_focused_skill() -> None:
    router = read_skill("deepracer-control")
    routed_names = set(
        re.findall(r"^\|[^\n|]+\|\s*`(deepracer-[\w-]+)`\s*\|$", router, re.MULTILINE)
    )

    assert routed_names == FOCUSED_SKILLS
    for name in routed_names:
        assert skill_path(name).is_file()
        assert name in frontmatter_value(router, "description")


def test_router_stays_a_small_index_instead_of_a_second_monolith() -> None:
    router = read_skill("deepracer-control")
    headings = re.findall(r"^#{1,6}\s+.+$", router, re.MULTILINE)

    assert headings == ["# AWS DeepRacer Control (router)"]
    assert len(router.splitlines()) <= 35
    assert "```" not in router
    assert "PUT /api/drive_mode" not in router


@pytest.mark.parametrize("name,markers", RESPONSIBILITY_MARKERS.items())
def test_focused_skill_keeps_its_assigned_responsibilities(
    name: str, markers: tuple[str, ...]
) -> None:
    text = read_skill(name)

    missing = [marker for marker in markers if marker not in text]
    assert not missing, f"{name} is missing responsibility markers: {missing}"


@pytest.mark.parametrize(
    "name,foreign_heading",
    (
        ("deepracer-calibration", "## Movement Control"),
        ("deepracer-calibration", "## Camera / Video"),
        ("deepracer-vision", "## Movement Control"),
        ("deepracer-vision", "## Connecting"),
        ("deepracer-troubleshooting", "## Movement Control"),
        ("deepracer-troubleshooting", "## Camera / Video"),
    ),
)
def test_focused_skills_do_not_recreate_foreign_top_level_sections(
    name: str, foreign_heading: str
) -> None:
    assert foreign_heading not in read_skill(name)


def test_safety_routing_survived_the_split() -> None:
    router = read_skill("deepracer-control")
    motor = read_skill("deepracer-motor-control")
    troubleshooting = read_skill("deepracer-troubleshooting")

    for text in (router, motor):
        assert "ALL driving goes through the Node backend" in text
        assert "NEVER SSH for movement" in text
    assert "never use SSH, dashboards or\nROS2 calls to MOVE" in troubleshooting
    assert "diagnose read-only first" in troubleshooting


def test_shared_resources_remain_with_the_router() -> None:
    router_dir = skill_path("deepracer-control").parent
    required_resources = (
        "references/throttle-dead-zone-2026-07-31.md",
        "references/steering-trim-2026-07-31.md",
        "references/deepracer-hardware-inventory.md",
        "scripts/drive-daemon.py",
        "scripts/drive-calibration.py",
        "scripts/cam-obstacle.py",
        "templates/esp32-micropython.py",
    )

    for directory in ("references", "scripts", "templates"):
        shared_dir = router_dir / directory
        assert shared_dir.is_dir()
        assert any(shared_dir.iterdir()), f"{directory}/ must not be empty"
    for relative_path in required_resources:
        assert (router_dir / relative_path).is_file(), relative_path


def test_explicit_relative_shared_resource_references_resolve() -> None:
    references = []
    for name in FOCUSED_SKILLS:
        path = skill_path(name)
        for reference in re.findall(
            r"`(\.\./deepracer-control/(?:references|scripts|templates)/[^` ]+)`",
            read_skill(name),
        ):
            references.append((path, reference))

    assert references, "expected the moved content to retain shared-resource links"
    missing = [
        f"{path.parent.name}: {reference}"
        for path, reference in references
        if not (path.parent / reference).resolve().is_file()
    ]
    assert not missing, f"broken shared-resource references: {missing}"


def test_repo_relative_vision_sources_still_exist() -> None:
    repo_root = SKILLS_ROOT.parents[1]
    vision = read_skill("deepracer-vision")
    required_sources = (
        "apps/navigation/src/controlcamara.py",
        "docs/plans/actividad-aruco.md",
    )

    for source in required_sources:
        assert f"`{source}`" in vision
        assert (repo_root / source).is_file()


@pytest.mark.parametrize("name", EXPECTED_SKILLS)
def test_markdown_code_fences_are_balanced(name: str) -> None:
    fences = [line for line in read_skill(name).splitlines() if line.startswith("```")]

    assert len(fences) % 2 == 0, f"{name} has an unclosed fenced code block"


def test_parent_readme_indexes_the_complete_skill_family() -> None:
    readme = (SKILLS_ROOT / "README.md").read_text(encoding="utf-8")
    indexed_paths = set(re.findall(r"`robotics/(deepracer-[\w-]+)/`", readme))

    assert indexed_paths == set(EXPECTED_SKILLS)
    assert all(skill_path(name).is_file() for name in indexed_paths)


def test_phase_plan_records_the_completed_split_and_preservation_audit() -> None:
    repo_root = SKILLS_ROOT.parents[1]
    plan = (repo_root / "docs/plans/plan-evolucion-agente.md").read_text(
        encoding="utf-8"
    )

    for name in FOCUSED_SKILLS:
        assert re.search(rf"^- \[x\] `{re.escape(name)}`:", plan, re.MULTILINE)
    assert "0 líneas de contenido perdidas" in plan
    assert "`deepracer-control/SKILL.md` queda como router" in plan
