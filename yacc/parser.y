%{
#include <def.h>
#define YYSTYPE pNode
extern *char yytext;
extern Value lexval;
extern int line;
extern FILE *yyin;
pNode root = NULL;
%}
%token IF THEN ELSE WHILE DO END 
%token INTEGER STRING BOOLEAN TABLE	
%token READ WRITE
%token ID
%token BOOL_OP UNARY_OP HIGH_BIN_OP LOW_BIN_OP COMP_OP
%token INT_CONST STR_CONST BOOL_CONST
%token AND OR NOT
%token PROJECT SELECT EXISTS ALL UPDATE EXTEND RENAME JOIN
%token PROGRAM
%token EQ NOT_EQ GET LET
%token ASSIGN END_OF_FILE
%token ERROR

%%
program 	: PROGRAM stat_list END {	root = non_term_node((N_PROGRAM); 
						root->child = non_term_node(N_STAT_LIST); 
						root->child->child = $2);
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
def_stat 	: type id_list  {$$ = non_term_node(N_DEF_STAT); $$->child = $1; $1->brother = $2; }
		;
id_list		: ID {$$ = id_node();} ',' id_list {$$ = non_term_node(N_ID_LIST); $$->child = $2; $2->brother = $4; }
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
assign_stat	: ID {$$ = id_node();} '=' expr {	$$ = non_term_node(N_ASSIGN_STAT); 
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
comp_term	: comp_term low_bin_op low_term { }
		| low_term  {}
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
extend_op 	: EXTEND '[' atomic_type ID '=' expr ']'
		;
update_op 	: UPDATE '[' ID '=' expr ']'
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

