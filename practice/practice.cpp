#include <iostream>
#include <exception>

using namespace std;

void terminator(){
    cout << "Iwill be back" << endl;
    exit(0);
}

void (*old_terminate) () = set_terminate(terminator);

class Botch{
    public:
        class Fruit{};
        void f(){
            cout << "Botch::f()" << endl;
            throw Fruit();
        }
        ~Botch() {throw 'c';}
};

int main(){
    try{
        Botch b;
        b.f();
    }catch(...) {
        cout << "inside catch(...)" << endl;
    }
}