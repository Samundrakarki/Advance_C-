/*
CH08-320143
a1 p1.cpp
Samundra karki
sa.karki@jacobs-university.de
*/
#include <iostream>

using namespace std;
template <class T>
class Complex{
    //declaring the real and imaginary part
    private:
 
        T real_part;
        T imaginary_part;
 
    public:
       //declaring the constructor and destructor
        Complex();
        Complex(T, T);
        Complex(Complex&);
        ~Complex();
 

       // setting real and imaginary part
        void setRealPart(T newrealpart);
        void setImgPart(T newimgpart);
 
        //getting real and imaginary part
        T getreal();
        T getimg();

        Complex operator+(const Complex&);
        Complex operator-(const Complex&);
        Complex operator*(const Complex&);
        bool operator<=(const Complex);
        bool operator>=(const Complex);
        
        Complex& operator=(const Complex);
         bool operator==(const Complex);
 
};
