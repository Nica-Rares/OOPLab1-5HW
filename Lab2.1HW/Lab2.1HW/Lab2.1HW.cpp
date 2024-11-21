#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

double calculateArea(double length, double width) {
    return length * width;
}

double calculateArea(double side) {
    return side * side;
}

double getArea(const string& inputLength, const string& inputWidth = "0") {
    double length, width;
    try {
        length = stod(inputLength);
        if (inputWidth != "0") {
            width = stod(inputWidth);
        }
        else {
            width = length; 
        }
    }
    catch (const invalid_argument& e) {
        throw runtime_error("Invalid input: non-numeric value provided.");
    }
    catch (const out_of_range& e) {
        throw runtime_error("Invalid input: value out of range.");
    }

    return calculateArea(length, width);
}

int main() {
    try {
        cout << "Area of rectangle: " << getArea("5.0", "7.0") << endl; // Rectangle
        cout << "Area of square: " << getArea("5.0") << endl; // Square
        cout << "Area of rectangle with invalid input: " << getArea("192a") << endl; // Invalid input
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
