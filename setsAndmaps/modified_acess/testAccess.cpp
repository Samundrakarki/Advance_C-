#include <map>
#include <iostream>
#include "Access.h"

using namespace std;

int main(){
    // Initialzing the requires arguments
    Access acc;
    unsigned long code;

    acc.activate(123456, 1);
    acc.activate(999999, 5);
    acc.activate(187692, 9);

    cin >> code;

    while(!acc.isactive(code, 5)){
        cout << "Please try again!" << endl;
        cin>> code;
    }
    cout << "Door with code " << code  << " opened successully\n";

    acc.deactivate(code);

    //if it was not deactivated then first I have deactivated it then activated it to change the level
    if(acc.isactive(999999, 5)){
        acc.deactivate(999999);
    }
    acc.activate(999999, 8);
    acc.activate(111111, 7);

    
    cin >> code;

    // asking the for the input and if it matches the condition then opening the door
    while(!acc.isactive(code, 7)){
        cout << "Please try again!" << endl;
        cin>> code;
    }
    cout << "Door with code " << code  << " opened successully\n";

}