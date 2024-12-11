# Planificación de Vuelo de un Drone para Aplicación de Herbicida

Este proyecto implementa un sistema para planificar el vuelo de un drone utilizando una imagen satelital procesada para identificar manchas significativas de malezas en un campo de siembra. El objetivo es encontrar el recorrido óptimo del drone minimizando el costo del trayecto, teniendo en cuenta las barreras y las distancias entre manchas. Este problema se modela como un Ciclo Hamiltoniano con restricciones específicas.

## Objetivo

- Detectar manchas significativas de malezas (de al menos 3x3 píxeles).
- Calcular el recorrido más corto para el drone, pasando por todas las manchas y regresando al punto de inicio.
- Evitar barreras representadas en la imagen.

## Estructura del Proyecto

### Archivos Principales

1. **`Imagen.cpp` y `Imagen.h`**: Manejan la carga y representación de la imagen.
    - Carga la matriz de 100x100 píxeles desde un archivo.
    - Identifica barreras y malezas significativas (3x3) como manchas.

2. **`Filtro.cpp` y `Filtro.h`**: Detectan las manchas significativas aplicando un filtro de 3x3.
    - Encuentra las posiciones centrales de cada mancha significativa.

3. **`Grafo.cpp` y `Grafo.h`**: Representan las manchas como un grafo no dirigido.
    - Calculan las distancias euclidianas entre manchas.
    - Consideran las barreras para determinar la conectividad entre nodos.

4. **`Hamilton.cpp` y `Hamilton.h`**: Implementan el algoritmo de búsqueda de amplitud para encontrar el Ciclo Hamiltoniano de menor costo.
    - Generan todos los caminos posibles y seleccionan el óptimo.
    - Guardan los resultados en `ciclos_hamiltonianos.txt`.

5. **`imagen.txt`**: Archivo de entrada con la representación de la imagen en formato de matriz.

6. **`Main.cpp`**: Punto de entrada del programa.
    - Integra todos los módulos y muestra los resultados en consola.

## Requisitos

- **Lenguaje**: C++ (estándar C++11 o superior).
- **Compilador**: GCC o equivalente.

## Ejecución

1. Clona o descarga el proyecto en tu máquina local.
2. Asegúrate de que el archivo `imagen.txt` esté en el directorio raíz.
3. Compila el proyecto:
   ```bash
   g++ -o drone Main.cpp -std=c++11
   ```
4. Ejecuta el programa:
   ```bash
   ./drone
   ```
5. Los resultados del Ciclo Hamiltoniano se guardarán en `ciclos_hamiltonianos.txt` y se imprimirán en la consola.

## Entrada

- **Imagen (`imagen.txt`)**: Una matriz de 100x100 donde:
    - `1`: Representa malezas.
    - `0`: Representa áreas sin malezas.
    - `X`: Representa barreras.

## Salida

- Imprime las manchas detectadas y sus posiciones.
- Muestra el grafo con las distancias entre manchas.
- Genera el recorrido óptimo del drone y el costo asociado en `ciclos_hamiltonianos.txt`.

## Ejemplo de Uso

### Entrada: `imagen.txt`
```
0000000111000110000010001110
0111000111001000011100001110
0111000111000110011100001110
0111000000001000011100000000
00000000000000000000xxxxxxx1
...
```

### Salida en consola
```
Mancha 0 encontrada en: (2, 4)
Mancha 1 encontrada en: (5, 7)
...
Grafo de manchas:
...
Ciclo Hamiltoniano encontrado: 0->1->2->3->0 con costo 45.67
```

### Salida en `ciclos_hamiltonianos.txt`
```
Ciclo Hamiltoniano encontrado: 0->1->2->3->0 con costo 45.67
...
Costo mínimo del ciclo Hamiltoniano: 45.67
Camino: 0->1->2->3->0
```

## Limitaciones y Mejoras Futuras

- **Barreras complejas:** Ampliar el manejo de barreras a formas más variadas.
- **Optimización:** Implementar heurísticas para mejorar la eficiencia del algoritmo.
- **Visualización:** Generar representaciones gráficas del grafo y del recorrido del drone.

## Autor
Este proyecto fue desarrollado como parte del tercer parcial de **Algoritmos y Estructuras de Datos** (2024) en el contexto de planificación de vuelos automatizados para drones.
