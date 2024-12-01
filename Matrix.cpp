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
/**
 * @brief Konstruktor alokujący macierz o wymiarach n x n i kopiujący dane z tabeli.
 *
 * Tworzy macierz kwadratową, alokuje pamięć i wypełnia ją wartościami z dostarczonej tablicy.
 *
 * @param n Rozmiar macierzy (liczba wierszy i kolumn).
 * @param t Wskaźnik na tablicę danych, która zawiera wartości do skopiowania.
 *          Tablica powinna zawierać co najmniej n * n elementów.
 */
Matrix::Matrix(int n, int* t) : data(nullptr), size(0) {
    if (n <= 0) {
        cout << "Rozmiar macierzy musi być większy od zera. Macierz nie została zaalokowana." << endl;
        return;
    }

    if (t == nullptr) {
        cout << "Podana tablica danych jest pusta. Macierz nie została zaalokowana." << endl;
        return;
    }

    size = n;
    data = new int[size * size];
    for (int i = 0; i < size * size; ++i) {
        data[i] = t[i]; // Kopiowanie danych z tablicy t
    }

    cout << "Konstruktor kopiujący wywołany. Macierz o rozmiarze "
         << size << " x " << size << " została zaalokowana i wypełniona danymi." << endl;
}
/**
 * @brief Konstruktor kopiujący klasy Matrix.
 *
 * Tworzy nową macierz, która jest kopią innej macierzy.
 * Alokuje pamięć dla nowej macierzy i kopiuje wartości z macierzy źródłowej.
 *
 * @param m Macierz, która ma zostać skopiowana.
 */
Matrix::Matrix(Matrix& m) : data(nullptr), size(0) {
    // Kopiowanie rozmiaru macierzy
    size = m.size;

    // Alokacja pamięci dla nowej macierzy
    data = new int[size * size];

    // Kopiowanie danych z macierzy źródłowej
    for (int i = 0; i < size * size; ++i) {
        data[i] = m.data[i]; // Kopiowanie każdego elementu z m
    }

    cout << "Konstruktor kopiujący wywołany. Macierz została skopiowana." << endl;
}
