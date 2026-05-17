#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Algoritmos Ordenamiento/insertSort.h"

using namespace std;

void printArray(int *arr, int size) {

    for (int i = 0; i < size; i++) {

        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    srand(time(NULL));

    const int SIZE = 100;

    // -----------------------------------------------------
    // ARRAY ALEATORIO
    // -----------------------------------------------------
    int aleatorio[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        aleatorio[i] = rand() % 1000;
    }

    cout << "========================================" << endl;
    cout << "ARRAY ALEATORIO" << endl;
    cout << "========================================" << endl;

    cout << "Array original:" << endl;
    printArray(aleatorio, SIZE);

    unsigned long long compAleatorio =
            insertSort(aleatorio, SIZE);

    cout << endl;
    cout << "Array ordenado:" << endl;
    printArray(aleatorio, SIZE);

    cout << endl;
    cout << "Comparaciones realizadas: "
         << compAleatorio << endl;

    cout << endl << endl;

    // -----------------------------------------------------
    // ARRAY ORDENADO DE MENOR A MAYOR - mejor caso
    // -----------------------------------------------------
    int ascendente[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        ascendente[i] = i + 1;
    }

    cout << "========================================" << endl;
    cout << "ARRAY ORDENADO ASCENDENTE - MEJOR ESCENARIO" << endl;
    cout << "========================================" << endl;

    cout << "Array original:" << endl;
    printArray(ascendente, SIZE);

    unsigned long long compAscendente =
            insertSort(ascendente, SIZE);

    cout << endl;
    cout << "Array ordenado:" << endl;
    printArray(ascendente, SIZE);

    cout << endl;
    cout << "Comparaciones realizadas: "
         << compAscendente << endl;

    cout << endl << endl;

    // -----------------------------------------------------
    // ARRAY ORDENADO DE MAYOR A MENOR - peor caso
    // -----------------------------------------------------
    int descendente[SIZE];

    int valor = SIZE;

    for (int i = 0; i < SIZE; i++)
    {
        descendente[i] = valor;
        valor--;
    }

    cout << "========================================" << endl;
    cout << "ARRAY ORDENADO DESCENDENTE - PEOR ESCENARIO" << endl;
    cout << "========================================" << endl;

    cout << "Array original:" << endl;
    printArray(descendente, SIZE);

    unsigned long long compDescendente =
            insertSort(descendente, SIZE);

    cout << endl;
    cout << "Array ordenado:" << endl;
    printArray(descendente, SIZE);

    cout << endl;
    cout << "Comparaciones realizadas: "
         << compDescendente << endl;

    return 0;
}

#ifdef proyecto

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Función para aplicar Insertion Sort y contar comparaciones
unsigned long long insertionSort(vector<int> &arr) {
    unsigned long long contadorComparaciones = 0;
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int aux = arr[i];
        int marcador = i;

        // Comparar y desplazar elementos
        while (marcador > 0 && aux < arr[marcador - 1]) {
            contadorComparaciones++;  // Cuenta cada comparación en el while
            arr[marcador] = arr[marcador - 1];
            marcador--;
        }

        // Inserción
        arr[marcador] = aux;
    }

    return contadorComparaciones;
}

// Función para mostrar el array
void printArray(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    ifstream file("numeros.txt");
    string line;
    vector<int> arr;

    if (file.is_open()) {
        // Leer el archivo y extraer los números
        while (getline(file, line, ',')) {
            stringstream ss(line);
            int num;
            ss >> num;
            arr.push_back(num);
        }
        file.close();

        // Aplicar Insertion Sort
        unsigned long long cantidadComparaciones = insertionSort(arr);
        cout << "Cantidad de comparaciones numeros al Azar: " << cantidadComparaciones << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: ";
        // printArray(arr);

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    // Leer y ordenar el segundo archivo
    ifstream file2("numerosOrdenados.txt");
    arr.clear();
    if (file2.is_open()) {
        while (getline(file2, line, ',')) {
            stringstream ss(line);
            int num;
            ss >> num;
            arr.push_back(num);
        }
        file2.close();

        // Aplicar Insertion Sort
        unsigned long long cantidadComparaciones = insertionSort(arr);
        cout << "Cantidad de comparaciones numeros ordenados: " << cantidadComparaciones << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: ";
        // printArray(arr);

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    // Leer y ordenar el tercer archivo
    ifstream file3("numerosInversa.txt");
    arr.clear();
    if (file3.is_open()) {
        while (getline(file3, line, ',')) {
            stringstream ss(line);
            int num;
            ss >> num;
            arr.push_back(num);
        }
        file3.close();

        // Aplicar Insertion Sort
        unsigned long long cantidadComparaciones = insertionSort(arr);
        cout << "Cantidad de comparaciones numeros en orden inverso: " << cantidadComparaciones << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: ";
        // printArray(arr);

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}



/*
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

struct Partido {
    string jornada;
    string fecha;
    string equipoLocal;
    int golesLocal;
    int golesVisitante;
    string equipoVisitante;
    string competicion;
};

vector<Partido> leerArchivoCSV(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    vector<Partido> partidos;
    string linea;

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo!" << endl;
        return partidos;
    }

    getline(archivo, linea); // Leer cabecera
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Partido partido;
        string dato;

        getline(ss, partido.jornada, ',');
        getline(ss, partido.fecha, ',');
        getline(ss, partido.equipoLocal, ',');
        getline(ss, dato, ',');
        partido.golesLocal = stoi(dato);
        getline(ss, dato, ',');
        partido.golesVisitante = stoi(dato);
        getline(ss, partido.equipoVisitante, ',');
        getline(ss, partido.competicion, ',');

        partidos.push_back(partido);
    }

    archivo.close();
    return partidos;
}

// Algoritmo de Insertion Sort con contador de comparaciones
template<typename T, typename Comparator>
unsigned long long insertionSort(vector<T>& arr, Comparator comparar) {
    int size = arr.size();
    unsigned long long contadorComparaciones = 0; // Contador de comparaciones

    for (int i = 1; i < size; i++) {
        T key = arr[i];
        int j = i - 1;

        // Mover los elementos que son mayores que 'key' a una posición adelante
        while (j >= 0 && comparar(key, arr[j])) {
            arr[j + 1] = arr[j];
            j--;
            contadorComparaciones++; // Incrementar contador de comparaciones
            contadorComparaciones++;
        }
        arr[j + 1] = key;
        contadorComparaciones++; // Comparación cuando sale del while
    }

    return contadorComparaciones; // Retornar la cantidad de comparaciones
}

void imprimirPartidos(const vector<Partido>& partidos) {
    for (const auto& partido : partidos) {
        cout << partido.jornada << " | " << partido.fecha << " | " << partido.equipoLocal
             << " " << partido.golesLocal << " - " << partido.golesVisitante << " "
             << partido.equipoVisitante << " | " << partido.competicion << endl;
    }
}

int main() {
    vector<Partido> partidos = leerArchivoCSV("Base_Datos_COMA.csv");

    if (partidos.empty()) {
        cerr << "No se encontraron datos para procesar." << endl;
        return 1;
    }

    // Ordenar por goles locales usando Insertion Sort
    unsigned long long condicionales = insertionSort(partidos, [](const Partido& a, const Partido& b) {
        return a.golesLocal < b.golesLocal;
    });

    cout << "\nPartidos después de ordenar por goles locales:\n";
    cout << "\nCantidad de condicionales:\n" << condicionales << endl;
    // imprimirPartidos(partidos);

    // Ordenar por goles visitantes usando Insertion Sort
    condicionales = insertionSort(partidos, [](const Partido& a, const Partido& b) {
        return a.golesVisitante < b.golesVisitante;
    });

    cout << "\nPartidos después de ordenar por goles visitantes:\n";
    cout << "\nCantidad de condicionales:\n" << condicionales << endl;
    // imprimirPartidos(partidos);

    return 0;
}

*/

#endif