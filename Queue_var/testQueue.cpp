/*
CH08-320143
a2 p3.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include <iostream>
#include "Queue.h"

//defau;t constructor that sets the size of the queue to 10
template <class T>
Queue<T>::Queue() : rear(0), front(0), len(10){
    arr = new T;
}

//paratermtized constructor that sets the size of the array
template <class T>
Queue<T>::Queue(int length) : rear(0), front(0), len(length){
    arr = new T;
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

//the maximum number of entried that can be made is the length of the array
template<class T>
int Queue<T>::getsize(){
    return len;
}

//as if dequqing done. As elements are removed from first index unitl the given size is reached.
template <class T>
void Queue<T>::resize(int size){

    if((getsize() > size) && (getNumEntries() > size)){
        //to store the array of minimized size
        T*  temp_arr = new T[size];       

        //index from which the number gets added
        int index =  getNumEntries() - size;

        //copying the elements in new array
        for(int i = 0; i < size; i++){
            temp_arr[i] = arr[index + i];
        }

        //setting the rear agaian and value of array as commanded by question
        rear = rear - index;
        arr = temp_arr;
        
        // to check if the elements are resized or not
        // for(int i = 0; i < size; i++){
        //     cout << arr[i];
        // }
        delete[] temp_arr;
    }
}


int main(){
    Queue<int> que;
    Queue<char> que3(10);

    for(int i= 0; i< 10; i++){
        que.Enqueue(4);
    }
    //Rather than crashing it prints overflow and 0
    cout << que.getNumEntries() << endl;
    if(que.Enqueue(7)){
        cout << "SOmethin wrong with the program" << endl;
    }
    cout << "First element of the array is " << que.start() << endl;
    for(int i= 0; i< 7; i++){
        que3.Enqueue('a'+i);
    }

    //resizing the array
    que3.resize(5);

    //output is 5 because rear is at position 5. 
    cout << que3.getNumEntries() << endl;

    return 0;
}