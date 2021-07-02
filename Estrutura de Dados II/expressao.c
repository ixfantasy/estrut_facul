#include <stdio.h>
#include <stdlib.h>

/* STRUCTS */
struct arv{
  char info;
  struct arv* esq;
  struct arv* dir;
};
typedef struct arv Arv;

struct no{
  int num;
  struct no* prox;
};
typedef struct no No;

struct pilha{
  No* prim;
};
typedef struct pilha Pilha;


/* FUNÇÕES DE PILHA */ 
// criar uma pilha vazia
Pilha* cria(){
  Pilha* p = (Pilha*) malloc(sizeof(Pilha));

  p->prim = NULL;

  return p;
}

// adicionar itens dentro da pilha
void push(Pilha* p, int v){
  No* n = (No*) malloc(sizeof(No));

  n->num = v;

  n->prox = p->prim;

  p->prim = n;
}

// remover itens da pilha
int pop(Pilha* p){
  No* aux;
  int v;

  aux = p->prim;

  v = aux->num;

  p->prim = aux->prox;

  free(aux);

  return v;
}

// imprimir pilha
void imp_p(Pilha* p){
  No* aux;

  for(aux = p->prim; aux != NULL; aux = aux->prox){
    printf("%d \t", aux->num);
  }
}

int pilha_vazia(Pilha* p){
  return (p->prim == NULL);
}

Pilha* inverter(Pilha* p){
  Pilha* aux = cria();

  while(!pilha_vazia(p)){
    push(aux, pop(p));
  }

  return aux;
}


/* FUNÇÕES ÁRVORE */
// verificar se a árvore está vazia
int vazia(Arv* a){
  return a == NULL;
}

// criar uma árvore vazia
Arv* cria_vazia(){
  return NULL;
}

// inserir itens dentro da árvore
Arv* criar(char c, Arv* esq, Arv* dir){
  Arv* p = (Arv*)malloc(sizeof(Arv));
	p->info = c;
	p->dir = dir;
	p->esq = esq;
	
	return p;
}

// analisar dados e jogar números dentro da pilha
void insert_pilha(Arv* a, Pilha* p){

  if(!vazia(a)){
    insert_pilha(a->esq, p);

    insert_pilha(a->dir, p);

    if(a->info != '+' && a->info != '*'){
      int y = a->info - '0';

      push(p, y);
    }
  }
}

// identificar operadores, resgatar itens da pilha e calcular
void calcular(Arv* a, Pilha* p){
  int res = 0;
  
  if(!vazia(a)){
     
    if(a->info == '+' || a->info == '*'){
      int z = pop(p);
      printf("Z = %d \t", z);

      int y = pop(p);
      printf("Y = %d \t", y);

      switch(a->info){
        case '*': res = z * y; break;

        case '+': res = z + y; break;

        default: break;
      }

      printf("-> Res: %d %c %d = %d \n", z, a->info, y, res);

      push(p, res);
    }

    calcular(a->esq, p);
    calcular(a->dir, p);
  }
}

// imprimir a árvore - na ordem
void imprime_in(Arv* a){
  if(!vazia(a)){
    imprime_in(a->esq);
    printf("%c \t", a->info);
    imprime_in(a->dir);
  }
}

// imprimir a árvore - pós-ordem
void imprime_pos(Arv* a){
  if(!vazia(a)){
    imprime_pos(a->esq);
    imprime_pos(a->dir);
    printf("%c \t", a->info);
  }
}

// imprimir a árvore - pré-ordem
void imprime_pre(Arv* a){
  if(!vazia(a)){
    printf("%c \t", a->info);
    imprime_pre(a->esq);
    imprime_pre(a->dir);
  }
}


int main(void) {

  // inserindo dados dentro da árvore
  Arv* a1 = criar('+',cria_vazia(),cria_vazia());

	Arv* a2 = criar('2',cria_vazia(),a1);

	Arv* a4 = criar('4',cria_vazia(),cria_vazia());

	Arv* a3 = criar('+',a4,a2);

	Arv* a5 = criar('5',a3,cria_vazia());

	Arv* a7 = criar('7',cria_vazia(),cria_vazia());

	Arv* a6 = criar('*',a7,a5);

  // criando pilha
  Pilha* p = cria();
  Pilha* nova = cria();

  // chamando função para inserir números dentro da pilha
  insert_pilha(a6, p);
  printf("Resultado da pilha: ");
  imp_p(p);

  // inverter a ordem da pilha
  nova = inverter(p);
  printf("\n\nResultado da nova pilha invertida: ");
  imp_p(nova);
  printf("\n\n");

  // calculando os números dentro da pilha
  printf("Calculando as expressões:\n");
  calcular(a6, nova);

  // métodos para imprimir árvore
  printf("\n\nNa ordem: ");
  imprime_in(a6);
  printf("\n\n");

  printf("Pós-ordem: ");
  imprime_pos(a6);
  printf("\n\n");

  printf("Pré-ordem: ");
  imprime_pre(a6); 

  return 0;
}