// Implementación y medicición algortimo SELECTION SORT:

#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>

// Load an array from a .txt file
std::vector<int> cargarArrayDesdeTxt(const std::string& filename) {
    std::vector<int> arr;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return arr;
    }
    int value;
    while (file >> value) {
        arr.push_back(value);
    }
    file.close();
    return arr;
}

//Algoritmo Selection Sort (https://www.geeksforgeeks.org/selection-sort-algorithm-2/)
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            std::swap(arr[min_idx], arr[i]);
    }
}

// Medicion del algoritmo y sus tiempos de ejecución
void medirTiempoDeEjecucion(std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    selectionSort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0; // Convert milliseconds to seconds
    std::cout << "Tiempo de ejecucion: " << elapsed << " segundos" << std::endl;
}

// Main
int main() {

    //Vector para arreglos, ordenado, desordenado y semidesordenado
    std::vector<std::string> archivos = {
        "array_ordenado_10^2.txt",
        "array_semiordenado_10^2.txt",
        "array_desordenado_10^2.txt"
    };

    // se sigue el siguiente formato para traer .txt con datos, donde solo cambia el 10^n por nombre,
    // con n = 2,4,6 respectivamente. Para cada caso de prueba se modifica solo el nombre, tal de no 
    // tener que hacer más codigo adicional.

    //"array_ordenado_10^6.txt",
    //"array_semiordenado_10^6.txt",
    //"array_desordenado_10^6.txt"

    //aplicar selectionSort para cada uno de los datasets
    for (const std::string& archivo : archivos) {
        std::cout << "Procesando archivo: " << archivo << std::endl;
        std::vector<int> arr = cargarArrayDesdeTxt(archivo);
        medirTiempoDeEjecucion(arr);
        std::cout << "Ordenamiento completado para: " << archivo << std::endl;
        std::cout << "--------------------------------------" << std::endl;
    }

    return 0;
}