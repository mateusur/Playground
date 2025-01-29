#include <iostream>

using namespace std;
int main(){
    int i = 99;
    int* p_i = &i;
    int** pp_i = &p_i;

    cout << "Adress of i: "<< &i << " and value: "<< i <<endl;
    cout << "Adress of p_i: "<< &p_i << " adress of i :"<< p_i <<" and value: "<< *p_i << endl;
    cout << "Adress of pp_i: "<< &pp_i << " adress of another pointer: "<< pp_i <<  " and adress of i:"<< *pp_i <<" and value of i: " <<**pp_i <<endl;


    return 0;
}