#include "Matrix.hpp"
#include <iostream>
#include <cstdlib>  // dla funkcji rand()
#include <ctime>    // dla funkcji time()
using namespace std;

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
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                data[i * size + j] = t[i];
            } else {
                data[i * size + j] = 0;
            }
        }
    }

    return *this;
}

Matrix& Matrix::diagonalna_k(int k, int* t) {
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    for (int i = 0; i < size * size; ++i) {
        data[i] = 0;
    }

    for (int i = 0; i < size; ++i) {
        int j = i + k;

        if (j >= 0 && j < size) {
            data[i * size + j] = t[i];
        }
    }

    return *this;
}

Matrix& Matrix::kolumna(int x, int* t) {
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    if (x < 0 || x >= size) {
        cerr << "Indeks kolumny poza zakresem. Wartość x powinna być w przedziale od 0 do " << size - 1 << "." << endl;
        return *this;
    }

    for (int i = 0; i < size; ++i) {
        data[i * size + x] = t[i];
    }

    return *this;
}

Matrix& Matrix::wiersz(int y, int* t) {
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    if (y < 0 || y >= size) {
        cerr << "Indeks wiersza poza zakresem. Wartość y powinna być w przedziale od 0 do " << size - 1 << "." << endl;
        return *this;
    }

    for (int i = 0; i < size; ++i) {
        data[y * size + i] = t[i];
    }

    return *this;
}

Matrix& Matrix::przekatna(void) {
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
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
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i > j) {
                data[i * size + j] = 1;
            } else {
                data[i * size + j] = 0;
            }
        }
    }

    return *this;
}

Matrix& Matrix::nad_przekatna(void) {
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i < j) {
                data[i * size + j] = 1;
            } else {
                data[i * size + j] = 0;
            }
        }
    }

    return *this;
}

Matrix& Matrix::szachownica(void) {
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((i + j) % 2 == 0) {
                data[i * size + j] = 0;
            } else {
                data[i * size + j] = 1;
            }
        }
    }

    return *this;
}

Matrix& Matrix::operator+(Matrix& m) {
    if (size != m.size) {
        cerr << "Macierze mają różne rozmiary, nie można ich dodać." << endl;
        return *this;
    }

    Matrix result(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i * size + j] = data[i * size + j] + m.data[i * size + j];
        }
    }

    return result;
}

Matrix& Matrix::operator*(Matrix& m) {
    if (size != m.size) {
        cerr << "Macierze mają różne rozmiary, nie można ich pomnożyć." << endl;
        return *this;
    }

    Matrix result(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i * size + j] = 0;
            for (int k = 0; k < size; ++k) {
                result.data[i * size + j] += data[i * size + k] * m.data[k * size + j];
            }
        }
    }

    return result;
}

void Matrix::wstaw(int x, int y, int wartosc) {
    if (x < 0 || x >= size || y < 0 || y >= size) {
        cerr << "Indeksy poza zakresem. Indeksy muszą być w zakresie od 0 do " << size - 1 << "." << endl;
        return;
    }
    data[x * size + y] = wartosc;
}

void Matrix::alokuj(int n) {
    if (data != nullptr) {
        cerr << "Pamięć dla macierzy już została zaalokowana." << endl;
        return;
    }
    size = n;
    data = new int[size * size]();
    if (data == nullptr) {
        cerr << "Nie udało się zaalokować pamięci." << endl;
        exit(1);
    }
}

int Matrix::pokaz(int x, int y) {
    if (x < 0 || x >= size || y < 0 || y >= size) {
        cerr << "Indeksy poza zakresem." << endl;
        return -1;
    }
    return data[x * size + y];
}

Matrix& Matrix::operator+(int a) {
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i * size + j] += a;
        }
    }

    return *this;
}

Matrix& Matrix::operator*(int a) {
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i * size + j] *= a;
        }
    }

    return *this;
}

Matrix& Matrix::operator-(int a) {
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i * size + j] -= a;
        }
    }

    return *this;
}

Matrix& Matrix::dowroc(void) {
    Matrix temp(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp.data[j * size + i] = data[i * size + j];
        }
    }

    return temp;
}

Matrix& Matrix::operator-(Matrix& m) {
    if (size != m.size) {
        cerr << "Macierze mają różne rozmiary, nie można ich odjąć." << endl;
        return *this;
    }

    Matrix result(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i * size + j] = data[i * size + j] - m.data[i * size + j];
        }
    }

    return result;
}

Matrix& Matrix::operator=(Matrix& m) {
    if (this == &m) {
        return *this;
    }

    if (data != nullptr) {
        delete[] data;
    }

    size = m.size;
    data = new int[size * size];
    if (data == nullptr) {
        cerr << "Nie udało się zaalokować pamięci." << endl;
        exit(1);
    }

    for (int i = 0; i < size * size; ++i) {
        data[i] = m.data[i];
    }

    return *this;
}


/**
 * @brief Wypełnia macierz losowymi liczbami od 0 do 9.
 *
 * Każdy element macierzy zostaje wypełniony losową liczbą z przedziału [0, 9].
 *
 * @return Referencja do bieżącego obiektu.
 */
Matrix& Matrix::losuj(void) {
    // Inicjalizacja generatora liczb losowych
    srand(time(0));  // Ustawiamy ziarno na podstawie bieżącego czasu

    // Wypełnianie macierzy losowymi liczbami od 0 do 9
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // Losowanie liczby z przedziału [0, 9]
            wstaw(i, j, rand() % 10);  // rand() % 10 zwraca liczby od 0 do 9
        }
    }

    return *this;
}
/**
 * @brief Wypełnia część macierzy losowymi liczbami od 0 do 9.
 *
 * Liczba losowanych elementów jest określona przez parametr `x`. Losowane liczby są w przedziale [0, 9],
 * a liczba elementów do losowania jest określona przez `x`.
 * Elementy są losowane w losowych pozycjach macierzy.
 *
 * @param x Liczba losowanych elementów.
 * @return Referencja do bieżącego obiektu.
 */
Matrix& Matrix::losuj(int x) {
    // Inicjalizacja generatora liczb losowych
    srand(time(0));  // Ustawiamy ziarno na podstawie bieżącego czasu

    // Liczba losowanych elementów
    int elementsToFill = x;

    while (elementsToFill > 0) {
        // Losowanie wiersza i kolumny
        int i = rand() % size;
        int j = rand() % size;

        // Sprawdzamy, czy na tej pozycji już jest liczba (żeby nie nadpisać istniejącego elementu)
        if (data[i * size + j] == 0) {
            // Losowanie liczby od 0 do 9 i wstawienie jej do odpowiedniej pozycji
            wstaw(i, j, rand() % 10);
            --elementsToFill;  // Zmniejszamy licznik pozostałych elementów do wypełnienia
        }
    }

    return *this;
}
/**
 * @brief Operator postinkrementacji macierzy.
 *
 * Operator umożliwia zwiększenie każdej wartości w macierzy o 1 (postinkrementacja).
 * Jeśli pamięć dla macierzy nie została zaalokowana, wypisywany jest komunikat o błędzie.
 *
 * @warning Jeśli pamięć dla macierzy nie została zaalokowana, funkcja zwróci obiekt macierzy w obecnym stanie.
 *
 * @return Referencja do zaktualizowanego obiektu macierzy.
 */
Matrix& Matrix::operator++(int) {
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    for (int i = 0; i < size * size; ++i) {
        ++data[i];
    }

    return *this;
}
Matrix& Matrix::operator--(int) {
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    for (int i = 0; i < size * size; ++i) {
        --data[i];
    }

    return *this;
}

ostream& operator<<(ostream& os, Matrix& m) {
    if (!m.data) {
        os << "Pamięć dla macierzy nie została zaalokowana." << endl;
        return os;
    }

    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            os << m.data[i * m.size + j] << " ";
        }
        os << endl;
    }
    return os;
}
bool Matrix::operator==(const Matrix& m) {
    if (size != m.size) {
        return false;
    }

    for (int i = 0; i < size * size; ++i) {
        if (data[i] != m.data[i]) {
            return false;
        }
    }

    return true;
}
bool Matrix::operator!=(const Matrix& m) {
    return !(*this == m);
}
bool Matrix::operator>(const Matrix& m) {
    if (size != m.size) {
        return false;
    }

    for (int i = 0; i < size * size; ++i) {
        if (data[i] <= m.data[i]) {
            return false;
        }
    }

    return true;
}
bool Matrix::operator<(const Matrix& m) {
    if (size != m.size) {
        return false;
    }

    for (int i = 0; i < size * size; ++i) {
        if (data[i] >= m.data[i]) {
            return false;
        }
    }

    return true;
}