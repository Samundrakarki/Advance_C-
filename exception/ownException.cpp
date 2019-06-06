/*
CH08-320143
a5 p2.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include<iostream>
#include<exception>
#include<string>

using namespace std;

//creating a class for my own exception
class OwnException : public exception{
	private:
		const char* warn = "This is an OwnExcption";
		string str_;
	public:
		OwnException(){}
		OwnException(string str) : str_(str){}
		virtual ~OwnException(){}

		//overloading the what() method
		virtual const char* what() const throw(){return warn;}
};

//fucntion for throwing specufic exception
void function(int i){
	if(i == 1) {throw 'e';}
	else if(i == 2) {throw 99;}
	else if(i == 3) {throw false;}
	else {throw OwnException("This is default case excpetion");}
}


int main(int argc, char* argv[]){
	//calling the fucntion for the throw and this loop we have catched all the exception.
	for(int i = 1; i < 5 ; i++){
		try{
		   function(i);
		}catch(const char i){
			cerr << "Exception caught in main:  " << i << endl; 
		}catch(const int i){
			cerr << "Exception caught in main:  " << i << endl; 
		}catch(bool i){
			cerr << "Exception caught in main:  " << i << endl; 
		}catch(OwnException i){
			cerr << "Exception caught in main: "  << i.what()  << endl; 
		}
	}
}
