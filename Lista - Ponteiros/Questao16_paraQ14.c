#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//Marcadores para funcao:
int comparador(const void *a, const void *b);

//Funcao principal:
int main(void){
	clock_t marcador[2];
	
	float *x, save, f; //ponteiro para float e variável de memória rápida
	int i, n, a, b; //Variaveis auxiliares de contagem
	
	marcador[0] = clock(); //inicia marcação aqui
	
	printf("Digite quantos valores devem ser gerados: ");
	scanf("%d", &n);// Guarda quantos valores devem ser gerados
	
	x = (float*) malloc(n*sizeof(float)); // aloca memoria dinamicamente
	
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
		 a  =  rand()%100;//guarda em a um valor inteiro
		 b  =  rand()%100;//guarda em b um valor inteiro
		 f  =  ((float)a/b);//guarda em f um valor tipo float a partir da razão a/b
		 
		x[i] =  f;//preenche o array
	}
	
	printf("Desordenado: ");//imprime o array antes do qsort
	for(i = 0; i<n; i++){
		printf("%.2f ", x[i]);
	}
	
	//ordenando array com a funcao qsort:
	qsort(x, n, sizeof(float), comparador);
	
		printf("\n");
	
	printf("Ordenado...: "); //Exibe os valores ordenados em ordem crescente
	for(i = 0; i<n; i++){
		printf("%.2f ", x[i]);
	}
	
	
	//memória, seja livre, a escravidão acabou
	free(x);
	
	marcador[1] = clock();
	double time = (marcador[1] - marcador[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("\n\nTempo gasto: %g ms.", time);
	printf("\nEm seg.....: %.2g   s.", time/1000);
	getchar();
	
	
}//fim da funcao man


//funcao comparadora para qsort:
int comparador(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}
/*Nessa funcao, subtraimos a de b, e o resultado
é retornado como inteiro:
a < b: resultado negativo
a > b: resultado positivo
a = b: resultado é zero

a e b são valores das posições do array,
a função recebe como argumento, dois ponteiros
void, por isso é feito o cast no return para
o tipo inteiro, já que o qsort trabalha com return desse tipo.
*/
