#include "vetores.h"

int main(){
    Coordenadas p1 = {2,3};
    Coordenadas p2 = {6,9};
    float vet[3];
    printf("P1: (%.2f, %.2f,%.2f)\n", p1.x, p1.y, p1.z);
    printf("P2: (%.2f, %.2f,%.2f)\n", p2.x, p2.y, p2.z);
    gerarVetor(p1, p2, vet);
    printf("Vetor deslocamento <%.2f , %.2f, %.2f>\n" , vet[0] ,  vet[1], vet[2]);
    printf("%.2f" , normaVetor(vet));
    return 0;
}