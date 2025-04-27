#include "vetores.h"

#define escalar 4

int main()
{
    Coordenadas p1 = {2, 3};
    Coordenadas p2 = {6, 9};
    Coordenadas p3 = {8, 1,3};
    Coordenadas p4 = {5, 7,7};
    float vet1[3], vet2[3];
    char operacao;
    printf("P1: (%.2f, %.2f,%.2f)\t", p1.x, p1.y, p1.z);
    printf("P2: (%.2f, %.2f,%.2f)\n", p2.x, p2.y, p2.z);
    printf("P3: (%.2f, %.2f,%.2f)\t", p3.x, p3.y, p3.z);
    printf("P4: (%.2f, %.2f,%.2f)\n", p4.x, p4.y, p4.z);
    gerarVetor(p1, p2, vet1);
    gerarVetor(p3, p4, vet2);
    printf("Norma do vetor: %.2f\n", normaVetor(vet1));
    scanf(" %c", &operacao);
    p1 = deslocarPonto(vet1, p1, operacao);
    printf("Deslocamento de P1: (%.2f, %.2f,%.2f)\n", p1.x, p1.y, p1.z);
    float *vetResultante = somaVetores(vet1, vet2, operacao);
    free(vetResultante);
    multiplicacaoEscalar(vet1, escalar);
    printf("Vetor e <%.2f , %.2f, %.2f>\n", vet1[0], vet1[1], vet1[2]);
    normalizacaoVetor(vet1);
    printf("Vetor Unitario <%.2f , %.2f, %.2f>\n", vet1[0], vet1[1], vet1[2]);
    return 0;
}