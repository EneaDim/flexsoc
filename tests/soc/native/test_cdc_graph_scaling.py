from __future__ import annotations

from flexsoc.backend.core import ClockConfig, ClockDomain
from flexsoc.backend.dv.lint import cdc as cdc_module


def _adff(clk: int, arst: int, d: int | str, q: int) -> dict[str, object]:
    return {
        "type": "$adff",
        "attributes": {},
        "parameters": {"ARST_POLARITY": "0"},
        "port_directions": {
            "CLK": "input",
            "ARST": "input",
            "D": "input",
            "Q": "output",
        },
        "connections": {"CLK": [clk], "ARST": [arst], "D": [d], "Q": [q]},
    }


def test_single_clock_dense_datapath_is_not_materialized_as_cdc_graph() -> None:
    clocks = ClockConfig((ClockDomain("core", "clk_i", "rst_ni", 10.0),))
    cells: dict[str, dict[str, object]] = {}
    source_bits = []
    for index in range(64):
        q = 100 + index
        source_bits.append(q)
        cells[f"src_{index}"] = _adff(1, 2, "0", q)

    cells["dense_reduce"] = {
        "type": "$reduce_or",
        "attributes": {},
        "port_directions": {"A": "input", "Y": "output"},
        "connections": {"A": source_bits, "Y": [500]},
    }
    for index in range(64):
        cells[f"dst_{index}"] = _adff(1, 2, 500, 600 + index)

    module = {
        "ports": {
            "clk_i": {"direction": "input", "bits": [1]},
            "rst_ni": {"direction": "input", "bits": [2]},
        },
        "netnames": {
            "clk_i": {"bits": [1]},
            "rst_ni": {"bits": [2]},
        },
        "cells": cells,
    }
    ir = cdc_module.CdcFlow.load_yosys_json({"modules": {"demo": module}}, "demo", clocks)
    analysis = cdc_module.CdcFlow.analyze_domains(ir, clocks)

    assert len(ir.sequential) == 128
    assert all(item.clock_domain == "core" for item in ir.sequential)
    assert analysis.clock_crossings == ()
    assert analysis.reset_crossings == ()
    assert analysis.dependencies == ()


def test_structurally_gated_clock_inherits_domain_but_remains_glitch_evidence() -> None:
    clocks = ClockConfig((ClockDomain("core", "clk_i", "rst_ni", 10.0),))
    module = {
        "ports": {
            "clk_i": {"direction": "input", "bits": [1]},
            "rst_ni": {"direction": "input", "bits": [2]},
            "enable_i": {"direction": "input", "bits": [3]},
        },
        "netnames": {
            "clk_i": {"bits": [1]},
            "rst_ni": {"bits": [2]},
            "gclk": {"bits": [4]},
        },
        "cells": {
            "gate_logic": {
                "type": "$and",
                "attributes": {},
                "port_directions": {"A": "input", "B": "input", "Y": "output"},
                "connections": {"A": [1], "B": [3], "Y": [4]},
            },
            "q0": _adff(4, 2, "0", 5),
            "q1": _adff(4, 2, "0", 6),
        },
    }
    ir = cdc_module.CdcFlow.load_yosys_json({"modules": {"demo": module}}, "demo", clocks)
    result = cdc_module.CdcFlow.classify_cdc_rdc(
        ir, cdc_module.CdcFlow.analyze_domains(ir, clocks)
    )

    assert all(item.clock_domain == "core" for item in ir.sequential)
    assert not [item for item in result.setup if item.classification == "unassigned_clock_domain"]
    glitch = [item for item in result.glitch if item.classification == "combinational_clock_path"]
    assert len(glitch) == 1
    assert glitch[0].status == "ERROR"
    assert "sequential_count=2" in glitch[0].evidence


def test_lowrisc_prim_clock_gating_is_a_trusted_clock_boundary() -> None:
    clocks = ClockConfig((ClockDomain("core", "clk_i", "rst_ni", 10.0),))
    cells: dict[str, dict[str, object]] = {
        "u_gate": {
            "type": "prim_clock_gating",
            "attributes": {},
            "port_directions": {
                "clk_i": "input",
                "en_i": "input",
                "test_en_i": "input",
                "clk_o": "output",
            },
            "connections": {
                "clk_i": [1],
                "en_i": [3],
                "test_en_i": ["0"],
                "clk_o": [4],
            },
        }
    }
    for index in range(126):
        cells[f"q_{index}"] = _adff(4, 2, "0", 100 + index)
    module = {
        "ports": {
            "clk_i": {"direction": "input", "bits": [1]},
            "rst_ni": {"direction": "input", "bits": [2]},
            "enable_i": {"direction": "input", "bits": [3]},
        },
        "netnames": {"clk_i": {"bits": [1]}, "gclk": {"bits": [4]}},
        "cells": cells,
    }

    ir = cdc_module.CdcFlow.load_yosys_json(
        {"modules": {"demo": module}}, "demo", clocks
    )
    result = cdc_module.CdcFlow.classify_cdc_rdc(
        ir, cdc_module.CdcFlow.analyze_domains(ir, clocks)
    )

    assert len(ir.sequential) == 126
    assert all(item.clock_domain == "core" for item in ir.sequential)
    assert not [
        item
        for item in result.glitch
        if item.classification == "combinational_clock_path"
    ]


def test_extract_script_preserves_lowrisc_clock_gate_boundary(tmp_path) -> None:
    script = cdc_module.CdcFlow.render_extract_script(
        top="soc",
        filelists=(tmp_path / "rtl.f",),
        repo_root=tmp_path,
        design_json=tmp_path / "design.json",
    )

    assert "setattr -mod -set whitebox 1 *prim_clock_gating*" in script
    assert "setattr -mod -set whitebox 1 m:*prim_clock_gating*" not in script
    assert "keep_hierarchy m:*prim_clock_gating*" not in script
    assert "keep_hierarchy */t:*prim_clock_gating*" not in script




def test_loader_rejects_unflattened_noncontract_hierarchy() -> None:
    clocks = ClockConfig((ClockDomain("core", "clk_i", "rst_ni", 10.0),))
    top = {
        "ports": {
            "clk_i": {"direction": "input", "bits": [1]},
            "rst_ni": {"direction": "input", "bits": [2]},
        },
        "netnames": {},
        "cells": {
            "u_child": {
                "type": "child",
                "attributes": {},
                "port_directions": {},
                "connections": {},
            }
        },
    }

    import pytest

    with pytest.raises(ValueError, match=r"unflattened hierarchy.*u_child:child"):
        cdc_module.CdcFlow.load_yosys_json(
            {"modules": {"demo": top, "child": {"ports": {}, "cells": {}}}},
            "demo",
            clocks,
        )


def test_loader_accepts_preserved_clock_gate_whitebox() -> None:
    clocks = ClockConfig((ClockDomain("core", "clk_i", "rst_ni", 10.0),))
    module = {
        "ports": {
            "clk_i": {"direction": "input", "bits": [1]},
            "rst_ni": {"direction": "input", "bits": [2]},
            "enable_i": {"direction": "input", "bits": [3]},
        },
        "netnames": {"gclk": {"bits": [4]}},
        "cells": {
            "u_gate": {
                "type": "prim_clock_gating",
                "attributes": {},
                "port_directions": {"clk_i": "input", "clk_o": "output"},
                "connections": {"clk_i": [1], "clk_o": [4]},
            },
            "q": _adff(4, 2, "0", 10),
        },
    }

    ir = cdc_module.CdcFlow.load_yosys_json(
        {"modules": {"demo": module, "prim_clock_gating": {"ports": {}, "cells": {}}}},
        "demo",
        clocks,
    )

    assert len(ir.sequential) == 1
    assert ir.sequential[0].clock_domain == "core"


def test_parameterized_lowrisc_clock_gate_type_is_trusted() -> None:
    cell = {"type": "$paramod$7f2a\\prim_clock_gating\\NoFpgaBuf=1"}

    assert cdc_module.CdcFlow._builtin_clock_gate_ports(cell) == ("clk_i", "clk_o")

def test_yosys_derived_lowrisc_clock_gate_type_is_trusted() -> None:
    cell = {"type": "prim_clock_gating$soc.u_ibex_top.core_clock_gate_i"}

    assert cdc_module.CdcFlow._builtin_clock_gate_ports(cell) == ("clk_i", "clk_o")


def test_real_cross_domain_dependency_is_preserved() -> None:
    clocks = ClockConfig((
        ClockDomain("a", "a_clk_i", "a_rst_ni", 10.0),
        ClockDomain("b", "b_clk_i", "b_rst_ni", 12.0),
    ))
    module = {
        "ports": {
            "a_clk_i": {"direction": "input", "bits": [1]},
            "a_rst_ni": {"direction": "input", "bits": [2]},
            "b_clk_i": {"direction": "input", "bits": [3]},
            "b_rst_ni": {"direction": "input", "bits": [4]},
        },
        "netnames": {},
        "cells": {
            "src": _adff(1, 2, "0", 10),
            "comb": {
                "type": "$not",
                "attributes": {},
                "port_directions": {"A": "input", "Y": "output"},
                "connections": {"A": [10], "Y": [11]},
            },
            "dst": _adff(3, 4, 11, 12),
            "sync2": _adff(3, 4, 12, 13),
        },
    }
    ir = cdc_module.CdcFlow.load_yosys_json({"modules": {"demo": module}}, "demo", clocks)
    analysis = cdc_module.CdcFlow.analyze_domains(ir, clocks)

    crossing = next(
        item
        for item in analysis.clock_crossings
        if item.source.name == "src" and item.destination.name == "dst"
    )
    assert crossing.relationship == "sync"
    assert crossing.path == ("comb",)
    assert any(
        item.source.name == "dst" and item.destination.name == "sync2"
        for item in analysis.dependencies
    )
