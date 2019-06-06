/*
CH08-320143
a1 p5.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

 #include <iostream>
using namespace std;

#ifndef VECTOR_H
#define VECTOR_H
#include "Matrix.h"

class Vector{
    private:
        int size;
        int *elements;
    public:
        //declaring required constructors
        Vector();
        Vector(int, const int*);
        Vector(const Vector&);
        ~Vector();
 
        //using getter and setter method for Size
        void setSize(int);
        int getSize(); 
        int getElem(int i);

        friend istream& operator>>(istream& input,Vector&);  
        friend ostream& operator<<(ostream& output,Vector&); 

        Vector& operator*(Matrix&);      
};
#endif