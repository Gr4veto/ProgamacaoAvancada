/*
Questão 17
Sistema operacional: Windowns 10 Home x64
IDE: DevC++
Linguagem C

Resposta:
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//marcadores das funções:
void matrixRead (int nl, int nc, int **m);
void matrixWrite (int nl, int nc, int **m);
void matrixX(int nlA, int ncA, int ncB, int **ma, int **mb, int **mc);

//variaveis globais:

int i, j, k; //auxiliares

int main (void){
	
	setlocale(LC_ALL,"");
	
	int **ma, **mb, **mc,
	nlA, ncA, ncB;
	
	printf("Digite o numero de linhas e colunas da matriz(ex.: i j): ");
	scanf("%d %d", &nlA, &ncA); //guardando dimensões da matriz
	ncB = nlA;//atribuindo o numero de linhas de A ao numero de colunas de B
	
	//alocando matrizes dinâmicamente:
	ma = malloc(nlA*sizeof(int*));
	ma[0] = malloc(ncA*nlA*sizeof(int));
	for (i = 1; i< nlA; i++){
  	ma[i] = ma[i-1] + ncA;
	}
	
	mb = malloc(ncA*sizeof(int*));
	mb[0] = malloc(ncA*ncB*sizeof(int));
	for (i = 1; i< nlA; i++){
  	mb[i] = mb[i-1] + ncB;
	}
	
	mc = malloc(nlA*sizeof(int*));
	mc[0] = malloc(nlA*ncB*sizeof(int));
	for (i = 1; i< nlA; i++){
  	mc[i] = mc[i-1] + ncB;
	}
	
	//Preenchendo matrizes:
	matrixWrite(nlA, ncA, ma);
	matrixWrite(ncA, ncB, mb);
	matrixX(nlA, ncA, ncB, ma, mb, mc);
	
	//imprimindo matrizes:
	printf("Matriz A:\n");
	matrixRead(nlA, ncA, ma);
	printf("\nMatriz B:\n");
	matrixRead(ncA, ncB, mb);
	printf("\nMatriz C:\n");
	matrixRead(nlA, nlA, mc);
	
	//Liberando memoria:
	free(mc[0]);
	free(mc);
	free(mb[0]);
	free(mb);
	free(ma[0]);
	free(ma);
	
}

//Função para gravação de matriz:
void matrixWrite (int nl, int nc, int **m){
	
	for (i = 0; i<nl; i++){
  		for (j =0; j<nc; j++){
    		m[i][j] = (rand()%10);
  		}
	}					
}

//Função de leitura de matriz:
void matrixRead (int nl, int nc, int **m){
	
	for (i = 0; i < nl; i++){
  		for (j =0; j < nc; j++){
    		printf(" %d ", m[i][j]);
  		}
  		printf("\n");
	}		
}

//Multiplicação de matrizes:
void matrixX(int nlA, int ncA, int ncB, int **ma, int **mb, int **mc){

	for (i = 0; i<nlA; i++){
  		for (j =0; j<ncB; j++){
    		for(k = 0; k<ncA; k++){
    		 mc[i][j] = ma[i][k]*mb[k][j]+ mc[i][j];
    		}
  		}
	}
}
