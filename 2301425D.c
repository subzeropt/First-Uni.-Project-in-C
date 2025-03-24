#include <stdio.h>
#include <string.h>
#define LINHAS 8
#define COLUNAS 8


unsigned int randaux()
{
  static long seed=1;
  return(((seed = seed * 214013L + 2531011L) >> 16) & 0x7fff);
}


void print_array_char(char *v[LINHAS][COLUNAS]){
  int contador=0;

  for (int i=0;i<(LINHAS);i++)
    for(int c=0;c<(COLUNAS);c++){
      printf("i=%d [%d][%d]=%s\n",contador,i,c,v[i][c]);
      contador++;
    }  
}

//"inicializa_matrix_memoria"->inicializa a matriz "memoria" 
//com os valore pre-definidos
void inicializa_matrix_memoria(char *v[LINHAS][COLUNAS]){
  v[0][0]="+1A";v[0][1]="+1B";v[0][2]="+1C";v[0][3]="+1D";
  v[0][4]="+2A";v[0][5]="+2B";v[0][6]="+2C";v[0][7]="+2D";
  v[1][0]="+3A";v[1][1]="+3B";v[1][2]="+3C";v[1][3]="+3D";
  v[1][4]="+4A";v[1][5]="+4B";v[1][6]="+4C";v[1][7]="+4D";

  v[2][0]="-1A";v[2][1]="-1B";v[2][2]="-1C";v[2][3]="-1D";
  v[2][4]="-2A";v[2][5]="-2B";v[2][6]="-2C";v[2][7]="-2D";
  v[3][0]="-3A";v[3][1]="-3B";v[3][2]="-3C";v[3][3]="-3D";
  v[3][4]="-4A";v[3][5]="-4B";v[3][6]="-4C";v[3][7]="-4D";

  v[4][0]="*1A";v[4][1]="*1B";v[4][2]="*1C";v[4][3]="*1D";
  v[4][4]="*2A";v[4][5]="*2B";v[4][6]="*2C";v[4][7]="*2D";
  v[5][0]="*3A";v[5][1]="*3B";v[5][2]="*3C";v[5][3]="*3D";
  v[5][4]="*4A";v[5][5]="*4B";v[5][6]="*4C";v[5][7]="*4D";

  v[6][0]="/1A";v[6][1]="/1B";v[6][2]="/1C";v[6][3]="/1D";
  v[6][4]="/2A";v[6][5]="/2B";v[6][6]="/2C";v[6][7]="/2D";
  v[7][0]="/3A";v[7][1]="/3B";v[7][2]="/3C";v[7][3]="/3D";
  v[7][4]="/4A";v[7][5]="/4B";v[7][6]="/4C";v[7][7]="/4D";
} 


//"converte_posicao_linha_coluna"->converta a posicao em linha e coluna
void converte_posicao_linha_coluna(int posicao,int *linha,int *coluna){
  *linha  = posicao/8;
  *coluna = posicao%8;
}

void converte_posicionamento_CL(int posicao,int *n_linha,int *n_coluna){

     int linha,coluna; 
     coluna=(posicao%10);
     linha=(posicao/10);
     coluna--;
     linha--;

     *n_linha=linha;
     *n_coluna=coluna;

}

//"verifica_posicao_valida"->verifica se a posicao inserida pelo utilizador esta entre 0 e 63
int verifica_posicao_valida(int posicao){
  if( posicao>=0 && posicao<=(LINHAS*COLUNAS)-1 )
    return 1;
  else
    return 0;
} 

//"escreve_memoria" -> procedimento para escrever as linhas e colunas especificadas de acordo com o enunciado
void escreve_memoria(char *v[LINHAS][COLUNAS]){
  char str_linhas[1024]="",str_1_linha[1024]="    ",str_aux[1024]="",carta[8];
  int l=0,c=0,linha;
  
  linha=0;
  for(c=0;c<COLUNAS;c++){
    sprintf(str_aux,"[%d] ",c+1);
    strcat(str_1_linha,str_aux); //"str_1_linha" fica a primeira linha:[coluna], é preenchida varias vezes no mesmo 

    sprintf(str_aux,"[%d]",linha+1); //Na variavel str_aux fica a construcao da coluna vertical a indicar o nº da linha
    strcat(str_linhas,str_aux); 
    linha++;

    for(l=0;l<LINHAS;l++){ 
      sprintf(carta,"%s",v[l][c]);

      strcat(str_linhas," "); 
      strcat(str_linhas,carta);
    }
    strcat(str_linhas,"\n"); 
   } 

   printf("%s\n",str_1_linha);
   printf("%s",str_linhas);
 }


 //"escreve_memoria_esconde" -> procedimento para ocultar todas as cartas excepto para as posicoes introduzidas
void escreve_memoria_esconde(char *v[LINHAS][COLUNAS],int pos1,int pos2,int pos3,int pos4){
  char str_linhas[1024]="",str_1_linha[1024]="    ",str_aux[1024]="",carta[8];
  int l=0,c=0,linha,flg_esconde,n_linha,n_coluna;
  
  linha=0;
  for(c=0;c<COLUNAS;c++){
    sprintf(str_aux,"[%d] ",c+1);
    strcat(str_1_linha,str_aux); //"str_1_linha" fica a primeira linha:[coluna], é preenchida varias vezes no mesmo 

    sprintf(str_aux,"[%d]",linha+1); //Na variavel str_aux fica a construcao da coluna vertical a indicar o nº da linha
    strcat(str_linhas,str_aux); 
    linha++;

    for(l=0;l<LINHAS;l++){ 
      flg_esconde=1;

      converte_posicao_linha_coluna(pos1,&n_linha,&n_coluna);
      if(l==n_linha && c==n_coluna)
        flg_esconde=0;

      converte_posicao_linha_coluna(pos2,&n_linha,&n_coluna);
      if(l==n_linha && c==n_coluna)
         flg_esconde=0;

      converte_posicao_linha_coluna(pos3,&n_linha,&n_coluna);
      if(l==n_linha && c==n_coluna)
         flg_esconde=0;

      converte_posicao_linha_coluna(pos4,&n_linha,&n_coluna);
      if(l==n_linha && c==n_coluna)
         flg_esconde=0;
          

      if(flg_esconde==1)  
        sprintf(carta,"%s","###");
      else
        sprintf(carta,"%s",v[l][c]);

      strcat(str_linhas," "); 
      strcat(str_linhas,carta);
    }
    strcat(str_linhas,"\n"); 
   } 

   printf("%s\n",str_1_linha);
   printf("%s",str_linhas);
 }


//"baralha_matrix_memoria" -> faz o baralhamento do baralho de acordo com o solicitado
void baralha_matrix_memoria(char *v[LINHAS][COLUNAS]){
  int l=0,c=0,n_rand,linha,coluna,posicao;
  char carta1[8],carta2[8],contador=0;

  for(l=0;l<(LINHAS);l++){
    for(c=0;c<(COLUNAS);c++){
     
     posicao=l*(LINHAS)+c;
     n_rand=posicao+randaux()%( (LINHAS*COLUNAS)-posicao);

     converte_posicao_linha_coluna(n_rand,&linha,&coluna);

     sprintf(carta1,"%s",v[l][c]);
     sprintf(carta2,"%s",v[linha][coluna]);

     v[l][c]=strdup(carta2);
     v[linha][coluna]=strdup(carta1);
    }
  }
}

//se as cartas indicadas já sairam: ="   ", então o jogo termina
int verifica_validade_jogada(char *v[LINHAS][COLUNAS],int pos1,int pos2,int pos3,int pos4){
  int n_linha,n_coluna,igualdades=0;
  char codigo1[4],codigo2[4],codigo3[4],codigo4[6];

  if(verifica_posicao_valida(pos1)==1){
    converte_posicao_linha_coluna(pos1,&n_linha,&n_coluna);
    sprintf(codigo1,"%s",v[n_linha][n_coluna]);

    if(strcmp(codigo1,"   ")==0)
    return 0;
  }
  
  if(verifica_posicao_valida(pos2)==1){
    converte_posicao_linha_coluna(pos2,&n_linha,&n_coluna);
    sprintf(codigo2,"%s",v[n_linha][n_coluna]);

    if(strcmp(codigo2,"   ")==0)
      return 0;  

  }

  if(verifica_posicao_valida(pos3)==1){
    converte_posicao_linha_coluna(pos3,&n_linha,&n_coluna);
    sprintf(codigo3,"%s",v[n_linha][n_coluna]);
  
    if(strcmp(codigo4,"   ")==0)
      return 0;
  }


  if(verifica_posicao_valida(pos4)==1){
    converte_posicao_linha_coluna(pos4,&n_linha,&n_coluna);
    sprintf(codigo4,"%s",v[n_linha][n_coluna]);

    if(strcmp(codigo4,"   ")==0)
      return 0;
  }
  
  return 1;
}


int verifica_sucesso_jogada(char *v[LINHAS][COLUNAS],int pos1,int pos2,int pos3,int pos4){
  char codigo1[4]="",codigo2[4]="",codigo3[4]="",codigo4[4]="";
  int n_linha,n_coluna,igualdades=0;
   
  if(verifica_posicao_valida(pos1)==1){
    converte_posicao_linha_coluna(pos1,&n_linha,&n_coluna);
    sprintf(codigo1,"%s",v[n_linha][n_coluna]);
  }


  if(verifica_posicao_valida(pos2)==1){
    converte_posicao_linha_coluna(pos2,&n_linha,&n_coluna);
    sprintf(codigo2,"%s",v[n_linha][n_coluna]);
  }

  if(verifica_posicao_valida(pos3)==1){
    converte_posicao_linha_coluna(pos3,&n_linha,&n_coluna);
    sprintf(codigo3,"%s",v[n_linha][n_coluna]);
  }

  if(verifica_posicao_valida(pos4)==1){
    converte_posicao_linha_coluna(pos4,&n_linha,&n_coluna);
    sprintf(codigo4,"%s",v[n_linha][n_coluna]);
  }
  
  if(codigo1[0]==codigo2[0] && codigo2[0]==codigo3[0] && codigo3[0]==codigo4[0]){
    igualdades++;
  } 
  if(codigo1[1]==codigo2[1] && codigo2[1]==codigo3[1] && codigo3[1]==codigo4[1]){
    igualdades++;
  }
  if(codigo1[2]==codigo2[2] && codigo2[2]==codigo3[2] && codigo3[2]==codigo4[2]){
    igualdades++;
  }

  if(igualdades!=0)
    return 1;

  return 0;
}


//"limpa_codigo_cartas"-> procedimento invocado quando a jogada termina com sucesso: 
//retirar o codigo da carta e colocar espacos 
void limpa_codigo_cartas(char *v[LINHAS][COLUNAS],int pos1,int pos2,int pos3,int pos4){
  int n_linha,n_coluna;

  converte_posicao_linha_coluna(pos1,&n_linha,&n_coluna);
  v[n_linha][n_coluna]="   ";
  
  converte_posicao_linha_coluna(pos2,&n_linha,&n_coluna);
  v[n_linha][n_coluna]="   ";

  converte_posicao_linha_coluna(pos3,&n_linha,&n_coluna);
  v[n_linha][n_coluna]="   ";

  converte_posicao_linha_coluna(pos4,&n_linha,&n_coluna);
  v[n_linha][n_coluna]="   ";
}


//"conta_cartas_disponiveis"-> conta o numero  de cartas diferentes de vazio
int conta_cartas_disponiveis(char *v[LINHAS][COLUNAS]){
  int contador=0;
  char codigo[4];

  for(int l=0;l<LINHAS;l++)   
   for(int c=0;c<COLUNAS;c++){
    sprintf(codigo,"%s",v[l][c]);
    if(strcmp(codigo,"   ")!=0)
      contador++;
   }

  return contador;
}


//"pos_proxima_carta_valida"-> determina a posicao da primeira carta disponivel(deiferente de vazio)
int pos_proxima_carta_valida(char *v[LINHAS][COLUNAS]){
  char codigo[4];

  for(int l=0;l<LINHAS;l++)   
   for(int c=0;c<COLUNAS;c++){
    sprintf(codigo,"%s",v[l][c]);
    if(strcmp(codigo,"   ")!=0)
      return l*LINHAS+c;
   }

  return -1;
}



int main(){
  char *memoria[LINHAS][COLUNAS],sequencia[1024];
  int posicao,linha,coluna,desperdicio,retorno;
  int jogada_terminada,posicao_invalida,humano_joga,n_posicoes;
  int pos1,pos2,pos3,pos4,nr_jogadas,contador_impressao,nr_cartas_disponiveis;
  
  scanf("%d",&desperdicio);

  for(int i=0;i<desperdicio;i++){
    randaux();
 
  }
    
  //inicializa a matriz "memoria" com os valores iniciais
  inicializa_matrix_memoria(memoria);
  
  baralha_matrix_memoria(memoria);
  //escreve_memoria(memoria);
  escreve_memoria_esconde(memoria,-1,-1,-1,-1);

  contador_impressao = 1;
  nr_jogadas = 0;
  jogada_terminada = 0;
  humano_joga = 1;
  while(jogada_terminada==0){

    if(humano_joga==1){
      //Introducao da sequencia de 4 valores separados por espacos 
      scanf(" %[^\t\n]s",sequencia);
      n_posicoes=sscanf(sequencia,"%d %d %d %d",&pos1,&pos2,&pos3,&pos4);// fazer funcao

      converte_posicionamento_CL(pos1,&linha,&coluna);
      pos1=linha*8+coluna;

      converte_posicionamento_CL(pos2,&linha,&coluna);
      pos2=linha*8+coluna;

      converte_posicionamento_CL(pos3,&linha,&coluna);
      pos3=linha*8+coluna;

      converte_posicionamento_CL(pos4,&linha,&coluna);
      pos4=linha*8+coluna;

      //escreve_memoria_esconde(memoria,pos1,pos2,pos3,pos4); 
  
      if(n_posicoes!= 4)
        jogada_terminada=1;
      else{
        posicao_invalida=0;

      if(verifica_posicao_valida(pos1)==0)
        posicao_invalida++;

      if(verifica_posicao_valida(pos2)==0)
        posicao_invalida++;
    
      if(verifica_posicao_valida(pos3)==0)
        posicao_invalida++;
       
      if(verifica_posicao_valida(pos4)==0)
        posicao_invalida++;
      }
      //0 posicoes validas:o humano deixa de jogar
      if(posicao_invalida==4 || jogada_terminada==1){
       humano_joga=0;
      }  
      else{
        //verificar uma das cartas indicadas correspondem a cartas já saidas, o jogo termina
        retorno=verifica_validade_jogada(memoria,pos1,pos2,pos3,pos4);
        if(retorno==0){
         jogada_terminada=1;
        }
        else{
         if(contador_impressao<=5){
           escreve_memoria_esconde(memoria,pos1,pos2,pos3,pos4); ;
           contador_impressao++;
         }  
         retorno=verifica_sucesso_jogada(memoria,pos1,pos2,pos3,pos4);

         if(retorno==1){
            limpa_codigo_cartas(memoria,pos1,pos2,pos3,pos4);
            nr_jogadas++;; 
         }
        }
      } 
    }


    if(humano_joga==0)
    {
      //obtem 1ªposicao mais baixa disponivel
      pos1=pos_proxima_carta_valida(memoria);
      
      pos2=-1;pos3=-1;pos4=-1;
      escreve_memoria_esconde(memoria,pos1,pos2,pos3,pos4);
      converte_posicao_linha_coluna(pos1,&linha,&coluna);
      memoria[linha][coluna] = "   "; 
    }

    nr_cartas_disponiveis=conta_cartas_disponiveis(memoria);

    if(nr_cartas_disponiveis==0){
     jogada_terminada=1;
    } 
}

if(contador_impressao>5){
 escreve_memoria_esconde(memoria,pos1,pos2,pos3,pos4); 
} 

printf("Jogo com %d jogadas. Restam %d cartas.\n",nr_jogadas,nr_cartas_disponiveis); 


  return 0;
}
