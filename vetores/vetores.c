#include "vetores.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

 struct coordenadas
 {
    float x;
    float y;
    float z;
 };


void gerarVetor(Coordenadas pi, Coordenadas pf, float vet[])
{
    vet[0] = pf.x - pi.x;
    vet[1] = pf.y - pi.y;
    vet[2] = pf.z - pi.z;
    printf("Vetor deslocamento <%.2f , %.2f, %.2f>\n", vet[0], vet[1], vet[2]);
}

float normaVetor(float vet[])
{
    return (sqrt(pow(vet[0], 2) + pow(vet[1], 2) + pow(vet[2], 2)));
}

Coordenadas deslocarPonto(float vet[], Coordenadas p1, char operacao)
{
    Coordenadas novoPonto;
    if (operacao == '+')
    {
        novoPonto.x = (vet[0] + p1.x);
        novoPonto.y = (vet[1] + p1.y);
        novoPonto.z = (vet[2] + p1.z);
    }
    else if (operacao == '-')
    {
        novoPonto.x = (p1.x - vet[0]);
        novoPonto.y = (p1.y - vet[1]);
        novoPonto.z = (p1.z - vet[2]);
    }
    else
    {
        printf("Operacao invalida\n");
        return p1;
    }

    return novoPonto;
}

float *somaVetores(float vet1[], float vet2[], char operacao)
{
    float *vetorResultante = (float *)malloc(3 * sizeof(float));
    if (vetorResultante == NULL)
    {
        printf("Erro na alocacao!\n");
        return NULL;
    }
    if (operacao == '+')
    {
        for (int i = 0; i < 3; i++)
        {
            vetorResultante[i] = vet1[i] + vet2[i];
        }
        printf("Vetor Resultante <%.2f , %.2f, %.2f>\n", vetorResultante[0], vetorResultante[1], vetorResultante[2]);
        return vetorResultante;
    }
    else if (operacao == '-')
    {
        for (int i = 0; i < 3; i++)
        {
            vetorResultante[i] = vet1[i] - vet2[i];
        }
        printf("Vetor Resultante <%.2f , %.2f, %.2f>\n", vetorResultante[0], vetorResultante[1], vetorResultante[2]);
        return vetorResultante;
    }else{
    free(vetorResultante);
    return NULL;
    }
}

void multiplicacaoEscalar(float vet[], float escalar){
    for (int i = 0; i < 3; i++)
    {
        vet[i] = vet[i] * escalar;
    }
}

void normalizacaoVetor(float vet[]){
    
    float norma = normaVetor(vet);

    for (int i = 0; i < 3; i++)
    {
       vet[i] = vet[i]/norma;
    }
}

float produtoInterno(float vet1[],float vet2[]){
    for (int i = 0; i < 3; i++)
    {
        return (vet1[0] * vet2[0] + vet1[1] * vet2[1] + vet1[2] * vet2[2]);
    }
    
}


float* produtoVetorial(float vet1[], float vet2[]){
    float* vetorResultante = (float*) malloc(3 *sizeof(float));
    if(vetorResultante == NULL){
        printf("Erro de alocacao");
        return 0;
    }
       vetorResultante[0] = (vet1[1] * vet2[2] - (vet1[2] * vet2[1]));
       vetorResultante[1] = (vet1[2] * vet2[0] - (vet1[0] * vet2[2]));
       vetorResultante[2] = (vet1[0] * vet2[1] - (vet1[1] * vet2[0]));
       return vetorResultante;
}
