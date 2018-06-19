#ifndef FUNCTIONS_TOKEN
#define FUNCTIONS_TOKEN

#include <stdio.h>
#include <string.h>
#include <string.h>

#include "buffer.h"

char tokensDesc[17][50];
int isDescUpdated = 0;

typedef struct{

	int id;
	char* lex;
	int row;
	int col;
}token;


void initTokenDesc(){
	sprintf(tokensDesc[0],"INTEIRO");
	sprintf(tokensDesc[1],"PONTO_FLUTUANTE");
	sprintf(tokensDesc[2],"STRING");
	sprintf(tokensDesc[3],"BOOL");
	sprintf(tokensDesc[4],"IDENTIFICADOR");
	sprintf(tokensDesc[5],"PALAVRA_RESERVADA");
	sprintf(tokensDesc[6],"PONTO_VIRGULA");
	sprintf(tokensDesc[7],"ABRE_PARENTESES");
	sprintf(tokensDesc[8],"FECHA_PARENTESES");
	sprintf(tokensDesc[9],"ABRE_CHAVES");
	sprintf(tokensDesc[10],"FECHA_CHAVES");
	sprintf(tokensDesc[11],"VIRGULA");
	sprintf(tokensDesc[12],"ATRIBUICAO");
	sprintf(tokensDesc[13],"OPERADOR");
	sprintf(tokensDesc[14],"OPERADOR_RELACIONAL");
	sprintf(tokensDesc[15],"INCREMENTO");
	sprintf(tokensDesc[16],"ERRO");
	
	isDescUpdated = 1;
}

void printTokenDesc(token t){

	if(!isDescUpdated) initTokenDesc();

	printf("%s",tokensDesc[t.id]);
}


void printToken(token t){

	printTokenDesc(t);
	printf("@");
	printf("%s",t.lex);
	printf("@");
	printf("%d",t.row);
	printf("@");
	printf("%d",t.col);

	printf("\n");
}

void returnToken(buffer * b,int type){

	token t;
	t.id     = type;
	t.lex    = getLexema(b);
	t.row    = b->row; 
	t.col    = b->col;

	printToken(t);

	free(t.lex);
}


#endif