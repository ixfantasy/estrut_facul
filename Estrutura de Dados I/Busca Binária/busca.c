#include <stdio.h>

int procura(int *vet, int fim, int num){
  int inic = 0;
  fim--;
  int pos = -1;
  int x;

  while(inic <= fim && pos == -1){
    x = (inic + fim) / 2;

      if(vet[x] == num){
        pos = x;
      } else {
          if(x < num){
            inic = x + 1;
          } else {
            fim = x - 1;
          }
      }
  }

  return pos;
}


int main(){
  int vetor[] = {1, 2, 3, 4, 5};
  int num;

  printf("Digite o número para busca: ");
  scanf("%d", &num);

  int pos = procura(vetor, 5, num);

  if(pos >= 0){
    printf("Este número foi encontrado na posição %d!", pos);
  } else {
    printf("Este número não foi encontrado!");
  }

  return 0;
}