#include <stdio.h> 
#include <stdlib.h>
#define N 100 /* número máximo de elementos */

struct fila {
  int n; /* número de elementos na fila */
  int ini; /* posição do próximo elemento a ser retirado da fila */
  float vet[N];
};
typedef struct fila Fila;


Fila* fila_cria(){
  Fila* f = (Fila*) malloc(sizeof(Fila));

  /* verificação */
  if(f == NULL){
    exit(1);
  }

  f->n = 0; /* fila vazia */
  f->ini = 0; /* posição inicial */

  return f;
}


int fila_cheia(Fila* f){
  return(f->n == N);
}


void fila_insere(Fila* f, float valor){
  int fim;

  /* verificação de fila cheia */
  if(fila_cheia(f)){
    printf("Fila cheia.");
    exit(1);
  }

  fim = (f->ini + f->n) % N; /* pega a posição */
  f->vet[fim] = valor; /* insere o valor */

  f->n++; /* atualiza número de elementos da fila */
}


int fila_vazia(Fila* f){
  return(f->n == 0);
}


float fila_retira(Fila* f){
  float valor;

  /* verificação */
  if(fila_vazia(f)){
    printf("Fila vazia.");
    exit(1);
  }

  /* pega o elemento inicial */
  valor = f->vet[f->ini];

  /* atualiza o início da fila */
  f->ini = (f->ini + 1) % N;

  f->n--; /* atualiza número de elementos da fila */

  return valor;
}


void fila_imprime(Fila* f){
  /* posição final */
  int fim = (f->ini + f->n) % N;

  /* i = posição inicial, e continuará progressivamente */
  for(int i = f->ini; i != fim; i = (i + 1) % N){
   printf("%f \t", f->vet[i]); /* elemento salvo na posição atual */
  }
}


void combina_filas(Fila* f_res, Fila* f1, Fila* f2){
  float valor;

  /* combinação */
  while(!fila_vazia(f1) || !fila_vazia(f2)){
    /* combinando fila 1 */
    if(!fila_vazia(f1)){
      valor = fila_retira(f1); /* retira o valor de f1*/

      /* verifica se f_res está cheia */
      if(!fila_cheia(f_res)){
        fila_insere(f_res, valor); /* se não estiver, insere o valor */
      }
    }

    /* combinando fila 2 */
    if(!fila_vazia(f2)){
      valor = fila_retira(f2); /* retira o valor de f2 */

      /* verifica se f_res está cheia */
      if(!fila_cheia(f_res)){
        fila_insere(f_res, valor); /* se não estiver, insere o valor */
      }
    }
  }
}


void imprime_fim(Fila* f){
  /*verificação */
  if(fila_vazia(f)){
    printf("Fila vazia.");
  }

  /* pega o final da fila */
  int fim = (f->ini + f->n-1) % N;

  printf("Fim da fila: %f", f->vet[fim]);
}


Fila* filtra(Fila* f, float x){
  Fila* ff = fila_cria();

  /* encontrar a posição final */
  int fim = (f->ini + f->n) % N;

  for(int i = f->ini; i != fim; i = (i + 1) % N){
    /* verificação do elemento de posição atual com x */
    if(f->vet[i] > x){
      fila_insere(ff, f->vet[i]);
    }
  }

  return ff;
}


void fila_libera(Fila* f){
  free(f);
}


int main(){
	
  Fila *f1,*f2,*f_res,*ff;

//Cria novas filas vazias
  f1 = fila_cria();
  f2 = fila_cria();
  f_res = fila_cria();

//Insere elementos na fila f1
  fila_insere(f1,10.0);
  fila_insere(f1,20.0);
  fila_insere(f1,30.0);
  fila_insere(f1,40.0);

//Retira um elemento da fila f1
  float v = fila_retira(f1);
  printf("\n%f: ",v);
  printf("\n");
  printf("\n");

//Imprime elementos de f1 
  fila_imprime(f1);
  printf("\n");
  printf("\n");

//Insere elementos na fila f2 
  fila_insere(f2,5.0);
  fila_insere(f2,15.0);
  fila_insere(f2,25.0);
  fila_insere(f2,35.0);
  fila_imprime(f2);
  printf("\n");
  printf("\n"); 
  
//Implementa a função "void combina_filas(Fila *f1, Fila*f2, Fila* f_res)" que, usando as funções anteriores
//retira, alternadamente, das filas f1 e f2 e insere em f_res 
  combina_filas(f_res,f1,f2);
  fila_imprime(f_res);
  
  printf("\n"); 
  printf("\n"); 
  printf("\n");

//Implementa a função "void imprime_fim (Fila *f)", que imprime o elemento de f_res que está no fim da fila
  imprime_fim(f_res);
  
  printf("\n"); 
  printf("\n"); 
  printf("\n");

//Implementa da função "Fila* filtra (Fila* f, float x)" que, usando as funções anteriores, Cria a nova fila ff, 
//com elementos de f_res maiores do que x 
  ff = filtra(f_res,20.0);
  fila_imprime(ff);
  
  fila_libera(f1);
  fila_libera(f2);
  fila_libera(f_res);
  fila_libera(ff);

  return 0;			
}