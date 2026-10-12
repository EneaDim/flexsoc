from pathlib import Path

from flexsoc.backend.core import BackendContext
from flexsoc.backend.design.soc.soc import SocFlow


def test_native_primitive_materialization_removes_legacy_prim_generic(tmp_path: Path) -> None:
    project = tmp_path / "project"
    context = BackendContext(
        project,
        tmp_path / "work",
        {
            "TOP": "test",
            "RUN_TOP": "test",
            "RUN_ID": "dev",
            "HOST": "ibex",
            "FABRIC": "tlul",
        },
    )
    context.paths.ensure()

    flexsoc = project / "hw" / "ips" / "prim_opentitan"
    generic = project / "vendor" / "lowrisc_ip" / "ip" / "prim_generic" / "rtl"
    flexsoc.mkdir(parents=True)
    generic.mkdir(parents=True)

    (flexsoc / "prim_buf.sv").write_text(
        "module prim_buf; endmodule\n",
        encoding="utf-8",
    )
    (generic / "prim_generic_ram_2p.sv").write_text(
        "module prim_generic_ram_2p; endmodule\n",
        encoding="utf-8",
    )

    stale = context.paths.rtl / "prim_generic"
    stale.mkdir(parents=True)
    (stale / "prim_buf.sv").write_text(
        "module prim_buf; endmodule\n",
        encoding="utf-8",
    )

    output = SocFlow(context).materialize_native_primitives()

    assert not stale.exists()
    assert (output / "prim_buf.sv").is_file()
    assert (output / "prim_ram_2p.sv").is_file()
