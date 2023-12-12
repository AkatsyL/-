// метод жордан - Гаусс

#include <iostream>

using namespace std;

int main() {
	const int n = 5, m = n + 1;

	float** matrix;
	matrix = new float* [n];

	for (int i = 0; i < n; i++) {
		matrix[i] = new float[m];
	}

	cout << "Input elements of matrix:\n";
	for (unsigned i = 0; i < n; i++)
	{
		cout << "Row " << i << " :";
		for (unsigned j = 0; j < m; j++)
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

		for (int i = 0; i < n; i++) {
			for (int j = k + 1; j <= n; j++) {
				if (i != k) matrix[i][j] = (matrix[i][j] * matrix[k][k] - matrix[k][j] * matrix[i][k]) / matrix[k][k];
			}
		}

		for (int i = 0; i < n; i++) {
			if (i != k) matrix[i][k] = 0;
		}

		for (int j = m - 1; j != k - 1; j--)
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

	// Вывод
	for (int i = 0; i < n; i++) {
		cout << matrix[i][m - 1] << "\t";
	}

	for (int i = 0; i < n; i++)
		delete[] matrix[i];

	delete[] matrix;
}
