//
// Created by edvaldo on 20/04/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#ifndef LISTAENCA_LISTA_ENC_H
#define LISTAENCA_LISTA_ENC_H

//--------------------------------
typedef struct estrutura{
    int key;
    struct estrutura *next;

}NODE;

typedef struct {
    NODE *begin;
    int sizeList;
}LISTA;

//-------------------------------------
void initializarList(LISTA *l);

NODE* criateNode(int key,NODE *next);

bool insertNode(int key,LISTA *l);

bool deleteNode(int key,LISTA *l);

void clearList(LISTA *l);

void showlist(LISTA *l);
//--------------------------------


#endif //LISTAENCA_LISTA_ENC_H
