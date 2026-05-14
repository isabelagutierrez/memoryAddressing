#include <iostream>
using namespace std;

int main(){
    cout << "\nActividad 4" << endl;
    //Asignación dinamica de memoria a matriz 2D
    int row = 5;
    int col = 5;
    int **matrix = new int *[row];
    for(int i = 0; i < row; i++){
        matrix[i] = new int[col];
    }

    // Agregar datos a la matriz
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            matrix[i][j] = i + j;
        }
    }

    // Mostrar informacion en la matriz
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << matrix[i][j] << " ";
        } cout << endl;
    }

    // Liberar la memoria con delete
    for(int i = 0; i < row; i++){
        delete[] matrix[i];
    } delete[] matrix;

    return 0;
}