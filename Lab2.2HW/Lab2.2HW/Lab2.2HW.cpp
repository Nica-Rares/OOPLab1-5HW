#include <iostream>
#include <cmath>

using namespace std;

struct nrComplex {
    float a;
    float b;
};

float absValue(float x) {
    return abs(x);
}

float absValue(nrComplex z) {
    return sqrt(z.a * z.a + z.b * z.b);
}

int main() {
    float realNum = -5.0;
    nrComplex complexNum = { 7.0, 8.0 };

    cout << "Absolute value of " << realNum << " is: " << absValue(realNum) << endl;
    cout << "Absolute value of " << complexNum.a << "+" << complexNum.b << "i is: " << absValue(complexNum) << endl;

    return 0;
}
