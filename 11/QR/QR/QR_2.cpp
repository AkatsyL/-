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

void print_mx(vector<vector<double>>& mx, const int n) {
    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
            cout << setw(12) << setprecision(5) << mx[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    const int n = 5;
    vector<vector<double>> A{ vector<double>{5, 6, 8, 3, 4},
                              vector<double>{2, 4, 7, 1, 3},
                              vector<double>{1, 2, 3, 4, 9},
                              vector<double>{5, 1, 4, 2, 9},
                              vector<double>{4, 8, 6, 5, 3} };

    vector<vector<double>> Q{ A };

    vector<vector<double>> R(n, vector<double>(n));

    int iter{ 100 };

    for (int t{}; t < iter; t++) {

        vector<vector<double>> At(A);
        vector<vector<double>> Qt(A);
        vector<vector<double>> Rt(R);

        for (int j{}; j < n; j++) {
            double sq_sum{};

            for (int m{}; m < n; m++) {
                sq_sum += pow(Qt[m][j], 2);
            }
            Rt[j][j] = sqrt(sq_sum);

            for (int i{}; i < n; i++) {
                Qt[i][j] /= Rt[j][j];
            }

            for (int k{ j + 1 }; k < n; k++) {

                for (int m{}; m < n; m++) {
                    Rt[j][k] += Qt[m][j] * Qt[m][k];
                }

                for (int i{}; i < n; i++) {
                    Qt[i][k] -= Qt[i][j] * Rt[j][k];
                }
            }
        }

        for (int i{}; i < n; i++) {
            for (int j{}; j < n; j++) {
                At[i][j] = 0;
                for (int k{}; k < n; k++) {
                    At[i][j] += Rt[i][k] * Qt[k][j];
                }
            }
        }

        cout << "A = " << "\n";
        print_mx(At, n);
        cout << "Q = " << "\n";
        print_mx(Qt, n);
        cout << "R = " << "\n";
        print_mx(Rt, n);

        A = At;

        At.clear();
        Qt.clear();
        Rt.clear();
    }
    A.clear();
    Q.clear();
    R.clear();
}
