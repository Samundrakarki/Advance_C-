#include <iostream>
using namespace std;

class Base{
    int i;
    public:
        class BaseExcept {};
        Base(int i) : i(i) {throw BaseExcept();}
};

class Derived : public Base{
    public:
        class DerivedExcept {
            const char* msg;
        public:
            DerivedExcept(const char* msg) : msg(msg){}
            const char* what() const{
                return msg;
            }
        };
        Derived(int j) try : Base(j){
            cout << "I am sure this wont print" << endl;
        }catch(Base::BaseExcept& e) {
            throw DerivedExcept("This is an error mother fuker");
        }
};

int main(){
    try{
        Derived D(3);
    }catch(Derived::DerivedExcept& d){
        cout << d.what() << endl;
    }
}
