#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Node.c"

#define len_nombre 30
#define len_cualidad 100
 
FILE *file = NULL;

void insert(char *nombre, char *cualidad){
    file = fopen("tree.txt","a"); 
    if(file == NULL){
        fprintf(stderr,"%d\n",errno);
        fprintf(stderr,"%s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }
    fprintf(file,"%s %s",nombre,cualidad);
    fclose(file);
}

struct Nodo * getDatos(struct Nodo *nodo,int *size){
    file = fopen("tree.txt","r");
    struct Nodo *back = NULL;
    char c;
    int create = 1, saveCualidad = 0;
    
    while((c = fgetc(file)) != EOF){
        if(create == 1){
            nodo = malloc(sizeof(struct Nodo));
            nodo->nombre = malloc(sizeof(char) * len_nombre);
            nodo->cualidad = malloc(sizeof(char) * len_cualidad);
            nodo->back = back;
            create = 0;
        }
        //save the name of the hero
        if(saveCualidad == 0) {
            if (c == '|') { //we have reached the end of the string
                saveCualidad = 1; //now time to save the quality
            }else{
                nodo->nombre = strcat(nodo->nombre,&c);
            }
            continue;
        }
        
        if (c == 10) { //when we reached a new line character in ascii
            create = 1;
            back = nodo;
            nodo = nodo->next;
            saveCualidad = 0;
            (*size)++;
            continue;
        }
        nodo->cualidad = strcat(nodo->cualidad,&c);
    }
    nodo = back;
    return nodo;
}