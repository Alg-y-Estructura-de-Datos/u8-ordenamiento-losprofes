#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_

#include <iostream>
using namespace std;

// Método para ordenar un arreglo utilizando el algoritmo Bubble //Sort
// Parámetros:
//   arr: arreglo de enteros a ordenar
//   size: tamaño del arreglo
// 
// Funcionamiento:
//   El algoritmo Bubble Sort compara pares consecutivos de //elementos en el arreglo
//   y los intercambia si están en el orden incorrecto (en este //caso, si el elemento
//   de la izquierda es mayor que el de la derecha). Después de //cada pasada completa,
//   el elemento más grande "burbujea" hasta su posición final.
// 
// Optimización:
//   El algoritmo incluye una optimización con la variable //'seguir'. Si en una pasada
//   no se realiza ningún intercambio, significa que el arreglo ya //está ordenado y el
//   bucle externo puede finalizar de inmediato, ahorrando iteraciones innecesarias.
//
// Complejidad Temporal:
//   Peor caso: O(n^2), cuando el arreglo está en orden inverso.
//   Mejor caso: O(n), cuando el arreglo ya está ordenado (gracias //a la optimización de 'seguir').
//
//
void bubbleSort(int *arr, int size) {
    int aux;
    bool seguir = true;

    for (int i = 0; i < size - 1 && seguir; i++) {
        seguir = false;
        for (int j = 0; j < size - i - 1; j++) // porque va al fondo, ya esta en el lugar que le corresponde
        {
            if (arr[j] > arr[j + 1]) {
                seguir = true;
                aux = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

#endif // BUBBLESORT_H_
