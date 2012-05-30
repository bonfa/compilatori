/* Analizzatore lessicale del linguaggio table 

OSS: vengono gestiti esplicitamente (con una regexpr apposita) il caso in cui vengono trovati numeri interi preceduti da zero
perche il matching da problemi (002 viene matchato come 0 intconst, 0 intconst, 2 intconst)
e il caso in cui vengono trovati id che cominciano con numeri per lo stesso motivo precedente.
non viene gestito esplicitamente il caso in cui vengono trovati id con caratteri non alfanumerici perche
in quel caso viene restituito errore

OSS_IMPORTANTE: a livello lessicale i numeri interi vengono rappresentati come operatore unario (-) seguito dal valore positivo
così si evita il problema di avere problemi di matching. 
Esempio: a = b +20, per il maximal munch il +20 verrebbe interpretato come numero intero e non come somma
Questo discorso vale solo per il meno (-). Non viene definito l'operatore unario (+)
*/

%{
#include "def.h"
#include "parser.h"
Value lexval;
int line = 1;
%}	
%option	noyywrap

newline		[\n]
delimiter 	[' '\t]
spacing 	{delimiter}+
letter 		[a-zA-Z]
digit 		[0-9]
no_zero 	[1-9]
intconst 	{no_zero}{digit}*|0
zeroconst	0{digit}+
strconst 	\"([^\"])*\"
boolconst 	false|true
id 		{letter}({letter}|{digit})*
numalfa		{digit}+{letter}+{digit}*
sugar 		[\( \) \; \: \[ \] \, \{ \}]

%%

   /*Pseudo simboli*/
{newline}	{line++;}
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
and 		{lexval.ival = AND;	return(BOOL_OP);}
or 		{lexval.ival = OR;	return(BOOL_OP);}
not 		{lexval.ival = NOT;	return(UNARY_OP);}
project 	{lexval.ival = PROJECT;	return(UNARY_OP);}
select 		{lexval.ival = SELECT;  return(UNARY_OP);}
exists 		{lexval.ival = EXISTS;  return(UNARY_OP);}
all 		{lexval.ival = ALL;	return(UNARY_OP);}
update 		{lexval.ival = UPDATE;	return(UNARY_OP);}
extend 		{lexval.ival = EXTEND;	return(UNARY_OP);}
rename 		{lexval.ival = RENAME;	return(UNARY_OP);}
join 		{lexval.ival = JOIN;	return(HIGH_BIN_OP);}

   /*costanti*/
{boolconst}	{if (yytext[0]=='t') lexval.ival=1; else lexval.ival=0; return(BOOL_CONST);}	
{intconst}	{lexval.ival = atoi(yytext); return(INT_CONST);}
{strconst}	{lexval.sval = new_string(yytext); return(STR_CONST);}

   /*id*/
{id}		{lexval.sval = new_string(yytext); return(ID);}

   /*operatori*/
\=		{return(ASSIGN);}		
\=\=		{lexval.ival = EQ; 		return(COMP_OP);}
\!\=		{lexval.ival = NOT_EQ;		return(COMP_OP);}
\>\=		{lexval.ival = GET;		return(COMP_OP);}
\<\=		{lexval.ival = LET;		return(COMP_OP);}
[\>\<]		{lexval.ival = yytext[0];	return(COMP_OP);}
[\+\-]		{lexval.ival = yytext[0];	return(LOW_BIN_OP);}
[\*\/]		{lexval.ival = yytext[0];	return(HIGH_BIN_OP);}

   /*resto*/
{zeroconst}	{return(ERROR);}
{numalfa}	{return(ERROR);}
.		{return(ERROR);}

%%

/*Salva in memoria il valore di yytext e ne restituisce un puntatore*/
char *new_string(char *s)
{
  char *p;
  p = malloc(strlen(s)+1);
  strcpy(p,s);
  return p;
}
