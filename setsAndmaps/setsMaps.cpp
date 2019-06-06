/*
CH08-320143
a4 p3.cpp
Samundra karki
sa.karki@jacobs-university.de
*/
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void print_set(set<int> A);
void print_multiset(multiset<int> B);

int main(){
    //declarations
    set<int> A;
    multiset<int> B;
    int n;

    cin >> n;
    //conditions 
    while(n >= 0){
        A.insert(n);
        B.insert(n);
        cin >> n;
    }

    //printing the sets and multisets
    print_set(A);
    cout << endl;
    print_multiset(B);
    cout << endl;

    //eleminating the number 11 from the sets
    A.erase(11);
    B.erase(11);

    print_set(A);
    cout << endl;
    print_multiset(B);
    cout << endl;

    A.insert(5);
    A.insert(421);

    //multi set for the union
    multiset<int> C;
    set_union (A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin()));
    print_multiset(C);

    // multiset for the insection
    multiset<int> D;
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(D, D.begin()));
    print_multiset (D);

    // set for the difference
    set<int> E;
    set_difference (A.begin(), A.end(), B.begin(), B.end(), inserter(E, E.begin()));
    print_set(E);

    // set for the symmetric difference
    set<int> F;
    set_symmetric_difference (A.begin(), A.end(), B.begin(), B.end(), inserter(F, F.begin()));
    print_set(F);
}

// printing the sets
void print_set(set<int> A){
    for(auto itr = A.begin(); itr!=A.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
}

// printing the multisets
void print_multiset(multiset<int> B){
for(auto itr = B.begin(); itr!=B.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
}