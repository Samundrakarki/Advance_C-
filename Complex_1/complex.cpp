/*
CH08-320143
a1 p1.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include <iostream>
#include <string>
#include <cmath>
#include "Complex.h"
 
using namespace std;
 

//overloading << operaotr
ostream& operator<<(ostream& output, const Complex& a){
    if(a.imaginary_part){
        output << noshowpos << a.real_part << showpos << a.imaginary_part << "i" << endl;
    }
    else{
        output << a.real_part;
    }
    
    return output;
}

//overloading >> operator
istream& operator>>(istream& input,Complex& a){
    input >> a.real_part;
    input >> a.imaginary_part;
    return input;
}

//overloading * operaotr
Complex Complex::operator+(const Complex &a){
    Complex r;
    r.real_part= real_part + a.real_part;
    r.imaginary_part = imaginary_part + a.imaginary_part;
    return r;
}

Complex Complex::operator-(const Complex &a){
    Complex r;
    r.real_part = real_part - a.real_part;
    r.imaginary_part = imaginary_part - a.imaginary_part;
    return r;
}

Complex Complex::operator*(const Complex &a){
    Complex r;
    r.real_part = real_part*a.real_part + imaginary_part*a.imaginary_part;
    r.imaginary_part= imaginary_part*r.real_part + real_part *a.imaginary_part;
    return r;  
}

Complex& Complex:: operator=(Complex b){
    real_part = b.real_part;
    imaginary_part = b.imaginary_part;
    return *this;
}
