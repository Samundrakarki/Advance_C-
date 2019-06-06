/*
CH08-320143
a2 p3.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include <iostream>
using namespace std;

template <class T>
class Queue{
    private:
        T *arr;
        int rear, front, len;
    public:
        Queue();
        Queue(int length);
        Queue(const Queue&);
        ~Queue();

        bool Enqueue(T data);
        bool Dequeue(T& out);
        T end();
        T start();
        int getNumEntries();

        void resize(int  size);
        int getsize();
};