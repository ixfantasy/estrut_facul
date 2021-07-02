#include <stdio.h>
#include <stdlib.h>

struct arv{
  int info;
  struct arv* esq;
  struct arv* dir;
};
typedef struct arv Arv;

int vazia(Arv* a);
Arv* arv_criavazia();
Arv* insere(Arv* a, int x);
void imprime(Arv* a);
Arv* remover(Arv* a, int x);

int main(void) {
  Arv* a = arv_criavazia();

  a = insere(a, 6);
  a = insere(a, 2);
  a = insere(a, 1);
  a = insere(a, 4);
  a = insere(a, 3);
  a = insere(a, 8);

  imprime(a);

  printf("\n\n");

  remover(a, 6);

  imprime(a);

  return 0;
}

int vazia(Arv* a){
  return a == NULL;
}

Arv* arv_criavazia(){
  return NULL;
}

Arv* insere(Arv* a, int x){
  if(a == NULL){
    a = (Arv*) malloc(sizeof(Arv));

    a->info = x;
    a->esq = NULL;
    a->dir = NULL;
  }

  if(a->info > x){
    a->esq = insere(a->esq, x);
  }

  if(a->info < x){
    a->dir = insere(a->dir, x);
  }

  return a;
}

void imprime(Arv* a){
  if(!vazia(a)){
    imprime(a->esq);
    printf("%d \t", a->info);
    imprime(a->dir);
  }
}

Arv* remover(Arv* a, int x){
  // verificando se a árvore está vazia
  if(a == NULL){
    return NULL;
  }

  // verificando se a raiz atual é maior que X
  else if(a->info > x){
    a->esq = remover(a->esq, x);
  }

  // verificando se a raiz atual é menor que X
  else if(a->info < x){
    a->dir = remover(a->dir, x);
  }

  // ENCONTROU O NÓ A SER REMOVIDO
  else{
    /* CASO 1: NÓ SEM FILHOS */
    if(a->esq == NULL && a->dir == NULL){
      // libera o nó
      free(a);
      a = NULL;
    }


    /* CASO 2: NÓ COM FILHO SOMENTE NA DIREITA */
    else if(a->esq == NULL){
      // guarda o nó numa variável auxiliar
      Arv* aux = a;

      // nó atual se transforma no filho da direita
      a = a->dir;

      // libera o nó
      free(aux);
    }


    /* CASO 3: NÓ COM FILHO SOMENTE NA ESQUERDA */
    else if(a->dir == NULL){
      // guarda o nó numa variável auxiliar
      Arv* aux = a;

      // nó atual se transforma no filho da esquerda
      a = a->esq;

      // libera o nó
      free(aux);
    }


    /* CASO 4: NÓ POSSUI 2 FILHOS */
    else{
      // guarda a informação da sub-árvore esquerda
      Arv* aux = a->esq;
      
      // explora o nó mais "fundo" da direita
      while(aux->dir != NULL){
        aux = aux->dir;
      }

      // troca de posições: a raiz se transforma no nó da direita
      a->info = aux->info;
      
      // o nó da direita se transforma na raiz que será removida
      aux->info = x;
      
      // roda todo o código do zero, explorando o lado esquerdo da árvore
      a->esq = remover(a->esq, x);
    }
  }

  return a;
}