#include "stdio.h"
#include "Complex_C.hpp"
#include <cstdio>


// TASK - write and test complexConjugate, complexNegate, complexSubtract, complexMagnitude, complexMultiply and complexDivide

int main() {
    printf("\n\nTASK312\n");

    //Create instance of a complex number
    ComplexNumber_C p = {2.0, 3.0};
    ComplexNumber_C q = {1.0, 1.0};
    complexDisplay("p", p);
    complexDisplay("q", q);
 
    ComplexNumber_C sum = complexAdd(p, q);
    complexDisplay("p+q", sum);

    ComplexNumber_C Conjugate = complexConjugate(p);
    complexDisplay("conjugate p", Conjugate);
    Conjugate = complexConjugate(q);
    complexDisplay("conjugate q", Conjugate);

    ComplexNumber_C Negate = complexNegate(p);
    complexDisplay("Negate p", Negate);
    Negate = complexNegate(q);
    complexDisplay("Negate q", Negate);

    Negate = complexNegate(q);
    ComplexNumber_C Subtraction = complexAdd(p, Negate);
    complexDisplay("p-q", Subtraction);

    ComplexNumber_C Mag = complexMag(p);
    printf("mag = %f\n", Mag);

    while (true) {
    }
}
