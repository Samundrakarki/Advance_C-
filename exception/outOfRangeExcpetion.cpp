/*
CH08-320143
a5 p1.cpp
Samundra karki
sa.karki@jacobs-university.de
*/
#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char* argv[]){
	vector<char> vec;
	vec.assign(15, '@');
	try{
		vec.at(16);	//this line thorws a out of range exception.
	}catch(out_of_range& oor){
		cerr << "Out of range error: " << oor.what() << endl;
	}
	return 0;
}
