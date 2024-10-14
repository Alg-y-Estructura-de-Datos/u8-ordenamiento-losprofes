#ifndef INSERTSORT_H_
#define INSERTSORT_H_

#include <iostream>
using namespace std;
// Método para ordenar un arreglo de enteros utilizando el algoritmo de Insertion Sort.
// Parámetros:
//   arr: arreglo de enteros a ordenar.
//   size: tamaño del arreglo.
//
// Descripción:
//   Insertion Sort es un algoritmo que organiza el arreglo en lugar, iterando de izquierda a derecha.
//   En cada iteración, toma el siguiente elemento y lo inserta en la posición correcta en la parte
//   del arreglo que ya está ordenada. A medida que avanza, la porción ordenada del arreglo va creciendo.
//
// Funcionamiento:
//   - El algoritmo mantiene dos subarreglos: uno ordenado a la izquierda y otro desordenado a la derecha.
//   - En cada pasada, selecciona el siguiente elemento del subarreglo desordenado y lo inserta en el
//     lugar adecuado dentro del subarreglo ordenado, moviendo los elementos mayores hacia la derecha.
//   - El bucle 'while' dentro de cada iteración del bucle principal se encarga de realizar el desplazamiento
//     de los elementos mayores para dejar espacio al nuevo elemento.
//
// Complejidad Temporal:
//   - Peor caso: O(n²), cuando el arreglo está en orden inverso, ya que cada nuevo elemento debe compararse
//     con todos los anteriores.
//   - Mejor caso: O(n), si el arreglo ya está ordenado, ya que el bucle interno nunca realiza intercambios.
//   - Caso promedio: O(n²).
//
// Ventajas:
//   - Simple de implementar.
//   - Eficiente para arreglos pequeños o casi ordenados.
// Desventajas:
//   - No es eficiente para arreglos grandes o muy desordenados debido a su complejidad cuadrática.
//
void insertSort(int *arr, int size)
{
    int marcador, aux;

    // Bucle comienza desde el segundo elemento (i = 1)
    for (int i = 1; i < size; i++)
    {
        marcador = i;
        aux = arr[i];

        // Mueve los elementos mayores hacia la derecha
        while (marcador > 0 && aux < arr[marcador - 1])
        {
            arr[marcador] = arr[marcador - 1];
            marcador--;
        }
        // Inserta el elemento en su posición correcta
        arr[marcador] = aux;
    }
}



#endif // INSERTSORT_H_
