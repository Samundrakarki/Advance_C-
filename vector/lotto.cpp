/*
CH08-320143
a4 p2.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include <iostream>
#include <ctime>
#include <set>

using namespace std;

int main(int argc, char** argv){
    //using set is a good option because it doesnot accepts duplicates and arranges the inputs in ascending order
    set<int> set;
    
    //random numbers
    srand(time(NULL));

    //inserting 6 elements
    for(int i = 0; i<6; i++)
        set.insert(((rand()%49) + 1));

    //auto automatically detects its var type i.e looking at the value assigned
    for(auto itr = set.begin(); itr != set.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
    return 0;
}