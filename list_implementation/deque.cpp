/*
CH08-320143
a3 p4.cpp
Samundra karki
sa.karki@jacobs-university.de
*/
#include <iostream>
#include <deque>

using namespace std;

int main() {
  deque<double> A;
  double value;
  int count = 0;
  
  cin >> value;
  while (value != 0) {
    if (value > 0){
        A.push_front(value);
        count++;
    }
    else{
        A.push_back(value);
    }
    cin >> value;
  }

  
    for (auto itr = A.begin(); itr != A.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;

    auto itr = A.begin();
    advance(itr, count);
    A.insert(itr, 0);

    unsigned int count2 = 0;
    for(auto itr = A.begin(); itr!=A.end(); itr++){
        if(count2 != A.size()-1){
            cout << *itr << " ; ";
        }else{
            cout << *itr << endl;
        }
        count2++;
  }
  return 0;
}