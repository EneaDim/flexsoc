"""Qualification stage ordering is deterministic and technology-independent."""

import pytest

from flexsoc.backend.core.flow.lifecycle import STAGE_CONTRACTS, StageContract, StageGraph


def test_existing_contract_graph_is_valid() -> None:
    StageGraph(STAGE_CONTRACTS).validate()


def test_shared_parents_are_ordered_once() -> None:
    graph = StageGraph({
        "source": StageContract(),
        "model": StageContract(parents=("source",)),
        "rtl": StageContract(parents=("source",)),
        "verification": StageContract(parents=("model", "rtl")),
    })
    assert graph.prerequisites("verification") == ("source", "model", "rtl")


@pytest.mark.parametrize("contracts, message", [
    ({"a": StageContract(parents=("missing",))}, "unknown prerequisite"),
    ({"a": StageContract(parents=("b",)), "b": StageContract(parents=("a",))}, "cycle"),
    ({"rtl": StageContract(parents=("syn",)), "syn": StageContract(scope="pdk")}, "technology-independent"),
])
def test_invalid_graph_is_rejected(contracts: dict[str, StageContract], message: str) -> None:
    with pytest.raises(ValueError, match=message):
        StageGraph(contracts).validate()


def test_pdk_stage_can_depend_on_run_stage() -> None:
    graph = StageGraph({"rtl": StageContract(), "syn": StageContract(parents=("rtl",), scope="pdk")})
    assert graph.prerequisites("syn") == ("rtl",)


def test_behavioral_and_rtl_regressions_have_independent_provenance() -> None:
    graph = StageGraph({
        "spec": StageContract(),
        "testplan": StageContract(parents=("spec",)),
        "model": StageContract(parents=("spec",)),
        "model_tests": StageContract(parents=("model", "testplan")),
        "csr": StageContract(parents=("spec",)),
        "rtl": StageContract(parents=("csr",)),
        "sdc": StageContract(parents=("rtl",)),
        "lint": StageContract(parents=("rtl",)),
        "cdc_rdc": StageContract(parents=("rtl", "sdc"), gates=("lint",)),
        "rtl_tests": StageContract(parents=("rtl", "testplan")),
        "rtl_regression": StageContract(parents=("rtl_tests", "rtl"), gates=("cdc_rdc",)),
        "traceability": StageContract(parents=("testplan", "rtl_regression")),
        "formal": StageContract(parents=("rtl",), gates=("rtl_regression",)),
        "l2": StageContract(gates=("model_tests", "rtl_regression", "traceability", "formal")),
        "syn": StageContract(parents=("rtl",), scope="pdk", gates=("l2",)),
    })
    graph.validate()
    assert graph.affected(("model",)) == ("model", "model_tests")
    assert graph.affected(("lint",)) == ("lint",)
    assert graph.affected(("rtl_tests",)) == ("rtl_tests", "rtl_regression", "traceability")
    assert graph.affected(("rtl",)) == (
        "rtl", "sdc", "lint", "rtl_tests", "cdc_rdc", "rtl_regression",
        "traceability", "formal", "syn",
    )
    prerequisites = graph.prerequisites("l2")
    assert prerequisites.index("model_tests") < len(prerequisites)
    assert prerequisites.index("cdc_rdc") < prerequisites.index("rtl_regression")
    assert prerequisites.index("rtl_regression") < prerequisites.index("formal")


def test_affected_stages_are_selective_and_ordered() -> None:
    graph = StageGraph({
        "spec": StageContract(),
        "model": StageContract(parents=("spec",)),
        "csr": StageContract(parents=("spec",)),
        "lint": StageContract(parents=("csr",)),
        "model_tests": StageContract(parents=("model",)),
        "regression": StageContract(parents=("lint",), gates=("model_tests",)),
        "formal": StageContract(parents=("lint",), gates=("regression",)),
        "syn": StageContract(parents=("regression",), scope="pdk"),
    })
    assert graph.affected(("model",)) == ("model", "model_tests")
    assert graph.affected(("csr",)) == ("csr", "lint", "regression", "formal", "syn")
    assert graph.affected(("syn",)) == ("syn",)
    assert graph.affected(()) == ()


def test_gates_are_validated_but_never_invalidate_evidence() -> None:
    graph = StageGraph({
        "model_tests": StageContract(),
        "rtl_tests": StageContract(gates=("model_tests",)),
    })
    assert graph.prerequisites("rtl_tests") == ("model_tests",)
    assert graph.affected(("model_tests",)) == ("model_tests",)
    with pytest.raises(ValueError, match="unknown prerequisite"):
        StageGraph({"rtl": StageContract(gates=("missing",))}).validate()
    with pytest.raises(ValueError, match="cycle"):
        StageGraph({"a": StageContract(gates=("b",)), "b": StageContract(gates=("a",))}).validate()
    with pytest.raises(ValueError, match="technology-independent"):
        StageGraph({"l2": StageContract(gates=("syn",)), "syn": StageContract(scope="pdk")}).validate()


def test_affected_rejects_invalid_stage_and_graph() -> None:
    graph = StageGraph({"a": StageContract()})
    with pytest.raises(ValueError, match="Unknown stage"):
        graph.affected(("missing",))
    with pytest.raises(ValueError, match="cycle"):
        StageGraph({"a": StageContract(parents=("b",)),
                    "b": StageContract(parents=("a",))}).affected(("a",))
