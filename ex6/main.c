#include "cliente.h"


int main(){
  
  Cliente clientes[200];

  for(int i=0;i<200;i++){
    clientes[i].codigo=0;
  }

  lerClientesDoArquivo(clientes);
  
  int opcao=0;
    printf("----------------------Menu----------------------\n");
    printf("1:Adicionar Cliente\n");
    printf("2:Excluir Cliente\n");
    printf("3:Mostrar Clientes\n");
    printf("-1:Sair\n");
    scanf("%d",&opcao);

  while(opcao !=-1){

      switch (opcao) {
          case 1:
              system("cls");
              adicionarCliente(clientes);
              salvarClientesNoArquivo(clientes);
              break;
          case 2:
              system("cls");
              int codigo;
              printf("Qual codigo a ser excluido?");
              scanf("%d",&codigo);
              excluirCliente(clientes,codigo);
              salvarClientesNoArquivo(clientes);
              break;

          case 3:
              system("cls");
              mostrarClientes(clientes);
              break;

          default:
              system("cls");
              printf("Opcao invalida");
              break;
      }
      printf("----------------------Menu----------------------\n");
      printf("1:Adicionar Cliente\n");
      printf("2:Excluir Cliente\n");
      printf("3:Mostrar Clientes\n");
      printf("-1:Sair\n");
      scanf("%d",&opcao);

  }

  
  
  

    return 0;
}