/*
CH08-320143
a3 p5.cpp
Samundra karki
sa.karki@jacobs-university.de
*/
#ifndef WINDGAUGE_H
#define WINDGAUGE_H
#include <deque>
using namespace std;
class WindGauge {
    public:
        WindGauge(int period = 10);
        void currentWindSpeed(int speed);
        int highest() const;
        int lowest() const;
        int average() const;
    private:
        int period;
        int speed;
        deque<int> deq;
};
#endif