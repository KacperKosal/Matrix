#include <iostream>
#include "Matrix.hpp"

/**
 * @file main.cpp
 * @brief Plik główny zawierający funkcję testującą klasę Matrix.
 */

/**
 * @brief Funkcja główna programu.
 *
 * Funkcja testuje podstawowe operacje na macierzy klasy Matrix, takie jak:
 * - tworzenie macierzy na podstawie danych wejściowych,
 * - wyświetlanie macierzy,
 * - modyfikacja elementów macierzy,
 * - kopiowanie macierzy,
 * - porównywanie macierzy.
 *
 * @return Zwraca 0 w przypadku poprawnego wykonania programu.
 */
int main() {
    try {
        /**
         * @brief Tablica wejściowa do inicjalizacji macierzy.
         */
        int initialData[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        /**
         * @brief Utworzenie macierzy `m1` o wymiarach 3x3 na podstawie tablicy `initialData`.
         */
        Matrix m1(3, initialData);

        std::cout << "Macierz m1:" << std::endl;
        std::cout << m1 << std::endl;

        /**
         * @brief Modyfikacja elementu macierzy `m1` w pozycji (0, 0).
         */
        m1.wstaw(0, 0, 99);
        std::cout << "Zmodyfikowana macierz m1:" << std::endl;
        std::cout << m1 << std::endl;

        /**
         * @brief Utworzenie kopii macierzy `m1` w nowej macierzy `m2`.
         */
        Matrix m2 = m1;
        std::cout << "Skopiowana macierz m2:" << std::endl;
        std::cout << m2 << std::endl;

        /**
         * @brief Porównanie macierzy `m1` i `m2`.
         */
        std::cout << "Czy macierze m1 i m2 są równe? "
                  << (m1 == m2 ? "Tak" : "Nie") << std::endl;

    } catch (const std::exception& e) {
        /**
         * @brief Obsługa błędów, w przypadku wystąpienia wyjątku.
         */
        std::cerr << "Błąd: " << e.what() << std::endl;
    }

    return 0;
}
