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
    //testing relational operator
    test(frac1 < frac2);
    test(frac1 > frac2);
    test(frac1 <= frac2);
    test(frac1 >= frac2);
    test(frac1 != frac2);
    test(frac1 == frac2);
    cout << "Passed test for realtional operator: " 
         << nPass << "\nFailed test for relational operator: " 
         << nFail << endl;
}