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

NoArv* copia(NoArv* arv){
  NoArv* aux = NULL;
 
  return aux = arv_cria(arv->info, arv->esq, arv->dir);
}


int main(){
  NoArv* arv = cria_v();

  arv = arv_cria(15, arv_cria(10, NULL, arv_cria(10, NULL, NULL)), arv_cria(50, arv_cria(20, NULL, arv_cria(50, NULL, arv_cria(30, NULL, NULL))), arv_cria(40, NULL, NULL)));

  imprimir_arv(arv);

  printf("\n\n");

  NoArv* arv2 = copia(arv);

  imprimir_arv(arv2);

  return 0;
}