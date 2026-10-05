# CC2019-LAB8

Análisis de algoritmos. El propósito del laboratorio es analizar y comparar cómo crece el tiempo de ejecución de tres algoritmos con distintas complejidades: `O(n² log n)`, `O(n)` y `O(n²)`.

## Descripción

Se implementaron los algoritmos en C++, un programa de *benchmark* que mide sus tiempos para diferentes tamaños de entrada y exporta los resultados a un archivo CSV. Finalmente, un script en Python genera una gráfica en escala logarítmica para comparar el comportamiento experimental con el análisis teórico.

## 1. Ejecutar

```bash
clang++ -std=c++17 -O2 main.cpp -o main
./main
```

## 2. Gráficar

```bash
docker compose run --rm plotter
```

**Enlace al video de ejecución**: <https://youtu.be/nkSnOaPbpj8>
