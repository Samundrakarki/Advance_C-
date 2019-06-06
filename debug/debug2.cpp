/*
CH08-320143
a6 p1.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include <iostream>
#include <sstream>
using namespace std;

/**
 * first : specify break point to main
 * then run the program
 * then go to next
 * found the odd values were not incremented. so modifed the code that would increase the odd values
 * 
 * used command
 * break line_number
 * next
 * 
*/


void foo(int *array, int n, int *odds) {
	for(int i=0; i<n; i++){
		if (array[i] % 2 == 1){
			(*odds)++;
		}
	}
}

class Test {
	private:
		double *a;
		int n;
	public:
		Test() {
			a=NULL;
			n=0;
		}
		Test(double *a, int n) {
			this->n = n;
			if (this->a != NULL) {
				delete this->a;
			}
			this->a = new double[n];
			for(int i=0; i<n; i++)
				this->a[i] = a[i];
		}
		string toString() {
			ostringstream ss;
			ss << "Length: " << n << endl << "Elements: ";
			for(int i=0; i<n; i++)
				ss << a[i] << " ";
			ss << endl;
			return ss.str();
		}
		~Test() {
			delete a;
		}
};
/**
 * From debugger, we found out that until line 64 
 * (obj3->tostring) program did not show any segementation fault
 * so this line must be causing the problem
 * as obj3 is set to point to NULL,
 * so we cannot point access the variable n as it is not allocated
 * so we must either delete it or set its instance that it have n allocated
 * Still the error is not over so, I set the break point in line 86(delete obj1)
 * here, destructor is deleting the instances of objs ans agian same obj is trying
 * to be deleted in main function
 * so I commented out the delete keywors
 * 
 * 
 * commands used
 * g++ filename.cpp -g
 * gdb a.out --tui
 * break line_number
 * next
 * print
 * 
 * 
*/


int main() {
	int array[3] = {1, 2, 3};
	int odd_values=0;
	foo(array, 3, &odd_values);
	cout << "Amount of odd values in the array=" << odd_values << endl;
	Test arr[5];
	double v[3] = {1.2, 2.3, 3.45};
	Test *obj1;
	obj1=&arr[0];
	Test *obj2 = new Test(v, 3);
	// Test *obj3 = NULL;
	cout << obj1->toString();
	cout << obj2->toString();
	// cout << obj3->toString();
	// delete obj1;
	// delete obj2;
	// delete obj3;
	return 0;
}