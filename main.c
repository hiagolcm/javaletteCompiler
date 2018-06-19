#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "buffer.h"
#include "automata.h"

void simulateAutomata(buffer *, FILE * f);

state current_state;



int main(){

	current_state = Q0;

	int size = 50;

	buffer* b = malloc(sizeof(buffer));

	initBuffer(b,size);

	FILE * f = fopen("teste.c","r");
	

	simulateAutomata(b,f)	;

	return 0;
}

void simulateAutomata(buffer * b, FILE * f){

	char c;
	int hasReturn;

	while(1){

		c = readNext(b,f);

		if(c==EOF) break;

		switch(current_state){
			case Q0:
				current_state = q0(c);
				break;
			case INTEIRO:
				current_state = inteiro(c);
				break;
			case PONTO_FLUTUANTE_1:
				current_state = ponto_flutuante_1(c);
				break;
			case  PONTO_FLUTUANTE_2:
				current_state = ponto_flutuante_2(c);
				break;
			case  PONTO_FLUTUANTE_3:
				current_state = ponto_flutuante_3(c);
				break;
			case  IDENTIFICADOR:
				current_state = identificador(c);
				break;
			case  ATRIBUICAO:
				current_state = atribuicao(c);
				break;
			case  OPERADOR_1:
				current_state = operador_1(c);
				break;
			case  OPERADOR_2:
				current_state = operador_2(c);
				break;
			case  OPERADOR_RELACIONAL_1:
				current_state = operador_relacional_1(c);
				break;
			case Q1:
				current_state = q1(c);
				break;
			case Q3:
				current_state = q3(c);
				break;
			case Q4:
				current_state = q4(c);
				break;
			case Q7:
				current_state = q7(c);
				break;
			case Q8:
				current_state = q8(c);
				break;
			case Q9:
				current_state = q9(c);
				break;
			case Q13:
				current_state = q13(c);
				break;

			default:
				current_state = Q0;


			
		}

		hasReturn = 1;


		switch(current_state){
			case BLANK:
				blank(b);
			case BREAK_LINE:
				break_line(b);
				break;
			case TAB:
				tab(b);
				break;
			case Q5:
				q5(b);
				break;
			case Q2:
				q2(b);
				break;
			case STRING:
				string(b);
				break;
			case BOOL_:
				bool_(b);
			case Q12:
				q12(b);
				break;
			case PONTO_VIRGULA:
				ponto_virgula(b);
				break;
			case ABRE_PARENTESES:
				abre_parenteses(b);
				break;
			case FECHA_PARENTESES:
				fecha_parenteses(b);
				break;
			case ABRE_CHAVES:
				abre_chaves(b);
				break;
			case FECHA_CHAVES:
				fecha_chaves(b);
				break;
			case VIRGULA:
				virgula(b);
				break;
			case Q11:
				q11(b);
				break;
			case Q6:
				q6(b);
				break;
			case OPERADOR_3:
				operador_3(b);
				break;
			case Q10:
				q10(b);
				break;
			case OPERADOR_RELACIONAL_2:
				operador_relacional_2(b);
				break;
			case INCREMENTO:
				incremento(b);
				break;
			case ERROR:
				error(b);
				break;
			default:
				hasReturn = 0;
		}


		if (hasReturn){
			nextToken(b);
			current_state = Q0;	
		} 


	}
}
