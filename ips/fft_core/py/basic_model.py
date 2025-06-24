import numpy as np
import matplotlib.pyplot as plt

# Parametri
N = 64
fs = 100e6            # Frequenza di campionamento (Hz)
f = 10e6              # Frequenza della sinusoide (Hz)
t = np.arange(N) / fs

# --- Sinusoide floating-point ---
sine_float = np.sin(2 * np.pi * f * t)

# --- Conversione Q1.15 ---
def float_to_q15(x):
    x_clipped = np.clip(x, -1.0, 0.999969)
    return np.round(x_clipped * 32768).astype(np.int16)

sine_q15 = float_to_q15(sine_float)
sine_q15_float = sine_q15.astype(np.float32) / 32768.0  # back to float for FFT

# --- FFT ---
fft_float = np.fft.fft(sine_float)
fft_q15   = np.fft.fft(sine_q15_float)
freqs     = np.fft.fftfreq(N, d=1/fs)

# === PLOT ===

plt.figure(figsize=(14, 12))

# --- 1. Segnale nel tempo ---
plt.subplot(4, 1, 1)
plt.plot(t * 1e9, sine_float, label='Floating-point')
plt.plot(t * 1e9, sine_q15_float, '--', label='Q1.15 (riconvertito)')
plt.title("Segnale in Ingresso (Dominio del Tempo)")
plt.xlabel("Tempo (ns)")
plt.ylabel("Ampiezza")
plt.grid()
plt.legend()

# --- 2. Modulo FFT ---
plt.subplot(4, 1, 2)
plt.stem(freqs[:N//2], np.abs(fft_float[:N//2]), linefmt='b-', markerfmt='bo', basefmt=" ", label='Float')
plt.stem(freqs[:N//2], np.abs(fft_q15[:N//2]), linefmt='r--', markerfmt='rx', basefmt=" ", label='Q1.15')
plt.title("Modulo FFT (float vs Q1.15)")
plt.ylabel("Ampiezza")
plt.legend()
plt.grid()

# --- 3. Parte reale ---
plt.subplot(4, 1, 3)
plt.stem(freqs[:N//2], np.real(fft_float[:N//2]), linefmt='b-', markerfmt='bo', basefmt=" ", label='Float')
plt.stem(freqs[:N//2], np.real(fft_q15[:N//2]), linefmt='r--', markerfmt='rx', basefmt=" ", label='Q1.15')
plt.title("Parte Reale della FFT")
plt.ylabel("Re(X[k])")
plt.legend()
plt.grid()

# --- 4. Parte immaginaria ---
plt.subplot(4, 1, 4)
plt.stem(freqs[:N//2], np.imag(fft_float[:N//2]), linefmt='b-', markerfmt='bo', basefmt=" ", label='Float')
plt.stem(freqs[:N//2], np.imag(fft_q15[:N//2]), linefmt='r--', markerfmt='rx', basefmt=" ", label='Q1.15')
plt.title("Parte Immaginaria della FFT")
plt.xlabel("Frequenza (Hz)")
plt.ylabel("Im(X[k])")
plt.legend()
plt.grid()

plt.tight_layout()
plt.show()

