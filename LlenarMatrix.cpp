#include<iostream>
#include<fstream>
using namespace std;

int main() {
    int n;
    cout << "Ingresar rango de la matriz -> ";
    cin >> n;

    double** array = new double*[n];
    for (int i = 0; i < n; ++i) {
        array[i] = new double[n];
    }

    cout << "Rellene la matriz" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> array[i][j];
        }
    }

    cout << "Matriz ingresada" << endl << endl;

    // Mostrar la matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    // Guardar la matriz en un archivo
    ofstream archivo("matriz.txt");
    if (archivo.is_open()) {
        archivo << n << endl;  // Guardar el tamaño de la matriz en la primera línea

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                archivo << array[i][j] << " ";
            }
            archivo << endl;
        }
        archivo.close();
        cout << "Matriz guardada en 'matriz.txt'" << endl;
    } else {
        cout << "No se pudo abrir el archivo 'matriz.txt'" << endl;
    }

    // Liberar la memoria asignada
    for (int i = 0; i < n; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
