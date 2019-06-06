#include <iostream>
#include <cstdio>
#include <exception>
using namespace std;

// Exception classes
class A {};
class B {};

// Terminate() handler
void my_thandler(){
    cout << "terminate called" << endl;
    exit(0);
}

// unexpected() handlers
void my_uhandler1() {throw A();}
void my_uhandler2() {throw;}

void t() {throw B(); }

void f() throw(A) { t();}  
void g() throw(A, bad_exception) { t() ;}

int main() {
    set_terminate(my_thandler); //ignores the return values
    set_unexpected(my_uhandler1); //ignores the return values

    //my_uhandler1 will throw exception type A() in this function
    try{
        f();
    }catch(A&){
        cout << "caught an A from f" << endl;
    }

    //my_handler2 throws the default expcetion handler expected when a function throws an unexpected error
    set_unexpected(my_uhandler2);
    try{
        g();
    }catch(bad_exception&){
        cout << "caught a bad exception from g" << endl;
    }
    try{
        f();
    }catch(...){
        cout << "this will never be printed" << endl;
    }
}