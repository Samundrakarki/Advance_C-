/*
CH08-320143
a4 p1.cpp
Samundra karki
sa.karki@jacobs-university.de
*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//printing with the iterator
void print_itr(vector<char> vec);

int main(){
    vector<char> vec;
    for(int i = 0; i < 26; i++){
        vec.push_back('a'+i);
    }
    print_itr(vec);

    //reversing the elements
    reverse(vec.begin(), vec.end());
    print_itr(vec);

    //replace the elements after adding 'f'
    vec.push_back('f');
    replace(vec.begin(), vec.end(), 'f', '$');
    print_itr(vec);
}

//printing with the help of iterator
void print_itr(vector<char> vec){
    unsigned int count2 = 0;
    vector<char>::iterator itr1 = vec.begin();
    vector<char>::iterator itr2 = vec.end(); 

    //loop for the iterator
    for(vector<char>::iterator itr = itr1; itr!=itr2; itr++){
        if(count2 != vec.size()-1){
            cout << *itr << " ";
        }else{
            cout << *itr << endl;
        }
        count2++;
    }
}