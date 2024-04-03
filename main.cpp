#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return 1 + 2 * x + 0.5 * pow(x, 2) - (double)1/6 * pow(x, 6);
}

double bruteforce(double a, double b, double eps) {
    double step = (b - a) / eps;
    double x = a;
    double f_prev = f(x);
    double f_next;

    for (int i = 0; i < step; i++) {
        cout << "f(" << x << ") = " << f_prev << endl;
        x += eps;
        f_next = f(x);
        if (f_prev > f_next) {
            return f_prev;
        } else {
            f_prev = f_next;
        }
    }

    return -1;
}

int main() {
    double a = 1, b = 1.5;
    double eps = 0.01;

    bruteforce(a, b, eps);
}
