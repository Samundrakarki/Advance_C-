#include "Access.h"
#include <set>
#include <iostream>

using namespace std;

//inseting the elemetns on the map
void Access :: activate(unsigned long code){
    this->user.insert(code);
}

//deactivating the key element
void Access :: deactivate(unsigned long code){
    this->user.erase(code);
}

//here checking for every code in set and code matches the conditon
bool Access :: isactive(unsigned long code) const{
    if(this->user.count(code)) return true;
    else return false;
}

