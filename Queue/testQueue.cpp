/*
CH08-320143
a2 p2.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include <iostream>
#include "Queue.h"

//defau;t constructor that sets the size of the queue to 10
template <class T>
Queue<T>::Queue() : rear(0), front(0), len(10){
    arr = new T[10];
}

//paratermtized constructor that sets the size of the array
template <class T>
Queue<T>::Queue(int length) : rear(0), front(0), len(length){
    arr = new T[length];
}

//copy constructor
template <class T>
Queue<T>::Queue(const Queue& cpy) : rear(cpy.rear), front(cpy.front), len(cpy.len){}

//destructor that is used to delete the array
template <class T>
Queue<T>::~Queue(){
    delete[] arr;
}

//method to enqueue the elements of desired type
template <class T>
bool Queue<T>:: Enqueue(T data){
    if(len == rear){
        return false;
    }else{
        arr[rear] = data;
        rear++;
        return true;
    }
    return false;
}

//method to dequeu the element
template <class T>
bool Queue<T>:: Dequeue(T& out){
    if(front == rear){
        return false;
    }else{
        out = arr[front];
        for(int i = 0; i < rear -1; i++){
            arr[i]= arr[i + 1];
        }
        //for pointing to last element of the array
        rear--;
        return true;
    }
    return false;
}

template <class T>
T Queue<T> :: end(){
    return arr[rear - 1];
}


template <class T>
T Queue<T> ::start(){
    return arr[front];
}

template<class T>
int Queue<T>::getNumEntries(){
    return rear;
}


int main(){
    Queue<int> que;
    Queue<char> que3(5);

    for(int i= 0; i< 10; i++){
        que.Enqueue(4);
    }
    //Rather than crashing it prints overflow and 0
    cout << que.getNumEntries() << endl;
    if(que.Enqueue(7)){
        cout << "SOmethin wrong with the program" << endl;
    }
    cout << "First element of the array is " << que.start() << endl;
    char out;
    for(int i= 0; i< 5; i++){
        que3.Enqueue('a'+i);
    }
    cout << "Last element of the array is " << que3.end() << endl;
    int j = 0;
    while(j < 9){
        if(que3.Dequeue(out)){
            cout << "Dequeued element is: " << out << endl;
        }
        j++;
    }
    return 0;
}