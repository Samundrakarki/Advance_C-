
/*
CH08-320143
a1 p3.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include<iostream>
using namespace std;
 
class A
{
    int x;
    public:
        void setX(int i) {x = i;}
        virtual void print() { cout << x << endl; } //endl is added to see the values clearly
};
 
 // another path is to add a virtual keyword, as which print to call this isn't any clear. So, virutal keyword which is used in runtime polymorphism is used to break this ambiguity 
class B:  virtual public A
{
    public:
    B() : A() { setX(10); }

};
 
class C:  public A  
{
    public:
    C()  { setX(20); }
};
 
class D: public B, public C { 
};
 
int main()
{
    D d;
    d.print();
    // d.B::print(); //Here as, both the derived class have print property inherited from A. Complier was confused which print methode to use. so (.B::) excplicty commands to print setting the calue set by default constructor of B
    // d.C::print();
    return 0;
}