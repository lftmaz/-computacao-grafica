#include <stdio.h>
#include <math.h>

#define altura 256
#define largura 256

unsigned char img[altura][largura][3];
const double PI = 3.14;

typedef struct coordenadas{
    float x;
    float y;
}Coordenadas;

void inicializarimg(){
    printf("P3\n%d\t%d\n255\n", altura, largura);
    for(int y = 0; y < altura; y++){
        for(int x = 0; x < largura; x++){
            img[y][x][0] = 0;
            img[y][x][1] = 0;
            img[y][x][2] = 0;
        }
    }
}


void alterarpixel (int y, int x, unsigned char r, unsigned char g, unsigned char b){
    img[y][x][0] = r;
    img[y][x][1] = g;
    img[y][x][2] = b;
}

void imprimirimg (){
    for(int y = 0; y < altura; y++){
        for(int x = 0; x < largura; x++){
            printf("%d\t%d\t%d\n", img[y][x][0], img[y][x][1], img[y][x][2] );
        }
    }
}

void casaConstrutor(int x1, int y1,int x2, int y2, unsigned char r, unsigned char g, unsigned char b){
    for (float t = 0.0; t < 1; t = t + 0.0001)
    {
        alterarpixel(( (int)(x2 - x1)*t + x1), (int)((y2 - y1)*t + y1), r, g, b);
    }    
}

float converterRad(float angulo){
    return angulo * PI/180;
}

Coordenadas rotacionarPonto(int y, int x, int origemX, int origemY, float angulo){
  float novaOrigemX = x - origemX;
  float novaOrigemY = y - origemY;
  float pontoRotacionadoX = novaOrigemX * cos(converterRad(angulo)) - novaOrigemY * sin(converterRad(angulo));
  float pontoRotacionadoY = novaOrigemX * sin(converterRad(angulo)) + novaOrigemY * cos(converterRad(angulo));
  Coordenadas pontoRotacao;
  pontoRotacao.x = pontoRotacionadoX + origemX;
  pontoRotacao.y = pontoRotacionadoY + origemY;
  return pontoRotacao;
}

int main(){
    Coordenadas rotacao1,rotacao2,rotacao3,rotacao4,rotacao5,rotacao6,rotacao7;
    inicializarimg(img);
    rotacao1 = rotacionarPonto(128,64,256,128, 180);
    rotacao2 = rotacionarPonto(64,128,256,128, 180);
    rotacao3 = rotacionarPonto(128,192,256,128, 180);
    rotacao4 = rotacionarPonto(128,84,256,128, 180);
    rotacao5 = rotacionarPonto(256,84,256,128, 180);
    rotacao6 = rotacionarPonto(128,172,256,128, 180);
    rotacao7 = rotacionarPonto(256,172,256,128, 180);
    casaConstrutor(rotacao1.y,rotacao1.x,rotacao2.y,rotacao2.x,200, 200, 0);
    casaConstrutor(rotacao2.y,rotacao2.x,rotacao3.y,rotacao3.x,200, 200, 0);
    casaConstrutor(rotacao1.y,rotacao1.x,rotacao3.y,rotacao3.x,200, 200, 0);
    casaConstrutor(rotacao4.y,rotacao4.x,rotacao5.y,rotacao5.x,200, 200, 0);
    casaConstrutor(rotacao6.y,rotacao6.x,rotacao7.y,rotacao7.x,200, 200, 0);
    casaConstrutor(rotacao5.y, rotacao5.x,rotacao7.y,rotacao7.x,200,200,0);
    imprimirimg(img);
}