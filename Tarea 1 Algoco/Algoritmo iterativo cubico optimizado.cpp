//Implementación y medicición ALGORITMO ITERATIVO CUBICO OPTIMIZADO:

#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Función para cargar una matriz desde un archivo de texto
vector<vector<int>> cargarMatriz(const string &archivo, int filas, int columnas) {
    ifstream file(archivo);
    vector<vector<int>> matriz(filas, vector<int>(columnas));

    if (file.is_open()) {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                file >> matriz[i][j];
            }
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo: " << archivo << endl;
    }

    return matriz;
}

// Función para transponer una matriz
vector<vector<int>> transponerMatriz(const vector<vector<int>> &matriz) {
    int filas = matriz.size();
    int columnas = matriz[0].size();
    vector<vector<int>> transpuesta(columnas, vector<int>(filas));

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }

    return transpuesta;
}

// Función para multiplicar dos matrices con la segunda transpuesta
vector<vector<int>> multiplicarMatricesTranspuesta(const vector<vector<int>> &A, const vector<vector<int>> &B_T) {
    int filasA = A.size();
    int columnasA = A[0].size();
    int columnasB = B_T.size(); // Ya que B_T es la transpuesta, sus filas son las columnas originales de B

    vector<vector<int>> resultado(filasA, vector<int>(columnasB, 0));

    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            for (int k = 0; k < columnasA; k++) {
                resultado[i][j] += A[i][k] * B_T[j][k];
            }
        }
    }

    return resultado;
}

int main() {
    // Cargar la matriz cuadrada de 100x100
    string archivoMatrizCuadrada = "matriz_cuadrada_1000x1000.txt";
    vector<vector<int>> matrizCuadrada = cargarMatriz(archivoMatrizCuadrada, 1000, 1000);

    // Cargar la matriz rectangular de 100x500
    string archivoMatrizRectangular = "matriz_rectangular_1000x500.txt";
    vector<vector<int>> matrizRectangular = cargarMatriz(archivoMatrizRectangular, 1000, 500);

    // Transponer la matriz rectangular
    vector<vector<int>> matrizRectangularT = transponerMatriz(matrizRectangular);

    // Multiplicar matriz cuadrada consigo misma
    cout << "Multiplicando matriz cuadrada consigo misma 1000x1000" << endl;
    auto start = high_resolution_clock::now();
    vector<vector<int>> resultadoCuadrada = multiplicarMatricesTranspuesta(matrizCuadrada, transponerMatriz(matrizCuadrada));
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Tiempo de ejecución: " << duration.count() << " ms" << endl;

    // Multiplicar matriz cuadrada con matriz rectangular transpuesta
    cout << "Multiplicando matriz cuadrada con matriz rectangular transpuesta 1000x500" << endl;
    start = high_resolution_clock::now();
    vector<vector<int>> resultadoRectangular = multiplicarMatricesTranspuesta(matrizCuadrada, matrizRectangularT);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Tiempo de ejecución: " << duration.count() << " ms" << endl;

    return 0;
}
