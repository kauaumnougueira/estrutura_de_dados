#include <stdio.h>
//frame

typedef struct{
  char nome[50];
  char idade[3];//max 999
  
}pessoa;

typedef pessoa dado;

const dado VL_NULO = {"", ""};

#include "ListaController.h"
#include "DadoModel.h"

tipo_lista lista_e;

void interface();
int listar();

int main() {
  dado teste = {"kauã", "019"};
  dado teste2 = {"iheard", "020"};
  
  init(&lista_e); //inicia lista
  max(&lista_e, 49); //setando tamanho máximo da lista
  
  int size = tamanho(lista_e);
  printf("%d", size);
  interface();
  listar();
  gravar_lista(lista_e);
}

void interface(){
  char linhas[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
  printf("%c |  ", linhas[0]);  
  for(int i = 1; i < 50; i++){
    printf("[ 1 ] ");
    
    if(i%7 == 0 && i > 0 && i != 49){
      printf("\n");
      printf("\n");
      printf("%c |  ", linhas[i/7]);  
    }
  }
  printf("\n");
  printf("\n");
  printf("     ");
  for(int i = 1; i < 8; i++)
    printf("  0%d  ", i);
}

int listar(){
  system("cleatr");
  int size = tamanho(lista_e);
  dado linha;
  if(size > 0){
    for(int i = 1; i <= size; i++){
      if(get(lista_e, i, &linha)){
        printf("%s\n%s", linha.nome, linha.idade);
        printf("\n");
      }
    }
  }
}