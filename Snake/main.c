#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <windows.h>

#include <stdbool.h>

typedef struct
{
    int x;
    int y;
    int direccion;
} coordenada;

char * leer(void);

void jugar();

void jugar_2();

void world_style();

void gotoxy (int x, int y);

void DibujarSnake();

void BorrarSnake();

void archivo (int frecord);

void palabra_snake();

int Menuinicial();

coordenada head;


coordenada cuerpo[50];
coordenada food;


char *nombre;


char buffer[500];
int tama=3;

int snake [50][2];

int t=1;


char boton = 0;

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

        t=1;

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

//        jugar_2();

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

    //system("color f5");

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

            system("CLS");

            printf("\t|**************************|\n");

            printf("\t|                          |\n");

            printf("\t|          SCORES          |\n");

            printf("\t|                          |\n");

            printf("\t|__________________________|\n");

            printf("\n\n");

            int counter =0;

            printf("\t|___________Top_10________|\n");

            printf("\n\n");

            while(fgets(buffer, 1024, (FILE*) f) && (counter <10))
            {

                printf ("\t%s",buffer);

                counter++;

            }

            printf("\n\n");

            system("PAUSE");

            system("CLS");

            Menuinicial();

        }

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

    return -1;



}

bool Perder()

{

    int j;


    //CONDICIONES PARA PERDER CON LOS MARCOS.

    if (head.y==3 || head.y==23 ||head.x==2 ||head.x==77)

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

            return false;

        }

        else

        {

            t=1,tama=3,head.x=10,head.y=12,head.direccion=3,food.x=30,food.y=15,score=0;

            system("PAUSE");

            system("CLS");

            Menuinicial();

            return false;

        }

    }


    for (j=tama-1; j>0; j--)

    {

//        if (cuerpo[j].x==head.x &&cuerpo[j].y==head.y)
        if(head.x==cuerpo[j].x && head.y==cuerpo[j].y)

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

                return false;

            }

            else

            {

                t=1,tama=3,head.x=10,head.y=12,head.direccion=3,food.x=30,food.y=15,score=0;

                system("PAUSE");

                system("CLS");

                Menuinicial();

                return false;

            }

        }

        return true;



    }

    return -1;

}





//bool Perder_2()
//
//{
//
//    int i;
//
//    int j;
//
//    //CONDICIONES PARA PERDER CON LOS MARCOS.
//
//    if (y==3 || y==23 ||x==2 ||x==77)
//
//    {
//
//        system("cls");
//
//
//
//        gotoxy(2,1);
//
//        printf (" Perdiste \n");
//
//
//
//        gotoxy(2,3);
//
//        printf(" Score : %d \n", score);
//
//        printf("\n \n");
//
//
//
//        if (score > 0)
//
//        {
//
//            archivo(score);
//
//            t=1,tama=3,x=10,y=12,direccion=3,coordx=30,coordy=15,score=0;
//
//            system("CLS");
//
//            Menuinicial();
//
//            return false;
//
//        }
//
//        else
//
//        {
//
//            t=1,tama=3,x=10,y=12,direccion=3,coordx=30,coordy=15,score=0;
//
//            system("PAUSE");
//
//            system("CLS");
//
//            Menuinicial();
//
//            return false;
//
//        }
//
//
//
//// CONDICIONES PARA PERDER CON LOS OBSTACULOS.
//
//    }
//
//    else if( (x==20 && y==10) || (x==21 && y==10) || (x==22 && y==10) || (x==70 && y==18) || (x==70 && y==19) || (x==70 && y==20) || (x==42 && y==17) || (x==42 && y==17) || (x==41 && y==16) || (x==41 && y==17))
//
//    {
//
//
//
//        system("cls");
//
//
//
//        gotoxy(2,1);
//
//        printf (" Perdiste \n");
//
//
//
//        gotoxy(2,3);
//
//        printf(" Score : %d \n", score);
//
//        printf("\n \n");
//
//
//
//        if (score > 0)
//
//        {
//
//            archivo(score);
//
//            t=1,tama=3,x=10,y=12,direccion=3,coordx=30,coordy=15,score=0;
//
//            system("CLS");
//
//            Menuinicial();
//
//            return false;
//
//        }
//
//        else
//
//        {
//
//            t=1,tama=3,x=10,y=12,direccion=3,coordx=30,coordy=15,score=0;
//
//            system("PAUSE");
//
//            system("CLS");
//
//            Menuinicial();
//
//            return false;
//
//
//
//        }
//
//for(i = 0; i< tama-1; i++){
//
//    for (j=tama-1; j>0; j--)
//
//    {
//
//        if (snake[j][i]==x &&snake [j][i+1]==y)
//
//        {
//
//            system("cls");
//
//
//
//            gotoxy(2,1);
//
//            printf (" Perdiste \n");
//
//
//
//            gotoxy(2,3);
//
//            printf(" Score : %d \n", score);
//
//            printf("\n \n");
//
//
//
//            if (score > 0)
//
//            {
//
//                archivo(score);
//
//                t=1,tama=3,x=10,y=12,direccion=3,coordx=30,coordy=15,score=0;
//
//                system("CLS");
//
//                Menuinicial();
//
//                return false;
//
//            }
//
//            else
//
//            {
//
//                t=1,tama=3,x=10,y=12,direccion=3,coordx=30,coordy=15,score=0;
//
//                system("PAUSE");
//
//                system("CLS");
//
//                Menuinicial();
//
//                return false;
//
//            }
//
//        }
//
//        return true;
//
//    }
//
//}
//
//}
//
//return -1;
//
//}



void jugar()

{



    //sndPlaySoundA8("C:\\Users\\USUARIO\\Desktop\\ProyectoLabAlgoritmo",0);



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

                if (head.direccion!=2) //no puede ser abajo

                    head.direccion=1;

                break;

            case 80: // abajo en ascii

                if (head.direccion!=1) //no puede ser arriba

                    head.direccion=2;

                break;

            case 77: //derecha en ascii

                if(head.direccion!=4)// no puede ser izquierda

                    head.direccion=3;

                break;

            case 75: // izquierda en ascii

                if (head.direccion!=3) //no puede ser derecha

                    head.direccion=4;

                break;

            }

        }

        if (head.direccion==1)
            head.y--;

        if (head.direccion==2)
            head.y++;

        if (head.direccion==3)
            head.x++;

        if (head.direccion==4)
            head.x--;







        Sleep(100); //disminuye la velocidad con la que se imprime en la pantalla en un tiempo expresado en milisegundos

        gotoxy(3,24);

        printf("Score: %d",score);

    }

    system ("pause>null");

}



//void jugar_2()
//
//{
//
//    system("color f5");
//
//    printf (" PRIMER MUNDO ");
//
//    world_style_2();
//
//    gotoxy(coordx,coordy); //ubicala serpiente en esta posicion
//
//    printf("%c", 5);
//
//
//
//    while (Perder_2())
//
//    {
//
//        BorrarSnake();
//
//        Movimiento_Snake();
//
//        DibujarSnake();
//
//        comida();
//
//
//
//        if (kbhit())
//
//        {
//
//            boton=getch();
//
//            switch (boton)
//
//            {
//
//            case 72: //arriba en ascii
//
//                if (direccion!=2) //no puede ser abajo
//
//                    direccion=1;
//
//                break;
//
//            case 80: // abajo en ascii
//
//                if (direccion!=1) //no puede ser arriba
//
//                    direccion=2;
//
//                break;
//
//            case 77: //derecha en ascii
//
//                if(direccion!=4)// no puede ser izquierda
//
//                    direccion=3;
//
//                break;
//
//            case 75: // izquierda en ascii
//
//                if (direccion!=3) //no puede ser derecha
//
//                    direccion=4;
//
//                break;
//
//            }
//
//        }
//
//        if (direccion==1)y--;
//
//        if (direccion==2)y++;
//
//        if (direccion==3)x++;
//
//        if (direccion==4)x--;
//
//
//
//
//
//
//
//        Sleep(100); //disminuye la velocidad con la que se imprime en la pantalla en un tiempo expresado en milisegundos
//
//        gotoxy(3,24);
//
//        printf("Score: %d",score);
//
//    }
//
//    system ("pause>null");
//
//}
//




void archivo (int frecord)

{



    FILE *highscore;

    highscore = fopen ("record.txt", "a+");

    if (highscore==NULL)

    {

        printf(" Error en la apertura. Es posible que el fichero no exista. \n ");

    }

    else

    {

        printf ("Escriba su nombre: ");

        nombre = leer();

        fprintf (highscore,"Jugador: %s | Record: %d\n",nombre,frecord);

        fclose (highscore);

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
