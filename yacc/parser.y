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

program 	: PROGRAM stat_list END {	root = non_term_node(N_PROGRAM); 
						root->child = non_term_node(N_STAT_LIST); 
						root->child->child = $2;
					}
		;
stat_list	: stat ';' stat_list {$$ = $1; $1->brother = $3;}
	 	| stat {$$ = $1;}
		;
stat 		: def_stat {$$ = non_term_node(N_STAT); $$->child = $1; }
		| assign_stat  {$$ = non_term_node(N_STAT); $$->child = $1; }
		| if_stat {$$ = non_term_node(N_STAT); $$->child = $1; }
		| while_stat {$$ = non_term_node(N_STAT); $$->child = $1; }
		| read_stat {$$ = non_term_node(N_STAT); $$->child = $1; }
		| write_stat {$$ = non_term_node(N_STAT); $$->child = $1; }
		;
def_stat 	: type id_list  {	$$ = non_term_node(N_DEF_STAT); 
					$$->child = $1;
					$1->brother = non_term_node(N_ID_LIST); 
					$1->brother->child = $2;
				}
		;
id_list		: ID {$$ = id_node();} ',' id_list {$$ = $2; $2->brother = $4; }
		| ID {$$ = id_node();}
		;
type		: atomic_type { $$ = non_term_node(N_TYPE); $$->child = $1; }
		| table_type { $$ = non_term_node(N_TYPE); $$->child = $1; }
		;
atomic_type	: INTEGER {$$ = non_term_node(N_ATOMIC_TYPE); $$->child = key_node(T_INTEGER);}
		| STRING {$$ = non_term_node(N_ATOMIC_TYPE); $$->child = key_node(T_STRING);}
		| BOOLEAN {$$ = non_term_node(N_ATOMIC_TYPE); $$->child = key_node(T_BOOLEAN);}
		;
table_type	: TABLE '(' attr_list ')' { 	$$ = non_term_node(N_TABLE_TYPE); 
						$$->child = non_term_node(N_ATTR_LIST); 
						$$->child->child = $3;
					  }
		;
attr_list	: attr_decl ',' attr_list { $$ = $1; $1->brother = $3;  }
		| attr_decl { $$ = $1; }
		;
attr_decl	: atomic_type ID {$$ = non_term_node(N_ATTR_DECL); $$->child = $1; $1->brother = id_node(); }
		;
assign_stat	: ID {$$ = id_node();} ASSIGN expr {	$$ = non_term_node(N_ASSIGN_STAT); 
							$$->child = $2; 						
							$2->brother = non_term_node(N_EXPR);
							$2->brother->child =  $4;
						}
		;
expr		: expr bool_op bool_term {$$ = $1; $1->brother = $2; $2->brother = $3; }
		| bool_term {$$ = $1; }
		;
bool_op		: AND { $$ = key_node(T_AND);}
		| OR { $$ = key_node(T_OR);}
		;
bool_term	: comp_term comp_op comp_term {	$$ = non_term_node(N_BOOL_TERM); 
						$$->child = non_term_node(N_COMP_TERM);
						$$->child->child = $1;
						$$->child->brother = $2;
						$2->brother = non_term_node(N_COMP_TERM);
						$2->brother->child = $3;
						}
		| comp_term { 	$$ = non_term_node(N_BOOL_TERM);  
				$$->child = non_term_node(N_COMP_TERM);
				$$->child->child = $1;
			    }
		;
comp_op		: EQ {$$ = key_node(T_EQ);}
		| NOT_EQ {$$ = key_node(T_NOT_EQ);}
		| '>' {$$ = key_node(T_GT);}
		| GET {$$ = key_node(T_GET);}
		| '<' {$$ = key_node(T_LT);}
		| LET {$$ = key_node(T_LET);}
		;
comp_term	: comp_term low_bin_op low_term {$$=$1;
						 $1->brother = $2;
						 $2->brother = non_term_node(N_LOW_TERM);
						 $2->brother->child = $3;
						}
		| low_term  {$$ = non_term_node(N_LOW_TERM); $$->child = $1; }
		;
low_bin_op	: '+' {$$ = key_node(T_ADD);}
		| '-' {$$ = key_node(T_SUB);}
		;
low_term	: low_term high_bin_op factor { $$ = $1;
						$1->brother = $2;
						$2->brother = $3;
					      }
		| factor {$$ = $1;}
		;
high_bin_op	: '*' {$$ = key_node(T_MUL);}
		| '/' {$$ = key_node(T_DIV);}
		| join_op {$$ = $1;}
		;
factor		: unary_op factor {$$ = non_term_node(N_FACTOR); $$->child = $1; $1->brother = $2;}
		| '(' expr ')' {$$ = non_term_node(N_FACTOR); $$->child = non_term_node(N_EXPR); $$->child->child = $2;}
		| ID {$$ = non_term_node(N_FACTOR); $$->child = id_node();}
		| constant {$$ = non_term_node(N_FACTOR); $$->child = $1;}
		;
unary_op 	: '-' {$$ = non_term_node(N_UNARY_OP); $$->child = key_node(T_UNARY_MINUS);}
		| NOT {$$ = non_term_node(N_UNARY_OP); $$->child = key_node(T_NOT);}
		| project_op {$$ = non_term_node(N_UNARY_OP); $$->child = $1;}
		| select_op {$$ = non_term_node(N_UNARY_OP); $$->child = $1;}
		| exists_op {$$ = non_term_node(N_UNARY_OP); $$->child = $1;}
		| all_op {$$ = non_term_node(N_UNARY_OP); $$->child = $1;}
		| update_op {$$ = non_term_node(N_UNARY_OP); $$->child = $1;}
		| extend_op {$$ = non_term_node(N_UNARY_OP); $$->child = $1;}
		| rename_op {$$ = non_term_node(N_UNARY_OP); $$->child = $1;}
		;
join_op 	: JOIN '[' expr ']' {	$$ = non_term_node(N_JOIN_OP); 
					$$->child = non_term_node(N_EXPR); 
					$$->child->child = $3;
				    }
		;
project_op 	: PROJECT '[' id_list ']' { 	$$ = non_term_node(N_PROJECT_OP); 
						$$->child = non_term_node(N_ID_LIST); 
						$$->child->child = $3;
					  }
		;
select_op 	: SELECT '[' expr ']' {	$$ = non_term_node(N_SELECT_OP); 
					$$->child = non_term_node(N_EXPR); 
					$$->child->child = $3;
				      }
		;
exists_op 	: EXISTS '[' expr ']' { $$ = non_term_node(N_EXISTS_OP); 
					$$->child = non_term_node(N_EXPR); 
					$$->child->child = $3;
				      }
		;
all_op 		: ALL '[' expr ']' { 	$$ = non_term_node(N_ALL_OP); 
					$$->child = non_term_node(N_EXPR); 
					$$->child->child = $3;
				   }
		;
extend_op 	: EXTEND '[' atomic_type ID {$$ = id_node();} ASSIGN expr ']' {	$$ = non_term_node(N_EXTEND_OP); 
										$$->child = $3;
										$3->brother = $5;
										$5->brother = non_term_node(N_EXPR); 
										$5->brother->child = $7;
							 		   }
		;
update_op 	: UPDATE '[' ID {$$ = id_node();} ASSIGN expr ']' {$$ = non_term_node(N_UPDATE_OP);
								$$->child = $4;
								$4->brother = non_term_node(N_EXPR); 
								$4->brother->child = $6;			
							       }
		;
rename_op 	: RENAME '[' id_list ']' { 	$$ = non_term_node(N_RENAME_OP); 
						$$->child = non_term_node(N_ID_LIST); 
						$$->child->child = $3;
					  }
		;
constant 	: atomic_const {$$ = non_term_node(N_CONSTANT); $$->child = $1;}
		| table_const {$$ = non_term_node(N_CONSTANT); $$->child = $1;}
		;
atomic_const 	: INT_CONST {$$ = non_term_node(N_ATOMIC_CONST); $$->child = int_const_node();}
		| STR_CONST {$$ = non_term_node(N_ATOMIC_CONST); $$->child = str_const_node();}
		| BOOL_CONST {$$ = non_term_node(N_ATOMIC_CONST); $$->child = bool_const_node();}
		;
table_const 	: '{' table_instance '}' { $$ = non_term_node(N_TABLE_CONST); $$->child = $2; }
		;
table_instance	: tuple_list  {$$ = non_term_node(N_TUPLE_LIST); $$->child = $1; }
		| atomic_type_l { $$ = non_term_node(N_ATOMIC_TYPE_LIST); $$->child = $1; }
		;
tuple_list 	: tuple_const ',' tuple_list {$$ = $1; $$->brother = $3; }
		| tuple_const {$$ = $1;}
		;
tuple_const	: '(' atomic_const_l ')'  {$$ = non_term_node(N_TUPLE_CONST); $$->child = $2;}
		;
atomic_const_l  : atomic_const ',' atomic_const_l {$$ = $1; $1->brother = $3;}
		| atomic_const {$$ = $1;}
		;
atomic_type_l 	: atomic_type ',' atomic_type_l {$$ = $1; $$->brother = $3;}
		| atomic_type {$$ = $1;}
		;
if_stat 	: IF expr THEN stat_list else_part END {$$ = non_term_node(N_IF_STAT);
							$$->child = non_term_node(N_EXPR);
							$$->child->child = $2;
							$$->child->brother = non_term_node(N_STAT_LIST);
							$$->child->brother->child = $4;
							$$->child->brother->brother = $5;
						       }
		;
else_part 	: ELSE stat_list { 	$$ = non_term_node(N_STAT_LIST); 
					$$->child = $2;
				 } 
		| {$$ = NULL; }
		;
while_stat 	: WHILE expr DO stat_list END {	$$ = non_term_node(N_WHILE_STAT); 
						$$->child = non_term_node(N_EXPR);
						$$->child->child = $2;
						$$->child->brother = non_term_node(N_STAT_LIST);
						$$->child->brother->child = $4;
					      }
		;
read_stat 	: READ specifier ID {$$ = id_node();} { 	$$ = non_term_node(N_READ_STAT);
					$$->child = $2;
					$2->brother = $4;
					//$3 = id_node();	
				    }
		;
specifier 	: '[' expr ']' {	$$ = non_term_node(N_SPECIFIER); 
					$$->child = non_term_node(N_EXPR);
					$$->child->child = $2;
			       }
		| {$$ = non_term_node(N_SPECIFIER);}
		; 
write_stat 	: WRITE specifier expr  {	$$ = non_term_node(N_WRITE_STAT); 
						$$->child = $2;
						$2->brother = non_term_node(N_EXPR);			
						$2->brother->child = $3;			
					}
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
		tree_print(root,0);
	return(result);		
}


yyerror() {
  fprintf(stderr, "Line %d: syntax error on symbol \"%s\"\n",line, yytext);
  exit(-1);
}

