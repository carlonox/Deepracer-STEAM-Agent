"""Pruebas de navegación: rutas BFS, instrucciones y lugares ArUco."""
import sys
import pathlib

SRC = pathlib.Path(__file__).resolve().parents[1] / "src"
sys.path.insert(0, str(SRC))

from controlcamara import (  # noqa: E402
    normalize_text, is_stop_instruction, place_name_for_aruco,
    aruco_id_for_place, infer_place_from_instruction, shortest_place_route,
    ARUCO_PLACES, ARUCO_ROUTES,
)


def test_normalize_text():
    assert normalize_text("  Ve a Salida  ") == "ve a salida"


def test_is_stop_instruction():
    assert is_stop_instruction("parate")
    assert is_stop_instruction("quieto")
    assert not is_stop_instruction("ve a salida")


def test_aruco_roundtrip():
    for marker_id, place in ARUCO_PLACES.items():
        assert place_name_for_aruco(marker_id) == place["name"]
        assert aruco_id_for_place(place["name"]) == marker_id


def test_infer_place():
    assert infer_place_from_instruction("ve a impresora") == "impresora"
    assert infer_place_from_instruction("llévame a la salida") == "salida"


def test_shortest_route_bfs():
    assert shortest_place_route("mesa", "salida") == ["mesa", "impresora", "salida"]
    assert shortest_place_route("salida", "mesa") == ["salida", "impresora", "mesa"]
    assert shortest_place_route("mesa", "mesa") == ["mesa"]
    assert shortest_place_route("mesa", "no_existe") == []


def test_grafo_consistente():
    # Todo lugar con rutas existe en ARUCO_PLACES y viceversa
    for lugar in ARUCO_ROUTES:
        assert lugar in {p["name"] for p in ARUCO_PLACES.values()}
    for lugar in ARUCO_PLACES.values():
        assert lugar["name"] in ARUCO_ROUTES
