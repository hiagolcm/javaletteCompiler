#ifndef FUNCTIONS_AUTOMATA
#define FUNCTIONS_AUTOMATA

#include <stdio.h>
#include <ctype.h>
#include "buffer.h"
#include "token.h"

typedef enum{
	INTEIRO,
	PONTO_FLUTUANTE_1,PONTO_FLUTUANTE_2,PONTO_FLUTUANTE_3,
	STRING,
	BOOL_,
	IDENTIFICADOR,
	PONTO_VIRGULA,
	ABRE_PARENTESES,
	FECHA_PARENTESES,
	ABRE_CHAVES,
	FECHA_CHAVES,
	VIRGULA,
	ATRIBUICAO,
	OPERADOR_1,OPERADOR_2,OPERADOR_3,
	OPERADOR_RELACIONAL_1,OPERADOR_RELACIONAL_2,
	INCREMENTO,
	Q0,Q1,Q2,Q3,Q4,Q5,Q6,Q7,Q8,Q9,Q10,Q11,Q12,Q13,
	BLANK, BREAK_LINE,TAB,
	ERROR
} state;

state inteiro(char c){

	if(isdigit(c)) return INTEIRO;
	if(c=='.')     return PONTO_FLUTUANTE_1;
	return Q5;
}



state ponto_flutuante_1(char c){

	if(isdigit(c)) return PONTO_FLUTUANTE_2;
	return Q2;
}

state ponto_flutuante_2(char c){

	if(isdigit(c)) return PONTO_FLUTUANTE_2;
	if(c=='e' || c=='E') return Q3;
	return Q2;
}

state ponto_flutuante_3(char c){

	if(isdigit(c)) return PONTO_FLUTUANTE_3;
	return Q2;
}

state identificador(char c){

	if(isdigit(c) || isalpha(c)) return IDENTIFICADOR;
	return Q12;

}

state atribuicao(char c){

	if(c == '=') return OPERADOR_RELACIONAL_2;
	return Q11;
}

state operador_1(char c){
	if(c=='-') return INCREMENTO;
	return Q6;
}

state operador_2(char c){
	if(c=='+') return INCREMENTO;
	return Q6;
}

state operador_relacional_1(char c){

	if(c=='=') return OPERADOR_RELACIONAL_2;
	return Q10;
}

state q0(char c){

	if(c==' ')      return BLANK;
	if(c=='\n')		return BREAK_LINE;
	if(c=='\t')		return TAB;
	if(c=='.')     	return Q1;
	if(isdigit(c)) 	return INTEIRO;
	if(c=='-')     	return OPERADOR_1;
	if(c=='+')     	return OPERADOR_2;
	if(c=='&')		return Q7;
	if(c=='|')		return Q8;
	if(c=='!')		return Q9;
	if(c=='=')		return ATRIBUICAO;
	if(c==',')		return VIRGULA;
	if(c=='}')		return FECHA_CHAVES;
	if(c=='{')		return ABRE_CHAVES;
	if(c==')')		return FECHA_PARENTESES;
	if(c=='(')		return ABRE_PARENTESES;
	if(c==';')		return PONTO_VIRGULA;
	if(isalpha(c))	return IDENTIFICADOR;
	if(c=='"')		return Q13;
	if(c=='>' || c=='<') 				return OPERADOR_RELACIONAL_1;
	if(c=='%' || c == '/' || c=='*') 	return OPERADOR_3;

	return ERROR;
}

state q1(char c){

	if(isdigit(c)) return PONTO_FLUTUANTE_2;
	return ERROR;
}

state q3(char c){

	if(isdigit(c)) return PONTO_FLUTUANTE_3;
	if(c=='+' || c=='-') return Q4;
	return ERROR;
}

state q4(char c){

	if(isdigit(c)) return PONTO_FLUTUANTE_3;
	return ERROR;
}

state q7(char c){

	if(c=='&') return OPERADOR_3;
	return ERROR;
}

state q8(char c){

	if(c=='|') return OPERADOR_3;
	return ERROR;
}

state q9(char c){

	if(c=='=') return OPERADOR_RELACIONAL_2;
	return ERROR;
}

state q13(char c){

	if(c!='"' && c!='\n') 	return Q13;
	
	if(c == '\n')         	return ERROR;
	return STRING;
}

void blank(buffer * b){

}

void break_line(buffer * b){
	
}

void tab(buffer * b){

}

void q5(buffer * b){

	//retorna inteiro
	backward(b);
	returnToken	(b,0);
}

void q2(buffer * b){

	//retorna PONTO_FLUTUANTE
	backward(b);
	returnToken(b,1);
}

void string(buffer * b){

	//retorna string
	returnToken(b,2);
}

void bool_(buffer * b){

	//retorna bull
	returnToken(b,3);
}

void q12(buffer * b){

	//retorna identificador;
	backward(b);
	returnToken(b,4);
}

void ponto_virgula(buffer * b){

	//retorna PONTO_VIRGULA
	returnToken(b,6);
}

void abre_parenteses(buffer * b){
	
	//retorna ABRE_PARENTESES
	returnToken(b,7);	
}


void fecha_parenteses(buffer * b){
	
	//retorna FECHA_PARENTESES
	returnToken(b,8);	
}

void abre_chaves(buffer * b){

	
	//retorna ABRE_CHAVES
	returnToken(b,9);	
}


void fecha_chaves(buffer * b){
	
	//retorna FECHA_CHAVES
	returnToken(b,10);	
}


void virgula(buffer * b){
	
	//retorna VIRGULA
	returnToken(b,11);
}


void q11(buffer * b){
	
	//retorna ATRIBUICAO
	backward(b);
	returnToken(b,12);
}

void q6(buffer * b){

	//retorna OPERADOR
	backward(b);
	returnToken(b,13);
}

void operador_3(buffer * b){

	//retorna OPERADOR
	returnToken(b,13);
}

void q10(buffer * b){

	//retorna OPERADOR_RELACIONAL
	backward(b);
	returnToken(b,14);
}

void operador_relacional_2(buffer * b){

	//retorna OPERADOR_RELACIONAL
	returnToken(b,14);
}

void incremento(buffer * b){

	//retorna INCREMENTO
	returnToken(b,15);
}

void error(buffer * b){

	//retorna erro
	returnToken(b,16);
}

#endif