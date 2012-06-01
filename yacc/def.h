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
N_ASSIGN_STAT, 
N_ATOMIC_TYPE, 
N_ATTR_DECL, 
N_BOOLCONST, 
N_COMP_EXPR,
N_DEF_STAT, 
N_EXTEND_EXPR, 
N_ID, 
N_IF_STAT, 
N_INTCONST, 
N_JOIN_EXPR,
N_LOGIC_EXPR, 
N_MATH_EXPR, 
N_NEG_EXPR, 
N_PROGRAM, 
N_PROJECT_EXPR,
N_READ_STAT, 
N_RENAME_EXPR, 
N_SELECT_EXPR, 
N_SPECIFIER, 
N_STAT_LIST,
N_STRCONST, 
N_TABLE_CONST, 
N_TABLE_TYPE, 
N_TUPLE_CONST, 
N_TYPE,
N_UPDATE_EXPR, 
N_WHILE_STAT, 
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
	
