#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
int main()
{
    menuMundos();
    printf("\n");
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
    system("color f5");
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
    for(i=20; i<=110; i++)
    {
        gotoxy (i,3);
        printf("%c", 177);
    }
    //Parte Izquierda Capa 1
    for(i=3; i<=20; i++)
    {
        gotoxy (19,i);
         printf("%c", 177);
    }
    //Parte Derecha Capa 1
    for(i=3; i<=20; i++)
    {
        gotoxy (110,i);
        printf("%c", 177);
    }
    //Parte Abajo Capa 1
    for(i=20; i<=110; i++)
    {
        gotoxy (i,20);
        printf("%c", 177);
    }
    system("color f5");
}

