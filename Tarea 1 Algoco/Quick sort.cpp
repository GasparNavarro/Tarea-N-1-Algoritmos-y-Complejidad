// Implementación y medicición algortimo QUICK SORT:

#include <bits/stdc++.h>
#include <fstream>
#include <chrono>  // Librería para medir el tiempo (en teoria más precisa que time.c)

// REFERENCIA: (https://www.geeksforgeeks.org/cpp-program-for-quicksort/)

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

// Función de partición para Quick Sort
int partition(vector<int> &vec, int low, int high) {
    int pivot = vec[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return (i + 1);
}

// Función de Quick Sort
void quickSort(vector<int> &vec, int low, int high) {
    if (low < high) {
        int p = partition(vec, low, high);
        quickSort(vec, low, p - 1);
        quickSort(vec, p + 1, high);
    }
}

// Función para medir el tiempo de ejecución del algoritmo
void medirTiempoDeEjecucion(vector<int>& arr) {
    auto start = high_resolution_clock::now();

    quickSort(arr, 0, arr.size() - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    
    cout << "Tiempo de ejecucion: " << duration.count() << " milisegundos" << endl;
}

// Función principal que carga y procesa múltiples datasets
int main() {
    // Lista de archivos .txt que contienen los datasets
    vector<string> archivos = {
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

    // Procesar cada archivo
    for (const string& archivo : archivos) {
        cout << "Procesando archivo: " << archivo << endl;

        // Cargar el dataset desde el archivo .txt
        vector<int> arr = cargarArrayDesdeTxt(archivo);

        // Medir el tiempo de ejecución del algoritmo Quick Sort
        medirTiempoDeEjecucion(arr);

        cout << "Finalizado el procesamiento de: " << archivo << endl;
        cout << "--------------------------------------" << endl;
    }

    return 0;
}