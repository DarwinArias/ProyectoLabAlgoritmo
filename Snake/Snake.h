#ifndef SNAKE_H
#define SNAKE_H
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
    int puntaje;
} read;

coordenada head;
coordenada cuerpo[50];
coordenada food;

void gotoxy (int x, int y);
char * leer(void);
void palabra_snake();
int Menuinicial();
void comida_2();
void comida();
void imprimir_scores();
void jugar();
void jugar_2();
void world_style();
void DibujarSnake();
void BorrarSnake();
void ordenar_mundo_1();
void ordenar_mundo_2();
void elegir_scores();
void score_mundo_1();
void score_mundo_2();
void archivo (int frecord);
void archivo_2(int frecord);
void perdiste_1();
void perdiste_2();
#endif
