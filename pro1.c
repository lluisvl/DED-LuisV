#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Jugador {
    char nombre[50];
    int vida;
    int defensa;
    void (*magias[3])(void*, void*);
};

// Magia
void usarDestructor(void* jugador1, void* jugador2) {
    struct Jugador* j1 = (struct Jugador*) jugador1;
    struct Jugador* j2 = (struct Jugador*) jugador2;
    
    int dado = rand() % 20 + 1;
    if (dado >= j2->defensa) {
        int daño = dado == 20 ? 120 : 60;
        j2->vida -= daño;
        printf("%s uso Destructor: dado %d, haces %d de daño a %s\n", j1->nombre, dado, daño, j2->nombre);
    } else {
        printf("%s fallo el ataque con Destructor: dado %d, no supera la defensa de %s\n", j1->nombre, dado, j2->nombre);
    }
}

void usarMedico(void* jugador1, void* jugador2) {
    struct Jugador* j1 = (struct Jugador*) jugador1;
    j1->vida += 15;
    printf("%s uso Medico: recuperas 15 puntos de vida.\n", j1->nombre);
}

void usarKapkan(void* jugador1, void* jugador2) {
    printf("%s uso Kapkan: el turno del oponente sera saltado.\n", ((struct Jugador*)jugador1)->nombre);
}

void usarCastle(void* jugador1, void* jugador2) {
    struct Jugador* j1 = (struct Jugador*) jugador1;
    j1->defensa += 5;
    printf("%s uso Castle: defensa incrementada en 5.\n", j1->nombre);
}

void usarAsh(void* jugador1, void* jugador2) {
    printf("%s uso Ash: tendras un turno extra.\n", ((struct Jugador*)jugador1)->nombre);
}

// Poderes disponibles
void mostrarPoderes() {
    char poderes_disponibles[5][50] = {
        "Destructor: 60 de daño a tu rival, 30 a ti",
        "Medico: Recupera 15 puntos de vida",
        "Kapkan: Salta el turno de tu rival",
        "Castle: Te quitan solo 5 puntos cuando te ataquen",
        "Ash: Tienes un turno extra"
    };

    printf("Poderes disponibles:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, poderes_disponibles[i]);
    }
}

int tirarDado() {
    return rand() % 20 + 1;
}

int main() {
    struct Jugador jugadores[2];

    srand(time(NULL));

    // Inicio del juego version del jugador
    printf("=======================¡Bienvenido a LLUISVL!=======================\n\n");
    printf("Instrucciones de juego:\n");
    printf("LLUISVL es un juego de Rol de 2 jugadores (Humano vs CPU). El juego se desarrolla por turnos, donde tu mision es aniquilar a la maquina, tendras 3 opciones atacar, defender o utilizar magia.\n\n");
    printf("Atacar: Se tira un dado de 20, si el resultado es mayor o igual a la defensa del otro jugador entonces el ataque es exitoso y hará 10 de daño,si el resultado es 20 se hara el doble de daño.\n \n Defender: Aumentará la vida del jugador por 5 hasta el inicio de su siguiene turno.\n\n Magia: Cada Jugador tendrá 3 funciones independientes con ataques mágicos.\n\n");
    printf("Ingresa tu nombre: ");
    scanf("%s", jugadores[0].nombre);
    jugadores[0].vida = 100;
    jugadores[0].defensa = 10;

    // Computadora
    strcpy(jugadores[1].nombre, "Computadora");
    jugadores[1].vida = 100;
    jugadores[1].defensa = 10;

    // Jugador eliga su magia
    printf("Selecciona 3 poderes magicos de la lista:\n\n");
mostrarPoderes();

int seleccion;
for (int i = 0; i < 3; i++) {
    do {
        printf("Selecciona el poder %d (1-5): ", i + 1);
        scanf("%d", &seleccion);

        if (seleccion < 1 || seleccion > 5) {
            printf("Opcion invalida. Elige un numero entre 1 y 5\n");
        }
    } while (seleccion < 1 || seleccion > 5); 

    jugadores[0].magias[i] = (seleccion == 1) ? usarDestructor :
                             (seleccion == 2) ? usarMedico :
                             (seleccion == 3) ? usarKapkan :
                             (seleccion == 4) ? usarCastle :
                                                usarAsh;
}

    // Seleccion magia computadora
    for (int i = 0; i < 3; i++) {
        seleccion = rand() % 5 + 1;
        jugadores[1].magias[i] = (seleccion == 1) ? usarDestructor :
                                 (seleccion == 2) ? usarMedico :
                                 (seleccion == 3) ? usarKapkan :
                                 (seleccion == 4) ? usarCastle :
                                                    usarAsh;
    }

    // Comienzo el juego
    while (jugadores[0].vida > 0 && jugadores[1].vida > 0) {
        printf("\nTurno de %s (Tienes %d%% de vida)\n", jugadores[0].nombre, jugadores[0].vida);
        printf("La computadora tiene %d%% de vida\n", jugadores[1].vida);
        printf("Elige tu accion:\n1. Atacar\n2. Defender\n3. Usar magia\n");
        int accion;
        scanf("%d", &accion);

        switch (accion) {
            case 1: {
                int dado = tirarDado();
                if (dado >= jugadores[1].defensa) {
                    int daño = (dado == 20) ? 20 : 10;
                    jugadores[1].vida -= daño;
                    printf("Ataque exitoso: dado %d. %s recibe %d de daño.\n", dado, jugadores[1].nombre, daño);
                } else {
                    printf("Ataque fallido: dado %d. No supera la defensa de %s.\n", dado, jugadores[1].nombre);
                }
                break;
            }
            case 2:
                jugadores[0].defensa += 5;
                printf("Defensa incrementada en 5.\n");
                break;
            case 3: {
                printf("Elige tu magia (1-3): ");
                scanf("%d", &seleccion);
                jugadores[0].magias[seleccion - 1](&jugadores[0], &jugadores[1]);
                break;
            }
        }

        // Turno de la computadora
        if (jugadores[1].vida > 0) {
    printf("\nTurno de la computadora\n");
    accion = rand() % 3 + 1; 
    if (accion == 1) {
        int dado = tirarDado(); 
        if (dado >= jugadores[0].defensa) {
            int danio = (dado == 20) ? 20 : 10;
            jugadores[0].vida -= danio;
            printf("Ataque de la computadora exitoso: dado %d. %s recibe %d de daño.\n", dado, jugadores[0].nombre, danio);
        } else {
            printf("Ataque de la computadora fallido: dado %d. No supera tu defensa.\n", dado);
        }
            } else if (accion == 2) {
                jugadores[1].defensa += 5;
                printf("La computadora incrementa su defensa en 5.\n");
            } else {
                seleccion = rand() % 3;
                jugadores[1].magias[seleccion](&jugadores[1], &jugadores[0]);
            }
        }
    }

    // Final del juego
    if (jugadores[0].vida <= 0) {
        printf("\n%s La tecnologia nos ha vuelto a ganar :(. La computadora gana.\n", jugadores[0].nombre);
    } else {
        printf("\nLa humanidad vence a las maquinas :), ¡Ganaste!\n");
    }

    return 0;
}
