import numpy as np
import matplotlib.pyplot as plt

magnitude = np.loadtxt("fft_output.txt")
# Peak
peak_bin = np.argmax(magnitude)
print("Peak at bin:", peak_bin)
# Plot
plt.plot(magnitude[:len(magnitude)//2])
plt.title("FFT Spectrum")
plt.xlabel("Frequency Bin")
plt.ylabel("Magnitude")
plt.grid(True)
plt.show()

