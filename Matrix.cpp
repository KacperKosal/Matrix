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
