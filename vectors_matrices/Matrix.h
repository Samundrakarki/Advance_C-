/*
CH08-320143
a1 p5.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include <iostream>
using namespace std;


class Matrix{
    private:
        int row;
        int column;
        int **elements;
    public:
        Matrix();
        Matrix(int, int,  int**);
        Matrix(const Matrix&);
        ~Matrix();

        //using getter and setter method for Size
        void setRow(int);
        int getRow(); 

        void setColumn(int);
        int getColumn();

        int getElem(int, int);


        friend istream& operator>>(istream& is,Matrix&);  
        friend ostream& operator<<(ostream& os,Matrix&); 
       
};