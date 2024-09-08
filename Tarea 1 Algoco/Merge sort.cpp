// Implementación y medicición algortimo MERGE SORT:

#include <bits/stdc++.h>
#include <fstream>
#include <chrono>  // Librería para medir el tiempo

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

//REFERENCIA: (https://www.geeksforgeeks.org/cpp-program-for-merge-sort/)

// Función para mergear dos subarrays de array[]
void merge(int array[], int const left, int const mid, int const right) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Crear arrays temporales
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copiar datos a los arrays temporales
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
         indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Mergear los arrays temporales de vuelta en array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copiar los elementos restantes de leftArray[], si hay alguno
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copiar los elementos restantes de rightArray[], si hay alguno
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

// Función de ordenamiento Merge Sort
void mergeSort(int array[], int const begin, int const end) {
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// Función para medir el tiempo de ejecución del algoritmo
void medirTiempoDeEjecucion(vector<int>& arr) {
    // Convertir vector a array para usar con mergeSort
    int* arr_data = arr.data();
    int n = arr.size();
    
    // Medir tiempo de inicio
    auto start = high_resolution_clock::now();

    // Ejecutar Merge Sort
    mergeSort(arr_data, 0, n - 1);

    // Medir tiempo de finalización
    auto stop = high_resolution_clock::now();

    // Calcular la duración
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

        // Medir el tiempo de ejecución del algoritmo Merge Sort
        medirTiempoDeEjecucion(arr);

        cout << "Ordenamiento completado para: " << archivo << endl;
        cout << "--------------------------------------" << endl;
    }

    return 0;
}
