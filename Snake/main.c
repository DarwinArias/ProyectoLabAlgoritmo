#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
int main()
{
    world_style();
    printf("\n");
    return 0;
}

void gotoxy (int x, int y)
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X=x;
    dwPos.Y=y;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);

}

void world_style()
{
    int i;
    //Parte Superior Capa 1
    for(i=0; i<=110; i++)
    {
        gotoxy (i,0);
        printf("%c", 177);
    }
    //Parte Izquierda Capa 1
    for(i=0; i<=20; i++)
    {
        gotoxy (0,i);
         printf("%c", 177);
    }
    //Parte Derecha Capa 1
    for(i=0; i<=20; i++)
    {
        gotoxy (110,i);
        printf("%c", 177);
    }
    //Parte Abajo Capa 1
    for(i=0; i<=110; i++)
    {
        gotoxy (i,20);
        printf("%c", 177);
    }
    //Parte Superior Capa 2
    for(i=0; i<=110; i++)
    {
        gotoxy (i,1);
         printf("%c", 177);
    }
    //Parte Izquierda Capa 2
    for(i=0; i<=20; i++)
    {
        gotoxy (1,i);
        printf("%c", 177);
    }
    //Parte Derecha Capa 2
    for(i=0; i<=20; i++)
    {
        gotoxy (109,i);
        printf("%c", 177);
    }
    //Parte Abajo Capa 2
    for(i=0; i<=110; i++)
    {
        gotoxy (i,19);
        printf("%c", 177);
    }
    system("color f5");
}
