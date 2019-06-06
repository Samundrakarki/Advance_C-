#include <iostream>
#include<exception>
#include <sstream>
#include <string>

#include "Fraction.h"
using namespace std;

Fraction::Fraction() : num(0), de_num(0){}

Fraction:: Fraction(int num, int de_num) {
    this->num = num; 
    this->de_num = de_num;
}

Fraction::Fraction(const Fraction& cpy){
    this->num = cpy.num;
    
    if(this->de_num == 0){
        throw LException("Invalid data or logical error");
    }else {
        this->de_num = cpy.de_num;
    }
}

//casting the given string to
//integers using sstream's child class istringstream

Fraction:: Fraction(string given_str){
    string str;
    int number;

    for (char f: given_str) {
        if (f == '/') {
        istringstream iss (str);
        iss >> number;
        this->num = number;
        str = "";
        continue;
        }
        str += f;
    }

    istringstream iss2 (str);
    iss2 >> number;
    if (number == 0)
        throw LException("Invalid data or logical error");

    this->de_num = number;
}


//overloading all the relational operators
bool Fraction:: operator<(const Fraction& frac){
    double frac1 = ((double)this->num/(double)this->de_num);
    double frac2 = (double)frac.num /(double)frac.de_num;

    return (frac1 < frac2);
}


bool Fraction:: operator>(const Fraction& frac){
    double frac1 = ((double)this->num/(double)this->de_num);
    double frac2 = (double)frac.num /(double)frac.de_num;

    return (frac1 > frac2);
}

bool Fraction:: operator<=(const Fraction& frac){
    double frac1 = ((double)this->num/(double)this->de_num);
    double frac2 = (double)frac.num /(double)frac.de_num;

    return (frac1 <= frac2);
}


bool Fraction:: operator>=(const Fraction& frac){
    double frac1 = ((double)this->num/(double)this->de_num);
    double frac2 = (double)frac.num /(double)frac.de_num;

    return (frac1 >= frac2);
}


bool Fraction:: operator==(const Fraction& frac){
    double frac1 = ((double)this->num/(double)this->de_num);
    double frac2 = (double)frac.num /(double)frac.de_num;

    return (frac1 == frac2);
}


bool Fraction:: operator!=(const Fraction& frac){
    double frac1 = ((double)this->num/(double)this->de_num);
    double frac2 = (double)frac.num /(double)frac.de_num;

    return (frac1 != frac2);
}


//overloading all arthemetic operators
Fraction Fraction::operator+(const Fraction& frac){
    Fraction new_fraction;
    int new_d = this->de_num * frac.de_num;
    int new_n = (this->num * frac.de_num) + (frac.num * this->de_num);  

    new_fraction.num = new_n;
    new_fraction.de_num = new_d;

    return new_fraction; 
}

Fraction Fraction::operator-(const Fraction& frac){
    Fraction new_fraction;
    int new_n = (this->num * frac.de_num) - (frac.num * this->de_num);  
    int new_d = this->de_num * frac.de_num;

    new_fraction.num = new_n;
    new_fraction.de_num = new_d;

    return new_fraction; 
}

Fraction Fraction::operator*(const Fraction& frac){
    Fraction new_fraction;
    int new_n = (this->num * frac.num);  
    int new_d = this->de_num * frac.de_num;

    new_fraction.num = new_n;
    new_fraction.de_num = new_d;

    return new_fraction; 
}

Fraction Fraction::operator/(const Fraction& frac){
    Fraction new_fraction;
    int new_n = this->num * frac.de_num;
    int new_d = (this->de_num * frac.num);   

    new_fraction.num = new_n;
    new_fraction.de_num = new_d;

    return new_fraction; 
}

Fraction Fraction::operator=(const Fraction& frac){
    Fraction new_fraction;    
    this->num = frac.num;
    this->de_num = frac.num;
    
    new_fraction.num =this->num;
    new_fraction.de_num= this->de_num;
    return new_fraction;
}

//overloading iostream operators
istream& operator>>(istream& is,Fraction& frac){
    is >> frac.num;
    is >> frac.de_num;
    if(frac.de_num == 0){
        throw LException("Invalid data or logical error");
    }
    return is;
}

ostream& operator<<(ostream& os,  const Fraction& frac){
    os << frac.num << "/" << frac.de_num << endl;
    return os;
}



