// Implementación y medición del algoritmo SORT de la biblioteca estándar de C++

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>  // Librería para medir el tiempo
#include <algorithm>  // Para std::sort

using namespace std;
using namespace std::chrono;

// Función para cargar un array desde un archivo .txt
vector<int> cargarArrayDesdeTxt(const string& filename) {
    vector<int> arr;
    ifstream file(filename);
    int value;
    while (file >> value) {
        arr.push_back(value);
    }
    file.close();
    return arr;
}

// Función para aplicar sort
void aplicarSort(vector<int>& vec) {
    // Aplica sort para ordenar todo el array
    sort(vec.begin(), vec.end());
}

// Función para medir el tiempo de ejecución del algoritmo
void medirTiempoDeEjecucion(vector<int>& arr) {
    auto start = high_resolution_clock::now();

    aplicarSort(arr);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    
    cout << "Tiempo de ejecucion: " << duration.count() << " milisegundos" << endl;
}

// Función principal que carga y procesa múltiples datasets
int main() {
    // Lista de archivos .txt que contienen los datasets
    vector<string> archivos = {
        "array_ordenado_10^6.txt",
        "array_semiordenado_10^6.txt",
        "array_desordenado_10^6.txt"
    };

    // Se sigue el siguiente formato para traer .txt con datos, donde solo cambia el 10^n por nombre,
    // con n = 2,4,6 respectivamente. Para cada caso de prueba se modifica solo el nombre, tal de no 
    // tener que hacer más código adicional.

    //"array_ordenado_10^6.txt",
    //"array_semiordenado_10^6.txt",
    //"array_desordenado_10^6.txt"

    // Procesar cada archivo
    for (const string& archivo : archivos) {
        cout << "Procesando archivo: " << archivo << endl;

        // Cargar el dataset desde el archivo .txt
        vector<int> arr = cargarArrayDesdeTxt(archivo);

        // Medir el tiempo de ejecución del algoritmo sort
        medirTiempoDeEjecucion(arr);

        cout << "Finalizado el procesamiento de: " << archivo << endl;
        cout << "--------------------------------------" << endl;
    }

    return 0;
}

