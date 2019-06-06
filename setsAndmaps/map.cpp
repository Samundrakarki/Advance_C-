/*
CH08-320143
a4 p5.cpp
Samundra karki
sa.karki@jacobs-university.de
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int main(){
    //declaration 
    int marticular_number;
    string name;
    ifstream in;
    string temp;
    //opening the file
    in.open("data.txt", ios::in);
    map<int, string> database;

    //getting the file and storing the required elements by required procedure
    while(getline(in, temp)){
        istringstream iss(temp);
        iss >> marticular_number;
        getline(in, name);
        database[marticular_number] = name;
    }

    //asking for input-- if matches the prints out the corresponding name
    int status = false;
    int temp_marticulation;
    cin >> temp_marticulation;

   if(database.count(temp_marticulation)){
       cout << database.find(temp_marticulation)->second << endl;
       status = true;
   }
    if(!status){
        cerr << "Marticulation numbers not found " << endl;
    }
    return 0;
}

//structure of the file
// 30002122 
// Samundra karki
// 30002123 
// Ankit koirala
// 30002124 
// Aashish paudel
// 30002125 
// Azay shah