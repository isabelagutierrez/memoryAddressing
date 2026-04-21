#include <iostream>
using namespace std;

int main(){
    cout << "\nActividad 3" << endl;
    int arr[5] = {1, 2, 3, 4, 5};

    // Acceder y modificar elementos con punteros
    int *p = arr;
    for(int i = 0; i < 5; i++){
        *(p + i) *= 5;
    }

    cout << "Array address " << arr << endl;
    cout << "Pointer address " << p << endl;

    return 0;
}