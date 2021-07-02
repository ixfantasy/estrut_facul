#include <stdio.h>

int soma (int* v, int n){

  if(n == 0){
    return 0;
  }

  return soma(v, n - 1) + v[n - 1];
}

int main(void) {
  int v[3];

  printf("Digite o valor de cada item do vetor: ");

  for(int i = 0; i < 3; i++){
    scanf("%d", &v[i]);
  }

  int resul = soma(v, 3);

  printf("Resultado da soma: %d", resul);

  return 0;
}