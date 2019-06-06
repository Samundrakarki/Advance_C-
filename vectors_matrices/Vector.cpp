/*
CH08-320143
a1 p5.cpp
Samundra karki
sa.karki@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Vector.h"
 
//default constructor
Vector::Vector() : size(3) {
    elements = new int[size];
    for (int i = 0; i < size; i++)
        elements[i] = 0;    
}
 
//parameterized constructor
Vector::Vector(int passed_size, const int *comp) : size(passed_size){
    elements = new int[passed_size];
    for (int i = 0; i< passed_size; i++)
        elements[i] = comp[i];
}
 
//copy constructor
Vector::Vector(const Vector& cpy) : size(cpy.size){
    elements = new int[size];
    for (int i = 0; i < size; i++)
        elements[i] = cpy.elements[i];
}
 
//using setter and getter method 
void Vector::setSize(int newSize){
    size = newSize;
}
int Vector::getSize(){
    return size;
}
int Vector::getElem(int i){
    return elements[i];
}

//destructor also deleteing the dynamically alllocated memory
Vector::~Vector(){
    delete[] elements;
}

istream& operator>>(istream& input, Vector& vec){
    input >> vec.size;
    vec.elements = new int[vec.size];
    for(int i = 0; i < vec.size; i++){
        input >> vec.elements[i];
    }
    return input;
}

ostream& operator<<(ostream& output, Vector& vec){
    output << vec.size << endl;
    for(int i = 0; i < vec.size; i++){
        output << vec.elements[i] << endl;
    }
    return output;
}
Vector& Vector::operator*(Matrix& mat){
    Vector v;
    this->size = mat.getRow();
    for(int i = 0; i < mat.getRow(); i++){
        for(int j = 0; j < mat.getColumn(); j++){
            v.elements[i] += mat.getElem(i, j) * this->elements[j]; 
        }
    }
    for(int i = 0; i < this->size; i++ ){
        this->elements[i] = v.elements[i];
    }
    return *this;
}

