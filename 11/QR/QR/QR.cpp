
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::setprecision;
using std::setw;

int main()
{
    const int n = 3;
    vector<vector<double>> A{ vector<double>{1, 6, 8},
                              vector<double>{2, 4, 7},
                              vector<double>{1, 1, 3} };

    vector<vector<double>> Q{ vector<double>{1, 6, 8},
                              vector<double>{2, 4, 7},
                              vector<double>{1, 1, 3} };

    vector<vector<double>> R(n, vector<double>(n));

    for (int j{}; j < n; j++) {
        double sq_sum{};

        for (int m{}; m < n; m++) {
            sq_sum += pow(Q[m][j], 2);
        }
        R[j][j] = sqrt(sq_sum);

        for (int i{}; i < n; i++) {
            Q[i][j] /= R[j][j];
        }

        for (int k{ j + 1 }; k < n; k++) {

            for (int m{}; m < n; m++) {
                R[j][k] += Q[m][j] * Q[m][k];
            }

            for (int i{}; i < n; i++) {
                Q[i][k] -= Q[i][j] * R[j][k];
            }
        }
    }

    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
            cout << setw(12) << setprecision(3) << Q[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
            cout << setw(12) << setprecision(3) << R[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    A.clear(); Q.clear(); R.clear();
}
