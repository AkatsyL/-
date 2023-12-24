#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	const int n{ 5 };
	float a[n][n + 1] = { {31, -4, 6, -3, 6, 36},
						{2, 34, -4, 7, -4, 70},
						{-7, 9, 29, 5, -3, 99},
						{3, -4, 4, 25, 1, 58},
						{6, -1, 1, -8, 34, 32} };

	float x_old[n]{};
	float x_new[n]{};

	float eps = 0.0001;

	while (1) {
		bool flag = true;
		for (int k = 0; k < n; k++) {
			x_new[k] = a[k][n];
			for (int j = 0; j < n; j++) {
				if (j != k) {
					x_new[k] -= a[k][j] * x_old[j]; //метод простых иитераций
					//x_new[k] -= a[k][j] * x_new[j]; //метод зейделя
				}
			}
			x_new[k] /= a[k][k];
			if (abs(x_new[k] - x_old[k]) > eps) {
				flag = false;
			}
		}
		for (int i{ 0 }; i < n; i++) {
			cout << x_new[i] << "\t";
			x_old[i] = x_new[i];
		}
		cout << "\n";
		if (flag) break;
	}
}
