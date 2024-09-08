Readme - Tarea N° 1 Algoritmos y Complejidad - Gaspar Navarro Cornejo

El repositorio cuenta con un conjunto de datasets con extensión .txt, donde están almacenadas listas y matrices. Tambien se encuentran los códigos desarrollados de los algoritmos
de ordenamiento, creados en el lenguaje c++ (Selection Sort, Merge Sort, Quick Sort, Sort) y algoritmos de multiplicación de matrices (cubico tradicional, cubico optimizado y Strassen).

Cada uno de los archivos .cpp contiene un algoritmo de ordenamiento o multiplicacion, tal como lo indica su nombre. 

El codigo fue realizado en un entorno Linux, en el lenguaje C++ como fue mencionado anteriormente.

Instalación:

Clonar el repositorio con los siguientes comandos a ejecutar en la cdm:

1- cd Escritorio // Dirección donde guardar el repositorio
2- git clone https://github.com/GasparNavarro/Tarea-N-1-Algoritmos-y-Complejidad/tree/79da12554d5d06c18e922f70d93e01b6baf95de6

Uso:

- Cada uno de los archivos de algoritmos con extensión .cpp debe ejecutarse.
- Es importante recalcar, que el cambio al tipo de archivo a procesar por el algoritmo es manual,
  es decir, se debe modificar la siguiente parte de cada codigo, y solo cambia el nombre del
  archivo a procesar, de igual manera, estas indicaciones vienen incluidas en el codigo y sus respectivos
  comentarios. A continuacion, un ejemplo:

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
