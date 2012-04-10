/* Analizzatore lessicale del linguaggio table 

Versione verbose: 
Il programma restituisce la costante con cui viene riconosciuto il simbolo
Se il simbolo non viene riconosciuto, viene restituito errore
In questa versione, il programma continua l'esecuzione
*/


%{
#include <stdio.h>
#include <stdlib.h>
#include "def.h"  /*Scritto da me che include tutte le costanti che andrò a richiamare*/
Lexval lexval; /*typedef union {int ival; char *sval} Lexval;*/
int n_righe=0;
%}	
%option	noyywrap

delimiter 	[' '\t\n]
spacing 	{delimiter}+
letter 		[a-zA-Z]
digit 		[0-9]
no_zero 	[1-9]
intconst 	{no_zero}{digit}*|0
strconst 	\"([^\"])*\"
boolconst 	false|true
id 		{letter}({letter}|{digit})*
sugar 		[\( \) \; \: \= \[ \]]

%%

   /*Pseudo simboli*/
{spacing} 	;
{sugar}		{printf("%s\t--->\tSUGAR\n",yytext);}

   /*keyword*/
program	{printf("%s\t--->\tPROGRAM\n",yytext);}
end		{printf("%s\t--->\tEND\n",yytext);}
integer		{printf("%s\t--->\tINTEGER\n",yytext);}
string		{printf("%s\t--->\tSTRING\n",yytext);}
boolean		{printf("%s\t--->\tBOOLEAN\n",yytext);}
table		{printf("%s\t--->\tTABLE\n",yytext);}
if		{printf("%s\t--->\tIF\n",yytext);}
then		{printf("%s\t--->\tTHEN\n",yytext);}
else		{printf("%s\t--->\tELSE\n",yytext);}
while		{printf("%s\t--->\tWHILE\n",yytext);}
do		{printf("%s\t--->\tDO\n",yytext);}
read		{printf("%s\t--->\tREAD\n",yytext);}
write 		{printf("%s\t--->\tWRITE\n",yytext);}
and 		{lexval.ival = AND;	printf("%s\t--->\tBOOL_OP = AND\n",yytext);}
or 		{lexval.ival = OR;	printf("%s\t--->\tBOOL_OP = OR\n",yytext);}
not 		{lexval.ival = NOT;	printf("%s\t--->\tUNARY_OP = NOT\n",yytext);}
project 	{lexval.ival = PROJECT;	printf("%s\t--->\tUNARY_OP = PROJECT\n",yytext);}
select 		{lexval.ival = SELECT;  printf("%s\t--->\tUNARY_OP = SELECT\n",yytext);}
exists 		{lexval.ival = EXISTS;  printf("%s\t--->\tUNARY_OP = EXISTS\n",yytext);}
all 		{lexval.ival = ALL;	printf("%s\t--->\tUNARY_OP = ALL\n",yytext);}
update 		{lexval.ival = UPDATE;	printf("%s\t--->\tUNARY_OP = UPDATE\n",yytext);}
extend 		{lexval.ival = EXTEND;	printf("%s\t--->\tUNARY_OP = EXTEND\n",yytext);}
rename 		{lexval.ival = RENAME;	printf("%s\t--->\tUNARY_OP = RENAME\n",yytext);}
join 		{lexval.ival = JOIN;	printf("%s\t--->\tHIGH_BIN_OP = JOIN\n",yytext);}

   /*costanti*/
{boolconst}	{if (yytext[0]=='t') lexval.ival=1; else lexval.ival=0; printf("%s\t--->\tBOOL_CONST = %d\n",yytext,lexval.ival);}	
{intconst}	{lexval.ival = atoi(yytext); printf("%s\t--->\tINT_CONST\n",yytext);}
{strconst}	{lexval.sval = my_copy(yytext); printf("%s\t--->\tSTR_CONST\n",yytext);}

   /*id*/
{id}		{lexval.ival = assign_id(); printf("%s\t--->\tID\n",yytext);}

   /*operatori*/
\=\=		{lexval.ival = EQ; 		printf("%s\t--->\tCOMP_OP\n",yytext);}
\!\=		{lexval.ival = NOT_EQ;		printf("%s\t--->\tCOMP_OP\n",yytext);}
\>\=		{lexval.ival = GET;		printf("%s\t--->\tCOMP_OP\n",yytext);}
\<\=		{lexval.ival = LET;		printf("%s\t--->\tCOMP_OP\n",yytext);}
[\>\<]		{lexval.ival = yytext[0];	printf("%s\t--->\tCOMP_OP\n",yytext);}
[\+\-]		{lexval.ival = yytext[0];	printf("%s\t--->\tLOW_BIN_OP\n",yytext);}
[\*\/]		{lexval.ival = yytext[0];	printf("%s\t--->\tHIGH_BIN_OP\n",yytext);}

   /*resto*/
.		{printf("%s\t--->\tERROR\n",yytext);}


%%

/*Salva in memoria il valore di yytext e ne restituisce un puntatore*/
char *my_copy(char *s)
{
  char *p;
  p = malloc(strlen(s)+1);
  strcpy(p,s);
  return p;
}

/*Controlla se nella TABELLA DEI SIMBOLI c'è già un simbolo con quell'id, altrimenti lo inserisce e ritorna il numero di linea nella tabella dei simboli*/
int assign_id()
{ 
  /*int line;
  if((line = lookup(yytext)) == 0) 
	line = insert(yytext);
  return(line);*/ return 0;
}


/*main */
int main()
{ 
  yylex();
  return(0);
}
