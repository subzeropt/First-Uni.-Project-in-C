#include <stdio.h>
#include <stdbool.h>

#define MAX_JOGADAS 20


int Primo(int n){
  int divisor=2;

  while(divisor*divisor<=n){
    if(n%divisor==0)
      return 0;

    divisor++;
  }
  return 1;
}


//                   K=45 W=40
bool JPLanceValido(int k,int w) {

int i;
  if(k<w)
   return 0;

  for(i=2;i<=k;i++) {

    //os fatores primos de um inteiro são números primos que dividem esse numero exatamente
    if(Primo(i)==1 && k%i==0){

       if( (k / i) == w )
         return true;


       if( (k - i) == w )
         return true;
    }
  }

  return false;
}


int JPJogadas(int arr[],int k)
{

  int y,i,j=0,flag1=0,flag2=0;

  for(i=2;i<=k;i++)
  {

    if(Primo(i)==1 && k%i==0)
	{

       flag1=0;
       flag2=0;
       for(y=0;y<MAX_JOGADAS;y++)
	   {
          if( arr[y] == (k/i) )
            flag1=1 ;

          if( arr[y] == (k-i))
            flag2=1 ;
       }

       if(flag1==0 )
	   {
         arr[j]=k/i;
         j++;
       }

       if(flag2==0 && (k/i)!=(k-i))
	   {
         arr[j]=k - i;
         j++;
       }
    }


  }


  return j;
}


void main(){


//****************** GRUPO II ******************
 /*
 int k,w,i;
 printf("\nIndique Lance(dois numeros):");
 scanf("%d %d",&k,&w);

 if(JPLanceValido(k,w))
   printf("Lance valido\n");
 else
   printf("(Lance invalido\n");

 */

 /*
  int k,w,i;
 printf("\nIndique Lance(dois numeros):");
 scanf("%d",&k);

 for(i=2;i<k;i++){

   if(JPLanceValido(k,i)==true)
     printf("Lance valido\n");
   else
     printf("(Lance invalido\n");

 }
 */



//****************** GRUPO III ******************
/*
int n,jogador=1,valor,k,i;
int jogadas[MAX_JOGADAS];

printf("\nIndique Posicao(um numero):");
scanf("%d",&k);


n=JPJogadas(jogadas,k);


//mostrar as jogadas
printf("\nJoagadas(%d):",n);
for(i=0;i<n;i++)
   printf("%d ",jogadas[i]);

printf("\n");
*/


//****************** GRUPO IV ******************
int k,n,i,lance,lance_valido,jogador,fim_de_jogo;
int jogadas[MAX_JOGADAS];


printf("\nIndique Posicao(um numero):");
scanf("%d",&k);

jogador=1;
lance_valido=1;

do{
 n=JPJogadas(jogadas,k);

 printf("\nJogadas(%d):",n);
 for(i=0;i<n;i++)
   printf("%d ",jogadas[i]);

 printf("\n");
 printf("Lance :");
 scanf("%d",&lance);

 lance_valido=0;
 for(i=0;i<n;i++)
  if(lance == jogadas[i])
    lance_valido=1;


 if(lance_valido==0)
  if(jogador%2==0)
    printf("Ganha jogador impar\n");
  else
    printf("Ganha jogador par\n");


if( (lance==0 || lance==1)&& lance_valido==1 )
  if(jogador%2==0)
    printf("Ganha jogador par\n");
  else
    printf("Ganha jogador impar\n");

 k=lance;
 jogador++;
}while(lance_valido==1 && lance!=1 && lance!=0);



}
