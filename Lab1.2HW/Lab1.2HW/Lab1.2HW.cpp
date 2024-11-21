#include <iostream>

using namespace std;

#define USE_HEADER1 0  // Change this to 0 to use header2.h

#ifdef USE_HEADER1
#include "header1.h"
#else
#include "header2.h"
#endif

int main() {
    f();  // Call the function f()
    return 0;
}
