"""RDC: synchronous state controls must not mask genuine async reset hazards."""
from dataclasses import replace
from unittest.mock import patch

import pytest

from flexsoc.backend.core import ClockConfig, ClockDomain
from flexsoc.backend.dv.lint import cdc as mod


def _seq(name, domain, *, asynchronous=False):
    return mod.SequentialElement(
        name, "$sdff", 1 if domain == "core" else 9, domain,
        (10,), (11,),
        async_reset_bit=2 if asynchronous else None,
        sync_reset_bit=None if asynchronous else 3,
        reset_signal=name + "_rst", reset_polarity="high",
    )


@pytest.mark.parametrize(
    "src_async,dst_async,src_domain,dst_domain,expect_rdc",
    [
        (False, False, "core", "core", False),
        (True, False, "core", "core", True),
        (False, True, "core", "core", True),
        (True, True, "core", "core", True),
        (False, False, "core", "other", True),
        (False, False, None, None, True),
    ],
)
def test_sync_only_reset_scope(src_async, dst_async, src_domain, dst_domain, expect_rdc):
    src = _seq("src", src_domain, asynchronous=src_async)
    dst = _seq("dst", dst_domain, asynchronous=dst_async)
    crossing = mod.Crossing(
        mod.Endpoint("seq", "src", 0, src_domain, src.reset_signal),
        mod.Endpoint("seq", "dst", 0, dst_domain, dst.reset_signal),
        "same" if src_domain == dst_domain else "async",
    )
    ir = mod.DesignIR(
        top="test", clocks=(ClockDomain("core", "clk_i", "rst_i", 10.0),),
        ports=(), sequential=(src, dst), module={"ports": {}, "cells": {}, "netnames": {}},
    )
    with patch.object(mod.CdcFlow, "_sequential_dependencies", return_value=(crossing,)), patch.object(
        mod.CdcFlow, "_reset_family_map", return_value={"src": "src_rst", "dst": "dst_rst"}
    ):
        result = mod.CdcFlow.analyze_domains(ir, ClockConfig(ir.clocks))
    assert bool(result.reset_crossings) == expect_rdc
    if expect_rdc:
        findings = mod.CdcFlow._check_reset_crossings(result, ())
        assert findings[0].status == "ERROR"
