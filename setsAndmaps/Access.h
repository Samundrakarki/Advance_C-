/*
CH08-320143
a4 p4.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#ifndef ACCESS_H
#define ACCESS_H

#include <set>
using namespace std;

class Access {
    public:
        void activate(unsigned long code);
        void deactivate(unsigned long code);
        bool isactive(unsigned long code) const;
    private:
        set<unsigned long> user;
};

#endif