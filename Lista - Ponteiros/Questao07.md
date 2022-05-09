Resposta:

Considerando int mat[4], *p , x;
As seguintes expressões são válidas:

p = mat + 1; Válida!
Justificativa: porque o ponteiro irá receber o endereço mat[1], a segunda posição do vetor.

p = mat++; Inválida!
Justificativa: Tendo em vista que a sitaxe não condiz com o vetor. O incremento soma 1 a unidade, é justo utilizá-lo para incrementar o valor guardado em alguma de suas posições.

p = ++mat; Inválida!
Justificativa: Pela mesma razão da expressão anterior, o incremento antes ou após a operação não faz diferença. É justo utilizar a expressão 01. O incremento soma 1 a unidade, é justo utilizá-lo para incrementar o valor guardado em alguma de suas posições.

x = (*mat)++; Válida!
Justificativa: Essa expressão é válida porque estamos pegando o endereço da primeira posição do vetor mat[], ou seja, mat[0], e incrementando o valor guardado nessa posição. Ex.: Se caso mat[0] = 1, x seria 2;