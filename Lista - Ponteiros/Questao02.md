Para:

int i=5, *p;
p = &i;
printf("%x %d %d %d %d", p,*p+2,**&p,3**p,**&p+4);

Considerando o endereço 4094, será impresso exatamente:
Resposta: 4094 7 5 15 9
