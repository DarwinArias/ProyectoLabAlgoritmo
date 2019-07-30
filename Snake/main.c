#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int x;
    int y;
    int direccion;
} coordenada;

typedef struct
{
    char buffer[500];
    char nombre[50];
    int score;
} read;

char * leer(void);
void comida_2();
void comida();
void imprimir_scores();
void jugar();
void jugar_2();
void world_style();
void gotoxy (int x, int y);
void DibujarSnake();
void BorrarSnake();
void archivo (int frecord);
void palabra_snake();
void ordenar_mundo_1();
int Menuinicial();
void ordenar_mundo_2();
void elegir_scores();
void score_mundo_1();
void score_mundo_2();
void archivo_2(int frecord);
void perdiste_1();
void perdiste_2();

coordenada head;
coordenada cuerpo[50];
coordenada food;
int tama=3;
int t=1;
read linea[500];
read linea2[500];
int score = 0;



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

void world_style_2()
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
    // OBSTACULO 1.
    gotoxy(20,10);
    printf("%C", 177);
    gotoxy(21,10);
    printf("%C", 177);
    gotoxy(22,10);
    printf("%C", 177);
    // OBSTACULO 2.
    gotoxy(70,18);
    printf("%C", 177);
    gotoxy(70,19);
    printf("%C", 177);
    gotoxy(70,20);
    printf("%C", 177);
    // OBSTACULO 3.
    gotoxy(42,16);
    printf("%C", 177);
    gotoxy(42,17);
    printf("%C", 177);
    gotoxy(41,16);
    printf("%C", 177);
    gotoxy(41,17);
    printf("%C", 177);
    system("color f5");
}

void DibujarSnake()
{
    int i;
    for (i=1; i<tama; i++)
    {
        gotoxy(cuerpo[i].x,cuerpo[i].y);
        printf("o");
    }
}

void BorrarSnake()
{
    gotoxy(cuerpo[t].x,cuerpo[t].y);
    printf(" ");
}

void Movimiento_Snake()
{
    cuerpo[t].x=head.x;
    cuerpo[t].y=head.y;
    t++;
    if (t==tama)
    {
        t=1;
    }
}

void comida()
{
    if (head.x==food.x && head.y==food.y)
    {
        food.x=(rand()%71)+4;
        food.y=(rand()%24)+4;
        tama++;
        score+=5;
        if(food.x <= 2)
        {
            food.x=35;
        }
        if(food.x >= 77)
        {
            food.x=11;
        }
        if(food.y <= 4)
        {
            food.y=11;
        }
        if(food.y >= 22)
        {
            food.y=18;
        }
        gotoxy(food.x,food.y);
        printf("%c", 208);
    }
}

void comida_2()
{
    if (head.x==food.x && head.y==food.y)
    {
        food.x=(rand()%71)+4;
        food.y=(rand()%24)+4;
        tama++;
        score+=5;
        if(food.x <= 2)
        {
            food.x=35;
        }

        if(food.x >= 77)
        {
            food.x=11;
        }
        if(food.y <= 4)
        {
            food.y=11;
        }
        if(food.y >= 22)
        {
            food.y=18;
        }
        //Obstaculos
        if( (food.x==20 && food.y==10) || (food.x==21 && food.y==10) || (food.x==22 && food.y==10) || (food.x==70 && food.y==18) || (food.x==70 && food.y==19) || (food.x==70 && food.y==20) || (food.x==42 && food.y==17) || (food.x==42 && food.y==17) || (food.x==41 && food.y==16) || (food.x==41 && food.y==17))
        {
            food.x = 5;
            food.y = 15;
        }
        gotoxy(food.x,food.y);
        printf("%c", 208);
    }
}

void menuNiveles()
{
    system("color f5");
    char menu1 = '0';
    printf(" \t|********************************************|\n");
    printf(" \t|                                            |\n");
    printf(" \t|                  NIVELES                   |\n");
    printf(" \t|                                            |\n");
    printf(" \t|  ****  ****  ****  ****  ****  ****  ****  |\n");
    printf(" \t|***  ****  ****  ****  ****  ****  ****  ***|\n");
    printf(" \t|                                            |\n");
    printf(" \t| 1- Primer nivel.                           |\n");
    printf(" \t| 2- Segundo nivel.                          |\n");
    printf(" \t| 3- Menu inicial.                           |\n");
    printf(" \t|____________________________________________|\n");
    menu1=(getch());

    switch (menu1)
    {
    case '1':
        system("cls");
        jugar();
        break;
    case '2':
        system ("cls");
        jugar_2();
        break;
    case '3':
        system("cls");
        Menuinicial();
        break;
    default:
        system ("cls");
        printf("Opcion no valida. Inserte una opcion valida.\n\n");
        menuNiveles();
        break;
    }
}

void palabra_snake()
{
    system("color f5");
    printf("\n\n");
    printf("\t|---------------------------------------------------------------------------------|\n");
    printf("\t|                                                                                 |\n");
    printf("\t| **********    *****        ***    *************    ***     ***    ************  |\n");
    printf("\t| **********    ******       ***    *************    ***    ***     ************  |\n");
    printf("\t| ***           *** ***      ***    ****     ****    ***   ***      ***           |\n");
    printf("\t| ***           ***  ***     ***    ****     ****    ***  ***       ***           |\n");
    printf("\t| **********    ***   ***    ***    *************    *******        ********      |\n");
    printf("\t| **********    ***    ***   ***    *************    *******        ********      |\n");
    printf("\t|        ***    ***     ***  ***    ****     ****    ***  ***       ***           |\n");
    printf("\t|        ***    ***      *** ***    ****     ****    ***   ***      ***           |\n");
    printf("\t| **********    ***       ******    ****     ****    ***    ***     ************  |\n");
    printf("\t| **********    ***        *****    ****     ****    ****    ***    ************  |\n");
    printf("\t|                                                                                 |\n");
    printf("\t|                                                                                 |\n");
    printf("\t|_________________________________________________________________________________|\n");

}

int Menuinicial()
{
    char menu = '0';
    FILE * f;
    char v;
    printf(" \t|********************************************|\n");
    printf(" \t|                                            |\n");
    printf(" \t|                 JUEGO SNAKE                |\n");
    printf(" \t|                                            |\n");
    printf(" \t|  ****  ****  ****  ****  ****  ****  ****  |\n");
    printf(" \t|***  ****  ****  ****  ****  ****  ****  ***|\n");
    printf(" \t|                                            |\n");
    printf(" \t| Presione 1 para jugar.                     |\n");
    printf(" \t| Presione 2 para ver los scores.            |\n");
    printf(" \t| Presione 3 para salir.                     |\n");
    printf(" \t|____________________________________________|\n");

    menu= getch();

    switch (menu)
    {
    case '1':
        system("cls");
        menuNiveles();
        break;
    case '2':
        f = fopen("record.txt", "rt");
        if (f==NULL)
        {
            printf(" Error en la apertura. Es posible que el fichero no exista. \n ");
            printf("****************************\n");
            printf("* Presione 'v' para volver *\n");
            printf("****************************\n");
            v=getch();
            switch(v)
            {
            case 'v':
                Menuinicial();
                break;
            }
        }
        else
        {
            elegir_scores();
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
    return -1;
}

void elegir_scores()
{
    char opcion = '0';
    system("CLS");
    printf("------Scores------\n\n");
    printf("1 - Nivel 1\n");
    printf("2 - Nivel 2\n");
    printf("Elija:");
    opcion = getch();

    if(opcion== '1')
    {
        system("CLS");
        score_mundo_1();
    }
    else if(opcion== '2')
    {
        system("CLS");
        score_mundo_2();

    }
    else
    {
        printf("\n\nDigita una opcion valida\n\n");
        system("PAUSE");
        system("CLS");
        Menuinicial();
    }

}
void score_mundo_1()
{



    printf("\t|**************************|\n");
    printf("\t|                          |\n");
    printf("\t|      SCORES MUNDO 1      |\n");
    printf("\t|                          |\n");
    printf("\t|__________________________|\n");
    printf("\n\n");
    printf("\t|___________Top_10___________|\n");
    printf("\n\n");
    ordenar_mundo_1();
    printf("\n\n");
    system("PAUSE");
    system("CLS");
    Menuinicial();
}
void score_mundo_2()
{
    printf("\t|**************************|\n");
    printf("\t|                          |\n");
    printf("\t|      SCORES MUNDO 2      |\n");
    printf("\t|                          |\n");
    printf("\t|__________________________|\n");
    printf("\n\n");
    printf("\t|___________Top_10___________|\n");
    printf("\n\n");
    ordenar_mundo_2();
    printf("\n\n");
    system("PAUSE");
    system("CLS");
    Menuinicial();
}

bool Perder()
{
    int j;
    //CONDICIONES PARA PERDER CON LOS MARCOS.
    if (head.y==3 || head.y==23 ||head.x==2 ||head.x==77)
    {
        perdiste_1();
    }
    for (j=tama-1; j>0; j--)
    {
        if(head.x==cuerpo[j].x && head.y==cuerpo[j].y)
        {
            perdiste_1();
        }
    }

    return true;
}
void perdiste_1()
{
    system("cls");
    gotoxy(2,1);
    printf (" Perdiste \n");
    gotoxy(2,3);
    printf(" Score : %d \n", score);
    printf("\n \n");
    if (score > 0)
    {
        archivo(score);
        t=1,tama=3,head.x=10,head.y=12,head.direccion=3,food.x=30,food.y=15,score=0;
        system("CLS");
        Menuinicial();
    }
    else
    {
        t=1,tama=3,head.x=10,head.y=12,head.direccion=3,food.x=30,food.y=15,score=0;
        system("PAUSE");
        system("CLS");
        Menuinicial();
    }
}
    bool Perder_2()
    {
        int j;
        //CONDICIONES PARA PERDER CON LOS MARCOS.
        if (head.y==3 || head.y==23 ||head.x==2 ||head.x==77)
        {
            perdiste_2();
        }
// CONDICIONES PARA PERDER CON LOS OBSTACULOS.

    else if( (head.x==20 && head.y==10) || (head.x==21 && head.y==10) || (head.x==22 && head.y==10) || (head.x==70 && head.y==18) || (head.x==70 && head.y==19) || (head.x==70 && head.y==20) || (head.x==42 && head.y==17) || (head.x==42 && head.y==17) || (head.x==41 && head.y==16) || (head.x==41 && head.y==17))
    {
        perdiste_2();
    }
    for (j=tama-1; j>0; j--)
    {
        if (head.x==cuerpo[j].x && head.y==cuerpo[j].y)
        {
            perdiste_2();
        }
    }
    return true;
}

void perdiste_2()
{
    system("cls");
    gotoxy(2,1);
    printf (" Perdiste \n");
    gotoxy(2,3);
    printf(" Score : %d \n", score);
    printf("\n \n");
    if (score > 0)
    {
        archivo_2(score);
        t=1,tama=3,head.x=10,head.y=12,head.direccion=3,food.x=30,food.y=15,score=0;
        system("CLS");
        Menuinicial();
    }
    else
    {
        t=1,tama=3,head.x=10,head.y=12,head.direccion=3,food.x=30,food.y=15,score=0;
        system("PAUSE");
        system("CLS");
        Menuinicial();
    }
}

void jugar()
{
    //sndPlaySoundA8("C:\\Users\\USUARIO\\Desktop\\ProyectoLabAlgoritmo",0);
    char boton = 0;
    system("color f5");
    printf (" PRIMER MUNDO ");
    world_style();
    gotoxy(food.x,food.y); //ubica la serpiente en esta posicion
    printf("%c", 208);
    while (Perder())
    {
        BorrarSnake();
        Movimiento_Snake();
        DibujarSnake();
        comida();
        if (kbhit())
        {
            boton=getch();
            switch (boton)
            {
            case 72: //arriba en ascii
                if (head.direccion!=2)  //no puede ser abajo
                {
                    head.direccion=1;
                }
                break;
            case 80: // abajo en ascii
                if (head.direccion!=1)  //no puede ser arriba
                {
                    head.direccion=2;
                }
                break;
            case 77: //derecha en ascii
                if(head.direccion!=4) // no puede ser izquierda
                {
                    head.direccion=3;
                }
                break;

            case 75: // izquierda en ascii
                if (head.direccion!=3)  //no puede ser derecha
                {
                    head.direccion=4;
                }
                break;
            }
        }
        if (head.direccion==1)
        {
            head.y--;
        }
        if (head.direccion==2)
        {
            head.y++;
        }
        if (head.direccion==3)
        {
            head.x++;
        }
        if (head.direccion==4)
        {
            head.x--;
        }
        Sleep(100); //disminuye la velocidad con la que se imprime en la pantalla en un tiempo expresado en milisegundos
        gotoxy(3,24);
        printf("Score: %d",score);
    }
    system ("pause>null");
}

void jugar_2()
{
    char boton = 0;
    system("color f5");
    printf (" PRIMER MUNDO ");
    world_style_2();
    gotoxy(food.x,food.y); //ubicala serpiente en esta posicion
    printf("%c", 208);
    while (Perder_2())
    {
        BorrarSnake();
        Movimiento_Snake();
        DibujarSnake();
        comida_2();
        if (kbhit())
        {
            boton=getch();
            switch (boton)
            {
            case 72: //arriba en ascii
                if (head.direccion!=2)  //no puede ser abajo
                {
                    head.direccion=1;
                }
                break;
            case 80: // abajo en ascii
                if (head.direccion!=1)  //no puede ser arriba
                {
                    head.direccion=2;
                }
                break;
            case 77: //derecha en ascii
                if(head.direccion!=4) // no puede ser izquierda
                {
                    head.direccion=3;
                }
                break;
            case 75: // izquierda en ascii
                if (head.direccion!=3)  //no puede ser derecha
                {
                    head.direccion=4;
                }
                break;
            }
        }
        if (head.direccion==1)
        {
            head.y--;
        }
        if (head.direccion==2)
        {
            head.y++;
        }
        if (head.direccion==3)
        {
            head.x++;
        }
        if (head.direccion==4)
        {
            head.x--;
        }
        Sleep(100); //disminuye la velocidad con la que se imprime en la pantalla en un tiempo expresado en milisegundos
        gotoxy(3,24);
        printf("Score: %d",score);
    }
    system ("pause>null");
}

void archivo (int frecord)
{
    char *nombre;
    FILE *highscore;
    FILE * nombres;
    highscore = fopen ("record.txt", "a+");
    nombres = fopen ("nombres.txt", "a+");
    if (highscore==NULL)
    {
        printf(" Error en la apertura. Es posible que el fichero no exista. \n ");
    }
    else
    {
        printf ("Escriba su nombre: ");
        nombre = leer();
        fprintf (nombres,"%s\n",nombre);
        fprintf (highscore,"%d\n",frecord);
        fclose (highscore);
        fclose (nombres);
    }
}

void archivo_2 (int frecord)

{

    char *nombre;
    FILE *highscore;
    FILE * nombres;
    highscore = fopen ("record_2.txt", "a+");
    nombres = fopen ("nombres_2.txt", "a+");
    if (highscore==NULL)
    {
        printf(" Error en la apertura. Es posible que el fichero no exista. \n ");
    }
    else
    {
        printf ("Escriba su nombre: ");
        nombre = leer();
        fprintf (nombres,"%s\n",nombre);
        fprintf (highscore,"%d\n",frecord);
        fclose (highscore);
        fclose (nombres);
    }
}

char * leer(void)

{
    char * arr;
    char c;
    arr =(char*)malloc(sizeof(char));
    int i = 0;
    *arr = '\0';
    while ((c=getchar()) != '\n')
    {
        arr = (char*)realloc(arr,(i+2)*sizeof(char));
        arr[i++]= c;
        arr[i]= '\0';
    }
    return arr;
}

void ordenar_mundo_1()
{
    FILE * f;
    FILE * f2;
    int i;
    int j;
    read temp;

    f=fopen("record.txt","r");
    f2=fopen("nombres.txt","r");
    for (i = 0; i < 50; i++)
    {
        fgets(linea[i].buffer, 1024, (FILE*) f);
        linea[i].score = atoi(linea[i].buffer);
        fgets(linea[i].buffer, 1024, (FILE*) f2);
        strcpy(linea[i].nombre,linea[i].buffer);
    }

    for (j=0; j<50; j++)
    {
        for(i=0; i<50; i++)
        {
            if(linea[i].score<linea[i+1].score)
            {
                temp = linea[i+1];
                linea[i+1]=linea[i];
                linea[i]=temp;
            }
        }
    }
    fclose(f);
    fclose(f2);
    imprimir_scores();
}

void imprimir_scores()
{
    int i;
    for(i=0 ; i<10; i++)
    {
        printf("\t%d-Nombre: %s", i+1, linea[i].buffer);
        printf("\tScore: %d",linea[i].score);
        printf("\n");
    }
}

void imprimir_scores2()
{
    int i;
    for(i=0 ; i<10; i++)
    {
        printf("\t%d-Nombre: %s", i+1, linea2[i].buffer);
        printf("\tScore: %d",linea2[i].score);
        printf("\n");
    }
}

void ordenar_mundo_2()
{
    FILE * f;
    FILE * f2;
    int i;
    int j;
    read temp;

    f=fopen("record_2.txt","r");
    f2=fopen("nombres_2.txt","r");
    for (i = 0; i < 50; i++)
    {
        fgets(linea2[i].buffer, 1024, (FILE*) f);
        linea2[i].score = atoi(linea2[i].buffer);
        fgets(linea2[i].buffer, 1024, (FILE*) f2);
        strcpy(linea2[i].nombre,linea2[i].buffer);
    }

    for (j=0; j<50; j++)
    {
        for(i=0; i<50; i++)
        {
            if(linea2[i].score<linea2[i+1].score)
            {
                temp = linea2[i+1];
                linea2[i+1]=linea2[i];
                linea2[i]=temp;
            }
        }
    }
    fclose(f);
    fclose(f2);

    imprimir_scores2();
}
