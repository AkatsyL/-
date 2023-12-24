#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	const int n{ 5 };

	float a[n][n]{
		{8, 7, 2, 3, 1},
	{7, 9, 3, 5, 3},
	{2, 3, 9 ,4, 1},
	{3 ,5, 4, 9, 2},
	{1, 3, 1, 2, 8} };

	float l[n][n]{};
	float y[n][n]{};
	float a_inv[n][n]{};

	l[0][0] = sqrt(a[0][0]);

	for (int i{ 1 }; i < n; i++) {
		l[i][0] = a[i][0] / l[0][0];
	}

	for (int k{ 1 }; k < n; k++) {
		float sq_s{};
		for (int m{}; m < k; m++) {
			sq_s += pow(l[k][m], 2);
		}
		l[k][k] = sqrt(a[k][k] - sq_s);
		if (k < n - 1) {
			for (int i{ k + 1 }; i < n; i++) {
				float pair_s{};
				for (int m{}; m < k; m++) {
					pair_s += l[i][m] * l[k][m];
				}
				l[i][k] = (a[i][k] - pair_s) / l[k][k];
			}
		}
	}

	for (int i{}; i < n; i++) {
		for (int j{}; j < n; j++) {
			cout << l[i][j] << "   \t";
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
					y[i][j] += l[i][m] * y[m][j];
				}
				y[i][j] /= -l[i][i];
			}
		}
	}

	for (int i{}; i < n; i++) {
		for (int j{}; j < n; j++) {
			cout << y[i][j] << "   \t";
		}
		cout << "\n";
	}
	cout << "\n";

	for (int i{}; i < n; i++) {
		for (int j{}; j < n; j++) {
			a_inv[i][j] = 0;
			for (int m{}; m < n; m++) {
				a_inv[i][j] += y[m][i] * y[m][j];
			}
		}
	}

	for (int i{}; i < n; i++) {
		for (int j{}; j < n; j++) {
			cout << a_inv[i][j] << "   \t";
		}
		cout << "\n";
	}
	cout << "\n";
}
