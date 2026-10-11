//-0.8 0.8 0.4 0.00001
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert> // 1. Додаємо бібліотеку для assert

using namespace std;

// Функція для обчислення додатка a_n через коефіцієнт R
double A(const double x, const int n, double a) {
    double R = -(x * x * (2 * n - 1)) / (2 * n + 1);
    a *= R;
    return a;
}

// Функція для обчислення суми ряду Тейлора
double S(const double x, const double eps, int& n, double s) {
    n = 0;
    double a = x; // Перший доданок при n = 0
    s = a;
    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    return s;
}

// 2. Окрема функція Unit-тесту
void testS() {
    int n = 0;
    double s = 0;
    double eps = 0.00001;

    // Перевірка: atan(0) має дорівнювати 0
    assert(abs(S(0.0, eps, n, s) - 0.0) < eps);

    // Перевірка: atan(0.5) має бути близьким до значення з cmath
    assert(abs(S(0.5, eps, n, s) - atan(0.5)) < eps);
}

int main() {
    // 3. Запуск Unit-тесту перед основною програмою
    testS();

    double xp, xk, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(10) << "atan(x)" << " |"
        << setw(10) << "S" << " |"
        << setw(5) << "n" << " |" << endl;
    cout << "-------------------------------------------------" << endl;

    double x = xp;
    while (x <= xk) {
        s = S(x, eps, n, s);

        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << atan(x) << " |"
            << setw(10) << setprecision(5) << s << " |"
            << setw(5) << n << " |" << endl;

        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}