#include "Matrix.hpp"
#include <iostream>
using namespace std;

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

Matrix& Matrix::nad_przekatna(void) {
    // Sprawdzenie, czy macierz została zainicjalizowana.
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    // Przejście przez wszystkie elementy macierzy.
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // Ustawienie 1 powyżej przekątnej (i < j), pozostałe elementy to 0.
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
    // Sprawdzenie, czy macierz została zainicjalizowana.
    if (!data) {
        cerr << "Pamięć dla macierzy nie została zaalokowana. Najpierw zaalokuj pamięć." << endl;
        return *this;
    }

    // Przejście przez wszystkie elementy macierzy.
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // Naprzemiennie ustawiamy 0 i 1, zależnie od parzystości indeksów i + j.
            if ((i + j) % 2 == 0) {
                data[i * size + j] = 0;
            } else {
                data[i * size + j] = 1;
            }
        }
    }

    return *this;
}

// Poprawiona implementacja operatora + dla macierzy
Matrix& Matrix::operator+(Matrix& m) {
    // Sprawdzenie, czy obie macierze mają ten sam rozmiar.
    if (size != m.size) {
        cerr << "Macierze mają różne rozmiary, nie można ich dodać." << endl;
        return *this;
    }

    // Tworzymy nową macierz, która będzie wynikiem dodawania.
    Matrix result(size);

    // Dodawanie odpowiadających sobie elementów macierzy.
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i * size + j] = data[i * size + j] + m.data[i * size + j];
        }
    }

    // Zwracamy wynikową macierz (nie modyfikujemy bieżącej, ponieważ operator powinien zwrócić nową).
    return result;
}

// Poprawiona implementacja operatora * dla macierzy
Matrix& Matrix::operator*(Matrix& m) {
    // Sprawdzenie, czy obie macierze mają ten sam rozmiar.
    if (size != m.size) {
        cerr << "Macierze mają różne rozmiary, nie można ich pomnożyć." << endl;
        return *this;
    }

    // Tworzymy nową macierz, która będzie wynikiem mnożenia.
    Matrix result(size);

    // Mnożenie macierzy A (this) i B (m)
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i * size + j] = 0; // Inicjalizujemy element na 0

            // Obliczenie wartości elementu wynikowej macierzy
            for (int k = 0; k < size; ++k) {
                result.data[i * size + j] += data[i * size + k] * m.data[k * size + j];
            }
        }
    }

    // Zwracamy wynikową macierz (nie modyfikujemy bieżącej, ponieważ operator powinien zwrócić nową).
    return result;
}

// Wstawienie wartości w określoną pozycję
Matrix& Matrix::wstaw(int x, int y, int wartosc) {
    // Sprawdzamy, czy indeksy x i y mieszczą się w rozmiarze macierzy
    if (x < 0 || x >= size || y < 0 || y >= size) {
        cout << "Indeksy poza zakresem macierzy." << endl;
        return *this;
    }

    // Wstawiamy wartość do odpowiedniej pozycji
    data[x * size + y] = wartosc;

    cout << "Wartość " << wartosc << " została wstawiona do macierzy na pozycji ("
         << x << ", " << y << ")." << endl;

    return *this;
}

// Poprawiona implementacja metody alokacji
Matrix& Matrix::alokuj(int n) {
    // Sprawdzamy, czy rozmiar n jest większy od zera
    if (n <= 0) {
        cout << "Rozmiar macierzy musi być większy od zera." << endl;
        return *this;
    }

    // Jeśli rozmiar macierzy nie zmienia się, nie alokujemy ponownie pamięci
    if (data != nullptr && n == size) {
        return *this;
    }

    // Jeśli macierz ma już zaalokowaną pamięć
    if (data != nullptr) {
        delete[] data;
    }

    // Alokujemy pamięć dla macierzy n x n
    size = n;
    data = new int[size * size]; // Alokacja pamięci

    // Inicjalizacja macierzy zerami
    for (int i = 0; i < size * size; ++i) {
        data[i] = 0; // Inicjalizujemy każdy element na 0
    }

    cout << "Pamięć dla macierzy o wymiarach " << size << " x " << size << " została pomyślnie zaalokowana." << endl;

    return *this;
}
