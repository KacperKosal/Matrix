#include <iostream>
using namespace std;

/**
 * @class Matrix
 * @brief Klasa reprezentująca macierz kwadratową z różnymi operacjami matematycznymi.
 */
class Matrix {
public:
  /**
   * @brief Konstruktor domyślny bez alokacji pamięci.
   */
  Matrix(void);

  /**
   * @brief Konstruktor alokujący macierz o wymiarach n x n.
   * @param n Rozmiar macierzy.
   */
  Matrix(int n);

  /**
   * @brief Konstruktor alokujący macierz i kopiujący dane z tabeli.
   * @param n Rozmiar macierzy.
   * @param t Wskaźnik na tabelę z danymi.
   */
  Matrix(int n, int* t);

  /**
   * @brief Konstruktor kopiujący.
   * @param m Referencja do kopiowanej macierzy.
   */
  Matrix(Matrix& m);

  /**
   * @brief Destruktor zwalniający pamięć.
   */
  ~Matrix(void);

  /**
   * @brief Alokuje pamięć dla macierzy o wymiarach n x n.
   * @param n Rozmiar macierzy.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& alokuj(int n);

  /**
   * @brief Wstawia wartość do macierzy na określonej pozycji.
   * @param x Wiersz.
   * @param y Kolumna.
   * @param wartosc Wstawiana wartość.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& wstaw(int x, int y, int wartosc);

  /**
   * @brief Zwraca wartość elementu macierzy na pozycji (x, y).
   * @param x Wiersz.
   * @param y Kolumna.
   * @return Wartość elementu.
   */
  int pokaz(int x, int y);

  /**
   * @brief Transponuje macierz (zamienia wiersze z kolumnami).
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& dowroc(void);

  /**
   * @brief Wypełnia macierz losowymi liczbami od 0 do 9.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& losuj(void);

  /**
   * @brief Wypełnia część macierzy losowymi liczbami od 0 do 9.
   * @param x Liczba losowanych elementów.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& losuj(int x);

  /**
   * @brief Tworzy macierz diagonalną z danymi z tabeli.
   * @param t Wskaźnik na tabelę z danymi.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& diagonalna(int* t);

  /**
   * @brief Tworzy macierz diagonalną z przesuniętą przekątną.
   * @param k Wartość przesunięcia przekątnej.
   * @param t Wskaźnik na tabelę z danymi.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& diagonalna_k(int k, int* t);

  /**
   * @brief Wypełnia wskazaną kolumnę danymi z tabeli.
   * @param x Numer kolumny.
   * @param t Wskaźnik na tabelę z danymi.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& kolumna(int x, int* t);

  /**
   * @brief Wypełnia wskazany wiersz danymi z tabeli.
   * @param y Numer wiersza.
   * @param t Wskaźnik na tabelę z danymi.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& wiersz(int y, int* t);

  /**
   * @brief Tworzy macierz jednostkową.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& przekatna(void);

  /**
   * @brief Wypełnia macierz 1 poniżej przekątnej, 0 w innych miejscach.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& pod_przekatna(void);

  /**
   * @brief Wypełnia macierz 1 powyżej przekątnej, 0 w innych miejscach.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& nad_przekatna(void);

  /**
   * @brief Wypełnia macierz wzorem szachownicy.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& szachownica(void);

  /**
   * @brief Dodaje dwie macierze.
   * @param m Macierz do dodania.
   * @return Wynikowa macierz.
   */
  Matrix& operator+(Matrix& m);

  /**
   * @brief Mnoży dwie macierze.
   * @param m Macierz do mnożenia.
   * @return Wynikowa macierz.
   */
  Matrix& operator*(Matrix& m);

  /**
   * @brief Dodaje do macierzy skalar.
   * @param a Skalar do dodania.
   * @return Wynikowa macierz.
   */
  Matrix& operator+(int a);

  /**
   * @brief Mnoży macierz przez skalar.
   * @param a Skalar do mnożenia.
   * @return Wynikowa macierz.
   */
  Matrix& operator*(int a);

  /**
   * @brief Zmniejsza macierz o skalar.
   * @param a Skalar do odjęcia.
   * @return Wynikowa macierz.
   */
  Matrix& operator-(int a);

    /**
   * @brief Dodaje skalar do macierzy (skalar + macierz).
   * @param scalar Skalar do dodania.
   * @param matrix Macierz, do której dodawany jest skalar.
   * @return Wynikowa macierz.
   */
  friend Matrix operator+(int scalar, const Matrix& matrix);

  /**
   * @brief Mnoży skalar przez macierz (skalar * macierz).
   * @param scalar Skalar do mnożenia.
   * @param matrix Macierz, którą mnożymy.
   * @return Wynikowa macierz.
   */
  friend Matrix& operator*(int scalar, const Matrix& matrix);

  /**
   * @brief Odejmuje macierz od skalaru (skalar - macierz).
   * @param scalar Skalar, od którego odejmowana jest macierz.
   * @param matrix Macierz do odjęcia.
   * @return Wynikowa macierz.
   */
  friend Matrix& operator-(int scalar, const Matrix& matrix);

  /**
   * @brief Inkrementuje każdy element macierzy o 1 (postinkrementacja).
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& operator++(int);

  /**
   * @brief Dekrementuje każdy element macierzy o 1 (postdekrementacja).
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& operator--(int);

  /**
   * @brief Dodaje do każdego elementu macierzy wartość a.
   * @param a Wartość do dodania.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& operator+=(int a);

  /**
   * @brief Odejmuje od każdego elementu macierzy wartość a.
   * @param a Wartość do odjęcia.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& operator-=(int a);

  /**
   * @brief Mnoży każdy element macierzy przez wartość a.
   * @param a Wartość do mnożenia.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& operator*=(int a);

  /**
   * @brief Dodaje część całkowitą liczby zmiennoprzecinkowej do każdego elementu macierzy.
   * @param x Liczba zmiennoprzecinkowa.
   * @return Referencja do bieżącego obiektu.
   */
  Matrix& operator+=(double x);

  /**
   * @brief Wyświetla macierz na strumieniu wyjściowym.
   * @param os Strumień wyjściowy.
   * @param matrix Macierz do wyświetlenia.
   * @return Strumień wyjściowy.
   */
  friend ostream& operator<<(ostream& os, const Matrix& matrix);

  /**
   * @brief Sprawdza, czy dwie macierze są równe.
   * @param m Macierz do porównania.
   * @return true, jeśli macierze są równe, false w przeciwnym razie.
   */
  bool operator==(const Matrix& m);

  /**
   * @brief Sprawdza, czy wszystkie elementy macierzy są większe od odpowiadających elementów innej macierzy.
   * @param m Macierz do porównania.
   * @return true, jeśli warunek jest spełniony, false w przeciwnym razie.
   */
  bool operator>(const Matrix& m);

  /**
   * @brief Sprawdza, czy wszystkie elementy macierzy są mniejsze od odpowiadających elementów innej macierzy.
   * @param m Macierz do porównania.
   * @return true, jeśli warunek jest spełniony, false w przeciwnym razie.
   */
  bool operator<(const Matrix& m);

private:
  int *data; /**< Wskaźnik na dane macierzy. */
  int size;  /**< Rozmiar macierzy. */
};
