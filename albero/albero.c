#include "def.h"

char * terminal[] = {
"INTEGER",
"STRING",
"BOOLEAN",
"AND",
"OR",
"NOT",
"UNARY_MINUS",
"EQ",
"NOT_EQ",
"GT",
"GET",
"LT",
"LET",
"ADD",
"SUB",
"MUL",
"DIV",
"INTCONST",
"BOOLCONST",
"STRCONST",
"ID",
"NONTERMINALnelmaenonvcfdnvofbvogfibjgfoboisboijn",
};

char * nonterm[] = {
"PROGRAM",
"STAT_LIST",
"STAT",
"DEF_STAT",
"ID_LIST",
"TYPE",
"ATOMIC_TYPE",
"TABLE_TYPE",
"ATTR_LIST",
"ATTR_DECL",
"ASSIGN_STAT",
"EXPR",
"BOOL_TERM",
"COMP_TERM",
"LOW_TERM",
"FACTOR",
"UNARY_OP",
"JOIN_OP",
"PROJECT_OP",
"SELECT_COP",
"EXISTS_OP",
"ALL_OP",
"EXTEND_OP",
"UPDATE_OP",
"RENAME_OP",
"CONSTANT",
"ATOMIC_CONST",
"TABLE_CONST",
"TUPLE_CONST",
"IF_STAT",
"WHILE_STAT",
"READ_STAT",
"SPECIFIER",
"WRITE_STAT"
};


void tree_print(pNode root, int indent){
	int i;
	pNode p;

	// stampa l'indentazione
	for(i=0; i<indent; i++)
		printf("   ");

	// stampa il simbolo
	if (root->type == T_NONTERMINAL)
		printf("%s",nonterm[root->value.ival]);
	else
		printf("%s",terminal[root->type]);

	printf("\n");	

	// stampa dei figli
	for(p=root->child;p!=NULL;p=p->brother)
		tree_print(p,indent+1);
}











