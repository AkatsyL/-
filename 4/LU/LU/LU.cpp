//LU

#include <iostream>
#include <ctime>

using namespace std;

int main() {
	srand(time(0));

	const int n = 5;

	float a[n][n] = { 0 };
	float l[n][n] = { 0 };
	float u[n][n] = { 0 };

	float y[n] = { 0 };
	float x[n] = { 0 };
	float c[n] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			l[i][j] = 0;
			if (i == j) {
				u[i][j] = 1;
			}
			else {
				u[i][j] = 0;
			}
		}
		cin >> c[i];
	}

	for (int i = 0; i < n; i++) {
		l[i][0] = a[i][0];
	}

	for (int j = 0; j < n; j++) {
		u[0][j] = a[0][j] / l[0][0];
	}

	for (int k = 0; k < n; k++) {
		for (int i = k; i < n; i++) {
			l[i][k] = a[i][k];
			for (int m = 0; m < k; m++) {
				l[i][k] -= l[i][m] * u[m][k];
			}
		}
		if (k <= n - 1) {
			for (int j = k + 1; j < n; j++) {
				u[k][j] = a[k][j];
				for (int m = 0; m < k; m++) {
					u[k][j] -= l[k][m] * u[m][j];
				}
				u[k][j] /= l[k][k];
			}
		}
	}

	y[0] = c[0] / l[0][0];
	for (int i = 1; i < n; i++) {
		y[i] = c[i];
		for (int m = 0; m < i; m++) {
			y[i] -= l[i][m] * y[m];
		}
		y[i] /= l[i][i];
	}

	for (int i = 0; i < n; i++) {
		cout << y[i] << "\t";
	}
	cout << "\n";

	x[n - 1] = y[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		x[i] = y[i];
		for (int m = i + 1; m < n; m++) {
			x[i] -= u[i][m] * x[m];
		}
	}

	for (int i = 0; i < n; i++) {
		cout << x[i] << "\t";
	}
	cout << "\n";
}


