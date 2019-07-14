#include <stdio.h>
#include <stdlib.h>

int menuMundos()
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
int main()
{
    printf("Hello world!\n");
    return 0;
}
