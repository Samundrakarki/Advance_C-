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
    //testing the tey catch block 
    Fraction f_excep;
    try{
        cin >> f_excep;
        test(false);
    }catch(logic_error& e){
        test(true);
    }
    cout << "Passed test for exception handlers: "
         << nPass << "\nFailed test for exception handlers: " 
         << nFail << endl;

}