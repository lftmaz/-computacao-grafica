#include <stdio.h>

#define altura 256
#define largura 256

unsigned char img[altura][largura][3];

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

int main(){
    inicializarimg(img);
    casaConstrutor(128,0,64,128,200, 200, 200);
    casaConstrutor(64,128,128,256,200, 200, 200);
    casaConstrutor(128,0,128,256,200, 200, 200);
    casaConstrutor(128,64,256,64,200, 200, 200);
    casaConstrutor(128,192,256,192,200, 200, 200);
    imprimirimg(img);
}