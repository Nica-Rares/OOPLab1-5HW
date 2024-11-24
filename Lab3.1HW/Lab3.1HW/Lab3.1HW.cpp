#include <iostream>

using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double l, double w) : length(l), width(w) {}

    // Getters
    double getLength() const { return length; }
    double getWidth() const { return width; }

    // Calculate perimeter
    double calculatePerimeter() const {
        return 2 * (length + width);
    }

    // Calculate area
    double calculateArea() const {
        return length * width;
    }
};

int main() {

    Rectangle rect1(5.0, 3.0);
    Rectangle rect2(7.0, 4.0);

    double perimeter1 = rect1.calculatePerimeter();
    double area1 = rect1.calculateArea();

    double perimeter2 = rect2.calculatePerimeter();
    double area2 = rect2.calculateArea();

    // Compare perimeters
    cout << "Rectangle 1 Perimeter: " << perimeter1 << endl;
    cout << "Rectangle 2 Perimeter: " << perimeter2 << endl;
    if (perimeter1 > perimeter2) {
        cout << "Rectangle 1 has a larger perimeter." << endl;
    }
    else if (perimeter1 < perimeter2) {
        cout << "Rectangle 2 has a larger perimeter." << endl;
    }
    else {
        cout << "Both rectangles have the same perimeter." << endl;
    }

    // Compare areas
    cout << "Rectangle 1 Area: " << area1 << endl;
    cout << "Rectangle 2 Area: " << area2 << endl;
    if (area1 > area2) {
        cout << "Rectangle 1 has a larger area." << endl;
    }
    else if (area1 < area2) {
        cout << "Rectangle 2 has a larger area." << endl;
    }
    else {
        cout << "Both rectangles have the same area." << endl;
    }

    return 0;
}
