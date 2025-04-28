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
    gerarVetor(p1, p2, vet1);
    gerarVetor(p3, p4, vet2);
    float *vetVetorial = produtoVetorial(vet1, vet2);
    scanf(" %c", &operacao);
    p1 = deslocarPonto(vet1, p1, operacao);
    float *vetResultante = somaVetores(vet1, vet2, operacao);
    multiplicacaoEscalar(vet1, escalar);
    normalizacaoVetor(vet1);
    free(vetResultante);
    free(vetVetorial);
    return 0;
}