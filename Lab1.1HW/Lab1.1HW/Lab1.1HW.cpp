#include <iostream>

using namespace std;

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    double temperature;
    char scale;

    cout << "Enter temperature: ";
    cin >> temperature;

    cout << "Enter scale (C for Celsius, F for Fahrenheit): ";
    cin >> scale;

    if (scale == 'C' || scale == 'c') {
        cout << temperature << " Celsius is equal to " << celsiusToFahrenheit(temperature) << " Fahrenheit." << endl;
    }
    else if (scale == 'F' || scale == 'f') {
        cout << temperature << " Fahrenheit is equal to " << fahrenheitToCelsius(temperature) << " Celsius." << endl;
    }
    else {
        cout << "Invalid scale entered." << endl;
    }

    return 0;
}
