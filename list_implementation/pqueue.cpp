/*
CH08-320143
a3 p6.cpp
Samundra karki
sa.karki@jacobs-university.de
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//setting the priority such that the element that is equal to element prior to that gets the max. priority
class Priority {
public:
  bool operator() (const int& elem1, const int& elem2) {
      if(elem1 == elem2) return true;
      else return false;
  }
};

int main() {

    priority_queue<int, vector<int>, Priority> pq;

    //pushing the elements
    pq.push(5);
    pq.push(4);
    pq.push(9);
    pq.push(5);
    pq.push(5);
    pq.push(3);
    pq.push(2);
    pq.push(1);

    //implementing the function of the priority queue.
    cout << "Size: " << pq.size() << endl;
    if(pq.empty()) cout << "Empty!!" << endl;

    cout << "Elements : ";
    while(! pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    return 0;
}