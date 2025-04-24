#include <stdio.h>


void alterar (int height, int width){
    if ()
    {
        
    }
    
}

int main()
{
    int height = 100;  // Corrigido: "height" em vez de "heigth"
    int width = 100;

    // Cabeçalho PPM formatado corretamente
    printf("P3\n %d \t %d\n 255\n", width, height);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 50 && j == 50)
            {
                printf("255 0 0\n");  // Ponto vermelho (sem tabs extras)
            }
            else
            {
                printf("0 0 0\n");  // Fundo preto (sem tabs extras)
            }
        }
    }

    return 0;  // Indica que o programa terminou com sucesso
}