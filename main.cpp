#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <utility>

#include "PROBLEMA 1/problema_1.cpp"
#include "PROBLEMA 2/problema_2.cpp"
#include "PROBLEMA 3/problema_3.cpp"

template <typename Func, typename... Args>
double benchmark(Func&& func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    std::forward<Func>(func)(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

int main() {
    const std::vector<int> test_sizes = {1, 10, 100, 1000, 10000, 100000};

    std::ofstream csv_file("benchmark_results.csv");
    csv_file << "n,Problema_1,Problema_2,Problema_3\n";

    std::cout   << std::left
                << std::setw(10) << "n"
                << std::setw(20) << "Problema 1 (ms)"
                << std::setw(20) << "Problema 2 (ms)"
                << std::setw(20) << "Problema 3 (ms)" << '\n'
                << std::string(70, '-') << '\n'
                << std::fixed << std::setprecision(4);

    for (int n : test_sizes) {
        double t1 = benchmark(problema_1, n);
        double t2 = benchmark(problema_2, n);
        double t3 = benchmark(problema_3, n);

        // Imprimir en consola
        std::cout   << std::setw(10) << n
                    << std::setw(20) << t1
                    << std::setw(20) << t2
                    << std::setw(20) << t3 << '\n';

        // Guardar en el CSV
        csv_file << n << "," << t1 << "," << t2 << "," << t3 << "\n";
    }

    csv_file.close();
    std::cout << "\nResultados guardados en 'benchmark_results.csv'.\n";
    return 0;
}
