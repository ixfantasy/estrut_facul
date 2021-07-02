/* Fazer a função MAX, que retorna o maior elemento do vetor */
#include <stdio.h>

int MAX(int *vet, int n){
  if(n < 0){
    return 0;
  }

  int x = MAX(vet, n - 1);
    if(x < vet[n]){
      x = vet[n];
    }
    
  return x;
}

int main(void) {
  int vet[3], x = 0;

  for(int i = 0; i < 3; i++){
    scanf("%d", &vet[i]);
  }

  int resul = MAX(vet, 3);

  printf("O maior número do vetor é: %d", resul);

  return 0;
}