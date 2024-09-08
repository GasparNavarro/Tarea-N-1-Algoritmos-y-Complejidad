//Creacion de datasets y matrices 

#include <bits/stdc++.h>

// Función para generar un array ordenado
std::vector<int> generarArrayOrdenado(size_t n) {
    std::vector<int> arr(n);
    for (size_t i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }
    return arr;
}

// Función para generar un array semiordenado
std::vector<int> generarArraySemiordenado(size_t n) {
    std::vector<int> arr = generarArrayOrdenado(n);
    std::random_shuffle(arr.begin() + n / 2, arr.end());
    return arr;
}

// Función para generar un array más desordenado que el semiordenado
std::vector<int> generarArrayDesordenado(size_t n) {
    std::vector<int> arr = generarArrayOrdenado(n);
    std::random_shuffle(arr.begin() + n / 4, arr.end());
    std::random_shuffle(arr.begin(), arr.end());
    return arr;
}

// Función para guardar un array en un archivo .txt
void guardarArrayEnTxt(const std::vector<int>& arr, const std::string& filename) {
    std::ofstream file(filename);
    for (int num : arr) {
        file << num << "\n";
    }
    file.close();
}

// Función para generar una matriz cuadrada
std::vector<std::vector<int>> generarMatrizCuadrada(size_t n) {
    std::vector<std::vector<int>> matriz(n, std::vector<int>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            matriz[i][j] = rand() % 1000;  // Números aleatorios entre 0 y 999999
        }
    }
    return matriz;
}

// Función para generar una matriz de dimensiones m x n
std::vector<std::vector<int>> generarMatrizRectangular(size_t m, size_t n) {
    std::vector<std::vector<int>> matriz(m, std::vector<int>(n));
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            matriz[i][j] = rand() % 1000;  // Números aleatorios entre 0 y 999999
        }
    }
    return matriz;
}

// Función para guardar una matriz en un archivo .txt
void guardarMatrizEnTxt(const std::vector<std::vector<int>>& matriz, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& fila : matriz) {
        for (int num : fila) {
            file << num << " ";
        }
        file << "\n";
    }
    file.close();
}

int main() {
    srand(time(0)); // Inicializa la semilla para la generación de números aleatorios

    // Generación de un array de tamaño 10^N, donde n = 2,4,6 para la generación de datos.
    size_t tamanio = 10000;
    
    auto arrOrdenado = generarArrayOrdenado(tamanio);
    guardarArrayEnTxt(arrOrdenado, "array_ordenado_10^4.txt");

    auto arrSemiordenado = generarArraySemiordenado(tamanio);
    guardarArrayEnTxt(arrSemiordenado, "array_semiordenado_10^4.txt");

    auto arrDesordenado = generarArrayDesordenado(tamanio);
    guardarArrayEnTxt(arrDesordenado, "array_desordenado_10^4.txt");
    
    // Generación de una matriz cuadrada de tamaño 1000 x 1000 
    // En realidad es matriz n x n, donde n = 100, 1000
    size_t matriz_tamanio = 10000;
    auto matrizCuadrada = generarMatrizCuadrada(matriz_tamanio);
    guardarMatrizEnTxt(matrizCuadrada, "matriz_cuadrada_1000x1000.txt");

    // Generación de una matriz rectangular de tamaño 1000 x 500
    // En realidad es matriz n x n, donde n = 100, 1000 y n = 50, 500
    size_t m = 1000;
    size_t n = 500;
    auto matrizRectangular = generarMatrizRectangular(m, n);
    guardarMatrizEnTxt(matrizRectangular, "matriz_rectangular_1000x500.txt");

    return 0;
}