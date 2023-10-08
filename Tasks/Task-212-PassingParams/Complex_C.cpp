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

ComplexNumber_C complexMul(const ComplexNumber_C a, const ComplexNumber_C b){
    ComplexNumber_C y = a;
    y.real = (a.real*b.real) + (-1*(a.imag*b.imag));
    y.imag = (a.real*b.imag) + (a.imag*b.real);
    return y;
}

ComplexNumber_C complexDiv(const ComplexNumber_C a, const ComplexNumber_C b){
    ComplexNumber_C y = a;
    ComplexNumber_C Con = complexConjugate(b);
    ComplexNumber_C mulnum = complexMul(a, Con);
    ComplexNumber_C muldenom = complexMul(b, Con);
    y.real = mulnum.real/muldenom.real;
    y.imag = mulnum.imag/muldenom.real;
    return y;
}

void complexNegateInplace(ComplexNumber_C& u) {
    u.imag = -u.imag;
    u.real = -u.real;
}

void complexConjugateInplace(ComplexNumber_C& u){  
    u.real = u.real;
    u.imag = -u.imag;
}

void complexDisplay(const char *strName, const ComplexNumber_C u) {
    printf("%s = %f + j%f\n", strName, u.real, u.imag);
}