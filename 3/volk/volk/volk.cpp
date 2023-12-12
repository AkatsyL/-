// Проходка

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;

int main() {
    srand(time(0));
    setlocale(LC_ALL, "rus");


    const int n = 3;
    vector<vector<int>> m(n, vector<int>(n + 1, 0));

    //создание матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            if (abs(j - i) <= 1 || j == n) {
                m[i][j] = rand() % 11;
            }
        }
    }

    cout << "Матрица системы  m = " << endl;;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }

    //Вектор свободных коэффициентов
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        f[i] = m[i][n];
    }

    cout << "Вектор свободных коэффициентов f = ";
    for (int i = 0; i < n; i++) {
        cout << f[i] << "\t";
    }
    cout << endl;

    //Вектор диагональных коэффициентов
    vector<int> c(n);
    for (int k = 0; k < n; k++) {
        c[k] = m[k][k];
    }

    cout << "Вектор диагональных коэффициентов c = ";
    for (int k = 0; k < n; k++) {
        cout << c[k] << "\t";
    }
    cout << endl;

    //Вектор леводиагональных коэффициентов
    vector<int> l(n + 1);
    l[0] = 0;
    for (int k = 1; k < n; k++) {
        l[k] = m[k][k - 1];
    }

    cout << "Вектор леводиагональных коэффициентов l = ";
    for (int k = 0; k <= n; k++) {
        cout << l[k] << "\t";
    }
    cout << endl;

    //Вектор праводиагональных коэффициентов
    vector<int> r(n + 1);
    for (int k = 0; k < n - 1; k++) {
        r[k] = m[k][k + 1];
    }

    r[n] = 0;
    cout << "Вектор праводиагональных коэффициентов r = ";
    for (int k = 0; k <= n; k++) {
        cout << r[k] << "\t";
    }
    cout << endl;

    vector<double> p(n, 0.0);
    vector<double> q(n, 0.0);
    vector<double> x(n, 0.0);

    //Прямой ход
    p[0] = (double)f[0] / c[0];
    q[0] = (double)r[0] / c[0];
    for (int k = 1; k < n; k++) {
        p[k] = ((double)f[k] - l[k] * p[k - 1]) / (c[k] - l[k] * q[k - 1]);
        if (k < n - 1) {
            q[k] = (double)r[k] / (c[k] - l[k] * q[k - 1]);
        }
    }

    //Обратный ход
    x[n - 1] = p[n - 1];
    for (int k = n - 2; k >= 0; k--) {
        x[k] = p[k] - q[k] * x[k + 1];
    }

    //Вывод результата
    cout << "Вектор решения системы x = ";
    for (int k = 0; k < n; k++) {
        cout << x[k] << " ";
    }
    cout << endl;

    return 0;
}
