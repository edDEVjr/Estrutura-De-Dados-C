//
// Created by edvaldo on 22/04/2024.
//

#include "Lista_D_Enca.h"


void initializarList(LISTA *l){
    l->begin =NULL;
    l->end =NULL;
    l->sizeList =0;
}

//Funcao que cria um novo NO
NODE* createNode(int key,NODE *previous,NODE *next){
    NODE *pNew = (NODE*) malloc(sizeof (NODE));
    if(pNew == NULL){
        printf("Nao foi possivel alocar memoria para pNew\n");
        exit(EXIT_FAILURE);
    }
    pNew->next = next;
    pNew->previous = previous;
    pNew->key = key;
    return pNew;
}

NODE* nodeInPosition(int n, LISTA *l){
    if (n < 0 || n >= l->sizeList)
        return NULL;

    NODE* p = l->begin;
    for (int i = 0; i < n; i++)
        p = p->next;
    return p;  // existe um n-esimo e p aponta para ele
}

NODE* searchNO(int key, LISTA *l)
{
    NODE* p = l->begin;
    while (p)   // enquanto nao e NULL
    {
        if (key == p->key)
            return p;
        p = p->next;
    }
    return NULL; // Nao achou
}


bool insertNode(int key,LISTA *l){
    NODE *p = l->begin;
    while(p != NULL) {
        if (key == p->key) {
            return false;
            break;
        }
        p = p->next;
    }

    NODE *pNEW = createNode(key,NULL,l->begin);
    l->sizeList++;

    if(l->begin){
        l->begin->previous = pNEW;
    }

    l->begin = pNEW;

    if(l->end == NULL){
        l->end = pNEW;
    }

    return true;


}

bool insertNodeInPosition(int key,int position,LISTA *l){
    NODE *p = l->begin;
    while(p != NULL) {
        if (key == p->key) {
            return false;
            break;
        }
        p = p->next;
    }

    if(position < 1  || position > l->sizeList ){
        printf("Posicao de insercao invalida (%d)\n", position);
        exit(EXIT_FAILURE);
    }

    NODE *pNew = NULL;
    if(position==0){
        pNew = createNode(key,NULL,l->begin);
        if(l->sizeList==0){
            l->end=pNew;
        }else{
            l->begin->previous=pNew;
        }
        l->begin = pNew;

    }else{
        if(position == l->sizeList){
            pNew = createNode(key, l->end, NULL);
            l->end->next = pNew;
            l->end = pNew;
        }else{
            NODE * noPrevious = nodeInPosition(position-1, l); // Obtem o no anterior
            pNew = createNode(key, noPrevious, noPrevious->next);
            pNew->next->previous = pNew; // ajusta o apontador anterior do NO seguinte
            noPrevious->next = pNew; // ajusta o apontador proximo do NO anterior
        }
    }
    l->sizeList++;
    return true;

}



//Funcao que remove o NO com a chave que foi passada
bool deleteNode(int key,LISTA *l){
    NODE* pCurrent = searchNO(key, l);
    if (pCurrent != NULL)
    {
        if (pCurrent == l->begin)  // ajusta a cabeca para o próximo do nó removido
            l->begin = pCurrent->next;

        if (pCurrent == l->end)  // ajusta a cauda para o anterior do nó removido
            l->end = pCurrent->previous;

        if (pCurrent->next != NULL)  // ajusta o apontador ant do próximo nó
            pCurrent->next->previous = pCurrent->previous;

        if (pCurrent->previous != NULL)  // ajusta o apontador prox do nó anterior
            pCurrent->previous->next = pCurrent->next;

        free(pCurrent);
        l->sizeList--;
        return true;
    }

    return false;  // nao removeu

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



