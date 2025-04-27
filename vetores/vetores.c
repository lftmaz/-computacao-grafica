#include "vetores.h"

void gerarvetor( Coordenadas pi, Coordenadas pf, float vet[]){
    printf("Dentro de gerarvetor: P1 = (%.2f, %.2f), P2 = (%.2f, %.2f)\n", pi.x, pi.y, pf.x, pf.y);
    vet[0] = pf.x - pi.x;
    vet[1] = pf.y - pi.y;
}


