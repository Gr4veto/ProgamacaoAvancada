/*
Questão 10
Resposta:

Sistema operacional: Windowns 10 Home x64
IDE: DevC++

Os dados referentes as bytes dos
tipos de variáveis comentados a seguir,
são baseados nos resultados desse código
referente as especificações dessa máquina:

Foi criado um array de 4 posições para 
cada tipo de variável(char, int, float e double)
e foi criado um ponteiro para apontar para cada
tipo de variável apontando para o endereço
inicial de cada array.

char(1 byte):
array: vtc [4] - ponteiro: *pc

int(4 bytes):
array: vti[4] - ponteiro: *pi

float(4 bytes):
array: vtf[4] - ponteiro: *pf

double(8 bytes): 
array: vtd[4] - ponteiro: *pd

Foi possível perceber que os endereços das 
posições dos arrays, variavam de acordo com
o tamanho de seu tipo. 

*/ 

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char   vtc[4], *pc;
  int    vti[4], *pi, i;
  float  vtf[4], *pf;
  double vtd[4], *pd;

  pc = &vtc;
  pi = &vti;
  pf = &vtf;
  pd = &vtd;

  printf("char:\n");
  for(i = 0; i < 3; i++){
  	printf("vtc[%d] end.: %X \n",i,vtc+i);
  }
  
  printf("\nint:\n");
  for(i = 0; i < 3; i++){
  	printf("vti[%d] end.: %X \n",i,vti+i);
  }

  printf("\nfloat:\n");
  for(i = 0; i < 3; i++){
  	printf("vtf[%d] end.: %X \n",i,vtf+i);
  }

  printf("\ndouble:\n");
  for(i = 0; i < 3; i++){
  	printf("vtd[%d] end.: %X \n",i,vtd+i);
  }

  }
