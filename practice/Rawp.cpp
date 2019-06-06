#include <iostream>
#include <cstddef>
using namespace std;

template <class T, int sz =1> 
class PWrap{
    T* ptr;
    public:
        class RangeError {}; //exception class
        PWrap(){
            ptr = new T[sz];
            cout << "PWrap constructor called" << endl;
        }
        ~PWrap() {
            delete[] ptr;
            cout << "PWrao destrucotr" << endl;
        }
        T& operator[](int i)throw (RangeError){
            if(i >= 0 && i < sz) return ptr[i];
            throw RangeError();
        }
};

class Cat{
    public:
        Cat() {cout << "Cat()" << endl;}
        ~Cat() {cout << "~Cat()" << endl;}
        void g(){}
};

class Dog{
    public:
    // Dog() {cout << "Dog()" << endl;}
    // ~Dog() {cout << "~Dog()" << endl;}
    void* operator new(size_t sz){
        cout << "allocating a Dog"<< endl;
        throw 47;
    }
    void operator delete(void* p){
        cout << "deallocating a Dog" << endl;
        ::operator delete(p);
    }
};

class UseResources {
    PWrap<Cat, 3> cats;
    PWrap<Dog> dog;
    public:
        UseResources(){
            cout << "Useresources()" << endl;
        }
        ~UseResources(){
            cout << "~UserResourses()" << endl;
        }
        void f() {cats[1].g();}
};

int main(){
    try{
        UseResources ur;
    }catch(int){
        cout << "inside handler now bitch().." << endl;
    }catch(...){
        cout << "inside elipses catch mf().. "<< endl;
    }
}