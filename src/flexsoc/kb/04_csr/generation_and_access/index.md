# Generation & Access

- Check generated RTL, software-visible register map, and bus transaction semantics against the register specification.
- Keep bus masters as reusable Cocotb drivers owned by the relevant interface or IP, not hardcoded in the generic backend.
