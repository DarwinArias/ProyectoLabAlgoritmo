#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int tama=3;
int snake [50][2];
int t=1;
int x=10;
int y=12;

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

void DibujarSnake()
{
    int i;
    for (i=1; i<tama; i++)
    {
        gotoxy(snake[i][0],snake[i][1]);
        printf("o");
    }
}

void BorrarSnake()
{
    gotoxy(snake[t][0],snake[t][1]);
    printf(" ");
}

void menuMundos()
{

    char menu1 = '0';
    printf(" \t|********************************************|\n");
    printf(" \t|                                            |\n");
    printf(" \t|                  NIVELES                   |\n");
    printf(" \t|                                            |\n");
    printf(" \t|  ****  ****  ****  ****  ****  ****  ****  |\n");
    printf(" \t|***  ****  ****  ****  ****  ****  ****  ***|\n");
    printf(" \t|                                            |\n");
    printf(" \t| 1- Primer nivel                            |\n");
    printf(" \t| 2- Segundo nivel                           |\n");
    printf(" \t| 3- Menu inicial                            |\n");
    printf(" \t|____________________________________________|\n");
    scanf("%c", &menu1);
    menu1=(getch());
    switch (menu1)
    {
    case '1':
        system("cls");
        jugar();

        break;

    case '2':
        system ("cls");
        jugar2();
        break;

    case '3':
        system("cls");
        Menuinicial();
        break;
    default:
        system ("cls");
        printf("Opcion no valida. Inserte una opcion valida.\n\n");
        menuMundos();
        break;
    }

}
