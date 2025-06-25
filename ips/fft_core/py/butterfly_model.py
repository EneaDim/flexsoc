import numpy as np

# Q1.15 conversion helpers
def q15(val):
    return np.int16(np.clip(np.round(val * (1 << 15)), -32768, 32767))

def q15_to_hex(val):
    return f"0x{np.uint16(val):04X}"

def q15_mul(a, b):
    return np.int16(np.clip((a * b) >> 15, -32768, 32767))

# Bit-reverse indices for radix-2 DIT
def bit_reverse_indices(N):
    bits = int(np.log2(N))
    return [int('{:0{w}b}'.format(i, w=bits)[::-1], 2) for i in range(N)]

# Q1.15 complex number class
class Q15Complex:
    def __init__(self, re, im=0):
        self.re = np.int32(re)
        self.im = np.int32(im)

    def __repr__(self):
        return f"({q15_to_hex(self.re)}, {q15_to_hex(self.im)})"

    def to_uint32(self):
        return (np.uint32(np.uint16(self.re)) << 16) | np.uint16(self.im)

# Twiddle factors
def twiddle_factors(N):
    W = []
    for k in range(N // 2):
        angle = -2 * np.pi * k / N
        W.append(Q15Complex(q15(np.cos(angle)), q15(np.sin(angle))))
    return W

# Butterfly operation
def butterfly(u, v, wn):
    # t = v * wn
    t_re = q15_mul(v.re, wn.re) - q15_mul(v.im, wn.im)
    t_im = q15_mul(v.re, wn.im) + q15_mul(v.im, wn.re)
    t = Q15Complex(t_re, t_im)

    u_prime = Q15Complex(
        np.int16(np.clip(u.re + t.re, -32768, 32767)),
        np.int16(np.clip(u.im + t.im, -32768, 32767))
    )

    v_prime = Q15Complex(
        np.int16(np.clip(u.re - t.re, -32768, 32767)),
        np.int16(np.clip(u.im - t.im, -32768, 32767))
    )

    return t, u_prime, v_prime

# Main FFT
def fft_q15_radix2_dit(samples):
    N = len(samples)
    logN = int(np.log2(N))
    assert N == 1 << logN, "N must be a power of 2"

    # Init input
    X = [Q15Complex(q15(s), 0) for s in samples]
    X = [X[i] for i in bit_reverse_indices(N)]

    # Twiddle factors
    W = twiddle_factors(N)

    stage = 0
    size = 2
    while size <= N:
        half = size // 2
        print(f"\n=== STAGE {stage} (size = {size}) ===")
        for i in range(0, N, size):
            for j in range(half):
                idx = i + j
                u = X[idx]
                v = X[idx + half]
                wn = W[(j * N) // size]

                print(f"\nButterfly [{idx}, {idx + half}]")
                print(f"  u  = {u}")
                print(f"  v  = {v}")
                print(f"  Wn = {wn}")

                t, u_prime, v_prime = butterfly(u, v, wn)

                print(f"  t  = {t}")
                print(f"  u' = {u_prime}")
                print(f"  v' = {v_prime}")

                X[idx] = u_prime
                X[idx + half] = v_prime
        size *= 2
        stage += 1

    return X

# Esempio di input
samples_16bit = [1000, 2000, 3000, 4000, 1000, -1000, -2000, -3000]

result = fft_q15_radix2_dit(samples_16bit)

# Output finale
print("\n=== RISULTATI FINALI ===")
for i, x in enumerate(result):
    print(f"X[{i}] = {x} => 0x{x.to_uint32():08X}")
