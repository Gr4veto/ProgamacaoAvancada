#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*
Matéria..: Progamação avançada
Professor: Agostinho De Medeiros Brito Junior
Aluno....: Wesley Costa Da Silva
Matrícula: 20210064582

Language: C 
Ide: DevC++

Prova - Questão 01: Matriz de led 8x8
Unidade I

*/

/*------------------- Marcadores das funções --------------------*/
void print_mt(unsigned char read); //Função para imprimir a matriz na base 2
void digitalHigh(unsigned char *read, unsigned long long leds);
void digitalLow(unsigned char *read, unsigned long long leds);

/*---------------------- Variáveis Globais -----------------------*/
unsigned int i, x, y; // auxiliar

/*----------------------- Função principal ----------------------*/
int main(){
	
  setlocale(LC_ALL,"");
  
  unsigned long long leds; //Variável de 64bits 
  unsigned char *matriz; //ponteiro para leds 8BITS
	matriz = &leds;

/*----------------------- Preencher de forma aleatória a matriz ----------------------*/
	srand(time(0));
	for(i = 0; i < 8; i++){
		matriz[i] = (rand()%100);
	}
	
	printf("Tamanho da variavel mat: %d bytes\n", sizeof(leds)); //Verifica se o long long tem 8bytes
	
	printf("\nMatriz: \n\n"); //Imprime matriz no formato 8x8
	printf("  76543210\n"); //Indice das colunas
	printf("  ||||||||\n");
	for(i = 7; i > 0; i--){
		printf("%d-", i);//Indice das linhas
		print_mt(matriz[i]);
		printf("\n");	
	}
	printf("%d-", 0);
	print_mt(matriz[0]);
	
   printf("\n\nValor inteiro - leds = %llu\n", leds); //Mostra o valor inteiro (ull)

//Acredito que o que se pede na questão acaba por aqui.
//------------ Aqui em diante é apenas para questionar se o usuário deseja desligar ou ligar algum led em específico   
   printf("\nDeseja alterar algum led específico?\n1. Sim\n2. Não\nDigite: ");
   scanf("%d", &x);
   
   if(x == 1){
	
	while(1){
	
   	system("cls");
   	printf("-----|ALTERAÇÃO|-----\n");
   	 
   	 printf("\n1. Ligar\n2. Desligar\n3. Sair\nDigite: ");
   	 scanf("%d", &x);
   	 
   	 switch (x){
   	 	case 1:
   	 		system("cls");
   	 		digitalHigh(matriz, leds);
   	 		break;
   	 	case 2:
   	 		digitalLow(matriz, leds);
   	 		break;
		case 3:
   	 		exit(0);
   	 		break;
		}
	printf("\nNovo valor inteiro: %llu\n", leds);	// exibe o novo valor inteiro referente a matriz alterada
	system("pause");
   }
}
   
  return 0;
} //Fim da função main


/*----------------------- Função de impressão ----------------------*/
void print_mt(unsigned char read){
  unsigned char bit, aux;
  bit=128;// 1000 0000
  for(aux=0; aux<8; aux++){
    if((read & bit) > 0){ 
      printf("1");
    }
    else{
      printf("0");
    }
    bit = bit>>1; //deslocando "bit" 1 bit para direita
  }
}

/*--------------------- Função para 'setar' bit --------------------*/
void digitalHigh(unsigned char *read, unsigned long long leds){
	
	system("cls");
	
	printf("\nMatriz - antes da alteração: \n"); //Imprime matriz no formato 8x8
	printf("  76543210\n");
	printf("  ||||||||\n");
	for(i = 7; i > 0; i--){
		printf("%d-", i);
		print_mt(read[i]);
		printf("\n");	
	}
	printf("%d-", 0);
	print_mt(read[0]);
	
	printf("\nValor inteiro - antes da alteração = %llu\n", leds); 
	 
	printf("\nDigite a linha e a coluna do led a ser ligado, respectivamente.\nEx.(0 7).\nDigite: ");
   	 		scanf("%d %d", &x, &y);
   	 		
   	 		printf("\n");
			read[x] |= (1<<y); // altera para nível lógico alto o bit referente a posição do led selecionado
			printf("Linha alterada: ");
			print_mt(read[x]); // exibe a linha alterada
			
}

/*--------------------- Função para 'resetar' bit ------------------*/

void digitalLow(unsigned char *read, unsigned long long leds){
	
	system("cls");
	
	printf("\nMatriz - antes da alteração: \n"); //Imprime matriz no formato 8x8
	printf("  76543210\n");
	printf("  ||||||||\n");
	for(i = 7; i > 0; i--){
		printf("%d-", i);
		print_mt(read[i]);
		printf("\n");	
	}
	printf("%d-", 0);
	print_mt(read[0]);;
	
	printf("\nValor inteiro - antes da alteração = %llu\n", leds);
	
	printf("\nDigite a linha e a coluna do led a ser desligado, respectivamente.\nEx.(0 7).\nDigite: ");
   	 		scanf("%d %d", &x, &y);
   	 		
   	 		printf("\n");
			read[x] &= ~(1<<y); // altera para nivel lógico baixo o bit referente a posição do led selecionado
			printf("Linha alterada: ");
			print_mt(read[x]);		
}
