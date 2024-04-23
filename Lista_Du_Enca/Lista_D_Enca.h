//
// Created by edvaldo on 22/04/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef LISTA_DU_ENCA_LISTA_D_ENCA_H
#define LISTA_DU_ENCA_LISTA_D_ENCA_H

//--------------------------------
typedef struct estrutura{
    int key;
    struct estrutura *next;
    struct estrutura *previous;

}NODE;

typedef struct {
    NODE *begin;
    NODE *end;
    int sizeList;
}LISTA;

//-------------------------------------
void initializarList(LISTA *l);

NODE* createNode(int key,NODE *previous,NODE *next);

NODE* nodeInPosition(int n, LISTA *l);

bool insertNode(int key,LISTA *l);

bool insertNodeInPosition(int key,int position,LISTA *l);

bool deleteNode(int key,LISTA *l);

void clearList(LISTA *l);

void showlist(LISTA *l);
//--------------------------------


#endif //LISTA_DU_ENCA_LISTA_D_ENCA_H
