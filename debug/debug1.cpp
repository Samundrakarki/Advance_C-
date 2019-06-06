/*
CH08-320143
a6 p1.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include <iostream>
using namespace std;
/**
 * Using GDB to find the error
 * with command g++ -g -o exe filename.cpp we opened the file in debugging mode
 * while running the program we found out that there is no problem with find fucntion as it doesnot produce desired output 
 *
 * used command
 * break main
 * run
 * next
 * 
*/


int find(int a[], int nr, int el) {
	for(int i=0; i<=nr; i++)
		if (a[i] == el)
			return i;
	return -1;
}

/**
 * Using GDB to find the error
 * with command g++ -g -o exe filename.cpp we opened the file in debugging mode
 * while running the program we found out that there is no problem with find fucntion as it doesnot produce desired output 
 * used run command to run the program
 *  the output for the difference was 18446744073709551611
 * this is because of the unsigned value doesnot take negative value 
 * so I changed all unsigned long value to long type of value.
 * 
*/
 long difference(long a, long b) {
	if (a-b < 0)
		return b-a;
	else
		return a-b;
}

int main() {
	int n, val;
	cout << "n=";
	cin >> n;
	int *v=new int[n];
	cout << "Elements the elements of array:" << endl;
	for(int i=0; i<n; i++)
		cin >> v[i];
	cout << "val=";
	cin >> val;
	int result = find(v, n, val);
	cout << "Position of the searched element=" << result << endl;
	delete v;
	long x, y;
	x=550000;
	y=550005;
	cout << "Difference=" << difference(x, y) << endl;
	return 0;
}