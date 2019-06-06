/*
CH08-320143
a1 p2.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include <iostream>
#include <fstream>
#include <string>

#define MAXLEN 100

using namespace std;

int main(){
    //getting the number of files
    int n;
    cin >> n;
    getchar();

    //file streams
    ifstream in_file;
    ofstream out_file;

    out_file.open("concatn.txt", ios::out | ios::binary);
    
    //file name are stored in this variable
    string file_name;
 
    int j = 0;
    while(j < n){
        getline(cin, file_name);

        //opening the file in the binary mode
        in_file.open(file_name, ios::in|ios::binary);
        
        //checking if file exists or not
        if(!in_file.good()){
            cout << "Worng piece of info. write the file name thats in this directory" << endl;
            exit(1);
        }
        
        //to know the size of the file
        in_file.seekg(0, in_file.end);
        int length = in_file.tellg();
        in_file.seekg(0, in_file.beg);

        char *buffer = new char[length+1];

        //reading the file in binary mode
        in_file.read(buffer, length);
        out_file.write(buffer, length) << '\n';
        j++;
        in_file.close();
        delete[] buffer;
    }
    out_file.close();
    return 0;
}
