#include <stdio.h>
#include <stdlib.h>

struct No{
  int num;
  struct No* prox;
};
typedef struct No PtrNo;

PtrNo* lst_insere(PtrNo* lst, int x){
  PtrNo* no = (PtrNo*) malloc(sizeof(PtrNo));

  no->num = x;
  no->prox = lst;

  return no;
}

PtrNo* retira_n(PtrNo* l, int n){
  PtrNo* aux;
  PtrNo* novo = NULL;

  while(l != NULL){
    if(l->num != n){
      novo = lst_insere(novo, l->num);
    }

    aux = l;
    l = l->prox;
    free(aux);
  }

  return novo;
}

void lst_imprime(PtrNo* lst){
  PtrNo* pt;

  for(pt = lst; pt != NULL; pt = pt->prox){
    printf("%d \t", pt->num);
  }
}

int main(void) {
  // criando lista
  PtrNo* lst;
  lst = NULL;

  // inserir elementos
  lst = lst_insere(lst, 12);
  lst = lst_insere(lst, 30);
  lst = lst_insere(lst, 68);

  // retorno da nova lista sem ocorrências
  int x;
  printf("Inserir um número:");
  scanf("%d", &x);

  lst = retira_n(lst, x);

  // imprimir lista
  lst_imprime(lst);

  return 0;
}