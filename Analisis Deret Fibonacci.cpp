#include <iostream>
#include <chrono>
#include <vector>

// Pendekatan rekursif
unsigned long long fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Pendekatan dynamic programming
unsigned long long fibonacci_dynamic(int n) {
    if (n <= 1)
        return n;
    std::vector<unsigned long long> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

// Fungsi untuk mengukur waktu eksekusi
double measure_time(unsigned long long (*func)(int), int n) {
    auto start = std::chrono::high_resolution_clock::now();
    func(n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

int main() {
    // Nilai n yang akan diuji
    std::vector<int> n_values = {10, 25, 30, 40, 50};

    // Mengukur waktu eksekusi untuk kedua pendekatan
    std::vector<double> recursive_times;
    std::vector<double> dynamic_times;

    for (int n : n_values) {
        recursive_times.push_back(measure_time(fibonacci_recursive, n));
        dynamic_times.push_back(measure_time(fibonacci_dynamic, n));
    }

    // Membuat tabel hasil waktu eksekusi
    std::cout << "Tabel Waktu Eksekusi:\n";
    std::cout << "n\tRecursive (s)\tDynamic (s)\n";
    for (size_t i = 0; i < n_values.size(); ++i) {
        std::cout << n_values[i] << "\t" << recursive_times[i] << "\t" << dynamic_times[i] << "\n";
    }

    return 0;
}
