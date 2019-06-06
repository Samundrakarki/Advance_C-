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
 
//initialinzing the value of real and imiaginary part in default constructor
template <class T>
Complex<T>::Complex(){
    real_part = 0;
    imaginary_part = 0;
}

//initializing the parameter of parameterized constructor in real and imaginamry part
template <class T>
Complex<T>::Complex(T m, T n){ 
    real_part = m;
    imaginary_part = n;
}

//Setting the value of real part
template <class T>
void Complex<T>:: setRealPart(T newrealpart){   
    real_part = newrealpart;
}
//setting the value of img part
template <class T>
void Complex<T>:: setImgPart(T newimgpart){
    imaginary_part = newimgpart;
}


//using getter method to get the real and imiginary part
template <class T>
T Complex<T>::getreal(){       
    return real_part;
}


//Destructor
template <class T>
Complex<T>::~Complex(){      
}
 

//copying the value of the constructor ansd setting it with real and imaginary part
template <class T>
Complex<T>::Complex(Complex& cp){   
    real_part = cp.real_part;
    imaginary_part = cp.imaginary_part;
}

template <class T>
T Complex<T>::getimg(){
    return imaginary_part;
}

template <class T>
Complex<T> Complex<T>::operator+(const Complex &a){
    Complex r;
    r.real_part= real_part + a.real_part;
    r.imaginary_part = imaginary_part + a.imaginary_part;
    return r;
}

//overloading - operator
template <class T>
Complex<T> Complex<T>::operator-(const Complex &a){
    Complex r;
    r.real_part = real_part - a.real_part;
    r.imaginary_part = imaginary_part - a.imaginary_part;
    return r;
}

//overloading * operator
template <class T>
Complex<T> Complex<T>::operator*(const Complex &a){
    Complex r;
    r.real_part = real_part*a.real_part + imaginary_part*a.imaginary_part;
    r.imaginary_part= imaginary_part*r.real_part + real_part *a.imaginary_part;
    return r;  
}

//overloading = operator
template <class T>
Complex<T>& Complex<T>:: operator=(Complex b){
    real_part = b.real_part;
    imaginary_part = b.imaginary_part;
    return *this;
}

//overloading <= operator
template <class T>
bool Complex<T>::operator<=(Complex a){
    int abs_val = sqrt((a.real_part*a.real_part) + (a.imaginary_part*a.imaginary_part));
    int abs_val1 = sqrt((real_part*real_part) + (imaginary_part*imaginary_part));
    if(abs_val1 <= abs_val){
        return true;
    }
    else{
        return false;
    }
}
//overloading >= operator
template <class T>
bool Complex<T>::operator>=(Complex a){
int abs_val = sqrt((a.real_part*a.real_part) + (a.imaginary_part*a.imaginary_part));
    int abs_val1 = sqrt((real_part*real_part) + (imaginary_part*imaginary_part));
    if(abs_val1 >= abs_val){
        return true;
    }
    else{
        return false;
    }
}
//overloading == operator
template <class T>
bool Complex<T>::operator==(Complex a){
    if((real_part == a.real_part) && (imaginary_part == a.imaginary_part))
        return true;
    else
        return false;
}

template class Complex<double>;
template class Complex<int>;
