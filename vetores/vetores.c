#include "vetores.h"

void gerarVetor( Coordenadas pi, Coordenadas pf, float vet[]){
    vet[0] = pf.x - pi.x;
    vet[1] = pf.y - pi.y;
    vet[2] = pf.z - pi.z;
}

float normaVetor(float vet[]){
    return (sqrt(pow(vet[0],2) +  pow(vet[1],2) + pow(vet[2],2)));
}


