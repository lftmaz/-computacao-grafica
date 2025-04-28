#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct coordenadas
{
   float x;
   float y;
   float z;
} Coordenadas;

void gerarVetor(Coordenadas p1, Coordenadas p2, float vet[]);

float normaVetor(float vet[]);

Coordenadas deslocarPonto(float vet[], Coordenadas p1, char operacao);

float *somaVetores(float vet1[], float vet2[], char operacao);

void multiplicacaoEscalar (float vet[], float escalar);

void normalizacaoVetor (float vet[]);

float produtoInterno(float vet1[], float vet2[]);

float *produtoVetorial(float vet1[], float vet2[]);