/*
CH08-320143
a1 p1.cpp
Samundra karki
sa.karki@jacobs-university.de
*/

#include<iostream>
#include <typeinfo>
#include <cmath>

using namespace std;

/*
@breif : return the index of the minimum value of the array
@para T* arr: array of the provided type
    int n: size of the array
*/
template <class T>
int array_min(T* arr, int n);


/*
@breif : prints the minimum value of the array for real numbers
@para T* arr: array of the provided type
    int index: index of the minimim value
*/

template<class T>
void print(T* arr, int index);


/*
@breif : prints the minimum value of the array for complex numbers
@para T* arr: array of the provided type
    int i: index of the minimim value
*/

template <class T>
void print_complex(T* arr, int i);



/*--------------------------------------------------complex.h------------------------------------------------------------------*/

template <class T>
class Complex{
    //declaring the real and imaginary part
    private:
 
        T real_part;
        T imaginary_part;
    public:
       //declaring the constructor and destructor
        Complex();
        Complex(T, T);
        Complex(Complex&);
        ~Complex();

        void setRealPart(T newrealpart);
        void setImgPart(T newimgpart);
 
        //getting real and imaginary part
        T getreal();
        T getimg();

        bool operator<(const Complex);
};

/*----------------------------------------------------------complex.cpp----------------------------------------------------------------*/


//initialinzing the value of real and imiaginary part in default constructor
template <class T>
Complex<T>::Complex(){
    real_part = 0;
    imaginary_part = 0;
}

//initializing the parameter of parameterized constructor in real and imaginamry part
template <class T>
Complex<T>::Complex(T m, T n){ 
    real_part = m;
    imaginary_part = n;
}

//Setting the value of real part
template <class T>
void Complex<T>:: setRealPart(T newrealpart){   
    real_part = newrealpart;
}
//setting the value of img part
template <class T>
void Complex<T>:: setImgPart(T newimgpart){
    imaginary_part = newimgpart;
}


//using getter method to get the real and imiginary part
template <class T>
T Complex<T>::getreal(){       
    return real_part;
}


//Destructor
template <class T>
Complex<T>::~Complex(){      
}
 

//copying the value of the constructor ansd setting it with real and imaginary part
template <class T>
Complex<T>::Complex(Complex& cp){   
    real_part = cp.real_part;
    imaginary_part = cp.imaginary_part;
}

template <class T>
T Complex<T>::getimg(){
    return imaginary_part;
}

//overloading <= operator
template <class T>
bool Complex<T>::operator<(Complex a){
    int abs_val = sqrt((a.real_part*a.real_part) + (a.imaginary_part*a.imaginary_part));
    int abs_val1 = sqrt((real_part*real_part) + (imaginary_part*imaginary_part));
    if(abs_val1 <= abs_val){
        return true;
    }
    else{
        return false;
    }
}



/*------------------------------main.cpp------------------------------------------------------------------*/
int main(){

    //array of different types
    double arr1[] = {1.1 ,2.2 ,3.2 ,4.3 ,5.4 ,0.0, 7.3, 8.5};
    int arr2[] = {2, 3, 4, 5, 1, 7, 8, 1};
    Complex<int> arr_com1[5] = {{1, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 8}};
    Complex<double> arr_com2[5] = { {3.3, 4.4}, {4.4, 5.5},{1.1, 2.2}, {5.5, 6.6}, {7.7, 8.8}};

    //function calls
    int index1 = array_min(arr2, 8);
    print(arr2, index1);
    
    int index2 = array_min(arr1, 8);
    print(arr1, index2);

    int index3 = array_min(arr_com1, 5);
    print_complex(arr_com1, index3);

    int index4 = array_min(arr_com2, 5);
    print_complex(arr_com2, index4);
}


//retrun the min value of the array
template <class T>
int array_min(T* arr, int n){
    int j = 0;
    T min = arr[0];
    for(int i = 1; i < n; i++){
        //<= operator is overloaded
        if(arr[i] < min){
            min = arr[i];
            j = i;
        }    
    }
    return j;
}

//prints the minimum value for real numbers
template<class T>
void print(T* arr, int index){
    if(index >= 0){ 
        cout << "Minimum  of given real numbers array is: " << arr[index] << endl; 
    }
    else{
      cout << "Elements doesnot exsits"<<endl;   
    }
}


//prints the minimum value of the complex numbers array
template <class T>
void  print_complex(T* arr, int i){
    if(i >= 0){
            if(arr[i].getimg()){
                cout << "Minimum of given  complex numbers array is : " << noshowpos << arr[i].getreal() << showpos << arr[i].getimg() << "i" << endl;   
            }
            else{
                cout << "Minimum of given complex numbers array is: "<< arr[i].getreal() << endl;
            }
    }
    else{
        cout << "Elements doesnot exsits" << endl;
    }
}
