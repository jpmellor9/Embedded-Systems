#include "DoubleNumber.hpp"
#include "ComplexNumber.hpp"

int main()
{
    //Constructor Function overloading 
    ComplexNumber c0(1.0, 2.0);
    DoubleNumber  d0(3.0);
    ComplexNumber c1(2.0, 3.0);
    DoubleNumber  d1;
    ComplexNumber c2;
    //This uses the operator= function
    d1 = 5.0;

    //Write the value as a string
    cout << d1.asString() << endl;

    //Now overrides the default =
    c2 = c1 + c0;

    //Now overrides the parent asString
    cout << c2.asString() << endl;

    //Challenge - try and understand this ;)
    cout << c1.asDoubleNumber().asString() << endl;

    //TODO - write an overloaded + operator
    DoubleNumber sum1 = c0 + c1 + d0 + d1;
    cout << sum1 << endl;

    while (true) {

    }
}

