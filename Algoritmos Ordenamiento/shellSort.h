#ifndef SHELLSORT_H_
#define SHELLSORT_H_

#include <iostream>
using namespace std;
// Método para ordenar un arreglo de enteros utilizando el algoritmo Shell Sort.
// Parámetros:
//   arr: arreglo de enteros a ordenar.
//   size: número de elementos en el arreglo.
//
// Descripción:
//   Shell Sort es un algoritmo de ordenamiento que generaliza el método de inserción.
//   Comienza ordenando elementos que están lejos unos de otros y va reduciendo la
//   distancia entre los elementos a medida que avanza. Este enfoque permite que el
//   algoritmo se comporte de manera más eficiente en comparación con la ordenación
//   por inserción simple, especialmente en arreglos más grandes.
//
// Funcionamiento:
//   - Se define un intervalo, o "gap", que se inicializa como la mitad del tamaño del arreglo.
//   - Se realizan pasadas sobre el arreglo, y en cada pasada, se compara e intercambia elementos
//     que están separados por el "gap".
//   - Después de cada pasada, el "gap" se reduce, y el proceso se repite hasta que "gap" es 0,
//     momento en el cual el arreglo está completamente ordenado.
//
// Complejidad Temporal:
//   - El peor caso: O(n²) (cuando el gap es muy grande al principio, pero las mejoras con
//     gaps más pequeños permiten que la complejidad se acerque a O(n log n) en algunos casos).
//   - El caso promedio: O(n log n) (para arreglos aleatorios, dependiendo de la secuencia de gaps).
//   - El mejor caso: O(n) (cuando el arreglo ya está casi ordenado).
//
// Complejidad Espacial:
//   - O(1) ya que Shell Sort es un algoritmo in-place y no requiere espacio adicional significativo.
//
// Ventajas:
//   - Shell Sort es más rápido que otros algoritmos de ordenación por inserción para arreglos grandes.
//   - Permite un intercambio de elementos que está más cerca del lugar donde deberían estar, lo que
//     mejora su eficiencia.
//
// Desventajas:
//   - La elección de la secuencia de gaps puede influir significativamente en la eficiencia del algoritmo.
//   - No es estable, lo que significa que no garantiza mantener el orden relativo de los elementos iguales.
//

// ---------------------------------------------------------
// SHELL SORT CON CONTEO DE COMPARACIONES
// Cuenta únicamente comparaciones entre elementos:
//
// arr[j - gap] > temp
// ---------------------------------------------------------
unsigned long long shellSort(int *arr, int size)
{
    unsigned long long comparaciones = 0;

    // El gap comienza siendo la mitad del tamaño
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        // Recorre el arreglo desde gap hasta el final
        for (int i = gap; i < size; i++)
        {
            // Elemento actual a insertar
            int temp = arr[i];

            int j;

            // Inserción con salto gap
            for (j = i; j >= gap; j -= gap)
            {
                // Comparación REAL entre elementos
                comparaciones++;

                if (arr[j - gap] > temp)
                {
                    // Desplaza elemento
                    arr[j] = arr[j - gap];
                }
                else
                {
                    // Ya encontró posición correcta
                    break;
                }
            }

            // Inserta el elemento
            arr[j] = temp;
        }
    }

    return comparaciones;
}


#endif // SHELLSORT_H_
