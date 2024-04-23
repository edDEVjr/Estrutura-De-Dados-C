//
// Created by edvaldo on 23/04/2024.
//

#include "ex29.h"

// Funcao que recebe duas listas que representam dois conjuntos de inteiros
// e retorna outra lista que representa a uniao dos dois conjuntos
LISTA * uniao(LISTA *l1, LISTA *l2){
    NODE *p1 = l1->begin;
    NODE *p2 = l2->begin;
    LISTA *l3 = (LISTA*)malloc(sizeof(LISTA));
    initializarList(l3);


    //Uniao no caso em que os dois conjutos são vazios
    if(p1 == NULL && p2 == NULL){
        return l3;
    }
    //Uniao no caso de apenas um dos conjuntos ser vazio
    if(p1 == NULL){
        while (p2){
            insertNode(p2->key,l3);
            p2 = p2->next;
        }
        return l3;


    }
    if(p2 == NULL){
        while (p1){
            insertNode(p1->key,l3);
            p1 = p1->next;
        }
        return l3;

    }

    //Uniao no caso em que os dois conjuntos não são vazios
    while (p1){
        insertNode(p1->key,l3);
        p1 = p1->next;
    }
    while (p2){
        insertNode(p2->key,l3);
        p2 = p2->next;
    }

    return l3;
}


// Funcao que recebe duas listas que representam dois conjuntos de inteiros
// e retorna outra lista que representa a intersecçao dos dois conjuntos
LISTA *interseccao(LISTA *l1,LISTA *l2){
    NODE *p1 = l1->begin;
    NODE *p2 = l2->begin;
    LISTA *l3 = (LISTA*)malloc(sizeof(LISTA));
    initializarList(l3);

    //Interseccao no caso em que um dos conjuntos seja vazio
    if(p1 == NULL || p2 == NULL){
        return l3;
    }

    //Caso ambos os conjuntos não sejam vazios
    while(p1){
        while (p2){
            if(p1->key == p2->key){
                insertNode(p1->key,l3);
                break;
            }
            p2 = p2->next;

        }
        p1 = p1->next;

    }
    return l3;
}


// Funcao que recebe duas listas que representam dois conjuntos de inteiros
// e retorna outra lista que representa a diferenca entre os dois conjuntos
LISTA *diferenca(LISTA *l1,LISTA *l2){
    NODE *p1 = l1->begin;
    NODE *p2 = l2->begin;
    LISTA *l3 = (LISTA*)malloc(sizeof(LISTA));
    initializarList(l3);

    //Diferenca caso o primeiro conjunto seja vazio
    if(p1 == NULL){
        return l3;
    }

    //Caso o primeiro nao seja vazio e o segundo seja vazio
    if(p2 == NULL){
        while (p1){
            insertNode(p1->key,l3);
            p1 = p1->next;
        }
        return l3;
    }

    //Caso ambos nao sejam vazios
    while (p1){
        bool igual = false;
        while (p2){
            if(p1->key == p2->key){
                igual = true;
                break;
            }

            p2 = p2->next;
        }
        if(!(igual)){
            insertNode(p1->key,l3);
        }
        p1 = p1->next;
    }
    return l3;


}
