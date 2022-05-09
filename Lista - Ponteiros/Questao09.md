Resposta:

Considerando que x está armazenado no endereço da memória 4092.

char(1byte):
x+1 = 4093
x+2 = 4094
x+3 = 4095

int(2bytes):
x+1 = 4094
x+2 = 4096
x+3 = 4098

float(4bytes):
x+1 = 4096
x+2 = 4100
x+3 = 4104

double(8bytes):
x+1 = 4100
x+2 = 4108
x+3 = 4116