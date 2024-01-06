#include <iostream>
#include <vector>

#include "Median.hpp"

int main() {
    std::cout << "Enter the total number of elements:\n";

    int elmntCount;
    std::cin >> elmntCount;

    Median med;

    for (int i = 0; i < elmntCount; ++i) {
        std::cout << "Enter number[" << i + 1 << '/' << elmntCount << "]: ";

        int num;
        std::cin >> num;

        med.add(num);
        std::cout << "Current median = " << med.median() << '\n';
    }

    return 0;
}
