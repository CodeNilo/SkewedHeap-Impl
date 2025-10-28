#ifndef SKEWEDHEAP_H
#define SKEWEDHEAP_H

#include <iostream>
#include "Incidente.h"

using namespace std;

// Estructura Nodo (SIN npl - diferencia clave con Leftist Heap)
struct Nodo {
    Incidente dato;
    Nodo* izq;
    Nodo* der;

    Nodo(const Incidente& dx) : dato(dx), izq(nullptr), der(nullptr) {}
};

// Función merge - CLAVE: SIEMPRE hace swap (sin condición de NPL)
Nodo* merge(Nodo* heap, Nodo* nuevoNodo) {
    if (!heap) return nuevoNodo;
    if (!nuevoNodo) return heap;

    // Mantener el heap con el mínimo en la raíz
    if (heap->dato > nuevoNodo->dato)
        swap(heap, nuevoNodo);

    // Merge recursivo en el hijo derecho
    heap->der = merge(heap->der, nuevoNodo);

    // DIFERENCIA CON LEFTIST: SIEMPRE swap (incondicional)
    swap(heap->izq, heap->der);

    return heap;
}

// Función insertar
Nodo* insertar(Nodo* heap, const Incidente& dx) {
    Nodo* nuevoNodo = new Nodo(dx);
    return merge(heap, nuevoNodo);
}

// Función eliminarMin
Nodo* eliminarMin(Nodo* heap) {
    if (!heap) return nullptr;

    Nodo* nuevoHeap = merge(heap->izq, heap->der);
    delete heap;
    return nuevoHeap;
}

// Función printHeap (SIN imprimir NPL porque no existe)
void printHeap(Nodo* heap, const Incidente* padre = nullptr) {
    if (!heap) return;

    cout << "\nValor actual: ";
    heap->dato.mostrarInfo();
    if (padre) {
        cout << ", Padre: ";
        padre->mostrarInfo();
    }
    // NO imprimimos NPL porque no existe en Skewed Heap

    cout << "\nHijo Izquierdo:";
    printHeap(heap->izq, &heap->dato);

    cout << "\nHijo Derecho:";
    printHeap(heap->der, &heap->dato);
}

#endif // SKEWEDHEAP_H
