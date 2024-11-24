#include <iostream>
#include <cmath>

using namespace std;

class QuadraticEquation {
private:
    double a, b, c;

public:
    // Constructor
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    // Calculate the discriminant
    double discriminant() const {
        return b * b - 4 * a * c;
    }

    // Solve the quadratic equation
    void solve() const {
        double delta = discriminant();

        if (delta >= 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);

            if (delta > 0) {
                cout << "The equation has two distinct real roots:" << endl;
                cout << "x1 = " << x1 << endl;
                cout << "x2 = " << x2 << endl;
            }
            else {
                cout << "The equation has one real root (double root):" << endl;
                cout << "x = " << x1 << endl;
            }
        }
        else {
            cout << "The equation has two complex roots:" << endl;
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-delta) / (2 * a);
            cout << "x1 = " << realPart << " + " << imaginaryPart << "i" << endl;
            cout << "x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
        }
    }
};

int main() {
    double a, b, c;

    cout << "Enter the coefficients of the quadratic equation (ax^2 + bx + c = 0):" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;

    QuadraticEquation equation(a, b, c);
    equation.solve();

    return 0;
}
