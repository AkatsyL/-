#include <iostream>

using namespace std;

int main()
{
    const int n{ 5 };

    float a[n][n]{
        { 3, 2, 2, 9, 1 },
        { 8, 7, 6, 7, 4 },
        { 3, 2, 5, 8, 7 },
        { 7, 5, 2, 9, 2 },
        { 9, 7, 2, 3, 3 } };

    float l[n][n]{};
    float u[n][n]{};
    float x[n][n]{ {}, {}, {}, {}, {} };
    float y[n][n]{};
    float a_inv[n][n]{};

    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
            i == j ? u[i][j] = 1 : u[i][j] = 0;
        }
    }

    for (int i{}; i < n; i++) {
        l[i][0] = a[i][0];
    }

    for (int j{ 1 }; j < n; j++) {
        u[0][j] = a[0][j] / l[0][0];
    }

    for (int k{ 1 }; k < n; k++) {
        for (int i{ k }; i < n; i++) {
            l[i][k] = a[i][k];
            for (int m{}; m < k; m++) {
                l[i][k] -= l[i][m] * u[m][k];
            }
        }
        if (k <= n - 2) {
            for (int j{ k + 1 }; j < n; j++) {
                u[k][j] = a[k][j];
                for (int m{}; m < k; m++) {
                    u[k][j] -= l[k][m] * u[m][j];
                }
                u[k][j] /= l[k][k];
            }
        }
    }

    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
            cout << l[i][j] << "         \t";
        }
        cout << "\n";
    }
    cout << "\n";

    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
            cout << u[i][j] << "         \t";
        }
        cout << "\n";
    }
    cout << "\n";

    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
            if (j > i) {
                y[i][j] = 0;
            }
            else if (j == i) {
                y[i][j] = 1 / l[i][i];
            }
            else if (j < i) {
                y[i][j] = 0;
                for (int m{ j }; m < i; m++) {
                    y[i][j] -= l[i][m] * y[m][j];
                }
                y[i][j] /= l[i][i];
            }
        }
    }

    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
            cout << y[i][j] << "         \t";
        }
        cout << "\n";
    }
    cout << "\n";

    for (int i{ n - 1 }; i >= 0; i--) {
        for (int j{ n - 1 }; j >= 0; j--) {
            if (j < i) {
                x[i][j] = 0;
            }
            else if (j == i) {
                x[i][j] = 1;
            }
            else if (j > i) {
                x[i][j] = 0;
                for (int m{ i + 1 }; m <= j; m++) {
                    x[i][j] -= u[i][m] * x[m][j];
                }
            }
        }
    }

    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
            cout << x[i][j] << "         \t";
        }
        cout << "\n";
    }
    cout << "\n";

    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
            a_inv[i][j] = 0;
            for (int m{}; m < n; m++) {
                a_inv[i][j] += x[i][m] * y[m][j];
            }
        }
    }

    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
            cout << a_inv[i][j] << "         \t";
        }
        cout << "\n";
    }
    cout << "\n";
}
