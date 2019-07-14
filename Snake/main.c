#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int tama=3;
int snake [50][2];
int t=1;
int x=10;
int y=12;
int coordx=30;
int coordy=15;
char boton;
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
    //Parte Vertical
    for (i=2; i<78; i++)
    {
        gotoxy(i,3);
        printf ("%c",177);
        gotoxy(i,23);
        printf ("%c",177);
    }
    //Parte Horizontal
    for (i=4; i<23; i++)
    {
        gotoxy(2,i);
        printf ("%c",177);
        gotoxy(77,i);
        printf ("%c",177);
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
void comida()
{
    if (x==coordx && y==coordy)
    {
        coordx=(rand()%73)+4;
        coordy=(rand()%19)+4;
        tama++;
        record+=5;

        gotoxy(coordx,coordy);
        printf("%c", 235);
    }
    void menuNiveles()
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
//        jugar();

            break;

        case '2':
            system ("cls");
//        jugar2();
            break;

        case '3':
            system("cls");
//        Menuinicial();
            break;
        default:
            system ("cls");
            printf("Opcion no valida. Inserte una opcion valida.\n\n");
            menuNiveles();
            break;
        }

    }

    int Menuinicial()
    {
        char nombre[4000];
        char menu = '0';
        while(boton!='3')
        {
            printf(" \t|********************************************|\n");
            printf(" \t|                 JUEGO SNAKE                |\n");
            printf(" \t|                                            |\n");
            printf(" \t|  ****  ****  ****  ****  ****  ****  ****  |\n");
            printf(" \t|***  ****  ****  ****  ****  ****  ****  ***|\n");
            printf(" \t|                                            |\n");
            printf(" \t| Presione 1 para jugar                      |\n");
            printf(" \t| Presione 3 para salir                      |\n");
            printf(" \t|____________________________________________|\n");
            scanf("%c", &menu);

            switch (menu)
            {
            case '1':
                system("cls");
                menuNiveles();
                break;

            case '3':
                return 0;
                break;
            default:
                system ("cls");
                printf("Opcion no valida. Intentelo de nuevo.\n\n");
                Menuprincipal();
                break;

            }
        }

    }
