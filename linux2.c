#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3
#define MAX_USERS 3
#define MAX_LENGTH 50

void retardo(unsigned long int a);
void mostrar(unsigned char dato);
void choque(unsigned long int speed);
void carrera(unsigned long int speed);
void pantalla_de_carga(unsigned long int speed);
void auto_fantastico(unsigned long int speed);
void avion(unsigned long int speed);

int main() {
    unsigned long int speedini = 150000000;
    unsigned long int speed = 150000000;

    char usuarios[MAX_USERS][MAX_LENGTH] = {"Tomas", "Franco"};
    char claves[MAX_USERS][MAX_LENGTH] = {"to123", "fr123"};

    char usuario[MAX_LENGTH], password[MAX_LENGTH];

    int contador = 0;
    int ingresa = 0;
    int opcion = 0;

    do {
        system("clear");
        printf("\n\t\t\t\tB I E N V E N I D O S\n");
        printf("\t\t\t\t---------------------\n");
        printf("\t\t\t\t\tLOGIN\n");
        printf("\t\t\t\t---------------------\n");
        printf("\n\tUSUARIO: ");
        scanf("%s", usuario);
        fflush(stdin);
        char caracter;
        printf("\tPASSWORD: ");
        int index = 0;
        while ((caracter = getchar()) != ENTER) {
            if (caracter != BACKSPACE) {
                password[index++] = caracter;
                printf("*");
            } else {
                if (index > 0) {
                    printf("\b \b");
                    index--;
                }
            }
        }
        password[index] = '\0';
        for (int i = 0; i < MAX_USERS; i++) {
            if (strcmp(usuarios[i], usuario) == 0 && strcmp(claves[i], password) == 0) {
                ingresa = 1;
                break;
            }
        }
        if (!ingresa) {
            printf("\nEl usuario y/o password son incorrectos\n");
            getchar();
            contador++;
        }
    } while (ingresa == 0 && contador < INTENTOS);

    if (ingresa == 0) {
        printf("\n\tUsted no pudo ingresar al sistema. ADIOS\n");
    } else {
        printf("\n\tBienvenido al sistema!\n");
        do {
            system("clear");
            printf("\n\t\t\tB I E N V E N I D O S  A L  S I S T E M A\n");
            printf("\nSeleccione el numero para mostrar en pantalla\n");
            printf("\n1. Auto Fantastico\n");
            printf("2. El Choque\n");
            printf("3. La Carrera\n");
            printf("4. Pantalla de carga\n");
            printf("5. Animacion de avion en el aire\n");
            printf("\n6. Salir\n");

            while (opcion < 1) {
                printf("Numero de secuencia seleccionada: ");
                scanf("%d", &opcion);
            }

            switch (opcion) {
                case 1:
                    system("clear");
                    auto_fantastico(speed);
                    opcion = 0;
                    speed = speedini;
                    break;
                case 2:
                    system("clear");
                    choque(speed);
                    opcion = 0;
                    speed = speedini;
                    break;
                case 3:
                    system("clear");
                    carrera(speed);
                    opcion = 0;
                    speed = speedini;
                    break;
                case 4:
                    system("clear");
                    pantalla_de_carga(speed);
                    opcion = 0;
                    speed = speedini;
                    break;
                case 5:
                    system("clear");
                    avion(speed);
                    opcion = 0;
                    speed = speedini;
                    break;
                case 6:
                    system("clear");
                    printf("\n\n\tGracias por utilizar el sistema\n");
                    getchar();
                    break;
                default:
                    printf("Opcion no valida. Intente nuevamente\n");
                    opcion = 0;
                    break;
            }
        } while (opcion != 8);
    }
}

void retardo(unsigned long int a) {
    usleep(a);
}

void mostrar(unsigned char dato) {
    for (unsigned char mask = 128; mask > 0; mask >>= 1) {
        if (dato & mask) {
            printf("*");
        } else {
            printf("_");
        }
    }
}

void choque(unsigned long int speed) {
    unsigned char tabla[] = {0x81, 0x42, 0x24, 0x18, 0x24, 0x42};

    while (1) {
        for (int i = 0; i < 6; ++i) {
            printf("El Choque\n");
            printf("Presione ESC para volver al menu principal\n");
            printf("Delay: %lu\n", speed);
            mostrar(tabla[i]);
            retardo(speed);
            system("clear");

            if ((speed - 5000000) > 1000000) {
                if (getchar() == 27) {
                    return;
                }
            }
        }
    }
}

void carrera(unsigned long int speed) {
    unsigned char tabla[] = {0xA0, 0x30, 0x08, 0x06, 0x03, 0x01};

    while (1) {
        for (int i = 0; i < 6; ++i) {
            printf("(3) La Carrera\n");
            printf("Presione ESC para volver al menu principal\n");
            printf("Delay: %lu\n", speed);
            mostrar(tabla[i]);
            retardo(speed);
            system("clear");

            if ((speed - 5000000) > 1000000) {
                if (getchar() == 27) {
                    return;
                }
            }
        }
    }
}

void pantalla_de_carga(unsigned long int speed) {
    unsigned char tabla[] = {0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF};

    while (1) {
        for (int i = 0; i < 9; i++) {
            printf("Pantalla de carga\n");
            printf("Presione ESC para volver al menu principal\n");
            printf("Delay: %lu\n", speed);
            mostrar(tabla[i]);
            retardo(speed);
            system("clear");

            if ((speed - 5000000) > 1000000) {
                if (getchar() == 27) {
                    return;
                }
            }
        }
    }
}

void auto_fantastico(unsigned long int speed) {
    unsigned int pos = 0x80;

    while (1) {
        for (int i = 0; i < 8; ++i) {
            printf("Auto Fantastico\n");
            printf("Presione ESC para volver al menu principal\n");
            printf("Delay: %lu\n", speed);
            mostrar(pos);
            retardo(speed);
            system("clear");

            if ((speed - 5000000) > 1000000) {
                if (getchar() == 27) {
                    return;
                }
            }

            pos >>= 1;
        }
        for (int i = 0; i < 6; ++i) {
            printf("Auto Fantastico\n");
            printf("Presione ESC para volver al menu principal\n");
            printf("Delay: %lu\n", speed);
            mostrar(pos);
            retardo(speed);
            system("clear");

            if ((speed - 5000000) > 1000000) {
                if (getchar() == 27) {
                    return;
                }
            }

            pos <<= 1;
        }
    }
}

void avion(unsigned long int speed) {
    unsigned char tabla[] = {0x08, 0x0C, 0x0E, 0x0F, 0x0E, 0x0C};

    while (1) {
        for (int i = 0; i < 6; ++i) {
            printf("Animacion de avion en el aire\n");
            printf("Presione ESC para volver al menu principal\n");
            printf("Delay: %lu\n", speed);
            mostrar(tabla[i]);
            retardo(speed);
            system("clear");

            if ((speed - 5000000) > 1000000) {
                if (getchar() == 27) {
                    return;
                }
            }
        }
    }
}
