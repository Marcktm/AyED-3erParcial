#include "Imagen.h"
#include "Filtro.h"
#include "Grafo.h"
#include "Hamilton.h"
#include "Imagen.cpp"
#include "Filtro.cpp"
#include "Grafo.cpp"
#include "Hamilton.cpp"


int main() {
    Imagen imagen("imagen.txt");
    imagen.imprimir();
    std::cout << std::endl;

    Filtro filtro(imagen);
    filtro.encontrarManchas();

    Grafo grafo(filtro.getManchas(), imagen.getBarreras());
    grafo.imprimir();

    Hamilton hamilton; 

    std::vector<int> caminoHamiltoniano;
    hamilton.busquedaAmplitud(grafo, caminoHamiltoniano);

}
