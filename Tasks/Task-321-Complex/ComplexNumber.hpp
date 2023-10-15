//
//  ComplexNumber.hpp
//  Complex
//
//  Created by Nicholas Outram on 21/09/2017.
//  Copyright © 2017 Nicholas Outram. All rights reserved.
//

#ifndef ComplexNumber_hpp
#define ComplexNumber_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class ComplexNumber {
private:
    double real;
    double imag;
    
public:
    //Default constructor
    ComplexNumber() {
        this->real = 0.0;
        this->imag = 0.0;
    }
    
    //Constructor 2 - default of second parameter is 1 if not specified
    ComplexNumber(const double r, const double i=0.0) {
        this->real = r;
        this->imag = i;
    }
    
    //Copy constructors
    ComplexNumber(const ComplexNumber& c) {
        this->imag = c.imag;
        this->real = c.real;
    }

    //Destructor
    ~ComplexNumber() {
        cout << "Bye'ee" << endl;
    }
    
    //Read-only accessors
    double getReal() {
        return this->real;
    }

    double getImag() {
        return this->imag;
    }

    //Conjugate - verb, so perform in place
    void conjugate() {
        this->imag *= -1.0;
    }
    
    //Conjugated - adjective, so return new copy
    ComplexNumber conjugated() {
        return ComplexNumber(this->real, -1.0*this->imag);
    }

    //Add in place
    void add(const ComplexNumber& c) {
        this->real += c.real;
        this->imag += c.imag;
    }
    
    //Add
    ComplexNumber addedTo(const ComplexNumber &c) {
        return ComplexNumber(this->real+c.real, this->imag+c.imag);
    }

    void subtract(const ComplexNumber &c){
        this->real -= c.real;
        this->imag -= c.imag;
    }

    ComplexNumber subtractfrom(const ComplexNumber &c){
        return ComplexNumber(this->real-c.real, this->imag-c.imag);
    }

    void multiply(const ComplexNumber &c){
        this->real = (this->real*c.real) + (-1*(this->imag*c.imag));
        this->imag = (this->real*c.imag) + (this->imag*c.imag);
    }

    ComplexNumber multiplywith(const ComplexNumber &c){
        return ComplexNumber((this->real*c.real) + (-1*(this->imag*c.imag)), (this->real*c.imag) + (this->imag*c.imag));
    }

    void divide(const ComplexNumber &c){
       ComplexNumber com1 = ComplexNumber(this->real, this->imag);
       ComplexNumber com2 = ComplexNumber(c.real, c.imag);
       ComplexNumber con = com2.conjugated();
       ComplexNumber mulnum = com1.multiplywith(con);
       ComplexNumber muldenom = com2.multiplywith(con);
       this->real = mulnum.real/muldenom.real;
       this->imag = mulnum.imag/muldenom.imag;
    }

    ComplexNumber dividewith(const ComplexNumber &c){
       ComplexNumber com1 = ComplexNumber(this->real, this->imag);
       ComplexNumber com2 = ComplexNumber(c.real, c.imag);
       ComplexNumber con = com2.conjugated();
       ComplexNumber mulnum = com1.multiplywith(con);
       ComplexNumber muldenom = com2.multiplywith(con);
       ComplexNumber div = ComplexNumber(mulnum.real/muldenom.real, mulnum.imag/muldenom.imag);
       return ComplexNumber(this->real = div.real, this->imag = div.imag); // check this
    }

    void negate(){
        this->real *= -1;
        this->imag *= -1;
    }

    ComplexNumber negated(){
        return ComplexNumber(-1*this->real, -1*this->imag);
    }
    
    //Display
    void display() {
        cout << this->real << " + " << this->imag << "j" << endl;
    }
    
};


#endif /* ComplexNumber_hpp */
