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
    cout << "Passed test for arthemetic operator: " << nPass << "\nFail test for arthematic operator :" << nFail << endl;

    ::nPass = 0;
    ::nFail = 0;

    //testing io operator
    Fraction f_in;
    Fraction f_out("4/5");
    try{
        cin >> f_in;
        test(true);
    }catch(logic_error& e){
        test(false);
    }try{
        cout << "provided fraction is: " <<f_out;
    }catch(logic_error& e){
        test(false);
    }
    cout << "Passed test for io operator: " << nPass << "\nFailed test for io operator: " << nFail << endl;
    
    ::nPass = 0;
    ::nFail = 0;

    // testing constructor
    Fraction f_const(1, 3);
    Fraction f_temp("1/3");
    Fraction f_copy(f_const);
    test(f_temp == f_const);
    test(f_temp == f_copy);
    cout << "Passed test for construcot: " << nPass << "\nFailed test for constructor: " << nFail << endl;

    ::nPass = 0;
    ::nFail = 0;
    //testing relational operator
    test(frac1 < frac2);
    test(frac1 > frac2);
    test(frac1 <= frac2);
    test(frac1 >= frac2);
    test(frac1 != frac2);
    test(frac1 == frac2);
    cout << "Passed test for realtional operator: " << nPass << "\nFailed test for relational operator: " << nFail << endl;

    ::nPass = 0;
    ::nFail = 0;
    //testing relational operator
    Fraction f_excep;
    try{
        cin >> f_excep;
        test(false);
    }catch(logic_error& e){
        test(true);
    }
    cout << "Passed test for exception handlers: " << nPass << "\nFailed test for exception handlers: " << nFail << endl;

}