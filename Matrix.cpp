#include "Matrix.hpp"

Matrix& Matrix::diagonalna(int* t) {
    // Sprawdzenie, czy macierz została zainicjalizowana.
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    // Iteracja po wszystkich elementach macierzy.
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                // Elementy na przekątnej ustawiamy na wartości z tablicy t.
                data[i * size + j] = t[i];
            } else {
                // Pozostałe elementy ustawiamy na 0.
                data[i * size + j] = 0;
            }
        }
    }

    return *this;
}
