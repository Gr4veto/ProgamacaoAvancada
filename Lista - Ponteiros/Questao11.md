Resposta:

aloha[2] = value; É válido, a posição 3 do vetor aloha recebe o valor da variável value.

scanf("%f", &aloha); É válida, é gravado o valor do lido na primeira posição do vetor aloha, aloha[0].

printf("%f", aloha); Comando válido, mas não exibirá o valor do vetor, para isso é preciso um laço e imprimir o vetor comutando seus índices.

coisas[4][4] = aloha[3]; Comando válido, guardará o valor de aloha[3] na linha e coluna indicada em coisas

coisas[5] = aloha; Inválido, um dos motivos é que é necessário indicar os índices de linha e de coluna

pf = value; inválido, necessário indicar o endereço da variável, exemplo: pf = &value.

pf = aloha; válido, ponteiro apontará para o endereço de aloha.


