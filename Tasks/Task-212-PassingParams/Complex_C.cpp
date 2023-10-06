#include "mbed.h"
#include "Complex_C.hpp"
#include <cmath>

ComplexNumber_C complexAdd(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;
    y.real += b.real;
    y.imag += b.imag;
    return y;
}

ComplexNumber_C complexConjugate(const ComplexNumber_C a){
    ComplexNumber_C y = a;
    y.real = a.real;
    y.imag = -a.imag;
    return y;
}

ComplexNumber_C complexNegate(const ComplexNumber_C a){
    ComplexNumber_C y = a;
    y.real = -a.real;
    y.imag = -a.imag;
    return y;
}

ComplexNumber_C complexMag(const ComplexNumber_C a){
    ComplexNumber_C y = a;
    y.real = sqrt(pow(a.real, 2) + (pow(a.imag, 2)));
    return y;
}

void complexDisplay(const char *strName, const ComplexNumber_C u) {
    printf("%s = %f + j%f\n", strName, u.real, u.imag);
}