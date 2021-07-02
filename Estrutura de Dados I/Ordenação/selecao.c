#include <stdio.h>
#include <stdlib.h>

void selecao(int *vetor, int y){

  int menor = 999;
  int pos, aux;

  for(int i = 0; i < y; i++){
    for(int j = i + 1; j < y; j++){

      if(vetor[j] < menor){
        menor = vetor[j];
        pos = j;
      }
    }

    if(menor < vetor[i]){
      vetor[pos] = vetor[i];

      vetor[i] = menor;
    }

    menor = 999;
  }
}

int procura(int *vetor, int y, int x){
  int inicio = 0;
  int fim = y;
  int k, pos = -1;

  while(inicio <= fim && pos == -1){
    k = (inicio + fim) / 2;

    if(vetor[k] == x){
      return k;
    } else {
      
      if(vetor[k] < x){
      inicio = k + 1;
    } else {
      fim = k - 1;
    }
    }
  }

  return pos;
}

int main(void) {
  int *vetor, y;

  printf("Diga o tamanho do vetor: ");
  scanf("%d", &y);

  vetor = (int*)malloc(y * sizeof(int));

  printf("Agora, preencha o vetor: ");

  for(int i = 0; i < y; i++){
    scanf("%d", &vetor[i]);
  }

  selecao(vetor, y);

  printf("Vetor organizado:");

  for(int i = 0; i < y; i++){
    printf("%d \t", vetor[i]);
  }

  int x;

  printf("Digite o número a ser buscado: ");
  scanf("%d", &x);

  int resposta = procura(vetor, y, x);

  if(resposta >= 0){
    printf("Este número existe na posição %d", resposta);
  } else {
    printf("Este número não existe no vetor!");
  }

  free(vetor);

  return 0;
}