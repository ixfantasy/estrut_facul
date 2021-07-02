#include <stdio.h>

int mdc(int a, int b){
  if(a % b == 0){
    return b;
  } else {
    a = a % b;

    return mdc(b, a);
  }
}

int main(void) {
  int a, b;

  printf("Digite o primeiro número: ");
  scanf("%d", &a);

  printf("Digite o segundo número: ");
  scanf("%d", &b);

  int resul = mdc(a, b);

  printf("O MDC é: %d", resul);

  return 0;
}