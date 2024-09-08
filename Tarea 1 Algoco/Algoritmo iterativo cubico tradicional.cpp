//Implementación y medicición ALGORITMO ITERATIVO CUBICO TRADICIONAL:

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

// Función para multiplicar dos matrices
vector<vector<int>> multiplicarMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int filasA = A.size();
    int columnasA = A[0].size();
    int columnasB = B[0].size();
    
    vector<vector<int>> resultado(filasA, vector<int>(columnasB, 0));
    
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            for (int k = 0; k < columnasA; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return resultado;
}

int main() {
    // Cargar la matriz cuadrada de n x n, con n = 100, 1000, 10000
    string archivoMatrizCuadrada = "matriz_cuadrada_1000x1000.txt";
    vector<vector<int>> matrizCuadrada = cargarMatriz(archivoMatrizCuadrada, 1000, 1000);

    // Cargar la matriz rectangular de n x m, con n = 100, 1000, 10000 y m = 50, 500, 5000
    string archivoMatrizRectangular = "matriz_rectangular_1000x500.txt";
    vector<vector<int>> matrizRectangular = cargarMatriz(archivoMatrizRectangular, 1000, 500);

    // Multiplicar matriz cuadrada con sí misma
    cout << "Multiplicando matriz cuadrada consigo misma 1000x1000" << endl;
    auto start = high_resolution_clock::now();
    vector<vector<int>> resultadoCuadrada = multiplicarMatrices(matrizCuadrada, matrizCuadrada);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Tiempo de ejecución: " << duration.count() << " ms" << endl;

    // Multiplicar matriz cuadrada con matriz rectangular
    cout << "Multiplicando matriz cuadrada con matriz rectangular 1000x1000 X 1000x500" << endl;
    start = high_resolution_clock::now();
    vector<vector<int>> resultadoRectangular = multiplicarMatrices(matrizCuadrada, matrizRectangular);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Tiempo de ejecución: " << duration.count() << " ms" << endl;

    return 0;
}
