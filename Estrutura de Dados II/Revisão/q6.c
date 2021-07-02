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

PtrNo* merge(PtrNo* l1, PtrNo* l2){
  PtrNo* pt1 = l1;
  PtrNo* pt2 = l2;

  PtrNo* lst = NULL;

  while(pt1 != NULL || pt2 != NULL){
    if(pt1 != NULL){
      lst = lst_insere(lst, pt1->num);
      pt1 = pt1->prox;
    }

    if(pt2 != NULL){
      lst = lst_insere(lst, pt2->num);
      pt2 = pt2->prox;
    }
  }

  return lst;
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

  PtrNo* lst2;
  lst2 = NULL;

  // inserir elementos lista 1
  lst = lst_insere(lst, 12);
  lst = lst_insere(lst, 30);
  lst = lst_insere(lst, 68);
  lst = lst_insere(lst, 50);
  lst = lst_insere(lst, 14);

  lst_imprime(lst);
  printf("\n");

  // inserir elementos lista 2
  lst2 = lst_insere(lst2, 2);
  lst2 = lst_insere(lst2, 3);
  lst2 = lst_insere(lst2, 4);
  lst2 = lst_insere(lst2, 5);
  lst2 = lst_insere(lst2, 6);

  lst_imprime(lst2);
  printf("\n");

  // retorno da nova lista
  PtrNo* lst3 = merge(lst, lst2);

  lst_imprime(lst3);

  return 0;
}