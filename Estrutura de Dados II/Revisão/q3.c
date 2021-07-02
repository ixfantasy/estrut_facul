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

PtrNo* concatena(PtrNo* l1, PtrNo* l2){
  PtrNo* pt = l1;
  PtrNo* pt2;
  
  while(pt != NULL){
    pt2 = pt;
    pt = pt->prox;
  }

  pt2->prox = l2;
  return l1;
}

void lst_imprime(PtrNo* lst){
  PtrNo* pt;

  for(pt = lst; pt != NULL; pt = pt->prox){
    printf("%d \t", pt->num);
  }
}

int main(void) {
  // criando listas
  PtrNo* lst1;
  lst1 = NULL;

  PtrNo* lst2;
  lst2 = NULL;

  // inserir elementos lista1
  lst1 = lst_insere(lst1, 1);
  lst1 = lst_insere(lst1, 2);
  lst1 = lst_insere(lst1, 3);

  // inserir elementos lista2
  lst2 = lst_insere(lst2, 4);
  lst2 = lst_insere(lst2, 5);
  lst2 = lst_insere(lst2, 6);
  lst2 = lst_insere(lst2, 7);

  // concatenar listas
  lst1 = concatena(lst1, lst2);

  // imprimir lista
  lst_imprime(lst1);

  return 0;
}