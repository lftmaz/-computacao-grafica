#include <stdio.h>

#define width 256
#define height 256

unsigned char img[height][width][3];

void set_pixel(int x, int y, char r, char g, char b)
{
    if ((x >= 0) && (x <= width) && (y >= 0) && (y <= height))
    {
        img[x][y][0] = r;
        img[x][y][1] = g;
        img[x][y][2] = b;
    }
}

void clear_img()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            img[i][j][0] = 0;
            img[i][j][1] = 0;
            img[i][j][2] = 0;
        }
    }
}

void save_img()
{
    printf("P3\n %d \t %d\n 255\n", width, height);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            for (int c = 0; c < 3; c++)
            {
                printf("%d \t", img[x][y][c]);
            }
            printf("\n");
        }
    }
}

void draw_line(int x1, int y1, int x2, int y2, char r, char g, char b)
{
    for (float t = 0; t < 1; t += 0.001)
    {
        set_pixel((int)(x2 - x1) * t + x1, (int)(y2 - y1) * t + y1, r, g, b);
    }
}


void bezier(int x1,int y1,int x2,int y2,int x3,int y3,char r, char g, char b){
    for (float t = 0; t < 1; t += 0.001)
    {
        set_pixel((int)(((1 - t) * (1 - t) * x1) + ((2 *t)*(1 - t) * x2) + (t * t) * x3), (int)(((1 - t) * (1 - t) * y1) + ((2 *t)*(1 - t) * y2) + (t * t) * y3),r,g,b);
    }
    
}
int main()
{
    clear_img(img);
    bezier(width / 2, height / 2,width / 2, 192, 0, 256, 255, 255, 255);
    bezier(width / 2, height / 2,width / 2, 192,width, height, 255, 255, 255);
    save_img(img);
}