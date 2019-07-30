#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "Snake.h"

int main()

{
    head.x=10;
    head.y=12;
    head.direccion = 3;
    food.x=30;
    food.y=15;
    palabra_snake();
    printf("\n\n");
    system("PAUSE");
    system("CLS");
    Menuinicial();
    printf("\n");
    return 0;

}

