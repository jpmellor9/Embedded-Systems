#include "mbed.h"
#include <type_traits>

// Date Type ComplexNumber_C
typedef struct {
  double real;
  double imag;
} ComplexNumber_C;


int main() {

    //Create instance of a complex number
    ComplexNumber_C p;

    //Initialise each attribute 
    p.real = 2.0;
    p.imag = 3.0;
    
    //Create and Initialise 
    ComplexNumber_C q = {1.0, 1.0};

    // TASK:
    // Create another complex number y
    // Calculate the complex sum of p and q and store in y
    // Use printf to display as a complex number (hint: you need two placeholders)
    
    ComplexNumber_C y1;
    

    y1.real = p.real + q.real;
    y1.imag = p.imag + q.imag;

    printf("real = %f imaginary = %f\n", y1.real, y1.imag);
    
    while (true) {
       // printf("real = %f imaginary = %f\n", y1.real, y1.imag);
    }
    
}
