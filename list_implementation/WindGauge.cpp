#include <iostream>
#include <deque>
#include "WindGauge.h"
#include <algorithm>

using namespace std;

//if called with the pararmter then we can intialize the period wich is a private member
WindGauge::WindGauge(int period){
    this->period = period;
}

//erasing the elements if the
void WindGauge::currentWindSpeed(int speed){
    if(this->deq.size() == 10){
        this->deq.erase(this->deq.begin());
    }
    this->deq.push_back(speed);
}

//returns the highest element
int WindGauge::highest() const {
    return *max_element((this->deq).begin(), (this->deq).end());
}

//returns the lowest element 
int WindGauge::lowest() const {
    return *min_element((this->deq).begin(), (this->deq).end());
}

//retrun the average
int WindGauge::average() const {
    int sum = 0, avg;
    for (auto itr = this->deq.begin(); itr != this->deq.end(); itr++)
        sum += *itr;
    avg = sum / this->deq.size();
    return avg;
}