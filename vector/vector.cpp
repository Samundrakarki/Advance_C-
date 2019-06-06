/*
CH08-320143
a3 p1.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> vec;
    string s;

    getline(cin, s);

    while(s.compare("stop")){
        vec.push_back(s);
        getline(cin, s);
    }

    for(unsigned int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    //not to print the last element with comma
    unsigned int count2 = 0;
    vector<string>::iterator itr1 = vec.begin();
    vector<string>::iterator itr2 = vec.end(); 

    //loop for the iterator
    for(vector<string>::iterator itr = itr1; itr!=itr2; itr++){
        if(count2 != vec.size()-1){
            cout << *itr << ", ";
        }else{
            cout << *itr << endl;
        }
        count2++;
    }
    return 0;
}