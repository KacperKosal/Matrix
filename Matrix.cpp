#include "Matrix.hpp"
#include <iostream>
using namespace std;

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
