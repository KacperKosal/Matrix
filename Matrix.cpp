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

/**
 * @brief Destruktor klasy Matrix.
 *
 * Zwolnia pamięć zaalokowaną dla danych macierzy.
 * Zapewnia, że zasoby są poprawnie zwolnione, aby uniknąć wycieków pamięci.
 */
Matrix::~Matrix() {
    // Sprawdzamy, czy pamięć została wcześniej zaalokowana
    if (data != nullptr) {
        delete[] data; // Zwalniamy pamięć
        data = nullptr; // Ustawiamy wskaźnik na nullptr po zwolnieniu pamięci
    }

    cout << "Destruktor wywołany. Pamięć macierzy została zwolniona." << endl;
}

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

Matrix& Matrix::wiersz(int y, int* t) {
    // Sprawdzenie, czy macierz została zainicjalizowana.
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    // Sprawdzenie, czy indeks wiersza jest w zakresie.
    if (y < 0 || y >= size) {
        cerr << "Indeks wiersza poza zakresem. Wartość y powinna być w przedziale od 0 do " << size - 1 << "." << endl;
        return *this;
    }

    // Przepisanie danych z tabeli do wskazanego wiersza.
    for (int i = 0; i < size; ++i) {
        data[y * size + i] = t[i];
    }

    return *this;
}

Matrix& Matrix::przekatna(void) {
    // Sprawdzenie, czy macierz została zainicjalizowana.
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    // Przejście przez wszystkie elementy macierzy i ustawienie wartości.
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // Ustawienie 1 na przekątnej (i == j) i 0 w innych miejscach.
            if (i == j) {
                data[i * size + j] = 1;
            } else {
                data[i * size + j] = 0;
            }
        }
    }

    return *this;
}

Matrix& Matrix::pod_przekatna(void) {
    // Sprawdzenie, czy macierz została zainicjalizowana.
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    // Przejście przez wszystkie elementy macierzy.
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // Ustawienie 1 poniżej przekątnej (i > j), pozostałe elementy to 0.
            if (i > j) {
                data[i * size + j] = 1;
            } else {
                data[i * size + j] = 0;
            }
        }
    }

    return *this;
}
