#include <stdio.h>
#include <stdlib.h>

struct lista2 {
  int info;
  struct lista2*ant;
  struct lista2* prox;
};
typedef struct lista2 Lista2;

Lista2* lst_insere(Lista2* l, int n){
  Lista2* novo = (Lista2*) malloc(sizeof(Lista2));

  novo->info = n;
  novo->prox = l;
  novo->ant = NULL;

  if(l != NULL){
    l->ant = novo;
  }

  return novo;
}

void lst_imprime(Lista2* l){
  Lista2* ponteiro;

  for(ponteiro = l; ponteiro != NULL; ponteiro = ponteiro->prox){
    printf("%d \t", ponteiro->info);
  }
}

Lista2* busca(Lista2* l, int n){
  Lista2* ponteiro;

  for(ponteiro = l; ponteiro != NULL; ponteiro = ponteiro->prox){
    if(ponteiro->info == n){
      return ponteiro;
    }
  }
  return NULL;
}

Lista2* ins_ultimo_cond(Lista2* l, int n){
  Lista2* ponteiro = l;
  Lista2* verifica = busca(l, n);

  if(verifica == NULL){
    Lista2* novo = (Lista2*) malloc(sizeof(Lista2));

    novo->info = n;
    novo->prox = NULL;

    if(ponteiro == NULL){
      novo->ant = NULL;
      return novo;
    } else {
      while(ponteiro->prox != NULL){
        ponteiro = ponteiro->prox;
      }
      ponteiro->prox = novo;
      novo->ant = ponteiro;
    }
  }
  return l;
}

Lista2* separa(Lista2* l, int n){
  Lista2* ponteiro;
  Lista2* l2;

  for(ponteiro = l; ponteiro != NULL; ponteiro = ponteiro->prox){
    if(ponteiro->info == n){
      l2 = ponteiro->prox;
      ponteiro->prox = NULL;

      return l2;
    }
  }

  if(ponteiro != NULL){
    ponteiro->ant = NULL;
  }

  return NULL;
}

Lista2* concatena(Lista2* l, Lista2* l2){
  Lista2* ponteiro = l;

  while(ponteiro->prox != NULL){
    ponteiro = ponteiro->prox;
  }

  ponteiro->prox = l2;
  ponteiro->prox->ant = ponteiro;

  return l;
}

Lista2* lst_libera(Lista2* l){
  Lista2* ponteiro = l;
  Lista2* anterior = NULL;

  while(ponteiro != NULL){
    anterior = ponteiro->prox;
    free(ponteiro);

    ponteiro = anterior;
  }
  return NULL;
}


int main (void){
  Lista2* l, *l2; /* declara uma lista não iniciada */
  l = NULL; /* inicia lista vazia */

  /* vai inserir no início da lista */
  l = lst_insere(l, 23); /* insere na lista o elemento 23 */
  l = lst_insere(l, 45); /* insere na lista o elemento 45 */
  l = lst_insere(l, 56); /* insere na lista o elemento 56 */
  l = lst_insere(l, 78); /* insere na lista o elemento 78 */
  lst_imprime(l); /* imprimirá: 78 56 45 23 */
  printf("\n");
  printf("\n");

  /*vai buscar um ponteiro para o nó com a informação 45*/
  Lista2* k = busca(l,45);
  if(k!=NULL)printf("info = %d\n", k->info); //imprimirá info = 45
  printf("\n");
  printf("\n");


  /*vai inserir o elemento no final da lista, condicionalmente.
  Caso ele ainda não exista, insere, no final, um nó com a informação enviada;
  caso a informação já exista em algum nó da lista, simplesmente não insere e retorna o ponteiro inicial*/
  l = ins_ultimo_cond(l,82);
  printf("\n");
  printf("\n");
  lst_imprime(l); /* imprimirá: 78 56 45 23 82 */

  l = ins_ultimo_cond(l,45);
  printf("\n");
  printf("\n");
  lst_imprime(l); /* imprimirá: 78 56 45 23 82 */

  //protótipo e descrição dessa função na Questão 1 do Arquivo de Exercícios, adaptando, agora, para lista dupla
  l2 = separa(l,56);
  printf("\n");
  printf("\n");
  lst_imprime(l); //imprimirá 78 56
  printf("\n");
  printf("\n");
  lst_imprime(l2); //imprimirá 45 23 82

  //protótipo e descrição dessa função na Questão 2 do Arquivo de Exercícios, adaptando, agora, para lista dupla
  l= concatena(l,l2);
  printf("\n");
  printf("\n");
  lst_imprime(l); //imprimirá 78 56 45 23 82

  /*vai liberar a lista l */ 
  l = lst_libera(l);
  l2 = NULL;
  return 0;
}