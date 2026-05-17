
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Función para aplicar Bubble Sort
unsigned long long bubbleSort(vector<int> &arr) {
    bool seguir = true;
    unsigned long long contadorComparaciones = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1 && seguir; i++) {
        seguir = false;

        for (int j = 0; j < n - i - 1; j++) {

            contadorComparaciones++;
            if (arr[j] > arr[j + 1]) {
                seguir = true;
                swap(arr[j], arr[j + 1]);
            }
        }
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

        // Mostrar el array antes de ordenar
        cout << "Array desordenado: ";
        //printArray(arr);

        // Aplicar Bubble Sort
        unsigned long long cantidadCondicionales  = bubbleSort(arr);
        cout << "Cantidad de comparaciones numeros al Azar: " << cantidadCondicionales << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: "<< endl;
       // printArray(arr);

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    vector<int> arr2;
    ifstream file2("numerosOrdenados.txt");
    if (file2.is_open()) {
        // Leer el archivo y extraer los números
        while (getline(file2, line, ',')) {
            stringstream ss(line);
            int num;
            ss >> num;
            arr2.push_back(num);
        }
        file2.close();

        // Mostrar el array antes de ordenar
        cout << "Array desordenado: ";
        //printArray(arr2);

        // Aplicar Bubble Sort
        unsigned long long cantidadCondicionales  = bubbleSort(arr2);
        cout << "Cantidad de comparaciones numeros ordenados: " << cantidadCondicionales << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: "<< endl;
        //printArray(arr2);

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    vector<int> arr3;
    ifstream file3("numerosInversa.txt");
    if (file3.is_open()) {
        // Leer el archivo y extraer los números
        while (getline(file3, line, ',')) {
            stringstream ss(line);
            int num;
            ss >> num;
            arr3.push_back(num);
        }
        file3.close();

        // Mostrar el array antes de ordenar
        cout << "Array desordenado: ";
       // printArray(arr3);

        // Aplicar Bubble Sort
        unsigned long long cantidadCondicionales  = bubbleSort(arr3);
        cout << "Cantidad de comparaciones numeros inversas: " << cantidadCondicionales << endl;
        // Mostrar el array ordenado
        cout << "Array inversas: "<< endl;
        //printArray(arr3);

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}
/* //(Descomentar para proar segunda parte
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

// Algoritmo de Bubble Sort con contador de comparaciones
template<typename T, typename Comparator>
unsigned long long bubbleSort(vector<T>& arr, Comparator comparar) {
    int size = arr.size();
    bool seguir = true;
    int contadorComparaciones = 0; // Contador de comparaciones

    for (int i = 0; i < size - 1 && seguir; i++) {
        seguir=false;
        contadorComparaciones++; // Incrementar contador de comparaciones
        for (int j = 0; j < size - i - 1; j++) {
            contadorComparaciones++; // Incrementar contador de comparaciones
            contadorComparaciones++; // Incrementar contador de comparaciones
            // Usar el comparator para decidir si se debe intercambiar
            if (comparar(arr[j + 1], arr[j])) {
                seguir=true;
                swap(arr[j], arr[j + 1]);
            }
        }
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

    cout << "Partidos antes de ordenar:\n";
   // imprimirPartidos(partidos);

    unsigned long long condicionales = bubbleSort(partidos, [](const Partido& a, const Partido& b) {
        return a.golesLocal < b.golesLocal;
//        return a.golesLocal > b.golesLocal;
    });


    cout << "\nPartidos después de ordenar por goles locales:\n";
    cout << "\nCantidad de condicionales:\n" << condicionales << endl;
    //imprimirPartidos(partidos);

   condicionales = bubbleSort(partidos, [](const Partido& a, const Partido& b) {
        return a.golesVisitante < b.golesVisitante;
    });

    cout << "\nPartidos después de ordenar por goles visitantes:\n";
    cout << "\nCantidad de condicionales:\n" << condicionales << endl;
//    imprimirPartidos(partidos);

    return 0;
}
*/
