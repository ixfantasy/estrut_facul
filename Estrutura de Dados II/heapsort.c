#include <stdio.h>
#include <stdlib.h>

// FUNÇÃO PARA IDENTIFICAR A RAIZ E OS FILHOS
void criarHeap(int *v, int n, int i){
  int maior = i;

  // ENCONTRAR O FILHO ESQUERDO (MÉTODO PADRÃO)
  int esq = 2 * i + 1;

  // ENCONTRAR O FILHO DIREITO (MÉTODO PADRÃO)
  int dir = 2 * i + 2;

  // SE ESQ FOR MAIOR QUE A RAIZ, PORÉM MENOR QUE O TAMANHO TOTAL DO VETOR
  if(esq < n && v[esq] > v[maior]){
    maior = esq;
  }

  // SE DIR FOR MAIOR QUE A RAIZ, PORÉM MENOR QUE O TAMANHO TOTAL DO VETOR
  if(dir < n && v[dir] > v[maior]){
    maior = dir;
  }

  // SE O MAIOR NÃO FOR MAIS A RAIZ ATUAL
  if(maior != i){

    // FAZ A TROCA ENTRE O ATUAL E O MAIOR
    int aux = v[i];

    v[i] = v[maior];

    v[maior] = aux;

    // REPETE O PROCESSO COM A SUB-ÁRVORE AFETADA PELAS TROCAS
    criarHeap(v, n, maior);
  }
}


// FUNÇÃO PARA ORDENAR
void heapSort(int *v, int n){

  // CONSTRÓI O HEAP, ENCONTRANDO O ELEMENTO CENTRAL E DECREMENTANDO
  for(int i = n / 2 - 1; i >= 0; i--){
    criarHeap(v, n, i);
  }

  // EXTRAIR OS ELEMENTOS DO HEAP - REMOVER ELEMENTO MÁXIMO
  for(int i = n - 1; i >= 0; i--){

    // MOVE A RAIZ ATUAL PARA O FINAL DA "ÁRVORE" E EXTRAIR O ÚLTIMO NÓ
    int aux = v[0];

    v[0] = v[i];

    v[i] = aux;

    // ENCONTRAR O NOVO ELEMENTO MÁXIMO NO HEAP AGORA REDUZIDO
    criarHeap(v, i, 0);
  }
}

void imprimir(int *ar, int n){
  for(int i = 0; i < n; i++){
    printf("%d \t", ar[i]);
  }

  printf("\n\n");
}

int main(){

  int v[] = {12, 11, 13, 5, 6, 7};

  
  int n = sizeof(v) / sizeof(v[0]);

  imprimir(v, n);

  heapSort(v, n);

  imprimir(v, n);

  return 0;
}