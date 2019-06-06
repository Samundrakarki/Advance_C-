#include "Access.h"
#include <map>
#include <iostream>

using namespace std;

//inseting the elemetns on the map
void Access :: activate(unsigned long code, unsigned int level){
    this->user.insert(pair<unsigned long, unsigned int>(code, level));
}

//deactivating the key elements
void Access :: deactivate(unsigned long code){
    this->user.erase(code);
}

//here checking for every pair whose level and code matches the conditon
bool Access :: isactive(unsigned long code, unsigned int level) const{
    if(this->user.count(code)){
        if(this->user.find(code)->second > 4)
            return true;
    }
    return false;
}

