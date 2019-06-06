/*
CH08-320143
a1 p1.cpp
Samundra karki
sa.karki@jacobs-university.de
*/
#include <iostream>

using namespace std;
class Complex{
    //declaring the real and imaginary part
    private:
 
        int real_part;
        int imaginary_part;
 
    public:
        friend ostream& operator<<(ostream &, const Complex &);
        friend istream& operator>>(istream&, Complex &);

        Complex operator+(const Complex&);
        Complex operator-(const Complex&);
        Complex operator*(const Complex&);
        
        Complex& operator=(const Complex);
 
};