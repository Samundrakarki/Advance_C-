#include <iostream>

using namespace std;

class Trace{
    private:
        static int counter;
        int objId;
    public:
        Trace() {
            objId = counter++;
            cout<< "Constructing trace #" << objId << endl;
            if(objId == 3) throw 3;
        }
        ~Trace(){
            cout << "Destructing the trace#" << endl;
        }
};

int Trace::counter = 0;

int main(){
    try{
        Trace n1;
        // throws an excpetion:
        Trace arr[5];
        Trace n2; //wont get here
    }catch(int i){
        cout << "Caugnt in main : " << i << endl;
    }
}