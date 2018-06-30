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

int isRESERVADA(buffer *b)
{
    char *palavra;
    palavra = getLexema(b);
    
    if(strcmp(palavra,"asm")==0)
        return 1;
    else if(strcmp(palavra,"auto")==0)
        return 1;
    else if(strcmp(palavra,"break")==0)
        return 1;
    else if(strcmp(palavra,"case")==0)
        return 1;
    else if(strcmp(palavra,"char")==0)
        return 1;
    else if(strcmp(palavra,"const")==0)
        return 1;
    else if(strcmp(palavra,"continue")==0)
        return 1;
    else if(strcmp(palavra,"default")==0)
        return 1;
    else if(strcmp(palavra,"do")==0)
        return 1;
    else if(strcmp(palavra,"double")==0)
        return 1;
    else if(strcmp(palavra,"else")==0)
        return 1;
    else if(strcmp(palavra,"enum")==0)
        return 1;
    else if(strcmp(palavra,"extern")==0)
        return 1;
    else if(strcmp(palavra,"float")==0)
        return 1;
    else if(strcmp(palavra,"for")==0)
        return 1;
    else if(strcmp(palavra,"goto")==0)
        return 1;
    else if(strcmp(palavra,"if")==0)
        return 1;
    else if(strcmp(palavra,"int")==0)
        return 1;
    else if(strcmp(palavra,"long")==0)
        return 1;
    else if(strcmp(palavra,"register")==0)
        return 1;
    else if(strcmp(palavra,"return")==0)
        return 1;
    else if(strcmp(palavra,"short")==0)
        return 1;
    else if(strcmp(palavra,"signed")==0)
        return 1;
    else if(strcmp(palavra,"sizeof")==0)
        return 1;
    else if(strcmp(palavra,"static")==0)
        return 1;
    else if(strcmp(palavra,"struct")==0)
        return 1;
    else if(strcmp(palavra,"switch")==0)
        return 1;
    else if(strcmp(palavra,"typedef")==0)
        return 1;
    else if(strcmp(palavra,"union")==0)
        return 1;
    else if(strcmp(palavra,"unsigned")==0)
        return 1;
    else if(strcmp(palavra,"void")==0)
        return 1;
    else if(strcmp(palavra,"volatile")==0)
        return 1;
    else if(strcmp(palavra,"while")==0)
        return 1;
    else if(strcmp(palavra,"bool")==0)
        return 1;
    else if(strcmp(palavra,"true")==0)
        return 1;
    else if(strcmp(palavra,"false")==0)
        return 1;
    else
        return 0;
}

int isBOOL(buffer *b)
{
    char *palavra;
    palavra = getLexema(b);
    if(strcmp(palavra,"true")==0)       return 1;
    else if(strcmp(palavra,"false")==0) return 1;
    else                                return 0;
}
#endif