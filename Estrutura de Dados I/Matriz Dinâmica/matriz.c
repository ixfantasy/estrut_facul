#include <stdio.h> 
#include <stdlib.h>

void reajusta(int n, float **setor, float cod){
  int i, achou = 0;

  for (i = 0; i < n; i++){
    if(setor[i][0] == cod){
      setor[i][1] = setor[i][1]*1.2;
      printf("\n Sal:%f", setor[i][1]);
      achou = 1;
      break;	
    }
  }

  if(!achou){
    printf("\n Setor nao encontrado!");
  }	
}

float maior(int n, float **setor){
  int i;
  float max = 0;

  for (i = 0; i < n; i++){
    if(setor[i][1] > max){
      max = setor[i][1];
    }	
  }

  return max;
}

void ordena_bolha(int n, float **setor){

  int troca = -1;

  while(troca == -1){
    troca = 0;
    n--;

    for(int i = 0; i < n; i++){
      if(setor[i][0] > setor[i + 1][0]){
        int aux = setor[i + 1][0];

        setor[i + 1][0] = setor[i][0];

        setor[i][0] = aux;


        int aux2 = setor[i + 1][1];

        setor[i + 1][1] = setor[i][1];

        setor[i][1] = aux2;

        troca = -1;
      }
    }
  }
}

int busca_bin(int n, float **setor, float cod){
  int inicio = 0;
  int fim = n - 1;
  int achou = 0;

  while(inicio <= fim && achou == 0){
    int x = (inicio + fim) / 2;

    if(setor[x][0] == cod){
      achou = x + 1;
    } else {
      if(setor[x][0] < cod){
        inicio = x + 1;
      } else {
        fim = x - 1;
      }
    }
  }

  return achou;
}

int main(){
	float **setor, cod;

	int i, mat, achou, p;
	
  /* Matriz Dinâmica */
	printf("\nEntre com a quantidade máxima de setores: ");
  scanf("%d", &p);

  setor = (float**) malloc (p * sizeof(float*));

	printf("\nEntrada da tabela de Salarios\n");

	for (i = 0; i < p; i++){	    	
    setor[i] = (float*)malloc(2 * sizeof(float));	  

    printf("\nEntre com o codigo do Setor %d: ", i+1);
    scanf("%f", &setor[i][0]);

    printf("\nEntre com o salario do Setor %5.1f: ", setor[i][0]);
    scanf("%f", &setor[i][1]);
	}
	
  printf("\nEntre com o codigo do Setor que deseja reajustar salario (vinte por cento): ");
  scanf("%f", &cod);
        
  reajusta(p, setor, cod);
          
  printf("\nO maior salario da Empresa é: %6.2f: ", maior(p, setor));

  ordena_bolha(p,setor);

  for(int i = 0; i < p; i++){
    printf("Código: %2.f // Salário: %2.f", setor[i][0], setor[i][1]);
    printf("\n");
  }

  printf("\nEntre com o codigo do Setor para busca: ");
  scanf("%f", &cod);
  
  if((achou = busca_bin(p,setor,cod)) == 0){
    printf("\nSetor nao encontrado!\n");
  } else {
    printf("\nSetor: %2.1f   Salario: %6.2f\n", cod, setor[(achou - 1)][1]	);
  }

  system("PAUSE");

  return 0;			
}