#include <iostream>
#include <algorithm>
#include <deque>
#include "WindGauge.h"

void print(WindGauge wg);

int main() {

    //instance of class 
    WindGauge wind;

    wind.currentWindSpeed(14);
    wind.currentWindSpeed(16);
    wind.currentWindSpeed(13);
    wind.currentWindSpeed(15);
    wind.currentWindSpeed(15);

    print(wind);

    wind.currentWindSpeed(15);
    wind.currentWindSpeed(17);
    wind.currentWindSpeed(17);
    wind.currentWindSpeed(16);
    wind.currentWindSpeed(20);
    wind.currentWindSpeed(16);
    wind.currentWindSpeed(20);

    print(wind);
    return 0;
}

//dummy function to print the requred entites
void print(WindGauge wg) {
  cout << "Highest speed in your location is " << wg.highest() << endl;
  cout << "Lowest speed in your location is " << wg.lowest() << endl;
  cout << "Average speed in your location is " << wg.average() << endl;
}