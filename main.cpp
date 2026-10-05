#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <utility>

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
    std::vector<int> test_sizes = {1, 10, 100, 1000, 10000, 100000, 1000000};

    std::cout   << std::left 
                << std::setw(12) << "n" 
                << std::setw(20) << "Tiempo (ms)" 
                << "\n";
    std::cout   << std::string(32, '-') << "\n";


    return 0;
}
