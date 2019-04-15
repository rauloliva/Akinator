#include <stdio.h>

struct Nodo{
    char *nombre;
    char *cualidad;
    struct Nodo *next;
    struct Nodo *back;
};

struct Tree{
    char *nombre;
    char *cualidad;
    struct Tree *nodoIzquierdo;
    struct Tree *nodoDerecho;
};
