/*
CH08-320143
a4 p6.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#ifndef ACCESS_H
#define ACCESS_H

#include <map>
using namespace std;

class Access {
    public:
        void activate(unsigned long code, unsigned int level);
        void deactivate(unsigned long code);
        bool isactive(unsigned long code, unsigned int level) const;
    private:
        map<unsigned long, unsigned int> user;
};

#endif