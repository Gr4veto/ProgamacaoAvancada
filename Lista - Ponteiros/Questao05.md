Resultado:

printf 01: contador/valor/valor/endereco/endereco

printf 02:
loop 0: i = 0
loop 1: i = 1
loop 2: i = 2
loop 3: i = 3
loop 4: i = 4

printf 03:
loop 0: vet[0] = 1.1
loop 1: vet[1] = 2.2
loop 2: vet[2] = 3.3
loop 3: vet[3] = 4.4
loop 4: vet[4] = 5.5

printf 04:
loop 0: *(f + 0) = 1.1
loop 1: *(f + 1) = 2.2
loop 2: *(f + 2) = 3.3
loop 3: *(f + 3) = 4.4
loop 4: *(f + 4) = 5.5

printf 05:
loop 0: &vet[0] = endereço de v[0] 
loop 1: &vet[1] = endereço de v[1] 
loop 2: &vet[2] = endereço de v[2] 
loop 3: &vet[3] = endereço de v[3] 
loop 4: &vet[4] = endereço de v[4] 

printf 06:
loop 0: *(f + 0) = endereço de v[0] 
loop 1: *(f + 1) = endereço de v[1] 
loop 2: *(f + 2) = endereço de v[2] 
loop 3: *(f + 3) = endereço de v[3] 
loop 4: *(f + 4) = endereço de v[4] 

Os resultados foram previstos com exatidão, só não pude determinar os endereços do array, que podem variar.
Compilando no DevC++ em minha maquina, foram:

endereço de v[0]: 62FDF0
endereço de v[1]: 62FDF4
endereço de v[2]: 62FDF8
endereço de v[3]: 62FDFC
endereço de v[4]: 62FE00

