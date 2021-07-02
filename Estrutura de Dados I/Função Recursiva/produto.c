/* Calcule a função "Produto" que multiplica os elementos do vetor. */
#include <stdio.h>

int produto(int *vet, int n){
  if(n == 0){
    return 1;
  }

  return vet[n - 1] * produto(vet, n - 1);
}

int main(void) {
  int vet[4];

  for(int i = 0; i < 4; i++){
    scanf("%d", &vet[i]);
  }

  int resul = produto(vet, 4);

  printf("O produto final é: %d", resul);

  return 0;
}