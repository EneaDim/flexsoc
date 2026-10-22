"""UART master semantic host requests, independently of CSR/bus timings."""
from dataclasses import dataclass

@dataclass(frozen=True)
class Request:
    address: int
    write: bool = False
    data: int = 0
    byte_enable: int = 0xF

REQUESTS = {
    "host_read": Request(0x10000040),
    "host_write": Request(0x10000080, write=True, data=0x12345678),
    "host_alignment": Request(0x10000043),
    "host_byte_enable": Request(0x10000080, write=True, data=0xA5A55A5A, byte_enable=0x5),
}
READ_RESPONSE = (0x12345678, True, (0x5A, 1, 0, 1, 0x12, 0x34, 0x56, 0x78))
MODEL_CASES = (*REQUESTS, "read_response_format")
