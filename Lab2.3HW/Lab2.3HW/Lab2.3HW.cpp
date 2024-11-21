#include <iostream>
#include <stdexcept>

using namespace std;

double solveLinearEquation(double a, double b) {
    if (a == 0) {
        if (b == 0) {
            throw runtime_error("Infinite solutions."); 
        }
        else {
            throw runtime_error("No solution."); 
        }
    }
    else {
        return -b / a; 
    }
}

int main() {
    try {
        double a, b;
        cout << "Enter coefficient a: ";
        cin >> a;
        cout << "Enter coefficient b: ";
        cin >> b;

        double solution = solveLinearEquation(a, b);
        cout << "Solution: x = " << solution << endl;
    }
    catch (const std::runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
