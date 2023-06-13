#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#ifndef MAX  
#define MAX 10000
#endif

char cadena[MAX];
extern void PantallaCarga();
extern void AnAvion();
extern void AutoFantastico();
extern void Carrera();
extern void Choque();

char cadenaRemove[MAX];
char cadenaRescri[MAX];
char primera[MAX];
char segunda[MAX];

int pines[] = {14, 15, 18, 23, 24, 25, 8, 7};

int bits[8];

void EncenderLuces(int pin, int estado);

void IntToBinario(int n) {
    int i = 7;
    while (i != -1) {
        bits[i] = n % 2;
        n = n / 2;
        i = i - 1;
    }
    for (int x = 0; x < 8; x++) {
        EncenderLuces(pines[x], bits[x]);
    }
}

void EncenderLuces(int pin, int estado) {
    memset(cadenaRescri, 0, MAX);
    sprintf(cadenaRescri, "%u", pin);
    strncpy(primera, "gpio -g write ", MAX);
    strncat(primera, cadenaRescri, MAX);
    if (estado == 1) {
        strncat(primera, " 1", MAX);
    } else {
        strncat(primera, " 0", MAX);
    }
    system(primera);
    memset(primera, 0, MAX);
    memset(segunda, 0, MAX);
    memset(cadenaRescri, 0, MAX);
}

int main() {
    system("gpio -g mode 14 output");
    system("gpio -g mode 15 output");
    system("gpio -g mode 18 output");
    system("gpio -g mode 23 output");
    system("gpio -g mode 24 output");
    system("gpio -g mode 25 output");
    system("gpio -g mode 8 output");
    system("gpio -g mode 7 output");

    int opcion = 0;

    printf("\n\t\t\tB I E N V E N I D O S  A L  S I S T E M A\n");
    printf("\nSeleccione el numero para mostrar en pantalla\n");
    printf("\n1. Auto Fantastico\n");
    printf("2. El Choque\n");
    printf("3. La Carrera\n");
    printf("4. Pantalla de carga\n");
    printf("5. Animacion de avion en el aire\n");
    printf("\n6. Salir\n");

    while (opcion < 1 || opcion > 6) {
        printf("Numero de secuencia seleccionada: ");
        scanf("%d", &opcion);
    }

    switch (opcion) {
        case 1:
            system("clear");
            AutoFantastico();
            break;
        case 2:
            system("clear");
            Choque();
            break;
        case 3:
            system("clear");
            Carrera();
            break;
        case 4:
            system("clear");
            PantallaCarga();
            break;
        case 5:
            system("clear");
            AnAvion();
            break;
        case 6:
            system("clear");
            printf("\n\n\tGracias por utilizar el sistema\n");
            break;
        default:
            printf("Opcion no valida. Intente nuevamente\n");
            break;
    }

    return 0;
}