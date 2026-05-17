#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Algoritmos Ordenamiento/quickSort.h"

using namespace std;

// ---------------------------------------------------------
// Función para imprimir un array
// ---------------------------------------------------------
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// ---------------------------------------------------------
// MAIN
// ---------------------------------------------------------
int main() {
    srand(time(NULL));

    const int SIZE = 100;

    // =====================================================
    // ARRAY ALEATORIO
    // =====================================================
    int aleatorio[SIZE];

    for (int i = 0; i < SIZE; i++) {
        aleatorio[i] = rand() % 1000;
    }

    cout << "========================================" << endl;
    cout << "ARRAY ALEATORIO" << endl;
    cout << "========================================" << endl;

    cout << "Array original:" << endl;
    printArray(aleatorio, SIZE);

    unsigned long long compAleatorio =
            quickSort(aleatorio, 0, SIZE - 1);

    cout << endl;
    cout << "Array ordenado:" << endl;
    printArray(aleatorio, SIZE);

    cout << endl;
    cout << "Comparaciones realizadas: "
         << compAleatorio << endl;

    cout << endl << endl;

    // =====================================================
    // ARRAY PEOR CASO
    // =====================================================
    int peorCasoPivotCentral[100] = {
            50,
            25, 75,
            12, 37, 62, 87,
            6, 18, 31, 43, 56, 68, 81, 93,
            3, 9, 15, 21, 28, 34, 40, 46,
            53, 59, 65, 71, 78, 84, 90, 96,
            1, 4, 7, 10, 13, 16, 19, 22,
            26, 29, 32, 35, 38, 41, 44, 47,
            51, 54, 57, 60, 63, 66, 69, 72,
            76, 79, 82, 85, 88, 91, 94, 97,
            2, 5, 8, 11, 14, 17, 20, 23,
            27, 30, 33, 36, 39, 42, 45, 48,
            52, 55, 58, 61, 64, 67, 70, 73,
            77, 80, 83, 86, 89, 92, 95, 98,
            24, 49, 74, 99, 100
    };

    cout << "========================================" << endl;
    cout << "ARRAY ORDENADO PARA PEOR CASO" << endl;
    cout << "========================================" << endl;

    cout << "Array original:" << endl;
    printArray(peorCasoPivotCentral, SIZE);

    unsigned long long comPeorCaso =
            quickSort(peorCasoPivotCentral, 0, SIZE - 1);

    cout << endl;
    cout << "Array ordenado:" << endl;
    printArray(peorCasoPivotCentral, SIZE);

    cout << endl;
    cout << "Comparaciones realizadas: "
         << comPeorCaso << endl;

    cout << endl << endl;

    // =====================================================
    // ARRAY ASCENDENTE
    // =====================================================
    int ascendente[SIZE];

    int valor = SIZE;

    for (int i = 0; i < SIZE; i++) {
        ascendente[i] = i;
    }

    cout << "========================================" << endl;
    cout << "ARRAY ORDENADO ASCENDENTE- MEJOR CASO" << endl;
    cout << "========================================" << endl;

    cout << "Array original:" << endl;
    printArray(ascendente, SIZE);

    unsigned long long compAscendente =
            quickSort(ascendente, 0, SIZE - 1);

    cout << endl;
    cout << "Array ordenado:" << endl;
    printArray(ascendente, SIZE);

    cout << endl;
    cout << "Comparaciones realizadas: "
         << compAscendente << endl;

    return 0;
}

#ifdef proyecto

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
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

        // Aplicar QuickSort
        unsigned long long cantidadComparaciones = quickSort(arr, 0, arr.size() - 1);
        cout << "Cantidad de comparaciones numeros al Azar: " << cantidadComparaciones << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: ";
//        printArray(arr);
//
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

        // Aplicar QuickSort
        unsigned long long cantidadComparaciones = quickSort(arr, 0, arr.size() - 1);
        cout << "Cantidad de comparaciones numeros ordenados: " << cantidadComparaciones << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: ";
//        printArray(arr);

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

        // Aplicar QuickSort
        unsigned long long cantidadComparaciones = quickSort(arr, 0, arr.size() - 1);
        cout << "Cantidad de comparaciones numeros en orden inverso: " << cantidadComparaciones << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: ";
//        printArray(arr);

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}
/* (descomentar para ver segunda parte)
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

// Algoritmo de QuickSort con contador de comparaciones
template<typename T, typename Comparator>
unsigned long long quickSort(vector<T>& arr, int inicio, int fin, Comparator comparar) {
    unsigned long long contadorComparaciones = 0;

    if (inicio < fin) {
        contadorComparaciones++;
        int i = inicio, j = fin;
        T pivot = arr[(inicio + fin) / 2];

        // Partición
        do {
            while (comparar(arr[i], pivot)) {
                i++;
                contadorComparaciones++; // Incrementar comparaciones
            }
            while (comparar(pivot, arr[j])) {
                j--;
                contadorComparaciones++; // Incrementar comparaciones
            }

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
            contadorComparaciones++; // Comparación para salida del bucle
        } while (i <= j);

        // Llamadas recursivas
        contadorComparaciones += quickSort(arr, inicio, j, comparar);
        contadorComparaciones += quickSort(arr, i, fin, comparar);
    }

    return contadorComparaciones; // Retornar cantidad de comparaciones
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

    // Ordenar por goles locales usando QuickSort
    unsigned long long condicionales = quickSort(partidos, 0, partidos.size() - 1, [](const Partido& a, const Partido& b) {
        return a.golesLocal < b.golesLocal;
    });

    cout << "\nPartidos después de ordenar por goles locales:\n";
    cout << "\nCantidad de condicionales:\n" << condicionales << endl;
    // imprimirPartidos(partidos);

    // Ordenar por goles visitantes usando QuickSort
    condicionales = quickSort(partidos, 0, partidos.size() - 1, [](const Partido& a, const Partido& b) {
        return a.golesVisitante < b.golesVisitante;
    });

    cout << "\nPartidos después de ordenar por goles visitantes:\n";
    cout << "\nCantidad de condicionales:\n" << condicionales << endl;
    // imprimirPartidos(partidos);

    return 0;
}

*/

#endif