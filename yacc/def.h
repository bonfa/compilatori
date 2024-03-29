#include <stdio.h>
#include <stdlib.h>

//Tipi di nodi
typedef enum{
//keyword
T_INTEGER,
T_STRING,
T_BOOLEAN,

T_AND,
T_OR,
T_NOT,
T_UNARY_MINUS,

//operator
T_EQ,
T_NOT_EQ,
T_GT,
T_GET,
T_LT,
T_LET,
T_ADD,
T_SUB,
T_MUL,
T_DIV,

// costanti
T_INTCONST,
T_BOOLCONST,
T_STRCONST,
//table-const: la table const viene costruita a partire da operatori semplici

T_ID,

T_NONTERMINAL
} Typenode;


//Non terminali
typedef enum{
N_PROGRAM,
N_STAT_LIST,
N_STAT,
N_DEF_STAT,
N_ID_LIST,
N_TYPE,
N_ATOMIC_TYPE,
N_TABLE_TYPE,
N_ATTR_LIST,
N_ATTR_DECL,
N_ASSIGN_STAT,
N_EXPR,
N_BOOL_TERM,
N_COMP_TERM,
N_LOW_TERM,
N_FACTOR,
N_UNARY_OP,
N_JOIN_OP,
N_PROJECT_OP,
N_SELECT_OP,
N_EXISTS_OP,
N_ALL_OP,
N_EXTEND_OP,
N_UPDATE_OP,
N_RENAME_OP,
N_CONSTANT,
N_ATOMIC_CONST,
N_TABLE_CONST,
N_TUPLE_LIST,
N_ATOMIC_TYPE_LIST,
N_TUPLE_CONST,
N_IF_STAT,
N_WHILE_STAT,
N_READ_STAT,
N_SPECIFIER,
N_WRITE_STAT
} Nonterminal;




typedef union{
	int ival;
	char *sval;
} Value;


typedef struct snode{
Typenode type;
Value value;
struct snode *child,*brother; 
} Node;


typedef Node *pNode;



/*Funzioni dell'analizzatore lessicale*/
char *new_string(char *s);
int assign_id();


/*Funzioni dell'analizzatore sintattico*/
	/*Funzioni di gestione del parser*/
	void parse_error();
	void match(int simbolo);
	void next();
	void parse();
	void tree_print(pNode p, int indent);

	/*Funzioni per la creazione dei nodi dell'albero*/
	pNode new_node(Typenode type_node);
	pNode non_term_node(Nonterminal nonterm);
	pNode id_node();
	pNode str_const_node();
	pNode int_const_node();
	pNode bool_const_node();
	pNode key_node(Typenode keyword);
	
