#!/usr/bin/env python3

import sys

def signed_to_twos_complement_hex(n: int, bits: int) -> str:
    if bits not in (8, 16, 32, 64):
        raise ValueError("Bit width must be 8, 16, 32, or 64")

    max_unsigned = 2 ** bits
    masked = n & (max_unsigned - 1)
    hex_width = bits // 4
    return f"0x{masked:0{hex_width}X}"

def main():
    if len(sys.argv) != 3:
        print("Uso: python twos_hex.py <numero_con_segno> <bit_width>")
        sys.exit(1)

    try:
        raw_input = sys.argv[1].replace('−', '-')  # Sostituisce il meno Unicode con quello ASCII
        n = int(raw_input)
        bits = int(sys.argv[2])
        result = signed_to_twos_complement_hex(n, bits)
        print(result)
    except Exception as e:
        print(f"Errore: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()

