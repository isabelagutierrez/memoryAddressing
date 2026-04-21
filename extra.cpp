#include <iostream>
using namespace std;

int global = 0;

int main(){
    cout << "\nExtra" << endl;
    int local = 1;
    int *heap = new int(5);

    cout << "Global " << &global << endl;
    cout << "Local " << &local << endl;
    cout << "Heap " << heap << endl;

    delete heap;
    cout << endl;
    return 0;
}