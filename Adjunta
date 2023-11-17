#include<iostream>
#include<fstream>
using namespace std;

// Función para leer el tamaño y la matriz desde un archivo de texto
void leerTamanioYMatrizDesdeArchivo(double**& matriz, int& orden, const string& nombreArchivo);

// Función para calcular la matriz adjunta de una matriz cuadrada
void calcularMatrizAdjunta(double** matriz, double** adjunta, int orden);

// Función para calcular la traspuesta de una matriz cuadrada
void calcularMatrizTraspuesta(double** matriz, double** traspuesta, int orden);

// Función para calcular el determinante de una matriz cuadrada
double calcularDeterminante(double** matriz, int orden);

// Función para calcular el determinante de una matriz menor
double determinanteMenor(double** matriz, int orden, int filaExcluir, int columnaExcluir);

// Función para quitar el signo negativo en los ceros
void quitarSignoNegativoCeros(double** matriz, int orden);

int main() {
    double** array = NULL;
    double** adjunta = NULL;
    double** traspuestaAdjunta = NULL;
    int n;

    // Cambios aquí: leer el tamaño y la matriz desde el archivo
    string nombreArchivo = "matriz.txt";
    leerTamanioYMatrizDesdeArchivo(array, n, nombreArchivo);

    // Calcular la matriz adjunta
    adjunta = new double*[n];
    for (int i = 0; i < n; i++) {
        adjunta[i] = new double[n];
    }

    calcularMatrizAdjunta(array, adjunta, n);

    // Quitar el signo negativo en los ceros de la matriz adjunta
    quitarSignoNegativoCeros(adjunta, n);

    // Imprimir la matriz adjunta
    cout << "Matriz adjunta:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjunta[i][j] << " ";
        }
        cout << endl;
    }

    // Calcular la traspuesta de la matriz adjunta
    traspuestaAdjunta = new double*[n];
    for (int i = 0; i < n; i++) {
        traspuestaAdjunta[i] = new double[n];
    }

    calcularMatrizTraspuesta(adjunta, traspuestaAdjunta, n);

    // Imprimir la traspuesta de la matriz adjunta
    cout << "Traspuesta de la matriz adjunta:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << traspuestaAdjunta[i][j] << " ";
        }
        cout << endl;
    }

    // Imprimir el determinante de la matriz
    cout << "Determinante de la matriz: " << calcularDeterminante(array, n) << endl;

    // Liberar la memoria asignada
    for (int i = 0; i < n; i++) {
        delete[] array[i];
        delete[] adjunta[i];
        delete[] traspuestaAdjunta[i];
    }
    
    delete[] array;
    delete[] adjunta;
    delete[] traspuestaAdjunta;

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

void calcularMatrizAdjunta(double** matriz, double** adjunta, int orden) {
    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            // Cofactor para el elemento en la posición (i, j)
            int signo = ((i + j) % 2 == 0) ? 1 : -1;
            adjunta[i][j] = signo * determinanteMenor(matriz, orden, i, j);
        }
    }
}

void calcularMatrizTraspuesta(double** matriz, double** traspuesta, int orden) {
    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            traspuesta[i][j] = matriz[j][i];
        }
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

void quitarSignoNegativoCeros(double** matriz, int orden) {
    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            if (matriz[i][j] == 0) {
                matriz[i][j] = 0;
            }
        }
    }
}
