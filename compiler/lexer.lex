%{   
#include "parser.h"                                                                                                                     
#include "def.h"
int line = 1;                                                       
Value lexval;
/*Si usa la tabella dei simboli lessicali per allocare più volte la stessa variabile. 
In questo modo, una variabile è identificata dal suo puntatore.*/
%}   
                                                                    
%option noyywrap

comment        --.*\n
spacing        ([ \t\r])+
letter         [A-Za-z]
digit          [0-9]
intconst       {digit}+
strconst       \"([^\"])*\"
boolconst      false|true
id             {letter}({letter}|{digit})*
sugar          [(){}:,;\+\-\*/\[\]=><]

%%

{comment}      ;
{spacing}      ;
\n             {line++;}
all            {return(ALL);}
and            {return(AND);}
boolean        {return(BOOLEAN);}
do             {return(DO);}
else           {return(ELSE);}
exists         {return(EXISTS);}
extend         {return(EXTEND);}
end            {return(END);}
"=="	       {return(EQ);}
">="           {return(GE);}
if             {return(IF);}
integer        {return(INTEGER);}
join           {return(JOIN);}
"<="	       {return(LE);}
"!="	       {return(NE);}
not            {return(NOT);}
or             {return(OR);}
project        {return(PROJECT);}
program        {return(PROGRAM);}
read           {return(READ);}
rename         {return(RENAME);}
select         {return(SELECT);}
string         {return(STRING);}
table          {return(TABLE);}
then           {return(THEN);}
update         {return(UPDATE);}
while          {return(WHILE);}
write          {return(WRITE);}
{intconst}     {lexval.ival = atoi(yytext); 
                return(INTCONST);}
{strconst}     {lexval.sval = update_lextab(clear_string(yytext)); 
                return(STRCONST);}
{boolconst}    {
                 lexval.ival = (yytext[0] == 'f' ? FALSE : TRUE);
                 return(BOOLCONST);
               }
{id}           {lexval.sval = update_lextab(yytext); 
                return(ID);}
{sugar}        {return(yytext[0]);}
.              {return(ERROR);}
<<EOF>>        {return(EOF);}

%%

char *clear_string(char *s)
{
    int lung = strlen(yytext);

    yytext[lung-1] = '\0';
    return(yytext+1);
}

