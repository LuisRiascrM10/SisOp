#include<iostream>
#include<fstream>
using namespace std;

// Función para calcular el determinante de una matriz cuadrada
double calcularDeterminante(double** matriz, int orden);

// Función para calcular el determinante de una matriz menor
double determinanteMenor(double** matriz, int orden, int filaExcluir, int columnaExcluir);

// Función para leer la matriz desde un archivo de texto y obtener su tamaño
void leerTamanioYMatrizDesdeArchivo(double**& matriz, int& orden, const string& nombreArchivo);

int main() {
    //double** array = nullptr;  // Utilizando arrays dinámicos
    double** array = NULL;  // En lugar de nullptr

    int n;

    // Cambios aquí: leer el tamaño y la matriz desde el archivo
    string nombreArchivo = "matriz.txt";
    leerTamanioYMatrizDesdeArchivo(array, n, nombreArchivo);

    // Imprimir el determinante de la matriz
    cout << "Determinante de la matriz: " << calcularDeterminante(array, n) <<" Calculado con Hilo1"<< endl;

    // Liberar la memoria asignada
    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}

void leerTamanioYMatrizDesdeArchivo(double**& matriz, int& orden, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str());

    if (archivo.is_open()) {
        archivo >> orden;  // Leer el tamaño de la matriz desde el archivo

        // Inicializar la matriz con el tamaño leído
        matriz = new double*[orden];
        for (int i = 0; i < orden; i++) {
            matriz[i] = new double[orden];
        }

        // Leer los elementos de la matriz desde el archivo
        for (int i = 0; i < orden; i++) {
            for (int j = 0; j < orden; j++) {
                archivo >> matriz[i][j];
            }
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo '" << nombreArchivo << "'" << endl;
        exit(1);
    }
}

double calcularDeterminante(double** matriz, int orden) {
    if (orden == 1) {
        return matriz[0][0];
    } else if (orden == 2) {
        return (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
    } else {
        double determinante = 0.0;
        for (int i = 0; i < orden; i++) {
            int signo = (i % 2 == 0) ? 1 : -1;
            determinante += signo * matriz[0][i] * determinanteMenor(matriz, orden, 0, i);
        }
        return determinante;
    }
}

double determinanteMenor(double** matriz, int orden, int filaExcluir, int columnaExcluir) {
    int filaDestino = 0;
    int columnaDestino = 0;
    double** menor = new double*[orden - 1];
    for (int i = 0; i < orden - 1; i++) {
        menor[i] = new double[orden - 1];
    }

    for (int fila = 0; fila < orden; fila++) {
        for (int columna = 0; columna < orden; columna++) {
            if (fila != filaExcluir && columna != columnaExcluir) {
                menor[filaDestino][columnaDestino++] = matriz[fila][columna];
                if (columnaDestino == orden - 1) {
                    columnaDestino = 0;
                    filaDestino++;
                }
            }
        }
    }

    double determinante = calcularDeterminante(menor, orden - 1);

    // Liberar memoria asignada para la matriz menor
    for (int i = 0; i < orden - 1; i++) {
        delete[] menor[i];
    }
    delete[] menor;

    return determinante;
}
