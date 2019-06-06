/*
CH08-320143
a1 p1.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include "Complex.h"
 
using namespace std;
 
int main(){
    //two complex number decleration
	Complex c1,c2,c3, c4, c5;

    //openeing the files
    ifstream fp1, fp2;
	fp1.open("in1.txt");
	fp2.open("in2.txt");
    if((!fp1.good())&&(!fp2.good()))
        exit(1);

    //reading the files
    ofstream fp3;
    fp3.open ("output.txt");
    if(!fp3.good())
        exit(1);
    /*
    File structure
    Opernad<<operator>Operand = realpart and img part
    */

	fp1 >> c1;
	fp2 >> c2;

    c3 = c1 + c2;
    c4 = c1 - c2;
    c5 = c1 * c2;
    
	fp3 << "Additon : "<< c3;
	fp3 << "Substraction : " << c4;
	fp3 << "Product : " << c5;

    return 0;
}