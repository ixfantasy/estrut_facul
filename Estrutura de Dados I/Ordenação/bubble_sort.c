#include <stdio.h>

void ordena(int n, int *vetor){
  int x = n, troca = 1;

  while(troca == 1){
    x--;
    troca = 0;

    for(int i = 0; i < x; i++){
      if(vetor[i] > vetor[i + 1]){
        int aux = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = aux;
        troca = 1;
      }
    }
  }

}

int procura(int *vet, int fim, int num){
  int inic = 0;
  int pos = -1;
  int x;

  while(inic <= fim && pos == -1){
    x = (inic + fim) / 2;

      if(vet[x] == num){
        pos = x;
      } else {
          if(vet[x] < num){
            inic = x + 1;
          } else {
            fim = x - 1;
          }
      }
  }

  return pos;
}

int main(void) {
  int vetor[] = {4, 10, 20, 8, 3}, x;

  for(int i = 0; i < 5; i++){
    printf("%d \t", vetor[i]);
  }

  ordena(5, vetor);

  printf("\n \n");

  for(int i = 0; i < 5; i++){
    printf("%d \t", vetor[i]);
  }

  printf("\n\nDigite um número para busca: ");
  scanf("%d", &x);

  int res = procura(vetor, 5, x);

  if(res >= 0){
    printf("O número foi encontrado na posição %d!", res);
  } else {
    printf("O número não foi encontrado!");
  }
   

  return 0;
}