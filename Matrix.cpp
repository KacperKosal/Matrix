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

Matrix& Matrix::diagonalna_k(int k, int* t) {
    // Sprawdzenie, czy macierz została zainicjalizowana.
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    // Wypełniamy całą macierz zerami.
    for (int i = 0; i < size * size; ++i) {
        data[i] = 0;
    }

    // Ustawianie wartości na przesuniętej przekątnej.
    for (int i = 0; i < size; ++i) {
        int j = i + k; // Kolumna obliczana na podstawie przesunięcia.

        // Sprawdzenie, czy indeks kolumny mieści się w zakresie macierzy.
        if (j >= 0 && j < size) {
            data[i * size + j] = t[i]; // Wpisanie wartości z tabeli.
        }
    }

    return *this;
}

Matrix& Matrix::kolumna(int x, int* t) {
    // Sprawdzenie, czy macierz została zainicjalizowana.
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    // Sprawdzenie, czy indeks kolumny jest w zakresie.
    if (x < 0 || x >= size) {
        cerr << "Indeks kolumny poza zakresem. Wartość x powinna być w przedziale od 0 do " << size - 1 << "." << endl;
        return *this;
    }

    // Przepisanie danych z tabeli do wskazanej kolumny.
    for (int i = 0; i < size; ++i) {
        data[i * size + x] = t[i];
    }

    return *this;
}
