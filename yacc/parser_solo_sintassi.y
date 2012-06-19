%{
#include "def.h"
#define YYSTYPE pNode
extern char *yytext;
extern Value lexval;
extern int line;
extern FILE *yyin;
pNode root = NULL;
%}

%token IF THEN ELSE WHILE DO END INTEGER STRING BOOLEAN TABLE READ WRITE ID BOOL_OP UNARY_OP HIGH_BIN_OP LOW_BIN_OP COMP_OP INT_CONST STR_CONST BOOL_CONST AND OR NOT PROJECT SELECT EXISTS ALL UPDATE EXTEND RENAME JOIN PROGRAM EQ NOT_EQ GET LET ASSIGN END_OF_FILE
%token ERROR

%%

program 	: PROGRAM stat_list END 
		;
stat_list	: stat ';' stat_list 
	 	| stat 
		;
stat 		: def_stat 
		| assign_stat  
		| if_stat
		| while_stat
		| read_stat 
		| write_stat 
		;
def_stat 	: type id_list  
		;
id_list		: ID  ',' id_list 
		| ID 
		;
type		: atomic_type
		| table_type 
		;
atomic_type	: INTEGER 
		| STRING 
		| BOOLEAN 
		;
table_type	: TABLE '(' attr_list ')' 
		;
attr_list	: attr_decl ',' attr_list 
		| attr_decl 
		;
attr_decl	: atomic_type ID 
		;
assign_stat	: ID  ASSIGN expr 
		;
expr		: expr bool_op bool_term 
		| bool_term 
		;
bool_op		: AND 
		| OR 
		;
bool_term	: comp_term comp_op comp_term 
		| comp_term 
		;
comp_op		: EQ 
		| NOT_EQ 
		| '>' 
		| GET 
		| '<' 
		| LET 
		;
comp_term	: comp_term low_bin_op low_term 
		| low_term  
		;
low_bin_op	: '+' 
		| '-' 
		;
low_term	: low_term high_bin_op factor
		| factor 
		;
high_bin_op	: '*' 
		| '/' 
		| join_op 
		;
factor		: unary_op factor 
		| '(' expr ')' 
		| ID 
		| constant 
		;
unary_op 	: '-'
		| NOT 
		| project_op 
		| select_op
		| exists_op 
		| all_op 
		| update_op
		| extend_op
		| rename_op
		;
join_op 	: JOIN '[' expr ']'
		;
project_op 	: PROJECT '[' id_list ']' 
		;
select_op 	: SELECT '[' expr ']' 
		;
exists_op 	: EXISTS '[' expr ']' 
		;
all_op 		: ALL '[' expr ']' 
		;
extend_op 	: EXTEND '[' atomic_type ID  ASSIGN expr ']'
		;
update_op 	: UPDATE '[' ID  ASSIGN expr ']' 
		;
rename_op 	: RENAME '[' id_list ']' 
		;
constant 	: atomic_const
		| table_const 
		;
atomic_const 	: INT_CONST
		| STR_CONST
		| BOOL_CONST 
		;
table_const 	: '{' table_instance '}'
		;
table_instance	: tuple_list  
		| atomic_type_l
		;
tuple_list 	: tuple_const ',' tuple_list 
		| tuple_const
		;
tuple_const	: '(' atomic_const_l ')' 
		;
atomic_const_l  : atomic_const ',' atomic_const_l
		| atomic_const 
		;
atomic_type_l 	: atomic_type ',' atomic_type_l 
		| atomic_type 
		;
if_stat 	: IF expr THEN stat_list else_part END 
		;
else_part 	: ELSE stat_list 
		| 
		;
while_stat 	: WHILE expr DO stat_list END 
		;
read_stat 	: READ specifier ID 
		;
specifier 	: '[' expr ']' 
		| 
		; 
write_stat 	: WRITE specifier expr
		;

%%

/*Funzione per la creazione di un nodo generico.
  Crea il nodo e annulla i puntatori al figlio e al fratello
*/
pNode new_node(Typenode type_node){
	pNode p;

	p = (pNode) malloc(sizeof(Node));
	p->type = type_node;
	p->child = NULL;
	p->brother = NULL;
	return p;
}

/*Crea un nodo di tipo non_terminale.
  Chiama la funzione new_node e assegna al campo value.ival il tipo di terminale*/	
pNode non_term_node(Nonterminal nonterm){
	pNode p = new_node(T_NONTERMINAL);
	p->value.ival = nonterm;
	return p;
}


/*Crea un nodo di tipo id.
  Chiama la funzione new_node e assegna al campo value.sval il nome dell'id*/
pNode id_node(){
	pNode p = new_node(T_ID);
	p->value.sval = lexval.sval;
	return p;
}

/*Crea un nodo di tipo str_const.
  Chiama la funzione new_node e assegna al campo value.sval la stringa*/
pNode str_const_node(){
	pNode p = new_node(T_STRCONST);
	p->value.sval = lexval.sval;
	return p;
}


/*Crea un nodo di tipo int_const.
  Chiama la funzione new_node e assegna al campo value.ival il valore*/
pNode int_const_node(){
	pNode p = new_node(T_INTCONST);
	p->value.ival = lexval.ival;
	return p;
}


/*Crea un nodo di tipo bool_const.
  Chiama la funzione new_node e assegna al campo value.ival il valore*/
pNode bool_const_node(){
	pNode p = new_node(T_BOOLCONST);
	p->value.ival = lexval.ival;
	return p;
}


/*Crea un nodo di tipo keyword
  Questi nodi rappresentano anche gli operatori (tutti i binari e il '-' e il 'not' unari.
  Gli altri operatori unari non hanno bisogno di essere definiti con un tipo in quanto hanno un non_terminale associato.*/
pNode key_node(Typenode keyword){
	pNode p = new_node(keyword);
	return p;
}



int main(){
	int result;
	
	yyin = stdin;
	if ((result = yyparse())==0)
		printf("sintassi corretta\n");
	return(result);		
}


yyerror() {
  fprintf(stderr, "Line %d: syntax error on symbol \"%s\"\n",line, yytext);
  exit(-1);
}

