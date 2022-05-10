#include<stdio.h>
#include<stdlib.h>

int main(void){
	
	float *x, save, f; //ponteiro para float e variável de memória rápida
	int i, j, n, a, b; //Variaveis auxiliares de contagem
	
	printf("Digite quantos valores devem ser gerados: ");
	scanf("%d", &n);
	
	x = (float*) malloc(n*sizeof(float));
	
	//verificar se deu bom:
	if(x == NULL){
		printf("Memória insuficiente :(");
		system("pause");
		exit(0);
	}
	
	srand(time(0)); // mudar semente para gerar valores aleatórios
	/*time retorna um número inteiro referente a hora da máquina,
	 vai ser usado para cada execução gerar uma semente diferente;*/
	 
	for(i = 0; i<n; i++){ //Esse for gera valores 'aleatórios' tipo float e atribui ao array
		 a  =  rand()%100;
		 b  =  rand()%100;
		 f  =  ((float)a/b);
		 
		x[i] =  f;
	}
	
	printf("Desordenado: ");
	for(i = 0; i<n; i++){
		printf("%.2f ", x[i]);
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i == 0){
				if(x[i] > x[j]){
					save = x[j];
					x[j] = x[i];
					x[i] = save;
				}
			}else{
				if((x[i] < x[j]) && (x[i] < x[i-1]) ){
       			 save = x[j];
       			 x[j]= x[i];
       			 x[i]=save;
			}
			}
		}
	}
	
		printf("\n");
	
	printf("Ordenado...: "); //Exibe os valores ordenados em ordem crescente
	for(i = 0; i<n; i++){
		printf("%.2f ", x[i]);
	}
	
	
	//memória, seja livre, a escravidão acabou
	free(x);
	
	
}
