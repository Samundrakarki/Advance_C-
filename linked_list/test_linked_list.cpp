/*
CH08-320143
a1_p4.cpp
Aashish Paudel
a.paudel@jacobs-university.de
*/

#include <iostream>
#include "linked_list.h"

using namespace std;

int main() {
  // Test of different methods for ints
    List <double>list;

        list.push_front(11.1); 
        list.push_front(7.8);
        list.push_back(19.1);
        
        //returns without removing
        cout << list.get_front() << endl;
        cout << list.get_last() << endl;

        //return removing the element at respective position
        cout << list.r_front() << endl;
        cout << list.r_last() << endl;


  return 0;
}