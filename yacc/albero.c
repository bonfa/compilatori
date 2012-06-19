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
"NONTERMINAL",
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
"SELECT_OP",
"EXISTS_OP",
"ALL_OP",
"EXTEND_OP",
"UPDATE_OP",
"RENAME_OP",
"CONSTANT",
"ATOMIC_CONST",
"TABLE_CONST",
"TUPLE_LIST",
"ATOMIC_TYPE_LIST",
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

	// quando il simbolo è un terminale, stampa anche il simbolo tra parentesi 
	// secondo il pattern %type_node% (%terminal_symbol%)
	if (root->type != T_NONTERMINAL){
		printf("  (");
		switch (root->type){
		case (T_INTEGER):printf("integer"); break;
		case (T_STRING):printf("string"); break;
		case (T_BOOLEAN):printf("boolean"); break;
		case (T_AND):printf("and"); break;
		case (T_OR):printf("or"); break;
		case (T_NOT):printf("not"); break;
		case (T_UNARY_MINUS):printf("-"); break;
		case (T_EQ):printf("=="); break;
		case (T_NOT_EQ):printf("!="); break;
		case (T_GT):printf(">"); break;
		case (T_GET):printf(">="); break;
		case (T_LT):printf("<"); break;
		case (T_LET):printf("<="); break;
		case (T_ADD):printf("+"); break;
		case (T_SUB):printf("-"); break;
		case (T_MUL):printf("*"); break;
		case (T_DIV):printf("/"); break;
		case (T_INTCONST):printf("%d",root->value.ival); break;
		case (T_BOOLCONST):if (root->value.ival ==1) printf("true"); else printf("false"); break;
		case (T_STRCONST):printf("%s",root->value.sval); break;
		case (T_ID):printf("%s",root->value.sval); break;
		}
		printf(")");
	}
	printf("\n");	

	// stampa dei figli
	for(p=root->child;p!=NULL;p=p->brother)
		tree_print(p,indent+1);
}











