#include "stdio.h"
#include "stdlib.h"

#include "cliente.h"


//---------------------------------------------------------------------

//-------------------------------------------------------------
void lerClientesDoArquivo(Cliente clientes[]){
  int i=0;
    FILE *arquivoClientes;
    //Open a file in read mode
    arquivoClientes = fopen("clientes.txt","r");
    if (arquivoClientes == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo de clientes.\n");
        return;
    }else{
      while (fscanf(arquivoClientes,"Codigo:%d\n Nome:%[^\n]\nTelefone:%d\nDataPC:%d-%d-%d\nDataUC:%d-%d-%d\nValorUC:%f\n\n",
                    &clientes[i].codigo, clientes[i].nome, &clientes[i].telefone, &clientes[i].dataPC.dia,&clientes[i].dataPC.mes,
                    &clientes[i].dataPC.ano, &clientes[i].dataUC.dia, &clientes[i].dataUC.mes,&clientes[i].dataUC.ano,&clientes[i].valorUC) != EOF) {
          i++;
      }
        
    }

    // close a file
    fclose(arquivoClientes);
}
//--------------------------------------------------------------
void salvarClientesNoArquivo(Cliente clientes[]){
    int x=0;
    FILE *arquivoClientes;
    arquivoClientes= fopen("clientes.txt", "w");

    for(int i=0; i<200; i++){
        if(clientes[i].codigo != 0){
            fprintf(arquivoClientes,"Codigo:%d\nNome:%s\nTelefone:%d\nDataPC:%d-%d-%d\nDataUC:%d-%d-%d\nValorUC:%.2f\n\n",
                    clientes[i].codigo, clientes[i].nome, clientes[i].telefone, clientes[i].dataPC.dia,clientes[i].dataPC.mes,
                    clientes[i].dataPC.ano, clientes[i].dataUC.dia, clientes[i].dataUC.mes,clientes[i].dataUC.ano,clientes[i].valorUC );
        }
    }

    fclose(arquivoClientes);
}
//---------------------------------------------------------------

void mostrarClientes(Cliente clientes[]){
    for(int i=0;i<200;i++){
        if(clientes[i].codigo != 0){
            printf("Codigo:%d\n",clientes[i].codigo);
            printf("Nome:%s\n\n",clientes[i].nome);

        }

    }

}

void adicionarCliente(Cliente clientes[]){

    for(int i=0;i<200;i++){
        if(clientes[i].codigo==0){
            printf("Digite o codigo do cliente:");
            scanf("%d",&clientes[i].codigo);
            printf("Digite o nome do cliente:");
            scanf("%s",clientes[i].nome);
            printf("Digite o telefone do cliente:");
            scanf("%d",&clientes[i].telefone);
            printf("Digite a data da primeira compra do cliente(xx-xx-xxxx):");
            scanf("%d-%d-%d",&clientes[i].dataPC.dia,&clientes[i].dataPC.mes,&clientes[i].dataPC.ano);
            printf("Digite a data da ultima compra do cliente(xx-xx-xxxx):");
            scanf("%d-%d-%d",&clientes[i].dataUC.dia,&clientes[i].dataUC.mes,&clientes[i].dataUC.ano);
            printf("Digite o valor da ultima compra do cliente:");
            scanf("%f",&clientes[i].valorUC);
            break;
        }
    }
  
}

void excluirCliente(Cliente clientes[],int codigo){
    for(int i=0;i<200;i++){
        if(clientes[i].codigo == codigo){
            clientes[i].codigo = 0;
            break;

        }
    }
}




