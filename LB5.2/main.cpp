#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);
int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << setw(4) << " |"
        << setw(10) << "arth()" << setw(4) << " |"
        << setw(9) << "S" << setw(8) << " |"
        << setw(7) << "n" << setw(7) << " |"
        << endl;
    cout << "-------------------------------------------------------" << endl;

    x = xp;
    while (x <= xk) {
        if (abs(x) < 1 - eps) {
            s = S(x, eps, n, s);
            cout << "|" << setw(7) << setprecision(2) << x << setw(2) << " |"
                << setw(10) << setprecision(5) << atanh(x) << setw(4) << " |"
                << setw(10) << setprecision(5) << s << setw(7) << " |"
                << setw(7) << n << setw(7) << " |"
                << endl;
        }
        else {
            cout << "|" << setw(7) << setprecision(2) << x << " |"
                << "Out of range" << " |" <<
                setw(15) << "Out of range" << " |"
                << "Out of range" << " |"
                << endl;
        }
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;
    return 0;
}
double S(const double x, const double eps, int& n, double s)
{
    n = 0; // ����� �������� �� ����� �������� �������
    double a = x; // ����� �������� �� ����� �������� �������
    s = a;
    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    return s;
}
double A(const double x, const int n, double a)
{
    double R = (2 * n * pow(x, 2) - pow(x, 2)) / (2 * n + 1); // ����� �������� �� ����� �������� �������
    a *= R;
    return a;
}
