/*
 * Incidente.h - Clase Incidente
 * Copiar de LeftistHeap-Impl/include/Incidente.h (sin cambios)
 */

// Copiar contenido aquí
#ifndef INCIDENTE_H
#define INCIDENTE_H

#include <string>

class Incidente {
private:
    int prioridad;             // menor = más urgente
    std::string descripcion;
    std::string ubicacion;

public:
    // Constructor
    Incidente(int p, const std::string& d, const std::string& u);

    // Getters
    int getPrioridad() const;
    std::string getDescripcion() const;
    std::string getUbicacion() const;

    // Mostrar información del incidente
    void mostrarInfo() const;

    // Comparacion (para heaps de minimo)
    bool operator<(const Incidente& other) const;
    bool operator>(const Incidente& other) const;
};

#endif // INCIDENTE_H