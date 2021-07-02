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

PtrNo* separa(PtrNo* l, int n){
  PtrNo* pt;
  PtrNo* l2;

  for(pt = l; pt != NULL; pt = pt->prox){
    if(pt->num == n){
      l2 = pt->prox;
      pt->prox = NULL;

      return l2;
    }
  }

  return NULL;
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
  lst = lst_insere(lst, 50);
  lst = lst_insere(lst, 14);

  // retorno da nova lista
  int x;
  printf("Inserir um número:");
  scanf("%d", &x);

  PtrNo* lst2 = separa(lst, x);
  
  lst_imprime(lst);
  printf("\n");
  lst_imprime(lst2);

  return 0;
}