/*Aloque espaço para uma sequência de
números escolhida pelo usuário. Até que
Ele digite a opção não.
Receba os valores e imprima-os em ordem inversa.*/

#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int tam);
void leitura(int *p, int tam);
void mostra_inversa(int *p, int tam);

main()
{
int *ptr=NULL,cont;

printf("\nQuantos numeros deseja alocar: ");
scanf("%i",&cont);
fflush(stdin);
aloca(&ptr,cont);
leitura(ptr,cont);
mostra_inversa(ptr,cont);
printf("\n\n");
system("pause");
}//main

void aloca(int **p, int tam)
{
if((*p=(int*)realloc(*p,tam*sizeof(int)))==NULL)
  exit(1);
}//aloca

void leitura(int *p, int tam)
{
int i;
for(i=0;i<tam;i++,p++)
  {
  	printf("\nEndereco: %u - Numero: ",p);
  	scanf("%i",p);
  	fflush(stdin);
  }//for
}//leitura

void mostra_inversa(int *p, int tam)
{
int i;
p+=tam-1;
for(i=tam-1;i>=0;i--,p--)
  printf("\nEndereco: %u - Numero: %i",p,*p);
}//mostra_inversa










