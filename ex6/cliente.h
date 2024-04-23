#include <stdio.h>
#include <stdlib.h>

#ifndef CLIENTE_H
#define CLIENTE_H


//estrutura com os dados de data (dia,mes e ano)
typedef struct {
    int dia;
    int mes;
    int ano;

}Data;

//Estrutura com os dados do cliente
typedef struct {
    int codigo;
    char nome[50];
    int telefone;
    Data dataPC; //data da primeira compra
    Data dataUC; //data da ultima compra
    float valorUC; //valor da ultima compra
}Cliente;



//Funcao que pega os dados dos clientes no arquivo e adiciona a lista de clientes
void pegarDadosNoArquivo(FILE *arquivoClientes,Cliente clientes[]);

//Funcao que le o arquivo e chama a funcao pegarDadosNoArquivo
void lerClientesDoArquivo(Cliente clientes[]);

//Funcao que adiciona os dados dos clientes na lista
void adicionarCliente(Cliente clientes[]);

// Funcao que salva os clientes ,com as alteracoes feitas
void salvarClientesNoArquivo(Cliente clientes[]);

void mostrarClientes(Cliente clientes[]);

void excluirCliente(Cliente clientes[],int codigo);

#endif