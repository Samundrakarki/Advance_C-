#include <iostream>
#include "Queue.h"

using namespace std;

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

template class Queue<int>;
template class Queue<double>;
template class Queue<char>;
template class Queue<unsigned int>;
