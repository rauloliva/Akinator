#include <stdio.h>
#include "db.c"
#include <string.h>

void Welcome();
void Victoria();
void Derrota(char nombre[],char cualidad[]);
int startAgain();
void printRecorrido(struct Tree *tree);

int main(){    
    int newGame = 1;
    while(newGame == 1){
        char opt[3];
        Welcome();
        scanf("%s",opt);
        if(!strcmp("no",opt) || !strcmp("n",opt)){
            newGame = 0;
            continue;
        }

        struct Nodo *nodes;
        int sizeHeroes = 0,sizeArbol = 0;
        /*here we get a double linked list 
          pointing from the bottom
        */
        nodes = getDatos(nodes,&sizeHeroes);
        
        struct Tree *root = malloc(sizeof(struct Tree));
        root->nombre = malloc(sizeof(char) * len_nombre);
        root->cualidad = malloc(sizeof(char) * len_cualidad);
        root->nombre = nodes->nombre;
        root->cualidad = nodes->cualidad;
        struct Tree *cpyRoot = root; //a copy from the root
        int victoria = 0;

        while(sizeArbol < sizeHeroes && victoria == 0){
            sizeArbol++;
            char res[3];
            printf("\n¿Tu superheroe %s?: ",root->cualidad);
            scanf("%s",res);

            if(!strcmp("si",res) || !strcmp("s",res)){
                printf("\n¿Tu superheroe es %s?: ",root->nombre);
                scanf("%s",res);
                if(!strcmp("si",res) || !strcmp("s",res)){
                    root->nodoIzquierdo = malloc(sizeof(struct Tree));
                    root->nodoIzquierdo->nombre = "victoria";
                    Victoria();
                    victoria = 1;
                }else{
                    root->nodoDerecho = malloc(sizeof(struct Tree));
                    if (sizeArbol == sizeHeroes) {//if we ran out of heroes
                        char nombre[30],cualidad[100];
                        Derrota(nombre,cualidad);
                        root = root->nodoDerecho;
                        root->nombre = nombre;
                        root->cualidad = cualidad;
                        insert(root->nombre,root->cualidad);
                        continue;
                    }
                    nodes = nodes->back;
                    root = root->nodoDerecho;
                    root->nombre = nodes->nombre;
                    root->cualidad = nodes->cualidad;
                }
            }else{
                root->nodoDerecho = malloc(sizeof(struct Tree));
                if (sizeArbol == sizeHeroes) {//if we ran out of heroes
                    char nombre[30],cualidad[100];
                    Derrota(nombre,cualidad);
                    insert(nombre,cualidad);
                    root = root->nodoDerecho;
                    root->nombre = nombre;
                    root->cualidad = cualidad;
                    continue;
                }
                //go a node back
                nodes = nodes->back;
                root = root->nodoDerecho;
                root->nombre = nodes->nombre;
                root->cualidad = nodes->cualidad;
            }
        }
        printRecorrido(cpyRoot);
        int desicion = startAgain();
        if(desicion == 0){
            newGame = 0;
        }
    }
    puts("\nGracias por jugar\n");
    return 0;
}

void Welcome(){
    puts("----------------------------");
    puts("|Instrucciones             |");
    puts("|Verdadero = 'si' o 's'    |");
    puts("|Falso = 'no' o 'n'        |");
    puts("----------------------------");
    puts("Piensa en un superheroe\ny yo tratare de adivinar cual, ¿Estas listo?");
    printf("> ");
}

void Victoria(){
    puts("-------------");
    puts("|Victoria!!!|");
    puts("-------------");
}

void Derrota(char *nombre,char *cualidad){
    //clear the buffer
    while((getchar()) != '\n');
    
    puts("\nMe rindo");
    puts("¿Dime cual es el nombre de tu superheroe?");
    printf("> ");
    fgets(nombre,len_nombre,stdin);
    
    //put the '|' instead at the end of the str
    int i;
    for( i = 0; i < strlen(nombre); i++){
        if(nombre[i] == '\n'){
            nombre[i] = '|';
        }
    }

    puts("\n¿Dime cual es su cualidad de tu superheroe?");
    printf("> ");
    fgets(cualidad,len_cualidad,stdin);
    printf("\n");
}

int startAgain(){
    char opt[3];
    puts("\n¿Quieres jugar otra vez?");
    printf("> ");
    scanf("%s",opt);
    if(!strcmp("si",opt) || !strcmp("s",opt)){
        return 1;
    }else{
        return 0;
    }
}

void printRecorrido(struct Tree *root){
    struct Tree *ptrTree = root;
    while(ptrTree != NULL){
        printf(" %s\n",ptrTree->nombre);
        if(ptrTree->nodoIzquierdo != NULL){
            puts(" /");
            ptrTree = ptrTree->nodoIzquierdo;
        }else if(ptrTree->nodoDerecho != NULL){
            puts(" \\");
            ptrTree = ptrTree->nodoDerecho;
        }else{
            ptrTree = NULL;
        }
    }
}
