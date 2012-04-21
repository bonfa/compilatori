#include <stdio.h>
#include <stdlib.h>

/*Costanti che servono all'analizzatore lessicale*/
#define ERROR 		-1

#define IF		300
#define THEN		301
#define ELSE		302
#define WHILE		303
#define DO		304
#define END 		305

#define INTEGER		310
#define STRING		311
#define BOOLEAN		312
#define TABLE		313

#define READ		320
#define WRITE		321

#define ID		325

#define BOOL_OP		330
#define UNARY_OP	331
#define HIGH_BIN_OP	332
#define LOW_BIN_OP	333
#define COMP_OP		334

#define INT_CONST	340
#define STR_CONST	341
#define BOOL_CONST	342

#define AND		350
#define OR		351
#define NOT		352

#define PROJECT		360
#define SELECT		361
#define EXISTS		362
#define ALL		363
#define UPDATE		364
#define EXTEND		365
#define RENAME		366
#define JOIN		367

#define PROGRAM		370

#define EQ		375
#define NOT_EQ		376
#define GET		377
#define LET		378

#define ASSIGN		385
#define END_OF_FILE	0

/*Costanti che servono all'analizzatore sintattico per generare i nodi corretti dell'albero*/

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
	

	/*Funzioni dei nonterminali*/
	pNode program();
	pNode stat_list();
	pNode stat();
	pNode def_stat();
	pNode id_list();
	pNode type();
	pNode atomic_type();
	pNode table_type();
	pNode attr_list();
	pNode attr_decl();
	pNode assign_stat();
	pNode expr();
	pNode bool_term();
	pNode comp_term();
	pNode low_term();
	pNode factor();
	pNode unary_op();
	pNode join_op();
	pNode project_op();
	pNode select_op();
	pNode exists_op();
	pNode all_op();
	pNode extend_op();
	pNode update_op();
	pNode rename_op();
	pNode constant();
	pNode atomic_const();
	pNode atomic_type_list();
	pNode tuple_list();
	pNode table_const();
	pNode tuple_const();
	pNode if_stat();
	pNode while_stat();
	pNode read_stat();
	pNode specifier();
	pNode write_stat();
