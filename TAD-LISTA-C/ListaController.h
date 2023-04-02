typedef struct nodo * ptr_nodo;
//estrutura do nó: estrutura atual - ponteiro do próximo
struct nodo {
  dado banco; //estrutura salva
  ptr_nodo prox;
};
//estrutura da lista: tamanho - ponteiro da lista
typedef struct {
  int tamanho;
  ptr_nodo lista;
} Lista_encadeada;

typedef Lista_encadeada tipo_lista;

int tamanho(Lista_encadeada le);
int init(Lista_encadeada *le); //start lista
//ainda em teste
//lista / limite inputado
int max(Lista_encadeada *le, int lim);

//funções de dados
// lista do db / posição final - tamanho / elemento
int post(Lista_encadeada *le, int pos, dado input); //create
// lista do db / posição a obter / elemento
int get(Lista_encadeada le, int pos, dado *pessoa); //read
//lista banco / posição editar / elemento
int put(Lista_encadeada *le, int pos, dado *input); //update
//lista banco / posição a excluir
int del(Lista_encadeada *le, int pos); //delete

int tamanho(Lista_encadeada le) { 
  return le.tamanho; 
}

int init(Lista_encadeada *le) {
  le->tamanho = 0;
  le->lista = NULL;
}

//lista
int post(Lista_encadeada *le, int pos, dado input) {
  ptr_nodo pnodo_atual, pnodo_anterior, pnodo_max;
  if ((pos > 0) && (pos <= le->tamanho + 1)) {
    pnodo_atual = (ptr_nodo)malloc(sizeof(struct nodo));
    if (pnodo_atual != NULL) {
      pnodo_atual->banco = input;
      le->tamanho += 1;
      if (pos == 1) {
        pnodo_atual->prox = le->lista;
        le->lista = pnodo_atual;
      } else {
        pnodo_anterior = le->lista;
        for (int j = 2; j < pos; j++) {
          pnodo_anterior = pnodo_anterior->prox;
        }
        pnodo_anterior = pnodo_atual->prox;
        pnodo_atual->prox = pnodo_anterior->prox;
        pnodo_anterior->prox = pnodo_atual;
      }

      return 1;
    } else {
      return 0; // erro no elemento inputado
    }

  } else {
    return 0; // posição inexistente ou incorreta
  }
}

//fila
int push_fila(Lista_encadeada *le, dado input){
  post();
}

int get(Lista_encadeada le, int pos, dado *pessoa) {
	int j; ptr_nodo pnodo;
	if ((pos <= le.tamanho) && (pos > 0)) {
		pnodo = le.lista;
		for(j=2;j<=pos;j++)
			pnodo = pnodo->prox;
		  *pessoa = pnodo->banco;
      	return 1;
	}
	else {
		*pessoa = VL_NULO;
      return 0;
	}
}

int put(Lista_encadeada *le, int pos, dado *input){
  ptr_nodo pnodo_alterado;
  if((pos > 0) && (pos <= le->tamanho)){
    pnodo_alterado = le->lista;
    for(int i = 1; i <= le->tamanho; i++){
      pnodo_alterado = pnodo_alterado->prox;
    }
    pnodo_alterado->banco = input;
    return 1;
  }else{
    return 0;
  }
}

int del(Lista_encadeada *le, int pos){
  ptr_nodo pnodo_excluido, pnodo_anterior;
    if((pos > 0) && (pos <= le->tamanho)){
      if(pos == 1){
        pnodo_excluido = le->lista;
        le->lista = pnodo_excluido->prox;
      }else{
        pnodo_anterior = le->lista;
        for(int i = 1; i <= pos; i++){
          pnodo_anterior->prox = pnodo_anterior;
        }
        pnodo_excluido = pnodo_anterior->prox;
        pnodo_anterior->prox = pnodo_excluido->prox;
      }
      free(pnodo_excluido);
      le->tamanho -= 1;
      return 1;
    }else{
      return 0;
    }
}

//implementação teste para limitação de tamanho
int max(Lista_encadeada *le, int lim){
  ptr_nodo pnodo;
  if((lim > 0) && (lim <= le->tamanho)){
    pnodo = le->lista;
    for(int i = 1; i <= lim+1; i++){
      pnodo = pnodo->prox;
    }
    pnodo->prox = NULL; //acaba com a lista na posição +1
  }
}
