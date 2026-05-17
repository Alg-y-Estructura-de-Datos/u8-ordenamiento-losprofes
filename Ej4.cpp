#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Algoritmos Ordenamiento/shellSort.h"

using namespace std;

// ---------------------------------------------------------
// Función para imprimir un array
// ---------------------------------------------------------
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// ---------------------------------------------------------
// MAIN
// ---------------------------------------------------------
int main()
{
    srand(time(NULL));

    const int SIZE = 100;

    // =====================================================
    // ARRAY ALEATORIO
    // =====================================================
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
            shellSort(aleatorio, SIZE);

    cout << endl;
    cout << "Array ordenado:" << endl;
    printArray(aleatorio, SIZE);

    cout << endl;
    cout << "Comparaciones realizadas: "
         << compAleatorio << endl;

    cout << endl << endl;

    // =====================================================
    // ARRAY ASCENDENTE
    // =====================================================
    int ascendente[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        ascendente[i] = i;
    }

    cout << "========================================" << endl;
    cout << "ARRAY ASCENDENTE - mejor caso" << endl;
    cout << "========================================" << endl;

    cout << "Array original:" << endl;
    printArray(ascendente, SIZE);

    unsigned long long compAscendente =
            shellSort(ascendente, SIZE);

    cout << endl;
    cout << "Array ordenado:" << endl;
    printArray(ascendente, SIZE);

    cout << endl;
    cout << "Comparaciones realizadas: "
         << compAscendente << endl;

    cout << endl << endl;

    // =====================================================
    // ARRAY DESCENDENTE
    // =====================================================
    int descendente[SIZE];

    int valor = SIZE;

    for (int i = 0; i < SIZE; i++)
    {
        descendente[i] = valor;
        valor--;
    }

    cout << "========================================" << endl;
    cout << "ARRAY DESCENDENTE - peor caso" << endl;
    cout << "========================================" << endl;

    cout << "Array original:" << endl;
    printArray(descendente, SIZE);

    unsigned long long compDescendente =
            shellSort(descendente, SIZE);

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

// Función para aplicar Shell Sort y contar comparaciones
unsigned long long shellSort(vector<int> &arr) {
    unsigned long long contadorComparaciones = 0;
    int n = arr.size();

    // Comienza con un "gap" (intervalo) grande y lo reduce
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            // Realizar comparaciones en intervalos de "gap"
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                contadorComparaciones++;  // Cuenta cada comparación exitosa
            }
            arr[j] = temp;
            contadorComparaciones++;  // Cuenta la comparación fallida que sale del ciclo
        }
        contadorComparaciones++;
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

        // Aplicar Shell Sort
        unsigned long long cantidadComparaciones = shellSort(arr);
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

        // Aplicar Shell Sort
        unsigned long long cantidadComparaciones = shellSort(arr);
        cout << "Cantidad de comparaciones numeros ordenados: " << cantidadComparaciones << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: ";
        //printArray(arr);

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

        // Aplicar Shell Sort
        unsigned long long cantidadComparaciones = shellSort(arr);
        cout << "Cantidad de comparaciones numeros en orden inverso: " << cantidadComparaciones << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: ";
        //printArray(arr);

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}


/* (descomentar para segunda parte)
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

// Algoritmo de Shell Sort con contador de comparaciones
template<typename T, typename Comparator>
unsigned long long shellSort(vector<T>& arr, Comparator comparar) {
    int size = arr.size();
    unsigned long long contadorComparaciones = 0; // Contador de comparaciones

    // Gap empieza en size/2 y se divide a la mitad en cada iteración
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            T temp = arr[i];
            int j;

            // Desplazar los elementos ordenados por el gap
            for (j = i; j >= gap && comparar(temp, arr[j - gap]); j -= gap) {
                arr[j] = arr[j - gap];
                contadorComparaciones++; // Incrementar contador de comparaciones
            }

            arr[j] = temp;
            contadorComparaciones++; // Comparación final para salida del bucle
        }
        contadorComparaciones++;
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

    // Ordenar por goles locales usando Shell Sort
    unsigned long long condicionales = shellSort(partidos, [](const Partido& a, const Partido& b) {
        return a.golesLocal < b.golesLocal;
    });

    cout << "\nPartidos después de ordenar por goles locales:\n";
    cout << "\nCantidad de condicionales:\n" << condicionales << endl;
    // imprimirPartidos(partidos);

    // Ordenar por goles visitantes usando Shell Sort
    condicionales = shellSort(partidos, [](const Partido& a, const Partido& b) {
        return a.golesVisitante < b.golesVisitante;
    });

    cout << "\nPartidos después de ordenar por goles visitantes:\n";
    cout << "\nCantidad de condicionales:\n" << condicionales << endl;
    // imprimirPartidos(partidos);

    return 0;
}
*/
#endif
