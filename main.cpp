#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <utility>

#include "PROBLEMA 1/problema_1.cpp"
#include "PROBLEMA 2/problema_2.cpp"
#include "PROBLEMA 3/problema_3.cpp"

// ==========================================
// Medición de resultados
// ==========================================
template <typename Func, typename... Args>
double benchmark(Func&& func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    
    std::forward<Func>(func)(std::forward<Args>(args)...);
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

int main() {
    const std::vector<int> test_sizes = {1, 10, 100, 1000, 10000, 100000, 1000000};

    std::cout   << std::left
                << std::setw(10) << "n"
                << std::setw(20) << "Problema 1 (ms)"
                << std::setw(20) << "Problema 2 (ms)"
                << std::setw(20) << "Problema 3 (ms)" << '\n'
                << std::string(70, '-') << '\n'
                << std::fixed << std::setprecision(3);

    for (int n : test_sizes) {
        std::cout   << std::setw(10) << n
                    << std::setw(20) << benchmark(problema_1, n)
                    << std::setw(20) << benchmark(problema_2, n)
                    << std::setw(20) << benchmark(problema_3, n) << '\n';
    }

    return 0;
}
