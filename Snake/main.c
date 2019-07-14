#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
int main()
{
    menuMundos();
    printf("\n");
    system("color f5");
    return 0;
}
void menuMundos()
{

        char menu1 = '0';
        printf(" \t\t|********************************************|\n");
        printf(" \t\t|                                            |\n");
        printf(" \t\t|                  NIVELES                   |\n");
        printf(" \t\t|                                            |\n");
        printf(" \t\t|  ****  ****  ****  ****  ****  ****  ****  |\n");
        printf(" \t\t|***  ****  ****  ****  ****  ****  ****  ***|\n");
        printf(" \t\t|                                            |\n");
        printf(" \t\t| 1- Primer nivel                            |\n");
        printf(" \t\t| 2- Segundo nivel                           |\n");
        printf(" \t\t| 3- Menu inicial                            |\n");
        printf(" \t\t|____________________________________________|\n");
         menu1=(getch());
        switch (menu1)
        {
        case '1':
            system("cls");
//            jugar();
            world_style();
            break;

        case '2':
                system ("cls");
//                jugar2();
            break;

        case '3':
            system("cls");
//            Menuinicial();
            break;
         default:
            system ("cls");
            printf("Opcion no valida. Inserte una opcion valida.\n\n");
            menuMundos();
            break;
    }
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

