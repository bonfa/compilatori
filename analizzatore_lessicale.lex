/* Analizzatore lessicale del linguaggio table */

%{
#include <stdio.h>
#include  <stdlib.h>
#include "def.h"  /*Scritto da me che include tutte le costanti che andrò a richiamare*/
Lexval lexval; /*typedef union {int ival; char *sval;boolean bval} Lexval;*/
int n_righe=0;
%}	
%option	noyywrap

newline \n
delimiter [ \t{newline}]
spacing {delimiter}+
letter [A-­Za-­z]
digit [0­-9]
no_zero [1-9]
intconst {no_zero}{digit}*|0
strconst \"([^\"])*\"
boolconst false|true
id {letter}({letter}|{digit})*
sugar [();:=[]]

%%

/*Pseudo simboli*/
{newline}	{n_righe++;}
{spacing} 	;
{sugar}		{return(yytext[0]);}

/*keyword*/
program 	{return(PROGRAM);}
end		{return(END);}
integer		{return(INTEGER);}
string		{return(STRING);}
boolean		{return(BOOLEAN);}
table		{return(TABLE);}
if		{return(IF);}
then		{return(THEN);}
else		{return(ELSE);}
while		{return(WHILE);}
do		{return(DO);}
read		{return(READ);}
write 		{return(WRITE);}
and 		{return(AND);}
or 		{return(OR);}
not 		{return(NOT);}
project 	{return(PROJECT);}
select 		{return(SELECT);}
exists 		{return(EXISTS);}
all 		{return(ALL);}
update 		{return(UPDATE);}
extend 		{return(EXTEND);}
rename 		{return(RENAME);}
join 		{return(JOIN);}

/*id*/
{id}		{lexval.sval = assign_id(); return(ID);}

/*costanti*/
{intconst}	{lexval.ival = atoi(yytext); return(INT_CONST);}
{strconst}	{lexval.sval = copy(yytext); return(STR_CONST)}
{boolconst}	{if (yytext[0]=='t') lexval.bval=1; else lexval.bval=0; return(BOOL_CONST);}

/*operatori*/
==		{return(EQ);}
!=		{return(NOT_EQ);}
>=		{return(GET);}
<=		{return(LET);}
[><+*-/]	{return(yytext[0]);}

/*resto*/
.		{return(ERROR);}

%%

/*Salva in memoria il valore di yytext e ne restituisce un puntatore*/
char *copy(s){
	char *p = malloc(strlen(s)+1);
	strcpy(s,p);
	return p;
}

/*Controlla se nella TABELLA DEI SIMBOLI c'è già un simbolo con quell'id, altrimenti lo inserisce e ritorna il numero di linea nella tabella dei simboli*/
int assign_id()
{ 
  int line;
  if((line = lookup(yytext)) == 0) line = insert(yytext);
  return(line);
}


/*main*/
main()
{ 
  yylex(); 
}
