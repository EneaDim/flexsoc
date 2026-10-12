"""Generic software build support for CPU-driven functional tests."""

from __future__ import annotations

import re
from dataclasses import dataclass
from pathlib import Path
from typing import TYPE_CHECKING

from ...core import BackendContext, CommandRequest, ToolRunner

if TYPE_CHECKING:
    from ...design.soc.soc import SoCPlan


@dataclass(slots=True)
class SoCSoftware:
    """Build test-owned software without knowing application-specific tests."""

    context: BackendContext
    runner: ToolRunner

    @property
    def paths(self):
        return self.context.paths

    @staticmethod
    def render_memory_map(plan: "SoCPlan") -> str:
        lines = [
            "#ifndef FLEXSOC_SOC_MEMORY_MAP_H",
            "#define FLEXSOC_SOC_MEMORY_MAP_H",
            "",
            "#include <stdint.h>",
            "",
        ]
        for device in plan.devices:
            macro = re.sub(r"[^A-Za-z0-9]+", "_", device.name).upper().strip("_")
            lines += [
                f"#define SOC_{macro}_BASE_ADDR UINT32_C(0x{device.base:08X})",
                f"#define SOC_{macro}_SIZE UINT32_C(0x{device.size:08X})",
                "",
            ]
        return "\n".join((*lines, "#endif")) + "\n"

    def generate_memory_map(self, plan: "SoCPlan") -> Path:
        output = self.paths.sw / "include" / "soc_memory_map.h"
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(self.render_memory_map(plan), encoding="utf-8")
        return output

    def source_dir(self, test: str) -> Path:
        return self.paths.tests / test / "sw"

    def runtime_inputs(self, test: str) -> tuple[Path, Path]:
        build = self.source_dir(test) / "build"
        outputs = (build / "main.elf", build / "main.vmem")
        missing = [path for path in outputs if not path.is_file()]
        if missing:
            raise FileNotFoundError(
                f"{test} software build is incomplete: " + ", ".join(map(str, missing))
            )
        return outputs

    @staticmethod
    def binary_to_vmem(binary: Path, output: Path) -> Path:
        payload = binary.read_bytes()
        if len(payload) % 4:
            payload += b"\x00" * (4 - len(payload) % 4)
        words = [
            f"{int.from_bytes(payload[offset:offset + 4], 'little'):08x}"
            for offset in range(0, len(payload), 4)
        ]
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text("\n".join(words) + ("\n" if words else ""), encoding="utf-8")
        return output

    def build(self, test: str, *, on: str = "local") -> object | None:
        sw = self.source_dir(test)
        makefile = sw / "Makefile"
        if not sw.is_dir():
            return None
        if not makefile.is_file():
            raise FileNotFoundError(f"software test is missing Makefile: {makefile}")
        sources = tuple(
            path for path in sorted(sw.rglob("*"))
            if path.is_file() and "build" not in path.relative_to(sw).parts
        )
        build = sw / "build"
        elf, binary, vmem = build / "main.elf", build / "main.bin", build / "main.vmem"
        result = self.runner.run(
            CommandRequest(
                ("make", "--no-print-directory", "-C", str(sw), "clean", "all"),
                self.context.project_root, {},
                self.paths.logs / "soc" / f"sw-{test}.log",
                inputs=sources, outputs=(elf, binary),
            ),
            on=on,
        )
        if getattr(result, "returncode", 0):
            return result
        if not binary.is_file():
            raise FileNotFoundError(f"software binary was not produced: {binary}")
        self.binary_to_vmem(binary, vmem)
        return result
