#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <cmath>

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

// Función para sumar dos matrices
vector<vector<int>> sumarMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> resultado(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }

    return resultado;
}

// Función para restar dos matrices
vector<vector<int>> restarMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> resultado(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }

    return resultado;
}

// Algoritmo de Strassen para multiplicar matrices
vector<vector<int>> multiplicarStrassen(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();

    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int k = n / 2;
    vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k)), A21(k, vector<int>(k)), A22(k, vector<int>(k));
    vector<vector<int>> B11(k, vector<int>(k)), B12(k, vector<int>(k)), B21(k, vector<int>(k)), B22(k, vector<int>(k));

    // Dividiendo las matrices en submatrices
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Calculando las matrices M1 a M7
    auto M1 = multiplicarStrassen(sumarMatrices(A11, A22), sumarMatrices(B11, B22));
    auto M2 = multiplicarStrassen(sumarMatrices(A21, A22), B11);
    auto M3 = multiplicarStrassen(A11, restarMatrices(B12, B22));
    auto M4 = multiplicarStrassen(A22, restarMatrices(B21, B11));
    auto M5 = multiplicarStrassen(sumarMatrices(A11, A12), B22);
    auto M6 = multiplicarStrassen(restarMatrices(A21, A11), sumarMatrices(B11, B12));
    auto M7 = multiplicarStrassen(restarMatrices(A12, A22), sumarMatrices(B21, B22));

    // Combinando los resultados en la matriz resultado
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + k] = M3[i][j] + M5[i][j];
            C[i + k][j] = M2[i][j] + M4[i][j];
            C[i + k][j + k] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    return C;
}

// Función para redimensionar la matriz a la potencia más cercana de 2
vector<vector<int>> redimensionarMatriz(const vector<vector<int>> &matriz, int nuevoTam) {
    vector<vector<int>> nuevaMatriz(nuevoTam, vector<int>(nuevoTam, 0));

    int filasOriginales = matriz.size();
    int columnasOriginales = matriz[0].size();

    for (int i = 0; i < min(filasOriginales, nuevoTam); i++) {
        for (int j = 0; j < min(columnasOriginales, nuevoTam); j++) {
            nuevaMatriz[i][j] = matriz[i][j];
        }
    }

    return nuevaMatriz;
}

int main() {
    // Cargar la matriz cuadrada 1000x1000
    string archivoMatrizCuadrada = "matriz_cuadrada_1000x1000.txt";
    vector<vector<int>> matrizCuadrada = cargarMatriz(archivoMatrizCuadrada, 1000, 1000);

    // Cargar la matriz rectangular 1000x500
    string archivoMatrizRectangular = "matriz_rectangular_1000x500.txt";
    vector<vector<int>> matrizRectangular = cargarMatriz(archivoMatrizRectangular, 1000, 500);

    // Redimensionar las matrices a la potencia más cercana de 2 si es necesario
    int nuevoTamCuadrada = pow(2, ceil(log2(max(1000, 1000))));
    int nuevoTamRectangular = pow(2, ceil(log2(max(1000, 500))));
    matrizCuadrada = redimensionarMatriz(matrizCuadrada, nuevoTamCuadrada);
    matrizRectangular = redimensionarMatriz(matrizRectangular, nuevoTamRectangular);
    
    
    // Multiplicar matriz cuadrada consigo misma usando Strassen
    cout << "Multiplicando matriz cuadrada consigo misma usando Strassen 1000x1000" << endl;
    auto start = high_resolution_clock::now();
    vector<vector<int>> resultadoCuadrada = multiplicarStrassen(matrizCuadrada, matrizCuadrada);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Tiempo de ejecución: " << duration.count() << " ms" << endl;

    // Multiplicar matriz cuadrada con matriz rectangular usando Strassen
    cout << "Multiplicando matriz cuadrada con matriz rectangular usando Strassen 1000x500" << endl;
    start = high_resolution_clock::now();
    vector<vector<int>> resultadoRectangular = multiplicarStrassen(matrizCuadrada, matrizRectangular);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Tiempo de ejecución: " << duration.count() << " ms" << endl;

    return 0;
}
