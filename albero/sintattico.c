#include "def.h"
#define DEBUG

extern char *yytext;
extern Value lexval;
extern FILE *yyin;
extern line;

int lookahead;
pNode root = NULL;


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

/*legge il primo simbolo in input, crea il nodo 'program' e demanda il suo riempimento (cioè sistemarne i puntatori) alla funzione program()*/
void parse(){	
	next();
	root = non_term_node(N_PROGRAM);	
	root->child = program();
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
	//printf("n_linea = %d\n",line);
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










/*Funzioni dei nonterminali*/

pNode program(){
	match(PROGRAM);

	pNode p = non_term_node(N_STAT_LIST);
	p->child = stat_list();
	
	match(END);
	match(END_OF_FILE); //end of file
	return p;
}


pNode stat_list(){
	pNode head,p;
	
	head = non_term_node(N_STAT);
	p = head;
	p->child = stat();

	while (lookahead == ';'){
		match(';');
		p->brother = non_term_node(N_STAT);
		p = p->brother;		
		p->child = stat();
	}
	return head;
}


pNode stat(){
	pNode p;
	if (lookahead == INTEGER || lookahead == STRING || lookahead == BOOLEAN || lookahead == TABLE){
		p = non_term_node(N_DEF_STAT);
		p->child = def_stat();
	}
	else if (lookahead == ID){
		p = non_term_node(N_ASSIGN_STAT);
		p->child = assign_stat();
	}
	else if (lookahead == IF){
		p = non_term_node(N_IF_STAT);
		p->child = if_stat();
	}
	else if (lookahead == WHILE){
		p = non_term_node(N_WHILE_STAT);
		p->child = while_stat();
	}
	else if (lookahead == READ){
		p = non_term_node(N_READ_STAT);
		p->child = read_stat();
	}
	else {//(lookahead == WRITE)
		p = non_term_node(N_WRITE_STAT);
		p->child = write_stat();
	}
	return p;
}


pNode def_stat(){
	pNode head,p;

	head = non_term_node(N_TYPE);
	head -> child = type();
	
	p = non_term_node(N_ID_LIST);
	p -> child = id_list();

	head-> brother = p;
	return head;
}


pNode assign_stat(){
	pNode head, p;

	head = id_node();	
	match(ID);	

	match(ASSIGN);
	
	p = non_term_node(N_EXPR);
	p-> child = expr();

	head -> brother = p;
	return head;
}


pNode if_stat(){
	pNode head,p,q;
	
	match(IF);
	head = non_term_node(N_EXPR);
	head->child = expr();

	match(THEN);
	p = non_term_node(N_STAT_LIST);
	p->child = stat_list();
	head->brother = p;

	if (lookahead == ELSE){
		match(ELSE);
		q = non_term_node(N_STAT_LIST);
		q->child = stat_list();
		p->brother = q;
	}
	match(END);

	return head;
}


pNode while_stat(){
	pNode head,p;

	match(WHILE);
	head = non_term_node(N_EXPR);
	head->child = expr();

	match(DO);
	p = non_term_node(N_STAT_LIST);
	p->child = stat_list();
	head->brother = p;

	match(END);
	return head;
}


pNode read_stat(){
	pNode head,p;

	match(READ);
	head = non_term_node(N_SPECIFIER);
	head->child = specifier();

	p = id_node();
	match(ID);
	head->brother = p;
	return head;	
}


pNode write_stat(){
	pNode head,p;

	match(WRITE);
	head = non_term_node(N_SPECIFIER);
	head->child = specifier();
	
	p = non_term_node(N_EXPR);
	p->child = expr();
	head -> brother = p;
	return head;
}


pNode type(){
	pNode head;
	if (lookahead == INTEGER || lookahead == STRING || lookahead == BOOLEAN){
		head = non_term_node(N_ATOMIC_TYPE);
		head->child = atomic_type();
	}
	else {
		head = non_term_node(N_TABLE_TYPE);
		head->child = table_type();
	}
	return head;
}


pNode atomic_type(){
	pNode head;
	if (lookahead == INTEGER){
		head = key_node(T_INTEGER);
		match(INTEGER);
	}
	else if (lookahead == STRING) {
		head = key_node(T_STRING);
		match(STRING);
	}
	else { //(lookahead == BOOLEAN)
		head = key_node(T_BOOLEAN);
		match(BOOLEAN);
	}
	return head;
}


pNode table_type(){
	pNode head;

	match(TABLE);
	match('(');
	head = non_term_node(N_TABLE_TYPE);
	head->child = attr_list();
	match(')');
	
	return head;
}



pNode attr_list(){
	pNode head,p;

	head = non_term_node(N_ATTR_DECL);
	head -> child = attr_decl();

	p = head;
	while(lookahead == ','){
		match(',');	
		p -> brother = non_term_node(N_ATTR_DECL);
		p = p->brother;
		p -> child = attr_decl();	
	}
	
	return head;
}


pNode attr_decl(){
	pNode head,p;

	head = non_term_node(N_ATOMIC_TYPE);
	head -> child = atomic_type();

	p = id_node();
	match(ID);
	head->brother = p;

	return head;
}


pNode expr(){
	pNode head,p;

	head = non_term_node(N_BOOL_TERM);
	head -> child = bool_term();

	p = head;
	while (lookahead == BOOL_OP){
		if (lexval.ival == AND)
			p -> brother = key_node(T_AND);
		else 	
			p -> brother = key_node(T_OR);
		p = p -> brother;
		match(BOOL_OP);

		p -> brother = non_term_node(N_BOOL_TERM);
		p = p->brother;
		p -> child = bool_term();	
	}	
	return head;	
}


pNode bool_term(){
	pNode head,p;

	head = non_term_node(N_COMP_TERM);
	head -> child =comp_term();

	p = head;
	if (lookahead == COMP_OP){
		switch(lexval.ival){
		case(EQ):	p -> brother = key_node(T_EQ);break;	
		case(NOT_EQ):	p -> brother = key_node(T_NOT_EQ);break;
		case('>'):	p -> brother = key_node(T_GT);break;
		case(GET):	p -> brother = key_node(T_GET);break;
		case('<'):	p -> brother = key_node(T_LT);break;
		case(LET):	p -> brother = key_node(T_LET);break;
		}
		p = p -> brother;
		match(COMP_OP);

		p -> brother = non_term_node(N_COMP_TERM);
		p = p->brother;
		p -> child = comp_term();
	}
	return head;	
}


pNode comp_term(){
	pNode head,p;
	
	head = non_term_node(N_LOW_TERM);
	head -> child = low_term();
	
	p = head;
	while (lookahead == LOW_BIN_OP){
		if (lexval.ival == '+')
			p -> brother = key_node(T_ADD);
		else 	
			p -> brother = key_node(T_SUB);
		p = p -> brother;
		match(LOW_BIN_OP);

		p -> brother = non_term_node(N_LOW_TERM);
		p = p->brother;
		p -> child = low_term();		
	}
	return head;
}


pNode low_term(){
	pNode head,p;

	head = non_term_node(N_FACTOR);
	head -> child =	factor();

	p = head;
	while (lookahead == HIGH_BIN_OP){
		if (lexval.ival == JOIN){
			p -> brother = non_term_node(N_JOIN_OP);
			p = p->brother;
			p->child = join_op();
		}
		else {
			if (lexval.ival == '*')
				p -> brother = key_node(T_MUL);
			else 	
				p -> brother = key_node(T_DIV);
			p = p->brother;	
			match(HIGH_BIN_OP);		
		}
		p->brother = non_term_node(N_FACTOR);
		p = p->brother;
		p->child = factor();		
	}
	return head;
}


pNode factor(){
	pNode head,p;

	if (lookahead == UNARY_OP || (lookahead == LOW_BIN_OP && lexval.ival == '-')) {
		head = non_term_node(N_UNARY_OP);
		head->child = unary_op();
		
		p = non_term_node(N_FACTOR);
		head -> brother = p;
		p->child = factor();
	}
	else if (lookahead == '('){
		match('(');
		head = non_term_node(N_EXPR);
		head -> child = expr();
		match(')');
	}
	else if (lookahead == ID){
		head = id_node();
		match(ID);
	}
	else { //(lookahead == INT_CONST || lookahead == STR_CONST || lookahead == BOOL_CONST || lookahead == '{')
		head = non_term_node(N_CONSTANT);
		head -> child = constant();
	}
	return head;
}


pNode join_op(){
	pNode head;

	match(HIGH_BIN_OP);
	match('[');
	head = non_term_node(N_EXPR);
	head -> child =	expr();
	match(']');

	return head;
}



pNode constant(){
	pNode head;

	if (lookahead == INT_CONST || lookahead == BOOL_CONST || lookahead == STR_CONST) {
		head = non_term_node(N_ATOMIC_CONST);
		head -> child = atomic_const();
	}
	else {
		head = non_term_node(N_TABLE_CONST);
		head -> child = table_const();
	}

	return head;
}


pNode unary_op(){
	pNode head;

	if (lookahead == LOW_BIN_OP && lexval.ival == '-'){
		head = key_node(T_UNARY_MINUS);
		match(LOW_BIN_OP);
	}
	else if (lexval.ival == PROJECT){
		head = non_term_node(N_PROJECT_OP);		
		head -> child = project_op();
	}
	else if (lexval.ival == SELECT){
		head = non_term_node(N_SELECT_OP);
		head -> child = select_op();
	}
	else if (lexval.ival == EXISTS){
		head = non_term_node(N_EXISTS_OP);
		head -> child = exists_op();
	}
	else if (lexval.ival == ALL){
		head = non_term_node(N_ALL_OP);
		head -> child = all_op();
	}
	else if (lexval.ival == EXTEND){
		head = non_term_node(N_EXTEND_OP);
		head -> child = extend_op();
	}	
	else if (lexval.ival == UPDATE){
		head = non_term_node(N_UPDATE_OP);
		head -> child = update_op();
	}
	else if (lexval.ival == NOT){
		head = key_node(T_NOT);
		match(UNARY_OP);
	}
	else {  //(lexval.ival == RENAME)
		head = non_term_node(N_UPDATE_OP);
		head -> child = rename_op();
	}

	return head;
}


pNode project_op(){
	pNode head;	

	match(UNARY_OP);	
	match('[');
	head = non_term_node(N_ID_LIST);		
	head -> child = id_list();
	match(']');

	return head;
}


pNode select_op(){
	pNode head;

	match(UNARY_OP);
	match('[');
	head = non_term_node(N_EXPR);		
	head -> child = expr();
	match(']');

	return head;
}


pNode exists_op(){
	pNode head;

	match(UNARY_OP);
	match('[');
	head = non_term_node(N_EXPR);		
	head -> child =	expr();
	match(']');

	return head;
}


pNode all_op(){
	pNode head;

	match(UNARY_OP);
	match('[');
	head = non_term_node(N_EXPR);
	head -> child = expr();
	match(']');

	return head;
}


pNode update_op(){
	pNode head,p;

	match(UNARY_OP);
	match('[');
	head = id_node();
	match(ID);
	match(ASSIGN);
		
	p = non_term_node(N_EXPR);
	p -> child = expr();
	
	head->brother = p;
	match(']');

	return head;
}


pNode extend_op(){
	pNode head,p,q;

	match(UNARY_OP);
	match('[');

	head = non_term_node(N_ATOMIC_TYPE);
	head -> child = atomic_type();
	
	p = id_node();
	head -> brother = p;	
	match(ID);
	match(ASSIGN);
	
	q = non_term_node(N_EXPR);
	q -> child = expr();
	p -> brother = q;
	match(']');

	return head;
}


pNode rename_op(){
	pNode head;

	match(UNARY_OP);
	match('[');
	head = non_term_node(N_ID_LIST);		
	head -> child = id_list();
	match(']');

	return head;
}


pNode id_list(){
	pNode head,p;

	head = id_node();
	match(ID);
	p = head;
	while (lookahead == ',') {
		match(',');
		p->brother = id_node();
		p = p -> brother;
		match(ID);
	}
	
	return head;
}


pNode atomic_const(){
	pNode head;

	if (lookahead == INT_CONST){
		head = key_node(T_INTCONST);
		match(INT_CONST);
	}
	else if (lookahead == BOOL_CONST) {
		head = key_node(T_BOOLCONST);
		match(BOOL_CONST);
	}
	else {//(lookahead == STR_CONST)
		head = key_node(T_STRCONST);
		match(STR_CONST);
	}

	return head;
}


/*Se c'è la tabella vuota, viene restituito NULL*/
pNode table_const(){
	pNode head,p;
	head = NULL;
	match('{');
	if (lookahead == '('){
		head = non_term_node(N_TUPLE_CONST);
		head -> child = tuple_const();
		p = head;
		while (lookahead == ',') {
			match(',');
			p-> brother = non_term_node(N_TUPLE_CONST);
			p = p-> brother;
			p->child = tuple_const();
		}
	}
	match('}');
	return head;
}


pNode tuple_const(){
	pNode head,p;
	
	match('(');
	head = non_term_node(N_ATOMIC_CONST);
	head -> child = atomic_const();

	p = head;
	while (lookahead == ',') {
		match(',');
		p -> brother = non_term_node(N_ATOMIC_CONST);
		p = p->brother;
		p -> child = atomic_const();
	}
	match(')');
	return head;	
}

/*Se lo specificatore non c'è, viene restituito NULL*/
pNode specifier(){
	if (lookahead == '['){
		match('[');
		pNode head = non_term_node(N_EXPR);
		head -> child = expr();
		match(']');
		return head;
	}
	return NULL;
}



