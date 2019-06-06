/*
CH08-320143
a1 p4.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include<iostream>
using namespace std;
 
class A
{
  int x;
public:
  A() {}
  A(int i) { x = i; }
  void print() { cout << x; }
};
 
class B: virtual public A
{
public:
  B():A(10) {  }
};
 
class C:  virtual public A 
{
public:
  C():A(10) {  }
};
 //the error was due to not specifying the constructor of the derived class, as it was dervied from two virtual classes. So, we must specify the base class which removed the ambiguity 
class D: public B, public C {
  public:
    D() :A(10) {};
};
 
int main()
{
    D d;
    d.print();
    return 0;
}