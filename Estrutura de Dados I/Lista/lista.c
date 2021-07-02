#include <stdio.h>
#include <stdlib.h>

struct lista {
  int info;
  struct lista* prox;
};

typedef struct lista Lista;

Lista* inicializa(){
  return NULL;
}

Lista* insere(Lista* list, int i){
  Lista* novo_pont = (Lista*) malloc(sizeof(Lista));

  novo_pont->info = i;

  novo_pont->prox = list;

  return novo_pont;
}

void imprimir(Lista* list){
  Lista* ponteiro;

  for(ponteiro = list; ponteiro != NULL; ponteiro = ponteiro->prox){
    printf("%d\n", ponteiro->info);
  }
}


int verificar(Lista* list){
  return (list == NULL);
}

Lista* busca(Lista* list, int i){
  Lista* ponteiro;

  for(ponteiro = list; ponteiro != NULL; ponteiro = ponteiro->prox){
    if(ponteiro->info == i){
      return ponteiro;
    }
  }

  return NULL;
}

Lista* remover(Lista* list, int i){
  Lista* anterior = NULL;
  Lista* ponteiro = list;

  while(ponteiro != NULL && ponteiro->info != i){
    anterior = ponteiro;

    ponteiro = ponteiro->prox;
  }

  if(ponteiro == NULL){
    return list;
  }

  if(anterior == NULL){
    list = ponteiro->prox;
  } else {
    anterior->prox = ponteiro->prox;
  }

  free(ponteiro);
  return list;
}

void libera(Lista* list){
  Lista* ponteiro = list;

  while(ponteiro != NULL){
    Lista* aux = ponteiro->prox;

    free(ponteiro);

    ponteiro = aux;
  }
}

Lista* criar(int i){
  Lista* ponteiro = (Lista*)malloc(sizeof(Lista));

  ponteiro->info = i;
  return ponteiro;
}

Lista* ordena(Lista* list, int i){
  Lista* Pont_Novo = criar(i);

  Lista* ponteiro = list;

  Lista* anterior = NULL;

  while(ponteiro != NULL && i > ponteiro->info){
    anterior = ponteiro;

    ponteiro = ponteiro->prox;
  }

  if(anterior == NULL){
    Pont_Novo->prox = list;
    list = Pont_Novo;
  } else {
    Pont_Novo->prox = anterior->prox;
    anterior->prox = Pont_Novo;
  }
  return list;
}

int main(void) {
  Lista* list;

  list = inicializa();

  list = insere(list, 5); // envia o ponteiro inicial e valor de info
  list = insere(list, 3);
  list = insere(list, 1);

  imprimir(list);

  int res = verificar(list);
  printf("%d", res);

  Lista* item = busca(list, 38);
  if(item != NULL){
    printf("O elemento existe! %d", item->info);
  }

  list = remover(list, 1);

  //libera(list);

  list = ordena(list, 2);
  list = ordena(list, 0);
  list = ordena(list, 4);
  list = ordena(list, 6);

  imprimir(list);

  return 0;
}