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

/**
 * @brief Ustawia macierz diagonalną na podstawie podanego wektora.
 * 
 * @param t Tablica wartości, które mają znaleźć się na przekątnej macierzy.
 * @return Zwraca referencję do obiektu macierzy.
 */

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


/**
 * @brief Ustawia macierz diagonalną przesuniętą o k pozycji względem głównej przekątnej.
 * 
 * @param k Przesunięcie przekątnej względem głównej przekątnej.
 * @param t Tablica wartości do ustawienia na przesuniętej przekątnej.
 * @return Zwraca referencję do obiektu macierzy.
 */
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

/**
 * @brief Wstawia wartości do kolumny macierzy.
 * 
 * @param x Indeks kolumny do wypełnienia.
 * @param t Tablica wartości do wstawienia w kolumnie.
 * @return Zwraca referencję do obiektu macierzy.
 */

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

/**
 * @brief Wstawia wartości do wiersza macierzy.
 * 
 * @param y Indeks wiersza do wypełnienia.
 * @param t Tablica wartości do wstawienia w wierszu.
 * @return Zwraca referencję do obiektu macierzy.
 */

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

/**
 * @brief Ustawia macierz jako macierz jednostkową.
 * 
 * @return Zwraca referencję do obiektu macierzy.
 */

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

/**
 * @brief Ustawia elementy poniżej głównej przekątnej na 1, a pozostałe na 0.
 * 
 * @return Zwraca referencję do obiektu macierzy.
 */

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

/**
 * @brief Ustawia elementy powyżej głównej przekątnej na 1, a pozostałe na 0.
 * 
 * @return Zwraca referencję do obiektu macierzy.
 */

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

/**
 * @brief Ustawia wzór szachownicy na macierzy, gdzie 0 i 1 pojawiają się naprzemiennie.
 * 
 * @return Zwraca referencję do obiektu macierzy.
 */

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

/**
 * @brief Operator dodawania macierzy.
 * 
 * Dodaje dwie macierze element po elemencie.
 * 
 * @param m Macierz, którą chcemy dodać.
 * @return Zwraca nową macierz będącą wynikiem dodawania.
 */

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

/**
 * @brief Operator mnożenia macierzy.
 * 
 * Mnoży dwie macierze zgodnie z zasadami algebry macierzy.
 * 
 * @param m Macierz, przez którą chcemy pomnożyć.
 * @return Zwraca nową macierz będącą wynikiem mnożenia.
 */

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

/**
 * @brief Wstawia wartość do macierzy w określonej pozycji.
 * 
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @param wartosc Wartość do wstawienia.
 */

void Matrix::wstaw(int x, int y, int wartosc) {
    if (x < 0 || x >= size || y < 0 || y >= size) {
        cerr << "Indeksy poza zakresem. Indeksy muszą być w zakresie od 0 do " << size - 1 << "." << endl;
        return;
    }
    data[x * size + y] = wartosc;
}

/**
 * @brief Alokuje pamięć dla macierzy o określonym rozmiarze.
 * 
 * @param n Rozmiar macierzy (n x n).
 */

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

/**
 * @brief Pobiera wartość z macierzy w określonej pozycji.
 * 
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @return Zwraca wartość w macierzy na pozycji (x, y). Zwraca -1 w przypadku błędu.
 */

int Matrix::pokaz(int x, int y) {
    if (x < 0 || x >= size || y < 0 || y >= size) {
        cerr << "Indeksy poza zakresem." << endl;
        return -1;
    }
    return data[x * size + y];
}

/**
 * @brief Operator dodawania skalaru do macierzy.
 * 
 * Dodaje skalar do każdego elementu macierzy.
 * 
 * @param a Wartość skalara.
 * @return Zwraca referencję do zmodyfikowanej macierzy.
 */

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

/**
 * @brief Operator mnożenia macierzy przez skalar.
 * 
 * Mnoży każdy element macierzy przez skalar.
 * 
 * @param a Wartość skalara.
 * @return Zwraca referencję do zmodyfikowanej macierzy.
 */

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

/**
 * @brief Operator odejmowania skalara od macierzy.
 * 
 * Odejmuje skalar od każdego elementu macierzy.
 * 
 * @param a Wartość skalara.
 * @return Zwraca referencję do zmodyfikowanej macierzy.
 */

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

/**
 * @brief Transponuje macierz.
 * 
 * Zamienia wiersze z kolumnami macierzy.
 * 
 * @return Zwraca nową macierz będącą transpozycją macierzy oryginalnej.
 */

Matrix& Matrix::dowroc(void) {
    Matrix temp(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp.data[j * size + i] = data[i * size + j];
        }
    }

    return temp;
}

/**
 * @brief Operator odejmowania macierzy.
 * 
 * Odejmuje dwie macierze element po elemencie.
 * 
 * @param m Macierz, którą chcemy odjąć.
 * @return Zwraca nową macierz będącą wynikiem odejmowania.
 */

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

/**
 * @brief Operator przypisania.
 * 
 * Kopiuje wartości z jednej macierzy do drugiej.
 * 
 * @param m Macierz, której wartości chcemy przypisać.
 * @return Zwraca referencję do zmodyfikowanej macierzy.
 */

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

/**
 * @brief Operator dekrementacji postfiksowej dla macierzy.
 * 
 * Zmniejsza każdy element macierzy o 1.
 * 
 * @return Zwraca referencję do zmodyfikowanej macierzy.
 */

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

/**
 * @brief Operator strumieniowego wypisywania macierzy.
 * 
 * Wypisuje zawartość macierzy w formacie tekstowym.
 * 
 * @param os Strumień wyjściowy (np. std::cout).
 * @param m Macierz do wypisania.
 * @return Zwraca referencję do strumienia wyjściowego.
 */

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

/**
 * @brief Operator porównania równości macierzy.
 * 
 * Sprawdza, czy dwie macierze są równe element po elemencie.
 * 
 * @param m Macierz, z którą porównujemy.
 * @return Zwraca true, jeśli macierze są równe, w przeciwnym razie false.
 */

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

/**
 * @brief Operator porównania nierówności macierzy.
 * 
 * Sprawdza, czy dwie macierze są różne.
 * 
 * @param m Macierz, z którą porównujemy.
 * @return Zwraca true, jeśli macierze są różne, w przeciwnym razie false.
 */


bool Matrix::operator!=(const Matrix& m) {
    return !(*this == m);
}

/**
 * @brief Operator porównania "większości" macierzy.
 * 
 * Sprawdza, czy wszystkie elementy macierzy są większe od odpowiadających elementów drugiej macierzy.
 * 
 * @param m Macierz, z którą porównujemy.
 * @return Zwraca true, jeśli każda wartość w tej macierzy jest większa, w przeciwnym razie false.
 */

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

/**
 * @brief Operator porównania "mniejszości" macierzy.
 * 
 * Sprawdza, czy wszystkie elementy macierzy są mniejsze od odpowiadających elementów drugiej macierzy.
 * 
 * @param m Macierz, z którą porównujemy.
 * @return Zwraca true, jeśli każda wartość w tej macierzy jest mniejsza, w przeciwnym razie false.
 */

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