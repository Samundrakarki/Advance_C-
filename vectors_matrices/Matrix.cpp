/*
CH08-320143
a1 p5.cpp
Samundra karki
sa.karki@jacobs-university.de
*/
#include <iostream>
#include <fstream>
#include<sstream>
#include "Matrix.h"


Matrix::Matrix(){}

Matrix::Matrix(int r, int c, int **elem) : row(r), column(c){
    for(int i = 0; i <r; i++){
        for(int j = 0; j < c; j++){
            elements[i][j] = elem[i][j];
        }
    }
}

Matrix::Matrix(const Matrix& cpy) : row(cpy.row), column(cpy.column){
    for(int i = 0; i < cpy.row; i++){
        for(int j = 0; j < cpy.column; j++){
            elements[i][j] = cpy.elements[i][j];
        }
    }
}

Matrix::~Matrix(){
    delete[] elements;
}

void Matrix::setRow(int nr){
    row = nr;
}

void Matrix::setColumn(int nc){
    column = nc;
}

int Matrix::getRow(){
    return row;
}

int Matrix::getColumn(){
    return column;
}

int Matrix::getElem(int i, int j){
    return elements[i][j];
}


//------overloaded operators----------//
istream& operator>>(istream& is,Matrix& mat){
    is >> mat.row;
    is >> mat.column;
    
    //allocating the memory
    mat.elements = new int*[mat.row];
    for(int i = 0; i < mat.row; i++){
        mat.elements[i] = new int[mat.column];
    }

    for(int i = 0; i < mat.row; i++){
        for(int j = 0; j < mat.column; j++){
            is >> mat.elements[i][j];
        }
    }
    return is;
}

ostream& operator<<(ostream& os, Matrix& mat){
    for(int i = 0; i < mat.row; i++){
        for(int j = 0; j < mat.column; j++){
            os << mat.elements[i][j] << " ";
        }
        os << " ";
    }
    return os;
}


