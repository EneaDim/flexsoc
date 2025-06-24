import numpy as np
import matplotlib.pyplot as plt

class HardwareFFT:
    def __init__(self, fft_len=1024, sample_rate=1e6, freq=50e3, amplitude=1.0, noise_amplitude=0.1, fixed_point=False):
        assert (fft_len & (fft_len - 1)) == 0, "FFT length must be a power of 2."
        self.N = fft_len
        self.fs = sample_rate
        self.freq = freq
        self.amplitude = amplitude
        self.noise_amplitude = noise_amplitude
        self.fixed_point = fixed_point

        self.input_signal = None
        self.fft_result = None
        self.twiddles = self.compute_twiddles()

    def compute_twiddles(self):
        """Compute twiddle factors (Wn = e^(-j*2*pi*k/N))"""
        return np.exp(-2j * np.pi * np.arange(self.N // 2) / self.N)

    def generate_input(self):
        """Generate noisy sine wave input signal"""
        t = np.arange(self.N) / self.fs
        sine = self.amplitude * np.sin(2 * np.pi * self.freq * t)
        noise = self.noise_amplitude * np.random.randn(self.N)
        self.input_signal = sine + noise
        if self.fixed_point:
            self.input_signal = np.round(self.input_signal * 32768).astype(np.int16)  # simulate Q15
        return self.input_signal

    def bit_reverse_indices(self):
        """Return bit-reversed indices for radix-2 FFT reordering"""
        bits = int(np.log2(self.N))
        return np.array([int('{:0{width}b}'.format(i, width=bits)[::-1], 2) for i in range(self.N)])

    def perform_fft(self):
        """Perform FFT manually in a radix-2 DIT way (like in hardware)"""
        x = self.input_signal.copy().astype(np.complex64)
        indices = self.bit_reverse_indices()
        x = x[indices]

        stages = int(np.log2(self.N))
        half_size = 1
        for stage in range(stages):
            step = half_size * 2
            for i in range(0, self.N, step):
                for j in range(half_size):
                    index = j * self.N // step
                    twiddle = self.twiddles[index]
                    a = x[i + j]
                    b = twiddle * x[i + j + half_size]
                    x[i + j] = a + b
                    x[i + j + half_size] = a - b
            half_size *= 2
        if self.fixed_point:
            # simulate fixed-point output truncation
            x = np.round(x.real).astype(np.int16) + 1j * np.round(x.imag).astype(np.int16)
        self.fft_result = x
        return self.fft_result

    def plot(self):
        """Plot time and frequency domain"""
        freqs = np.fft.fftfreq(self.N, d=1/self.fs)
        plt.figure(figsize=(12, 5))

        plt.subplot(1, 2, 1)
        plt.title("Time Domain Signal")
        plt.plot(np.arange(self.N) / self.fs, self.input_signal.real)
        plt.xlabel("Time [s]")
        plt.ylabel("Amplitude")

        plt.subplot(1, 2, 2)
        plt.title("FFT Magnitude")
        plt.plot(freqs[:self.N//2], 20 * np.log10(np.abs(self.fft_result[:self.N//2]) + 1e-6))
        plt.xlabel("Frequency [Hz]")
        plt.ylabel("Magnitude [dB]")
        plt.tight_layout()
        plt.show()


# === Example Usage ===
if __name__ == "__main__":
    fft_model = HardwareFFT(
        fft_len=64,
        sample_rate=1e6,
        freq=100e3,
        amplitude=1.0,
        noise_amplitude=0.05,
        fixed_point=True  # Set to True to simulate fixed-point rounding
    )

    fft_model.generate_input()
    fft_model.perform_fft()
    fft_model.plot()

