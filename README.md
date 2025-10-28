# Implementación de Skewed Heap

Implementación de la estructura de datos Skewed Heap (Montículo Sesgado) con gestión de elementos mediante cola de prioridad (min-heap).

## Compilación y Ejecución
```bash
g++ src/Incidente.cpp src/AtencionIncidentes.cpp src/Simulacion.cpp src/main.cpp -o main.exe && main.exe
```

## Funcionalidad
El programa ofrece un menú interactivo para gestionar 3 zonas (A, B, C) de Skewed Heaps:

- Insertar elementos con prioridad
- Ver elemento de mayor prioridad (sin eliminar)
- Extraer elemento de mayor prioridad
- Fusionar dos zonas (merge)
- Simular fusión de zonas con visualización
- Procesar todos los elementos de una zona
- Salir

## Estructura
**Incidente**: Clase que representa elementos con prioridad, descripción y ubicación

**SkewedHeap**: Implementa el Skewed Heap con operaciones merge, insertar y eliminarMin

**AtencionIncidentes**: Funciones auxiliares para manipular el heap

**Simulacion**: Funciones para simular y visualizar fusión de zonas

**Menu**: Interfaz de usuario para interactuar con las zonas

## Diferencias con Leftist Heap
El Skewed Heap es una versión **más simple** del Leftist Heap:

- ❌ **NO mantiene NPL** (Null Path Length)
- ✅ **SIEMPRE hace swap** de hijos izquierdo y derecho después del merge (incondicional)
- ✅ **Self-adjusting**: No requiere invariantes explícitos
- ✅ Igual de eficiente en promedio que Leftist Heap

El Skewed Heap mantiene la propiedad de min-heap. Todas las operaciones se basan en la función merge con swap incondicional.

## Complejidad Temporal
| Operación | Complejidad |
|-----------|-------------|
| merge() | O(log n) amortizado |
| insertar() | O(log n) amortizado |
| eliminarMin() | O(log n) amortizado |
| findMin() | O(1) |

**Nota**: Las complejidades son amortizadas debido a la naturaleza self-adjusting del Skewed Heap.
