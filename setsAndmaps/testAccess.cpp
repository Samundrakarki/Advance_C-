#include <set>
#include <iostream>
#include "Access.h"

using namespace std;

int main(){
    // Initializing the required args
    Access acc;
    unsigned long code;

    //activating the following codes
    acc.activate(123456);
    acc.activate(999999);
    acc.activate(187692);

    // asking for the input
    cin >> code;
    while(!acc.isactive(code)){
        cout << "Please try again!" << endl;
        cin>> code;
    }
    cout << "Door with code " << code  << " opened successully\n";

    // deactivating and activating some codes as asked by question
    acc.deactivate(code);
    acc.deactivate(999999);
    acc.activate(111111);

    // again asking for the input and checking required condiiton
    cin >> code;
    while(!acc.isactive(code)){
        cout << "Please try again!" << endl;
        cin>> code;
    }
    cout << "Door with code " << code  << " opened successully\n";
}