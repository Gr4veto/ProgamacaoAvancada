/*
Questão 10
Sistema operacional: Windowns 10 Home x64
IDE: DevC++
Resposta:

Ponteiros são variáveis que guardam endereços de variáveis.
A utilização dos ponteiros é interessante, porque eles passam
determinado dado, por referência, apontando seu endereço.
Isso facilita a passagem dos dados/valores, previnindo 
possíveis erros.

Uma aplicação interessante dos ponteiros, está nas funções,
onde por exemplo, podemos passar um array como argumento 
de um função, apenas passando através de um ponteiro, a 
referencia de seu endereço inicial.

Esse código, exemplifica esssa aplicação:
Funções - Gravação e leitura de vetores usando ponteiros
*/

#include<stdio.h>
#include<locale.h>

//marcadores das funções:
void vectorRead (int tam, int *vt); /*vt é um ponteiro para inteiro que irá apontar
 para o endereço de um vetor, e será utilizado para preencher e ler esse vetor*/
void vectorWrite (int tam, int *vt);

//marcadores das funções:
void vectorRead (int tam, int *vt);
void vectorWrite (int tam, int *vt);

//constantes:
#define tamanho 5

int main (void){
	setlocale(LC_ALL,"");
	int vetor[tamanho], vetor2[tamanho];
	
	printf("Preencha o primeiro vetor:\n");
	vectorWrite (tamanho, vetor);
	
	printf("Preencha o segundo vetor:\n");
	vectorWrite (tamanho, vetor2);
	
	printf("vetor 01: ");
	vectorRead(tamanho, vetor);
	
	printf("vetor 02: ");
	vectorRead(tamanho, vetor2);
}

//Função para gravação vetorial:
void vectorWrite (int tam, int *vt){
	unsigned int i = 0;
	
	for(i = 0; i < tam; i++){
		printf("Posição %d: ", i+1);
		scanf("%d", &vt[i]);
	}	
}

//Função de leitura vetorial:
void vectorRead (int tam, int *vt){
	unsigned int i = 0;
	
	for(i = 0; i < tam; i++){
		printf("%d ", vt[i]);
	}		
}
