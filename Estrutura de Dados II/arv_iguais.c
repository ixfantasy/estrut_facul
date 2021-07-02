#include <stdio.h>
#include <stdlib.h>

struct noArv {
 int info;
 struct noArv* esq;
 struct noArv* dir;
};
typedef struct noArv NoArv;

NoArv* cria_v(void){
 return NULL;
}

NoArv* arv_cria (int n, NoArv* sae, NoArv* sad){
  NoArv* ar = (NoArv*) malloc (sizeof(NoArv));

  if(ar == NULL){
    exit(1);
  }

  ar->info = n;
  ar->esq = sae;
  ar->dir = sad;

  return ar;
}

void imprimir_arv(NoArv* arv){
  if(arv != NULL){
    printf("%d \t", arv->info);
    imprimir_arv(arv->esq);
    imprimir_arv(arv->dir);
  }
}

int vazia(NoArv *arv){
  return arv == NULL;
}

int igual(NoArv* a1, NoArv* a2){
  if(a1 == NULL && a2 == NULL){
    return 1;
  }
  else{
    return a1->info == a2->info && igual(a1->dir, a2->dir) && igual(a1->esq, a2->esq);
  }
}

int main(){
  NoArv* arv = cria_v();

  arv = arv_cria(15, arv_cria(10, NULL, NULL), arv_cria(50, arv_cria(20, NULL, NULL), NULL));

  imprimir_arv(arv);

  printf("\n\n");

  NoArv* arv2 = cria_v();

  arv2 = arv_cria(15, arv_cria(10, NULL, NULL), arv_cria(50, arv_cria(20, NULL, NULL), NULL));

  imprimir_arv(arv2);

  int resul = igual(arv, arv2);
  if(resul == 0){
    printf("Árvores diferentes.");
  } else {
    printf("Árvores iguais.");
  }

  return 0;
}