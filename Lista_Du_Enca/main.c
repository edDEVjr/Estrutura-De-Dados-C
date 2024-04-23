//
// Created by edvaldo on 22/04/2024.
//

#include "Lista_D_Enca.h"

//----------------------------------------------------------------------------
void imprimirStatus(LISTA *l)
{
    printf("Tamanho = %d\n", l->sizeList);
    showlist(l);
    printf("\n");
}
//------------------------------------------------------
void inserir(LISTA *l){

    int item;

    printf("Digite o valor");
    scanf("%d", &item);

    if(insertNode(item, l)){
        printf("Valor inserido\n");
    }else{
        printf("Valor ja existe na lista\n");
    }

    imprimirStatus(l);
}
//---------------------------------------------------------------
void inserirNaPosicao(LISTA *l){
    int item,pos;

    printf("Digite o valor");
    scanf("%d", &item);
    printf("Digite a posicao");
    scanf("%d",&pos);

    if(insertNodeInPosition(item, pos,l)){
        printf("Valor inserido\n");
    }else{
        printf("Valor ja existe na lista\n");
    }

    imprimirStatus(l);
}

//----------------------------------------------------------------
void remover(LISTA *l){

    int item;
    printf("Qual item quer remover?");
    scanf("%d",&item);
    deleteNode(item,l);

    imprimirStatus(l);
}
//---------------------------------------------------------------------
void destruirLista(LISTA *l){
    clearList(l);
}
//--------------------------------------------------------------
int main(){
    LISTA l;
    int opcao;

    initializarList(&l);

    do {
        printf("\nMenu:\n");
        printf("1. Inserir\n");
        printf("2. InserirNaPosicao\n");
        printf("3. Remover\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                system("cls");
                inserir(&l);
                break;
            case 2:
                system("cls");
                inserirNaPosicao(&l);
                break;
            case 3:
                system("cls");
                remover(&l);
                break;
            case 0:
                system("cls");
                destruirLista(&l);
                printf("Saindo...\n");
                break;
            default:
                system("cls");
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while(opcao != 0);


    return 0;
}