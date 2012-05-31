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
and 		{return AND;}
or 		{return OR;}
not 		{return NOT;}
project 	{return PROJECT;}
select 		{return SELECT;}
exists 		{return EXISTS;}
all 		{return ALL;}
update 		{return UPDATE;}
extend 		{return EXTEND;}
rename 		{return RENAME;}
join 		{return JOIN;}

   /*costanti*/
{boolconst}	{if (yytext[0]=='t') lexval.ival=1; else lexval.ival=0; return(BOOL_CONST);}	
{intconst}	{lexval.ival = atoi(yytext); return(INT_CONST);}
{strconst}	{lexval.sval = new_string(yytext); return(STR_CONST);}

   /*id*/
{id}		{lexval.sval = new_string(yytext); return(ID);}

   /*operatori*/
\=		{return(ASSIGN);}		
\=\=		{return EQ;}
\!\=		{return NOT_EQ;}
\>\=		{return GET;}
\<\=		{return LET;}
[\>\<]		{return yytext[0];}
[\+\-]		{return yytext[0];}
[\*\/]		{return yytext[0];}

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
