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
int main(){

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
    cout << "Passed test for io operator: " 
         << nPass << "\nFailed test for io operator: " 
         << nFail << endl;
}