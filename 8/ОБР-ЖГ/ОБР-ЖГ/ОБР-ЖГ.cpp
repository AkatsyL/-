#include <iostream>

using namespace std;

int main()
{
    const int n{ 5 };

    float a[n][n * 2]{
        { 3, 2, 2, 9, 1, 1, 0, 0, 0, 0 },
        { 8, 7, 6, 7, 4, 0, 1, 0, 0, 0 },
        { 3, 2, 5, 8, 7, 0, 0, 1, 0, 0 },
        { 7, 5, 2, 9, 2, 0, 0, 0, 1, 0 },
        { 9, 7, 2, 3, 3, 0, 0, 0, 0, 1 } };

    for (int k{}; k < n; k++) {
        for (int i{}; i < n; i++) {
            for (int j{ k + 1 }; j < n * 2; j++) {
                if (i != k) a[i][j] = (a[i][j] * a[k][k] - a[k][j] * a[i][k]) / a[k][k];
            }
        }

        for (int i{}; i < n; i++) {
            if (i != k) a[i][k] = 0;
        }

        for (int j{ 2 * n - 1 }; j >= k; j--) {
            a[k][j] /= a[k][k];
        }

        for (int i{}; i < n; i++) {
            for (int j{}; j < n * 2; j++) {
                cout << a[i][j] << "   " << "\t";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
