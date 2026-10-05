import matplotlib
matplotlib.use("Agg")  # Renderizado sin interfaz gráfica (headless)
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("benchmark_results.csv")

df["Problema_1"] = df["Problema_1"].clip(lower=1e-6)
df["Problema_2"] = df["Problema_2"].clip(lower=1e-6)
df["Problema_3"] = df["Problema_3"].clip(lower=1e-6)

plt.figure(figsize=(10, 6))
plt.plot(df["n"], df["Problema_1"], marker="o", linewidth=2, label="Problema 1 (O(n² log n))")
plt.plot(df["n"], df["Problema_2"], marker="s", linewidth=2, label="Problema 2 (O(n))")
plt.plot(df["n"], df["Problema_3"], marker="^", linewidth=2, label="Problema 3 (O(n²))")

plt.xscale("log")
plt.yscale("log")
plt.title("Comparación de Rendimiento: Tiempo vs. Tamaño de Entrada (n)", fontsize=14, pad=12)
plt.xlabel("Tamaño de Entrada (n) [Escala Log]", fontsize=12)
plt.ylabel("Tiempo de Ejecución (ms) [Escala Log]", fontsize=12)
plt.grid(True, which="both", linestyle="--", linewidth=0.5, alpha=0.7)
plt.legend(fontsize=11)
plt.tight_layout()

plt.savefig("grafica_benchmark.png", dpi=300)
print("Gráfica generada exitosamente en 'grafica_benchmark.png'.")
