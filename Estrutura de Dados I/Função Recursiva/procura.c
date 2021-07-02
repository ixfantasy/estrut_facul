/* Faça a função "Procura" recursiva. */
#include <stdio.h>

int procura(int *vet, int n, int x){
  if(vet[n - 1] == x){
    return n - 1;
  } else if(n == 0){
    return -1;
  }
  
  return procura(vet, n - 1, x);
}

int main(void) {
  int vet[5], x;

  for(int i = 0; i < 5; i++){
    printf("Posição %d: ", i);
    scanf("%d", &vet[i]);
  }

  printf("\nNúmero a ser procurado: ");
  scanf("%d", &x);

  int resul = procura(vet, 5, x);

  if(resul >= 0){
    printf("Achou na posição %d!", resul);
  } else {
    printf("Não achou o número! :(");
  }

  return 0;
}