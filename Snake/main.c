#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>

int direccion = 3;
int tama=3;
int snake [50][2];
int t=1;
int x=10;
int y=12;
int coordx=30;
int coordy=15;
char boton = 0;
int score = 0;
int main()
{
    Menuinicial();
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
        score+=5;

        gotoxy(coordx,coordy);
        printf("%c", 235);
    }
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
        menu1=(getch());
        switch (menu1)
        {
        case '1':
            system("cls");
//        jugar();
        world_style();
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
        char menu = '0';
            printf(" \t|********************************************|\n");
            printf(" \t|                 JUEGO SNAKE                |\n");
            printf(" \t|                                            |\n");
            printf(" \t|  ****  ****  ****  ****  ****  ****  ****  |\n");
            printf(" \t|***  ****  ****  ****  ****  ****  ****  ***|\n");
            printf(" \t|                                            |\n");
            printf(" \t| Presione 1 para jugar                      |\n");
            printf(" \t| Presione 3 para salir                      |\n");
            printf(" \t|____________________________________________|\n");
            menu= getch();
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
                Menuinicial();
                break;

            }


    }

    bool Perder()
{
    int j;
    if (y==3 || y==23 ||x==2 ||x==77)
    {
        system("cls");

        gotoxy(2,1);
        printf (" Perdiste \n");

        gotoxy(2,3);
        printf(" Score : %d \n", score);
        printf("\n \n");

        if (score > 0)
        {
//            ficheros(score);
            t=1,tama=3,x=10,y=12,direccion=3,coordx=30,coordy=15,score=0;
//            Menuprincipal();
            return false;
        }
        else
        {
            t=1,tama=3,x=10,y=12,direccion=3,coordx=30,coordy=15,score=0;

//            Menuprincipal();
            return false;
        }
    }

    for (j=tama-1; j>0; j--)
    {
        if (snake[j][0]==x &&snake [j][1]==y)
        {
            system("cls");

            gotoxy(2,1);
            printf (" Perdiste \n");

            gotoxy(2,3);
            printf(" Score : %d \n", score);
            printf("\n \n");

            if (score > 0)
            {
//                ficheros(score);
                t=1,tama=3,x=10,y=12,direccion=3,coordx=30,coordy=15,score=0;
//                Menuprincipal();
                return false;
            }
            else
            {
                t=1,tama=3,x=10,y=12,direccion=3,coordx=30,coordy=15,score=0;

//                Menuprincipal();
                return false;
            }
        }
        return true;
    }
}

