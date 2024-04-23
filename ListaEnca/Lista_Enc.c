//
// Created by edvaldo on 20/04/2024.
//

#include "Lista_Enc.h"


void initializarList(LISTA *l){
    l->begin =NULL;
    l->sizeList =0;
}

//Funcao que cria um novo no
NODE* criateNode(int key,NODE *next){
    NODE *pNew = (NODE*) malloc(sizeof (NODE));
    if(pNew == NULL){
        printf("Nao foi possivel alocar memoria para pNew\n");
        exit(EXIT_FAILURE);
    }
    pNew->next = next;
    pNew->key = key;
    return pNew;
}

bool insertNode(int key,LISTA *l){

    if(l->begin == NULL){
        l->begin = criateNode(key,l->begin);
        l->sizeList++;
        return true;
    }else{
        NODE *p = l->begin;
        while(p != NULL){
            if(key == p->key){
                return false;
                break;
            }
            p = p->next;
        }
        l->begin = criateNode(key,l->begin);
        l->sizeList++;
        return true;
    }


}


//Funcao que remove o NO com a chave que foi passada
bool deleteNode(int key,LISTA *l){
    //Analisa se lista esta vazia
    if(l->begin == NULL){
        return false;
    }

    NODE *previous = l->begin;
    //Analisa se a chave que será excluida esta
    //no inicio da lista
    if (key == l->begin->key){
        l->begin = l->begin->next;
        l->sizeList--;
        free(previous);
        return true;
    }else{
        //Percorre a lista ate encontrar a chave que sera excluida
        //Remove a chave e corrige a ligacao da lista
        //removendo o no do item
        while (previous->next){
            NODE* current = previous->next;

            if(key == current->key){
                previous->next = current->next;
                free(current);
                l->sizeList--;
                return true;
            }
            previous = current;

        }
    }

    return false;

}

void showlist(LISTA *l){
    printf("[");
    NODE* p = l->begin;
    while (p){
        printf("%d",p->key);
        if(p->next){
            printf(",");
        }
        p = p->next;

    }
    printf("]");
}

void clearList(LISTA *l)
{
    NODE* current = l->begin;
    while (current) {
        NODE* next = current->next; // guarda proxima posicao
        free(current);            // libera memoria apontada por atual
        current = next;
    }
    l->begin = NULL; // ajusta inicio da lista (vazia)
    l->sizeList = 0;
}




