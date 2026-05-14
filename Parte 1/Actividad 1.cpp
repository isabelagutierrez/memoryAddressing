#include <iostream>
using namespace std;

int main(){
    cout << "\nActividad 1" << endl;
    // Se asigna una variable entera
    int var = 10;
    cout << "Current value " << var << endl; 
    cout << "Memory address " << &var << endl;

    // Se modifica el valor utilizando punteros
    int *p = &var;
    *p = 20;
    cout << "New value " << var << endl;
    cout << "Memory address " << &var << endl;

    return 0;
}