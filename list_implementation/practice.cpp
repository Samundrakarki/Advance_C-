/*
CH08-320143
a3_p5.cpp
Aashish Paudel
a.paudel@jacobs-university.de
*/

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

#include <deque>

class WindGauge {
 public:
  WindGauge(int period = 12);
  void currentWindSpeed(int);
  int highest() const;
  int lowest() const;
  int average() const;
 private:
  int period;
  int size;
  deque<int> history;
};


WindGauge::WindGauge(int period) {
  (this->period) = period;
}

void WindGauge::currentWindSpeed(int speed) {
  if (this->history.size() == 12) 
    this->history.erase(this->history.begin());
  this->history.push_back(speed);
}

int WindGauge::highest() const {
  return *max_element((this->history).begin(), (this->history).end());
}

int WindGauge::lowest() const {
  return *min_element((this->history).begin(), (this->history).end());
}

int WindGauge::average() const {
  int sum = 0;

  for (auto it = (this->history).begin(); it != (this->history).end(); it++)
    sum += *it;

  return sum/(this->history).size();
}


void dump(WindGauge);

int main() {
  WindGauge wg;

  wg.currentWindSpeed(15);
  wg.currentWindSpeed(16);
  wg.currentWindSpeed(12);
  wg.currentWindSpeed(15);
  wg.currentWindSpeed(15);

  dump(wg);

  wg.currentWindSpeed(16);
  wg.currentWindSpeed(17);
  wg.currentWindSpeed(16);
  wg.currentWindSpeed(16);
  wg.currentWindSpeed(20);
  wg.currentWindSpeed(17);
  wg.currentWindSpeed(16);
  wg.currentWindSpeed(15);
  wg.currentWindSpeed(16);
  wg.currentWindSpeed(20);

  dump(wg);
  
  return 0;
}

void dump(WindGauge wg) {
  cout << "Highest speed: " << wg.highest() << endl;
  cout << "Lowest speed: " << wg.lowest() << endl;
  cout << "Average speed: " << wg.average() << endl;
}