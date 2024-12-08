#include <iostream>
#include "Matrix.hpp"

/**
 * @file main.cpp
 * @brief Plik główny do testowania klasy Matrix.
 *
 * Testuje różne funkcje i operatory klasy Matrix, w tym:
 * - Tworzenie i inicjalizację macierzy.
 * - Operacje matematyczne (dodawanie, mnożenie, odejmowanie).
 * - Operacje na elementach macierzy (ustawianie wartości, wierszy, kolumn, przekątnych).
 * - Testowanie losowego wypełniania macierzy.
 * - Porównywanie macierzy.
 */

/**
 * @brief Funkcja główna programu.
 *
 * Funkcja testuje funkcjonalności klasy Matrix poprzez różnorodne operacje:
 * - Tworzenie macierzy, kopiowanie i modyfikowanie.
 * - Operacje matematyczne między macierzami oraz z wykorzystaniem skalarów.
 * - Losowanie wartości w macierzy i ustawianie wartości na przekątnych, wierszach i kolumnach.
 * - Sprawdzanie operatorów porównania, inkrementacji i dekrementacji.
 *
 * @return Zwraca 0, jeśli program zakończył się poprawnie.
 */
int main() {
    /**
     * @section Initialization Inicjalizacja macierzy
     */
    // Tworzenie macierzy o rozmiarze 3x3
    Matrix m1(3);
    int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    m1 = Matrix(3, t);

    // Wyświetlanie macierzy
    std::cout << "Macierz m1:" << std::endl;
    std::cout << m1 << std::endl;

    /**
     * @section Copying Kopiowanie macierzy
     */
    // Kopiowanie macierzy
    Matrix m2 = m1;

    // Modyfikacja elementów macierzy
    m2.wstaw(0, 0, 10);

    // Wyświetlanie zmodyfikowanej macierzy
    std::cout << "Macierz m2 po modyfikacji:" << std::endl;
    std::cout << m2 << std::endl;

    /**
     * @section Comparison Porównywanie macierzy
     */
    // Porównywanie macierzy
    if (m1 == m2) {
        std::cout << "Macierze m1 i m2 są równe." << std::endl;
    } else {
        std::cout << "Macierze m1 i m2 są różne." << std::endl;
    }

    /**
     * @section MathOperators Operacje matematyczne
     */
    // Dodawanie macierzy
    Matrix m3 = m1 + m2;
    std::cout << "Macierz m3 (m1 + m2):" << std::endl;
    std::cout << m3 << std::endl;

    // Mnożenie macierzy
    Matrix m4 = m1 * m2;
    std::cout << "Macierz m4 (m1 * m2):" << std::endl;
    std::cout << m4 << std::endl;

    // Odejmowanie macierzy
    Matrix m5 = m1 - m2;
    std::cout << "Macierz m5 (m1 - m2):" << std::endl;
    std::cout << m5 << std::endl;

    /**
     * @section ScalarOperators Operacje ze skalarami
     */
    // Dodawanie skalaru
    Matrix m6 = m1 + 5;
    std::cout << "Macierz m6 (m1 + 5):" << std::endl;
    std::cout << m6 << std::endl;

    // Mnożenie przez skalar
    Matrix m7 = m1 * 2;
    std::cout << "Macierz m7 (m1 * 2):" << std::endl;
    std::cout << m7 << std::endl;

    // Odejmowanie skalaru
    Matrix m8 = m1 - 3;
    std::cout << "Macierz m8 (m1 - 3):" << std::endl;
    std::cout << m8 << std::endl;

    /**
     * @section Randomization Losowanie wartości w macierzy
     */
    // Losowanie wartości w macierzy
    m1.losuj();
    std::cout << "Macierz m1 po losowaniu:" << std::endl;
    std::cout << m1 << std::endl;

    // Losowanie ograniczonej liczby elementów
    m1.losuj(5);
    std::cout << "Macierz m1 po losowaniu 5 elementów:" << std::endl;
    std::cout << m1 << std::endl;

    /**
     * @section DiagonalOperations Operacje na przekątnych
     */
    // Ustawianie przekątnej
    int diag[] = {1, 2, 3};
    m1.diagonalna(diag);
    std::cout << "Macierz m1 po ustawieniu diagonalnej:" << std::endl;
    std::cout << m1 << std::endl;

    // Ustawianie przesuniętej przekątnej
    m1.diagonalna_k(1, diag);
    std::cout << "Macierz m1 po ustawieniu diagonalnej przesuniętej o 1:" << std::endl;
    std::cout << m1 << std::endl;

    /**
     * @section RowColumnOperations Operacje na wierszach i kolumnach
     */
    // Ustawianie kolumny
    int kol[] = {4, 5, 6};
    m1.kolumna(1, kol);
    std::cout << "Macierz m1 po ustawieniu kolumny 1:" << std::endl;
    std::cout << m1 << std::endl;

    // Ustawianie wiersza
    int wiersz[] = {7, 8, 9};
    m1.wiersz(2, wiersz);
    std::cout << "Macierz m1 po ustawieniu wiersza 2:" << std::endl;
    std::cout << m1 << std::endl;

    /**
     * @section SpecialPatterns Wzory specjalne w macierzy
     */
    // Macierz jednostkowa
    m1.przekatna();
    std::cout << "Macierz m1 po ustawieniu jako macierz jednostkowa:" << std::endl;
    std::cout << m1 << std::endl;

    // Elementy poniżej przekątnej na 1
    m1.pod_przekatna();
    std::cout << "Macierz m1 po ustawieniu elementów poniżej przekątnej na 1:" << std::endl;
    std::cout << m1 << std::endl;

    // Elementy powyżej przekątnej na 1
    m1.nad_przekatna();
    std::cout << "Macierz m1 po ustawieniu elementów powyżej przekątnej na 1:" << std::endl;
    std::cout << m1 << std::endl;

    // Wzór szachownicy
    m1.szachownica();
    std::cout << "Macierz m1 po ustawieniu wzoru szachownicy:" << std::endl;
    std::cout << m1 << std::endl;

    /**
     * @section IncrementDecrement Testowanie inkrementacji i dekrementacji
     */
    // Postinkrementacja
    m1++;
    std::cout << "Macierz m1 po postinkrementacji:" << std::endl;
    std::cout << m1 << std::endl;

    // Postdekrementacja
    m1--;
    std::cout << "Macierz m1 po postdekrementacji:" << std::endl;
    std::cout << m1 << std::endl;

    return 0;
}
