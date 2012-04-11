#include "def.h"
#define DEBUG

extern char *yytext;
extern Value lexval;
extern FILE *yyin;
int lookahead;

//--------------------------------------------------------------
/*main*/
int main(){	
	yyin = stdin;
	parse();
	return(0);		
}


/*legge il primo simbolo in input e chiama l'assioma*/
void parse(){	
	next();
	program();	
}



/*riceve dall'analizzatore lessicale la codifica del prossimo simbolo in ingresso e lo salva nella variabile lookahead

lookahead è un integer e contiene la codifica ritornata dall'analizzatore lessicale
le informazioni aggiuntive sono contenute nella variabile lexval
*/
void next()
{
	lookahead = yylex();
}



/*fa il match tra il simbolo ricevuto in ingresso e la variabile di lookahead*/
void match(int simbolo){
if (lookahead == simbolo){
	next();
#ifdef DEBUG
	printf("lookahead: %d\t symbol: %s\n",lookahead,yytext);
#endif
}
else
	error();
}



/* stampa un messaggio di errore ed esce*/
void error(){
	fprintf(stderr,"Error at line %d\t : %s\n",1,yytext);
#ifdef DEBUG
	printf("lookahead: %d\t symbol: %s\n",lookahead,yytext);
#endif
	exit(-1);
}
//-------------------------------------------------------------

void program(){
	match(PROGRAM);
	stat_list();
	match(END);
}


void stat_list(){
	stat();
	while (lookahead == ';'){
		match(';');
		stat();
	}
}


void stat(){
	if (lookahead == INTEGER || lookahead == STRING || lookahead == BOOLEAN || lookahead == TABLE)
		def_stat();
	else if (lookahead == ID)
		assign_stat();
	else if (lookahead == IF)
		if_stat();
	else if (lookahead == WHILE)
		while_stat();
	else if (lookahead == READ)
		read_stat();
	else if (lookahead == WRITE)
		write_stat();
}


void def_stat(){
	type();
	id_list();
}


void assign_stat(){
	match(ID);
	match(ASSIGN);
	expr();
}


void if_stat(){
	match(IF);
	stat();
	match(THEN);
	if (lookahead == ELSE){
		match(ELSE);
		stat_list();
	}
	match(END);
}


void while_stat(){
	match(WHILE);
	expr();
	match(DO);
	stat_list();
	match(END);
}


void read_stat(){
	match(READ);
	specifier();
	match(ID);
}


void write_stat(){
	match(WRITE);
	specifier();
	expr();
}


void type(){
	if (lookahead == INTEGER || lookahead == STRING || lookahead == BOOLEAN)
		atomic_type();
	else 
		table_type();
}


void atomic_type(){
	if (lookahead == INTEGER)
		next();
	else if (lookahead == STRING) 
		next();
	else if (lookahead == BOOLEAN)
		next();
	else 
		error(); //Qui l'error c'e' perche' non e' stata usata la funzione match()
}


void table_type(){
	match(TABLE);
	match('(');
	attr_list();
	match(')');	
}


void attr_list(){
	attr_decl();
	while(lookahead == ','){
		match(',');	
		attr_decl();	
	}
}


void attr_decl(){
	atomic_type();
	match(ID);
}


void expr(){
	bool_term();
	while (lookahead == AND || lookahead == OR){
		next();
		bool_term();	
	}		
}


void bool_term(){
	comp_term();
	if (lookahead == COMP_OP){
		next();
		comp_term();
	}
}


void comp_term(){
	low_term();
	while (lookahead == LOW_BIN_OP){
		next();
		low_term();		
	}
}


void low_term(){
	factor();
	while (lookahead == HIGH_BIN_OP){
		next();
		factor();		
	}
}

void factor(){
	if (lookahead == UNARY_OP || (lookahead == LOW_BIN_OP && lexval.ival == '-')) {
		unary_op();
		factor();
	}
	else if (lookahead == '('){
		next();
		expr();
		match(')');
	}
	else if (lookahead == ID){
		next();
	}
	else if (lookahead == INT_CONST || lookahead == STR_CONST || lookahead == BOOL_CONST || lookahead == '{'){
		constant();
	}
}


void join_op(){
	match(JOIN);
	match('[');
	expr();
	match(']');
}



void constant(){
	if (lookahead == INT_CONST || lookahead == BOOL_CONST || lookahead == STR_CONST)
		atomic_const();
	else 
		table_const();
}


void unary_op(){
	if (lookahead == LOW_BIN_OP && lexval.ival == '-')	
		next();
	else if (lexval.ival == PROJECT)
		project_op();
	else if (lexval.ival == SELECT)
		select_op();
	else if (lexval.ival == EXISTS)
		exists_op();
	else if (lexval.ival == ALL)
		all_op();
	else if (lexval.ival == EXTEND)
		extend_op();	
	else if (lexval.ival == UPDATE)
		update_op();
	else if (lexval.ival == RENAME)
		rename_op();
}


void project_op(){
	match(PROJECT);	
	match('[');
	id_list();
	match(']');
}


void select_op(){
	match(SELECT);
	match('[');
	expr();
	match(']');
}


void exists_op(){
	match(EXISTS);
	match('[');
	expr();
	match(']');

}


void all_op(){
	match(ALL);
	match('[');
	expr();
	match(']');
}


void update_op(){
	match(UPDATE);
	match('[');
	match(ID);
	match(ASSIGN);
	expr();
	match(']');
}


void extend_op(){
	match(EXTEND);
	match('[');
	atomic_type();
	match(ID);
	match(ASSIGN);
	expr();
	match(']');

}


void rename_op(){
	match(RENAME);
	match('[');
	id_list();
	match(']');
}


void id_list(){
	match(ID);
	while (lookahead == ',') {
		next();
		match(ID);
	}
}


void atomic_const(){
	if (lookahead == INT_CONST)
		next();
	else if (lookahead == BOOL_CONST) 
		next();
	else if (lookahead == STR_CONST)
		next();
	else
		error();
}


void table_const(){
	match('{');
	if (lookahead == '('){
		tuple_const();
		while (lookahead == ',') {
			next();
			tuple_const();
		}
	}
	match('}');
}


void tuple_const(){
	match('(');
	atomic_const();
	while (lookahead == ',') {
		atomic_const();
	}
	match(')');	
}


void specifier(){
	if (lookahead == '['){
		next();
		expr();
		match(']');
	}
	//non genera errore perche' c'e' eps
}



