#include <iostream>
#include <vector>
#include <random>
#include <chrono>

#include "Median.hpp"

int main() {
    std::size_t count = 100'000'000;

    std::cout << "Enter number of elements: \n";
   // std::cin >> count;

    std::random_device rd;
    std::mt19937 gen{ rd() };
    std::uniform_int_distribution<> distrib{  std::numeric_limits<int>::min(), std::numeric_limits<int>::max() };

    std::cout << "Generating " << count << " random elements\n";

    const auto start = std::chrono::steady_clock::now();
    {
        Median med;
        for (size_t i = 0; i < count; ++i) {
            med.add(distrib(gen));
        }

        std::cout << "Median is " << med.median() << '\n';
    }
    const auto end = std::chrono::steady_clock::now();

    std::cout << "Time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n";

    return 0;
}
