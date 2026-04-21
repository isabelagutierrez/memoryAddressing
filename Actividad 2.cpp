#include <iostream>
using namespace std;

int main(){
    cout << "\nActividad 2" << endl;
    int var = 10;
    // Puntero a la variable
    int *p = &var;
    // Modificación de la variable mediante el puntero
    *p = 20;

    // Modificacion variable por referencia
    int &ref = var;
    ref = 30;

    cout << "final " << var << endl;
    cout << "Pointer address " << p << endl;
    cout << "Reference address " << &ref << endl;

    return 0;
}