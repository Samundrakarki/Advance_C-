/*
CH08-320143
a1 p5.cpp
Samundra karki
sa.karki@jacobs-university.de
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include "Vector.h"


int main(){
    //creating a instance of vector and matrices classes
    Vector vec;
    Matrix mat;

    //creating a file stream
    ifstream file1, file2;

    //opening th files
    file1.open("in1.txt", ios::in);
    file2.open("in2.txt", ios::in);

    if(!file1.good() && !file2.good())
        exit(1);

    ofstream out;
    out.open("matvec.txt", ios::out);
    if(!out.good()){
        exit(1);
    }

    //overloaded issertion opeartor for vectors and matrices
    file1 >> vec;
    file2 >> mat;

    //overloaded << operator for vectos matrices and * too;
    out << (vec * mat);
}

