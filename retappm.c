#include <stdio.h>

#define altura 100
#define largura 100

unsigned char img[altura][largura][3];

void inicializarimg(){
    
    printf("P3\n%d\t%d\n255\n", altura, largura);

    for(int y = 0; y < altura; y++){
        for(int x = 0; x < largura; x++){
               img[y][x][0] = 255;
               img[y][x][1] = 255;
               img[y][x][2] = 255;
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
int main(){
    inicializarimg(img);
    alterarpixel((int)altura/2,(int)largura/2, 255, 255, 255);
    imprimirimg(img);
    return 0;
}