#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//LUIS LEAL & JOSE DE LA TORRE
//PROYECTO 3 HUFFMAN

#define MAX_CHAR 256

// odo para el arbol
typedef struct Nodo {
    char caracter;
    int frecuencia;
    struct Nodo *izquierdo, *derecho;
} Nodo;

// funciones auxiliares para nodos
Nodo *crearNodo(char caracter, int frecuencia, Nodo *izquierdo, Nodo *derecho) {
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo->caracter = caracter;
    nodo->frecuencia = frecuencia;
    nodo->izquierdo = izquierdo;
    nodo->derecho = derecho;
    return nodo;
}

//estructura para el mapa
typedef struct {
    char caracter;
    char *codigo;
} Mapa;

typedef struct {
    Mapa *elementos;
    int capacidad;
    int tamano;
} Map;

Map *crearMapa(int capacidad) {
    Map *mapa = (Map *)malloc(sizeof(Map));
    mapa->elementos = (Mapa *)malloc(capacidad * sizeof(Mapa));
    mapa->capacidad = capacidad;
    mapa->tamano = 0;
    return mapa;
}

void mapPut(Map *mapa, char caracter, char *codigo) {
    mapa->elementos[mapa->tamano].caracter = caracter;
    mapa->elementos[mapa->tamano].codigo = strdup(codigo);
    mapa->tamano++;
}

char *mapGet(Map *mapa, char caracter) {
    for (int i = 0; i < mapa->tamano; i++) {
        if (mapa->elementos[i].caracter == caracter) {
            return mapa->elementos[i].codigo;
        }
    }
    return NULL;
}
void liberarMapa(Map *mapa) {
    for (int i = 0; i < mapa->tamano; i++) {
        free(mapa->elementos[i].codigo);
    }
    free(mapa->elementos);
    free(mapa);
}

// contar frecuencias
void contFrecuencias(const char *texto, int frecuencias[]) {
    for (int i = 0; i < MAX_CHAR; i++) {
        frecuencias[i] = 0;
    }
    for (int i = 0; texto[i] != '\0'; i++) {
        frecuencias[(unsigned char)texto[i]]++;
    }
}

// construir arbol
typedef struct {
    Nodo **datos;
    int capacidad;
    int tamano;
} ColaPrioridad;

ColaPrioridad *crearCola(int capacidad) {
    ColaPrioridad *cola = (ColaPrioridad *)malloc(sizeof(ColaPrioridad));
    cola->datos = (Nodo **)malloc(capacidad * sizeof(Nodo *));
    cola->capacidad = capacidad;
    cola->tamano = 0;
    return cola;
}

void insertarCola(ColaPrioridad *cola, Nodo *nodo) {
    int i = cola->tamano++;
    while (i > 0 && cola->datos[(i - 1) / 2]->frecuencia > nodo->frecuencia) {
        cola->datos[i] = cola->datos[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    cola->datos[i] = nodo;
}

Nodo *extraerMinimo(ColaPrioridad *cola) {
    Nodo *min = cola->datos[0];
    cola->datos[0] = cola->datos[--cola->tamano];

    int i = 0, hijo;
    Nodo *temp = cola->datos[0];
    while ((hijo = 2 * i + 1) < cola->tamano) {
        if (hijo + 1 < cola->tamano && 
            cola->datos[hijo + 1]->frecuencia < cola->datos[hijo]->frecuencia) {
            hijo++;
        }
        if (temp->frecuencia <= cola->datos[hijo]->frecuencia) {
            break;
        }
        cola->datos[i] = cola->datos[hijo];
        i = hijo;
    }
    cola->datos[i] = temp;
    return min;
}

void liberarCola(ColaPrioridad *cola) {
    free(cola->datos);
    free(cola);
}

Nodo *constArbHuffman(int frecuencias[]) {
    ColaPrioridad *cola = crearCola(MAX_CHAR);
    for (int i = 0; i < MAX_CHAR; i++) {
        if (frecuencias[i] > 0) {
            insertarCola(cola, crearNodo(i, frecuencias[i], NULL, NULL));
        }
    }

    while (cola->tamano > 1) {
        Nodo *izquierdo = extraerMinimo(cola);
        Nodo *derecho = extraerMinimo(cola);
        Nodo *padre = crearNodo('\0', izquierdo->frecuencia + derecho->frecuencia, izquierdo, derecho);
        insertarCola(cola, padre);
    }

    Nodo *arbolHuffman = extraerMinimo(cola);
    liberarCola(cola);
    return arbolHuffman;
}

// generar codigos de huffman
void genCodigos(Nodo *raiz, Map *mapaCodigos, char *codigo, int nivel) {
    if (raiz->izquierdo) {
        codigo[nivel] = '0';
        genCodigos(raiz->izquierdo, mapaCodigos, codigo, nivel + 1);
    }
    if (raiz->derecho) {
        codigo[nivel] = '1';
        genCodigos(raiz->derecho, mapaCodigos, codigo, nivel + 1);
    }
    if (!raiz->izquierdo && !raiz->derecho) {
        codigo[nivel] = '\0';
        mapPut(mapaCodigos, raiz->caracter, codigo);
    }
}

// comprimir texto
void compriTexto(const char *texto, Map *mapaCodigos) {
    printf("Texto comprimido:\n");
    for (int i = 0; texto[i] != '\0'; i++) {
        printf("%s", mapGet(mapaCodigos, texto[i]));
    }
    printf("\n");
}

// descomprimir texto
void descomprimirTexto(const char *textoComprimido, Nodo *arbolHuffman) {
    Nodo *actual = arbolHuffman;
    printf("Texto descomprimido:\n");
    for (int i = 0; textoComprimido[i] != '\0'; i++) {
        if (textoComprimido[i] == '0') {
            actual = actual->izquierdo;
        } else if (textoComprimido[i] == '1') {
            actual = actual->derecho;
        }

        if (!actual->izquierdo && !actual->derecho) {
            printf("%c", actual->caracter);
            actual = arbolHuffman;
        }
    }
    printf("\n");
}

// liberar arbol 
void liberarArbol(Nodo *raiz) {
    if (!raiz) return;
    liberarArbol(raiz->izquierdo);
    liberarArbol(raiz->derecho);
    free(raiz);
}

int main() {
    const char *texto = "The sun is a huge ball of gases. It has a huge diameter. It is so huge that it can hold millions of planets inside it. The Sun is mainly made up of hydrogen and helium gas.";
    int frecuencias[MAX_CHAR] = {0};
    char codigo[256];
    Map *mapaCodigos = crearMapa(MAX_CHAR);

    // Paso 1
    contFrecuencias(texto, frecuencias);

    // Paso 2
    Nodo *arbolHuffman = constArbHuffman(frecuencias);

    // Paso 3
    genCodigos(arbolHuffman, mapaCodigos, codigo, 0);

    // imprimir codigos generados
    printf("cdigos de Huffman:\n");
    for (int i = 0; i < MAX_CHAR; i++) {
        char *codigo = mapGet(mapaCodigos, i);
        if (codigo) {
            printf("%c: %s\n", i, codigo);
        }
    }

    //comprimir texto
    compriTexto(texto, mapaCodigos);
    liberarMapa(mapaCodigos);
    liberarArbol(arbolHuffman);

    return 0;
}


