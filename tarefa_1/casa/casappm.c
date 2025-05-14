#include <stdio.h>
#include <math.h>

#define altura 256
#define largura 256

unsigned char img[altura][largura][3];
const double PI = 3.14;

typedef struct coordenadas
{
    float y;
    float x;
} Coordenadas;

void inicializarimg()
{
    printf("P3\n%d\t%d\n255\n", altura, largura);
    for (int y = 0; y < altura; y++)
    {
        for (int x = 0; x < largura; x++)
        {
            img[y][x][0] = 0;
            img[y][x][1] = 0;
            img[y][x][2] = 0;
        }
    }
}

void alterarpixel(int y, int x, unsigned char r, unsigned char g, unsigned char b)
{
    img[y][x][0] = r;
    img[y][x][1] = g;
    img[y][x][2] = b;
}

void imprimirimg()
{
    for (int y = 0; y < altura; y++)
    {
        for (int x = 0; x < largura; x++)
        {
            printf("%d\t%d\t%d\n", img[y][x][0], img[y][x][1], img[y][x][2]);
        }
    }
}

void casaConstrutor(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b)
{
    for (float t = 0.0; t < 1; t = t + 0.0001)
    {
        alterarpixel(((int)(x2 - x1) * t + x1), (int)((y2 - y1) * t + y1), r, g, b);
    }
}

float converterRad(float angulo)
{
    return angulo * PI / 180;
}

Coordenadas rotacionarPonto(Coordenadas vet[], int origemX, int origemY, float angulo)
{
    float novaOrigemX = vet[0].x - origemX;
    float novaOrigemY = vet[0].y - origemY;
    float pontoRotacionadoX = novaOrigemX * cos(converterRad(angulo)) - novaOrigemY * sin(converterRad(angulo));
    float pontoRotacionadoY = novaOrigemX * sin(converterRad(angulo)) + novaOrigemY * cos(converterRad(angulo));
    Coordenadas pontoRotacao;
    pontoRotacao.x = pontoRotacionadoX + origemX;
    pontoRotacao.y = pontoRotacionadoY + origemY;
    return pontoRotacao;
}

int main()
{
    Coordenadas rotacao1, rotacao2, rotacao3, rotacao4, rotacao5, rotacao6, rotacao7;
    inicializarimg(img);
    Coordenadas vetorCasa[7] = {{128, 64}, {64, 128}, {128, 192}, {128, 84}, {256, 84}, {128, 172}, {256, 172}};
    casaConstrutor(vetorCasa[0].y, vetorCasa[0].x, vetorCasa[1].y, vetorCasa[1].x, 200, 200, 0);
    casaConstrutor(vetorCasa[1].y, vetorCasa[1].x, vetorCasa[2].y, vetorCasa[2].x, 200, 200, 0);
    casaConstrutor(vetorCasa[0].y, vetorCasa[0].x, vetorCasa[2].y, vetorCasa[2].x, 200, 200, 0);
    casaConstrutor(vetorCasa[3].y, vetorCasa[3].x, vetorCasa[4].y, vetorCasa[4].x, 200, 200, 0);
    casaConstrutor(vetorCasa[4].y, vetorCasa[4].x, vetorCasa[6].y, vetorCasa[6].x, 200, 200, 0);
    casaConstrutor(vetorCasa[5].y, vetorCasa[5].x, vetorCasa[6].y, vetorCasa[6].x, 200, 200, 0);
    imprimirimg(img);
}