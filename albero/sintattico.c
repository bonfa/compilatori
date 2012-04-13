#include "def.h"
#define DEBUG

extern char *yytext;
extern Value lexval;
extern FILE *yyin;
extern line;

int lookahead;



/*
Per come è definita la sintassi non si possono dichiarare interi positivi con segno. 
Ad esempio a = +5; ritorna errore.
Il caso corretto è a = 5;
E' corretto, invece scrivere a = -5;
*/

int main(){	
	yyin = stdin;
	parse();
	fprintf(stderr,"frase sintatticamente corretta\n");
	return(0);		
}





/*Funzioni di gestione del parser*/

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
if ((lookahead == simbolo) && (lookahead != END_OF_FILE)){
	next();
}
else if ((lookahead == simbolo) && (lookahead == END_OF_FILE))
	;
else
	parse_error();
}


/* stampa un messaggio di errore ed esce*/
void parse_error(){
	fprintf(stderr,"[line %d]: sintax error on symbol: '%s'\n",line,yytext);
	exit(-1);
}










/*Funzioni per la creazione dei nodi dell'albero*/

/*Funzione per la creazione di un nodo generico.
  Crea il nodo e annulla i puntatori al figlio e al fratello
*/
pNode new_node(Typenode type_node){
	pNode p;

	pNode p = (pNode) malloc(sizeof(Node));
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
	p->value.ivalue = lexval.ivalue;
	return p;
}


/*Crea un nodo di tipo bool_const.
  Chiama la funzione new_node e assegna al campo value.ival il valore*/
pNode bool_const_node(){
	pNode p = new_node(T_BOOLCONST);
	p->value.ivalue = lexval.ivalue;
	return p;
}



pNode key_node(){

	return p;
}










/*Funzioni dei nonterminali*/

void program(){
	match(PROGRAM);
	stat_list();
	match(END);
	match(END_OF_FILE); //end of file
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
	else //(lookahead == WRITE)
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
	expr();
	match(THEN);
	stat_list();
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
		match(INTEGER);
	else if (lookahead == STRING) 
		match(STRING);
	else //(lookahead == BOOLEAN)
		match(BOOLEAN);
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
	while (lookahead == BOOL_OP){
		match(BOOL_OP);
		bool_term();	
	}		
}


void bool_term(){
	comp_term();
	if (lookahead == COMP_OP){
		match(COMP_OP);
		comp_term();
	}
}


void comp_term(){
	low_term();
	while (lookahead == LOW_BIN_OP){
		match(LOW_BIN_OP);
		low_term();		
	}
}


void low_term(){
	factor();
	while (lookahead == HIGH_BIN_OP){
		if (lexval.ival == JOIN)
			join_op();
		else
			match(HIGH_BIN_OP);
		factor();		
	}
}

void factor(){
	if (lookahead == UNARY_OP || (lookahead == LOW_BIN_OP && lexval.ival == '-')) {
		unary_op();
		factor();
	}
	else if (lookahead == '('){
		match('(');
		expr();
		match(')');
	}
	else if (lookahead == ID){
		match(ID);
	}
	else { //(lookahead == INT_CONST || lookahead == STR_CONST || lookahead == BOOL_CONST || lookahead == '{')
		constant();
	}
}


void join_op(){
	match(HIGH_BIN_OP);
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
		match(LOW_BIN_OP);
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
	else if (lexval.ival == NOT)
		match(UNARY_OP);
	else //(lexval.ival == RENAME)
		rename_op();
}


void project_op(){
	match(UNARY_OP);	
	match('[');
	id_list();
	match(']');
}


void select_op(){
	match(UNARY_OP);
	match('[');
	expr();
	match(']');
}


void exists_op(){
	match(UNARY_OP);
	match('[');
	expr();
	match(']');

}


void all_op(){
	match(UNARY_OP);
	match('[');
	expr();
	match(']');
}


void update_op(){
	match(UNARY_OP);
	match('[');
	match(ID);
	match(ASSIGN);
	expr();
	match(']');
}


void extend_op(){
	match(UNARY_OP);
	match('[');
	atomic_type();
	match(ID);
	match(ASSIGN);
	expr();
	match(']');

}


void rename_op(){
	match(UNARY_OP);
	match('[');
	id_list();
	match(']');
}


void id_list(){
	match(ID);
	while (lookahead == ',') {
		match(',');
		match(ID);
	}
}


void atomic_const(){
	if (lookahead == INT_CONST)
		match(INT_CONST);
	else if (lookahead == BOOL_CONST) 
		match(BOOL_CONST);
	else //(lookahead == STR_CONST)
		match(STR_CONST);
}


void table_const(){
	match('{');
	if (lookahead == '('){
		tuple_const();
		while (lookahead == ',') {
			match(',');
			tuple_const();
		}
	}
	match('}');
}


void tuple_const(){
	match('(');
	atomic_const();
	while (lookahead == ',') {
		match(',');
		atomic_const();
	}
	match(')');	
}


void specifier(){
	if (lookahead == '['){
		match('[');
		expr();
		match(']');
	}
}



