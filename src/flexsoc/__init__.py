"""FlexSoC public package exports."""

from __future__ import annotations

__all__ = [
    "FlexSoC", "FlexSoCCommand", "FlexSoCConfig", "FlexSoCResult",
    "FlexSoCTarget", "FlexSoCTargetInfo",
]


def __getattr__(name: str) -> object:
    """Load public API objects only when requested."""

    if name not in __all__:
        raise AttributeError(f"module {__name__!r} has no attribute {name!r}")
    from . import api

    return getattr(api, name)
