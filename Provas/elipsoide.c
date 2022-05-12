#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include<locale.h>

/*
Mat�ria..: Progama��o avan�ada
Professor: Agostinho De Medeiros Brito Junior
Aluno....: Wesley Costa Da Silva
Matr�cula: 20210064582

Language: C 
Ide: DevC++

Prova - Quest�o 02: Matriz tridimensional - Elips�ide
Unidade I

*/

/*----------------------- Vari�veis Globais ---------------------*/

int i, k, j, aux; //vari�veis auxiliares para contagem

/*----------------------- Fun��o principal ----------------------*/
int main(){
	
	setlocale(LC_ALL,"");
	int np = 23, nl = 23, nc = 25,//n� de planos, linhas e colunas
	centroP = 11, centroL = 11, centroC = 12,//centro de x, y e z
	rp = 11, rl = 11, rc = 12,//raio de x, y e z
	cndZ; //vari�veis de coordenadas XYZ
	
	//definindo dimens�es das matrizes
	printf("Defina as dimens�es da matriz\n");
	printf("profundidade: ");
	scanf("%d", &np);
	printf("linhas......: ");
	scanf("%d", &nl);
	printf("colunas.....: ");
	scanf("%d", &nc);
	
	centroP = (np-1)/2;
	centroL = (nl-1)/2;
	centroC = (nc-1)/2;
	rp = centroP;
	rl = centroL;
	rc = centroC;
	
	system("cls");

	//Alocando din�nmicamente a matriz 3d
	unsigned int ***m = malloc(np*sizeof(int**));//aux para planos
	
		//Aux para linhas
		for(k = 0; k < np; k++){
			m[k] = malloc(nl*sizeof(int*));
			
			//alocando colunas
			for(i = 0; i < nl; i++){
				m[k][i] = malloc(nc*sizeof(int));
			}
		}
		
/*---------------------------------------------------------------*/		

//preenchendo matriz com o elips�ide atrav�s da equa��o:
		for(k = 0; k < np; k++){
			for(i = 0; i < nl; i++){
				for(j = 0; j < nc; j++){
					
					if ((
						 (pow(k-centroP,2)/pow(rp,2))
					 +   (pow(i-centroL,2)/pow(rl,2))
					 +   (pow(j-centroC, 2)/pow(rc, 2))) <= 1){
					 	
          				m[k][i][j]  = 1;
        			
					}
        			else{
          				m[k][i][j]  = 0;
        			}
				}
			}
		}
		
//Solicitando entrada das coordenadas ao usu�rio:
	
	while(1){
	
	printf("-------- Matriz tridimensional --------\n\t      (%d,%d,%d)\n\n", np, nl, nc);
	printf("\t  Figura: Elipsoide\n\t  Centro: (%d,%d,%d)\n\t  Raio..: (%d,%d,%d)\n", rp, rl, rc, rp, rl, rc);
	printf("\n--------- Digite a coordenada --------- \nZ = ");
  	scanf("%d", &cndZ);
	printf("\nElipsoide:\n");
 	for(k = 0; k < np; k++){
    	for (i = 0; i < nl; i++){
      		printf("%d ", m[k][i][cndZ]);
        }
  		 printf("\n");
    }
	
	printf("\nDeseja ver outra coordenada?\n1. Sim\n2. N�o\nDigite: ");
	scanf("%d", &aux);
	
	if(aux == 1){
		system("cls");
	}else{
		break;	
	}
	
	}
 
	
/*---------------------------------------------------------------*/		
	//Liberar mem�ria da matriz 3d alocada
	for(k = 0; k < np; k++){
		for(i = 0; i < nl; i++){
			free(m[k][i]);		
		}
		free(m[k]);
	}
	
	free(m);
	m = NULL; // m n�o aponta para nada
	
}//fim do main
