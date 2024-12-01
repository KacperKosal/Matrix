#include "Matrix.hpp"

/**
 * @brief Domyślny konstruktor klasy Matrix.
 *
 * Ustawia wskaźnik danych na nullptr i rozmiar macierzy na 0.
 * Nie alokuje pamięci dla macierzy.
 */
Matrix::Matrix() : data(nullptr), size(0) {
    cout << "Domyślny konstruktor wywołany. Macierz nie została zaalokowana." << endl;
}
/**
 * @brief Konstruktor alokujący macierz o wymiarach n x n.
 *
 * Tworzy macierz kwadratową i alokuje pamięć dla jej elementów.
 * Wszystkie elementy są inicjalizowane wartością 0.
 *
 * @param n Rozmiar macierzy (liczba wierszy i kolumn).
 */
Matrix::Matrix(int n) : data(nullptr), size(0) {
    if (n <= 0) {
        cout << "Rozmiar macierzy musi być większy od zera. Macierz nie została zaalokowana." << endl;
        return;
    }

    size = n;
    data = new int[size * size];
    for (int i = 0; i < size * size; ++i) {
        data[i] = 0; // Inicjalizacja elementów macierzy zerami
    }

    cout << "Konstruktor alokujący wywołany. Macierz o rozmiarze "
         << size << " x " << size << " została zaalokowana." << endl;
}
