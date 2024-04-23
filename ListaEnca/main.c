//
// Created by edvaldo on 20/04/2024.
//

#include "Lista_Enc.h"

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
        printf("2. Remover\n");
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

