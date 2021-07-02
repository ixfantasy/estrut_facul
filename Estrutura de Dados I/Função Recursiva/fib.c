#include <stdio.h>

int FIB (int n){
  if(n <= 2){
    return 1;
  }

  return FIB(n -1) + FIB(n - 2);
}

int main(void) {
  int n;
  printf("Entre com o valor de n: ");
  scanf("%d", &n);

  int resul = FIB(n);

  printf("O valor de Fibonacci na posição %d é: %d", n, resul);

  return 0;
}