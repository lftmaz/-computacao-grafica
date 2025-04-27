#include "vetores.h"

int main(){
    Coordenadas p1 = {2,3};
    Coordenadas p2 = {6,9};
    float vet[2];
    printf("P1: (%.2f, %.2f)\n", p1.x, p1.y);
    printf("P2: (%.2f, %.2f)\n", p2.x, p2.y);
    gerarvetor(p1, p2, vet);
    printf("Vetor deslocamento <%.2f , %.2f>\n" , vet[0] ,  vet[1]);
    return 0;
}