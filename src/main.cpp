#include <iostream>
#include <string>
#include "../include/SkewedHeap.h"
#include "../include/Incidente.h"



int main() {
    Nodo* raiz = nullptr;
    int opcion = 0;

    while (true) {
        std::cout << "\n=== Sistema de atención de incidentes (SKEWED HEAP) ===\n";
        std::cout << "1) Agregar incidente\n";
        std::cout << "2) Atender incidente más urgente\n";
        std::cout << "3) Ver incidente más urgente (sin atender)\n";
        std::cout << "4) Salir\n";
        std::cout << "Seleccione una opción: ";
        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrada no válida.\n";
            continue;
        }

        if (opcion == 1) {
            int prioridad;
            std::string descripcion;
            std::string ubicacion;
            std::cout << "Prioridad (entero, menor = más urgente): ";
            std::cin >> prioridad;
            std::cin.ignore(); // descartar newline
            std::cout << "Descripción: ";
            std::getline(std::cin, descripcion);
            std::cout << "Ubicación: ";
            std::getline(std::cin, ubicacion);

            Incidente inc(prioridad, descripcion, ubicacion);

            // Insertar usando la función proporcionada por la implementación del heap
            raiz = insertar(raiz, inc);

            std::cout << "Incidente agregado.\n";
        } else if (opcion == 2) {
            raiz = atenderIncidente(raiz);
        } else if (opcion == 3) {
            verMasUrgente(raiz);
        } else if (opcion == 4) {
            std::cout << "Saliendo...\n";
            break;
        } else {
            std::cout << "Opción no válida.\n";
        }
    }

    return 0;
}

