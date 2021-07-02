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

int maiores(PtrNo* l, int n){
  PtrNo* pt;
  int x = 0;

  for(pt = l; pt != NULL; pt = pt->prox){
    if(pt->num > n){
      x++;
    }
  }

  return x;
}

int main(void) {
  // criando lista
  PtrNo* lst;
  lst = NULL;

  // inserir elementos
  lst = lst_insere(lst, 12);
  lst = lst_insere(lst, 30);
  lst = lst_insere(lst, 68);

  // retorno do número de nós
  int x;
  printf("Inserir um número:");
  scanf("%d", &x);

  int total = maiores(lst, x);
  printf("Número total de nós: %d", total);

  return 0;
}