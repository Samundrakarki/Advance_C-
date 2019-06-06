/*
CH08-320143
a3 p3.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <fstream>

int main(){
    std::list<int> A;
    std::list<int> B;
    std::ofstream out; 
    int x;

    //getting the input from user 
    std::cin >> x; 
    while( x > 0){
        A.push_front(x);
        B.push_back(x);
        std::cin >> x;
    }

    //printing in the console
    for(auto itr = A.begin(); itr != A.end(); ++itr){
        std::cout << *itr << " ";
    }
    std::cout<< "\n";


    //opening the file for the transferring the requred elements
    out.open("listB.txt", std::ios::out);

    std::reverse(B.begin(), B.end());

    if(!out.good()){
        std::cerr << "File could not be opened\n";
    }
    for(auto itr = B.begin(); itr != B.end(); ++itr){
        out << *itr << " ";
    }
    out.close();
    std::reverse(B.begin(), B.end());
    
    std::cout << std::endl;


    //taking the last element to the first in the list
    auto itr = A.begin(); 
    std::advance(itr, A.size() -1);
    A.splice(A.begin(), A, itr);

    unsigned int count = 0;
    for(auto itr = A.begin(); itr != A.end(); ++itr){
        if(count == A.size() - 1){
            std::cout << *itr << "\n";    
        }else{
            std::cout << *itr << ", ";
        }
        count++;
    }
    
    auto itr1 = B.begin(); 
    std::advance(itr1, B.size() -1);
    B.splice(B.begin(), B, itr1);

    unsigned int count1 = 0;
    for(auto itr = B.begin(); itr != B.end(); ++itr){
        if(count1 == B.size() - 1){
            std::cout << *itr << "\n";    
        }else{
            std::cout << *itr << ", ";
        }
        count1++;
    }

    A.merge(B);
    B.sort();
    unsigned int count2 = 0;
    for(auto itr = A.begin(); itr != A.end(); ++itr){
        if(count2 == A.size() - 1){
            std::cout << *itr << "\n";    
        }else{
            std::cout << *itr << ", ";
        }
        count2++;
    }
    
    return 0;
}