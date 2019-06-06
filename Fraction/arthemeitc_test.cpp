#include <iostream>
#include <exception>
#include "Fraction.h"

using namespace std;

//Test machinery 
int nPass = 0, nFail = 0;

void test(bool t){
    if(t) nPass++;
    else nFail++;
}

int main() {
    Fraction frac1("2/5");
    Fraction frac2;
    
    //3/5 to test all the assignment operators
    try{
        cin >> frac2;
    }catch(logic_error& e){
        cout << e.what() << endl;
    }

    //teating assignment operator 
    Fraction frac("1/1");
    Fraction frac3("1/5");
    Fraction frac4("6/25");
    Fraction frac5("2/3");
    Fraction frac6 = frac;
    test(frac == frac1+ frac2);
    test(frac3 == frac2 - frac1);
    test(frac4 == frac1 * frac2);
    test(frac5 == frac1 / frac2);
    test(frac6 == frac);
    cout << "Passed test for arthemetic operator: " 
         << nPass << "\nFail test for arthematic operator :" 
         << nFail << endl;
}