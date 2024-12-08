#include "Matrix.hpp"
#include <iostream>

/**
 * @brief Main function for testing the Matrix class
 */
int main() {
    try {
        // Create matrix and test methods
        int initialData[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        Matrix m1(3, initialData);

        std::cout << "Matrix m1:" << std::endl;
        std::cout << m1 << std::endl;

        m1.wstaw(0, 0, 99);
        std::cout << "Modified m1:" << std::endl;
        std::cout << m1 << std::endl;

        Matrix m2 = m1;
        std::cout << "Copied m2:" << std::endl;
        std::cout << m2 << std::endl;

        std::cout << "Are m1 and m2 equal? " << (m1 == m2 ? "Yes" : "No") << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
