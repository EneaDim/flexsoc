"""Coverage annotation resolves relative RTL names against the run root."""

from pathlib import Path
from types import SimpleNamespace

from flexsoc.backend.dv.func.coverage import CoverageFlow


def test_annotation_uses_run_root_for_relative_coverage_sources(tmp_path: Path) -> None:
    run = tmp_path / "relocated" / "gpio" / "run"
    source = run / "rtl" / "gpio.sv"
    source.parent.mkdir(parents=True)
    source.write_text("module gpio; endmodule\n", encoding="utf-8")
    coverage = run / "dv" / "functional" / "coverage"
    coverage.mkdir(parents=True)
    merged = coverage / "merged.dat"
    merged.write_text("coverage\n", encoding="utf-8")
    calls = []

    class Runner:
        def run(self, request, *, on="local"):
            calls.append(request)
            assert (request.cwd / "rtl/gpio.sv").is_file()
            return SimpleNamespace(returncode=0)

    flow = CoverageFlow(runner=Runner())
    assert flow.annotate(merged, coverage / "annotated", source_root=run).is_dir()
    assert len(calls) == 1
    assert calls[0].cwd == run
