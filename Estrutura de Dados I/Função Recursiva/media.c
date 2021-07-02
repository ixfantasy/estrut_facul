/* Calcule a função "Média" dos elementos do vetor. Dica: acrescente um parâmetro. */
#include <stdio.h>

float media(float *vet, int n, float tam){
  if(n == 0){
    return 0;
  }

  return vet[n - 1] / tam + media(vet, n - 1, tam);
  
}

int main(void) {
  float vet[4];

  for(int i = 0; i < 4; i++){
    scanf("%f", &vet[i]);
  }

  float resul = media(vet, 4, 4);

  printf("A média é: %.2f", resul);

  return 0;
}