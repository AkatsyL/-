//метод гауса 
#include <iostream>

using namespace std;


int main() {

    const int n = 5, m = n + 1;

    float* x = new float[m];

    float** matrix;

    matrix = new float* [n];

    for (int i = 0; i < n; i++) {
        matrix[i] = new float[m];
    }

    cout << "Input elements of matrix:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Row " << i << " :";
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
        cout << endl;
    }

    // Прямой ход
    for (int k = 0; k < n; k++) {
        if (abs(matrix[k][k]) < 0.000001) {
            int c = k++;
            while (abs(matrix[c][k]) < 0.000001);
            for (int i = 0; i < n; i++) {
                float tmp = matrix[k][i];
                matrix[k][i] = matrix[m - 1][i];
                matrix[m - 1][i] = tmp;
            }
        }

        for (int i = k + 1; i < n; i++) {
            for (int j = k + 1; j <= n; j++) {
                matrix[i][j] = (matrix[i][j] * matrix[k][k] - matrix[k][j] * matrix[i][k]) / matrix[k][k];
            }
        }

        for (int i = k + 1; i < n; i++) {
            matrix[i][k] = 0;
        }
        for (int j = n; j != k - 1; j--)
        {
            matrix[k][j] = matrix[k][j] / matrix[k][k];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Обратный ход
    for (int k = n - 1; k >= 0; k--) {
        if (k == n - 1) {
            x[k] = matrix[k][n];
        }
        else {
            x[k] = matrix[k][n];
            for (int i = k + 1; i < n; i++) {
                x[k] -= x[i] * matrix[k][i];
            }
        }
    }
    // Вывод
    for (int i = 0; i < m - 1; i++) {
        cout << x[i] << "\t";
    }

    delete[] x;
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}

