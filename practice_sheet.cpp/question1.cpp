#include <iostream>
using namespace std;

template <class T>
T sumArray(T* arr, int size){
    T sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}
int main(){
    int inum[5] = {10, 20, 30, 40, 50};
    double dnum[5] = {1.1, 1.2, 1.3, 1.4, 1.5};
    cout << "Sum of inum is: " << sumArray(inum, 5) << endl;
    cout << "Sum of dnum is: " << sumArray(dnum, 5) << endl;
}