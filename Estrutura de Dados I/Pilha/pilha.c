#include<stdio.h>
#include<stdlib.h>

struct lista {
  float info;
  struct lista* prox;
};
typedef struct lista Lista;


/* estrutura da pilha */
struct pilha {
   Lista* prim; /* aponta para o topo da pilha */
};
typedef struct pilha Pilha;


Pilha* pilha_cria(){
  Pilha* pont = (Pilha*) malloc(sizeof(Pilha));

  if(pont == NULL){
    exit(1);
  }

  pont->prim = NULL;

  return pont;
}


void pilha_push(Pilha* pont, float n){
  Lista* no = (Lista*) malloc(sizeof(Lista));

  if(no == NULL){
    exit(1);
  }

  no->info = n;
  no->prox = pont->prim;
  pont->prim = no;
}


float pilha_pop(Pilha* pont){
  Lista* aux;
  float n;

  if(pont->prim == NULL){
    printf("Pilha vazia! \n");
    exit(1);
  }

  aux = pont->prim;
  n = aux->info;

  pont->prim = aux->prox;
  free(aux);

  return n;
}


void pilha_imprime(Pilha* pont){
  Lista* no;

  for(no = pont->prim; no != NULL; no = no->prox){
    printf("%f \t", no->info);
  }
}


void pilha_libera(Pilha* pont){
  Lista* no = pont->prim;

  while(no != NULL){
    Lista* aux = no->prox;
    
    free(no);

    no = aux;
  }

  free(pont);
}


void imprime(Pilha* pont){
  Pilha* aux = pilha_cria();

  while(pont->prim != NULL){
    pilha_push(aux, pilha_pop(pont));
  }

  while(aux->prim != NULL){
    float n = pilha_pop(aux);
    printf("%f \t", n);

    pilha_push(pont, n);
  }

  pilha_libera(aux);
}


void troca_topo(Pilha* pont){
  if(pont->prim == NULL){
    printf("Lista vazia! Não é possível fazer a troca.");
    exit(1);
  }

  Lista* no;
  int cont = 0;
  for(no = pont->prim; no != NULL; no = no->prox){
    cont++;
  }
  if(cont < 2){
    printf("Não há elementos suficiente! Não é possível fazer a troca.");
    exit(1);
  }

  int n1 = pilha_pop(pont);
  int n2 = pilha_pop(pont);

  pilha_push(pont, n1);
  pilha_push(pont, n2);
}


int main(){

  /* Implementação de pilha com lista encadeada */
	Pilha *p;
	p = pilha_cria();
	pilha_push(p,10);
	pilha_push(p,15);
	pilha_push(p,20);
	pilha_push(p,25);
	float v = pilha_pop(p);
	printf("%f\n", v);
	printf("\n");
       
  /* vai imprimir do topo para a base, percorrendo a lista encadeada */
	pilha_imprime(p);
	printf("\n");
        
  /* vai imprimir da base para o topo usando as funções já definidas e uma pilha auxiliar */
	imprime(p);
  printf("\n");

  /*vai executar a função troca_topo, que troca o valor do topo com aquele abaixo, usando somente as funções push e pop*/
  // protótipo: void troca_topo(Pilha*p) - emite mensagem de erro para
  // pilha vazia ou com menos de dois elementos.
	troca_topo(p);
  pilha_imprime(p);

	pilha_libera(p);
  system("PAUSE");
	return 0;
}