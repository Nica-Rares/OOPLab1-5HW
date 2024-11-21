#include <iostream>

using namespace std;

int operate(int a, int b, int (*operation)(int, int)) {
    if (b == 0) {
        throw runtime_error("Division by zero error!");
    }
    return operation(a, b);
}

double operate(double a, double b, double (*operation)(double, double)) {
    if (b == 0) {
        throw runtime_error("Division by zero error!");
    }
    return operation(a, b);
}

int divideInt(int a, int b) {
    return a / b;
}

double divideDouble(double a, double b) {
    return a / b;
}

int main() {
    try {
        int result1 = operate(10, 2, divideInt);
        cout << "Integer division: " << result1 << endl;

        int result2 = operate(10, 0, divideInt);
        cout << "Integer division by zero: " << result2 << endl; 
    }
    catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        double result3 = operate(10.5, 2.5, divideDouble);
        cout << "Double division: " << result3 << endl;

        double result4 = operate(10.5, 0, divideDouble);
        cout << "Double division by zero: " << result4 << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
