/*
CH08-320143
a6 p1.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include <exception>

using namespace std;

class Fraction {
    private:
        int num;
        int de_num;
    public:
        Fraction();
        Fraction(const Fraction&);
        Fraction(int , int);
        Fraction(string);

    //overload all relational operator
    bool operator<(const Fraction&);
    bool operator>(const Fraction&);
    bool operator<=(const Fraction&);
    bool operator>=(const Fraction&);
    bool operator==(const Fraction&);
    bool operator!=(const Fraction&);

    //overload all arthemetic operators
    Fraction operator+(const Fraction&);
    Fraction operator-(const Fraction&);
    Fraction operator*(const Fraction&);
    Fraction operator/(const Fraction&);
    Fraction operator=(const Fraction&);

    //overload io stream operatros
    friend ostream& operator<<(ostream&,  const Fraction&);
    friend istream& operator>>(istream&, Fraction&);
};

//extending the class of logical error 
class LException: public logic_error{
    public:
        LException(string str): logic_error(str){};
};