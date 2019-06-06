/*
CH08-320143
a3 p2.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//printing with index 
void print_index(vector<string> v);

//printing with the iterator
void print_itr(vector<string> v);
int main(){
    vector<string> vec;
    string s;

    //for the first input
    getline(cin, s);

    //check loop - only add if the string is not stop then ask for another input
    while(s.compare("STOP")){
        vec.push_back(s);
        getline(cin, s);
    }
    
    print_index(vec);

    //swapping the elements
    if(vec.size() >= 5){
        vec[1].swap(vec[4]);
    }else{
        cout << "Elements cannot be swapped due to the size problem.";
    }
    print_index(vec);

    //replacing the element. Using replace algorithm class is not possible with string as it replacing caharacters length must be same which is rare
    if(!vec.empty()){
        vec[vec.size()-1] = "?";
    }else{
        cout << "No elements in the array " << endl;
    }
    print_itr(vec);

    //reversing the elements
    reverse(vec.begin(), vec.end());
    print_itr(vec);
    return 0;
}

//prints the with the index
void print_index(vector<string> v){
    for(unsigned int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

//printing with the help of iterator
void print_itr(vector<string> vec){
    unsigned int count2 = 0;
    vector<string>::iterator itr1 = vec.begin();
    vector<string>::iterator itr2 = vec.end(); 

    //loop for the iterator
    for(vector<string>::iterator itr = itr1; itr!=itr2; itr++){
        if(count2 != vec.size()-1){
            cout << *itr << " - ";
        }else{
            cout << *itr << endl;
        }
        count2++;
    }
}