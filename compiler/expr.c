#include "def.h"
#include "parser.h"

/* Appende due schemi tra loro */
Boolean type_equal(Schema schema1, Schema schema2)
{
  Pschema p1, p2;
  
  if(schema1.type != schema2.type)
    return(FALSE);
  if(schema1.type == TABLE)
  {
    for(p1 = schema1.next, p2 = schema2.next; p1 != NULL && p2 != NULL; p1= p1->next, p2 = p2->next)
      if(p1->type != p2->type || !compatible(p1->name, p2->name))
        return(FALSE);
    return(p1 == NULL && p2 == NULL);
  }
  else
    return(TRUE);
}


/* Dice se due nomi sono compatibili 
  (Due tabelle con stesso numero di attributi, una con nomi, l'altra senza nomi)  */
Boolean compatible(char *name1, char *name2)
{
  return(name1 == NULL || name2 == NULL || name1 == name2);
}


/* Copia lo schema passato come argomento */
Pschema clone_schema(Pschema pschema)
{
  Pschema clone, psch;
  
  clone = psch = (Pschema) newmem(sizeof(Schema));
  *psch = *pschema;
  while(pschema->next)
  {
    psch->next = (Pschema) newmem(sizeof(Schema));
    *(psch->next) = *(pschema->next);
    psch = psch->next;
    pschema = pschema->next;
  }
  return (clone);
}



/* Appende schemi tra loro */
Pschema append_schemas(Pschema psch1, Pschema psch2)
{
  Pschema head = psch1;
  
  while(psch1->next)
    psch1 = psch1->next;
  psch1->next = psch2;
  return(head);
}




//^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^

/*Genera lo schema del nodo e ritorna il codice pcode*/
Code expr(Pnode expr_node,Pschema expr_schema){
	//Definisco la variabile che contiene il codice da ritornare
	Code expr_code;

	//Analizzo il tipo di nodo e chiamo la funzione appropriata
	switch (expr_node->type){
		case(N_COMP_EXPR):	expr_code = comp_expr(expr_node,expr_schema); break;
		case(N_LOGIC_EXPR): 	expr_code = logic_expr(expr_node,expr_schema); break;		
		case(N_MATH_EXPR): 	expr_code = math_expr(expr_node,expr_schema); break;
		case(N_NEG_EXPR): 	expr_code = neg_expr(expr_node,expr_schema); break;
		case(N_SELECT_EXPR): 	expr_code = select_kind_expr(expr_node,expr_schema); break;
		case(N_PROJECT_EXPR):	expr_code = project_expr(expr_node,expr_schema); break;
		case(N_UPDATE_EXPR):	expr_code = update_expr(expr_node,expr_schema); break;
		case(N_EXTEND_EXPR):	expr_code = extend_expr(expr_node,expr_schema); break;
		case(N_RENAME_EXPR):	expr_code = rename_expr(expr_node,expr_schema); break;
	}
	return expr_code;
}




/*Genera lo schema della comp_expr e ritorna il codice pcode*/
Code comp_expr(Pnode comp_expr_node, Pschema comp_expr_schema){
	//Definisco i due figli del nodo comp_expr
	Pnode first_op_node = comp_expr_node->child;
	Pnode second_op_node = comp_expr_node->child->brother;

	//Preparo la variabile che contiene il codice
	Code comp_expr_code;

	//Definisco il codice per i due operandi
	Code first_op_code;
	Code second_op_code;

	//Creo gli schemi per i due operandi
	Pschema first_op_schema = (Pschema) newmem(sizeof(Schema));
	Pschema second_op_schema = (Pschema) newmem(sizeof(Schema));

	//Genero ricorsivamente gli schemi e il codice dei due operandi
	first_op_code = expr(first_op_node, first_op_schema); 
	second_op_code = expr(second_op_node, second_op_schema);


	//La generazione di codice e gli errori semantici dipendono dal tipo di operazione
	if(qualifier(comp_expr_node) == EQ || qualifier(comp_expr_node) == NE) {
		//Controllo gli errori semantici
		//I due tipi dell'espressione devono essere uguali
		if(!type_equal(*first_op_schema,*second_op_schema))
			semerror(comp_expr_node, "Comparison operation requires equal types");

		//Imposto il tipo del risultato
		comp_expr_schema->type = BOOLEAN;

		//Genero il codice
		Operator op;
		if (qualifier(comp_expr_node) == EQ)
			op = T_EQU;
		else 
			op = T_NEQ;

		comp_expr_code = concode(first_op_code,second_op_code,op,endcode());				
	}
	else {
		//Controllo gli errori semantici
		//Entrambi i tipi dei due operandi devono essere string o integer
		if(((first_op_schema->type != INTEGER) || (second_op_schema->type != INTEGER)) 
		&& ((first_op_schema->type != STRING) || (second_op_schema->type != STRING))) 
			semerror(comp_expr_node, "Operator types must be integer or string");

		//Imposto il tipo del risultato
		comp_expr_schema->type = BOOLEAN;

		//Genero il codice
		Operator op;
		if (first_op_schema->type == INTEGER)
			switch (qualifier(comp_expr_node)) {
				case ('>'): op = T_IGT ; break;
				case (GE):  op = T_IGE ; break;
				case ('<'): op = T_ILT ; break;
				case (LE):  op = T_ILE ; break;	
			}
		else
			switch (qualifier(comp_expr_node)) {
				case ('>'): op = T_SGT ; break;
				case (GE):  op = T_SGE ; break;
				case ('<'): op = T_SLT ; break;
				case (LE):  op = T_SLE ; break;
			}
		comp_expr_code = concode(first_op_code,second_op_code,op,endcode());
	}
	
	return comp_expr_code;
}




/*Genera il codice e definisce lo schema della logic_expr*/
Code logic_expr(Pnode logic_expr_node, Pschema logic_expr_schema){
	//Definisco i due figli del nodo logic_expr
	Pnode first_op_node = logic_expr_node->child;
	Pnode second_op_node = logic_expr_node->child->brother;

	//Preparo la variabile che contiene il codice
	Code logic_expr_code;

	//Definisco il codice per i due operandi
	Code first_op_code;
	Code second_op_code;

	//Creo gli schemi per i due operandi
	Pschema first_op_schema = (Pschema) newmem(sizeof(Schema));
	Pschema second_op_schema = (Pschema) newmem(sizeof(Schema));

	//Genero ricorsivamente gli schemi e il codice dei due operandi
	first_op_code = expr(first_op_node, first_op_schema); 
	second_op_code = expr(second_op_node, second_op_schema);

		
	//Controllo gli errori semantici
	//Entrambi i tipi dei due operandi devono essere boolean
	if(first_op_schema->type != BOOLEAN || second_op_schema->type != BOOLEAN) 
		semerror(logic_expr_node, "Logic operation requires boolean types");

	//Imposto lo schema del risultato dell'espressione
	logic_expr_schema->type = BOOLEAN;

	//Le operazioni booleane vengono valutate in corto circuito
	//Genero il codice in modo diverso per l'AND e per l'OR
	if(qualifier(logic_expr_node)==AND){
		int offset = second_op_code.size+2;
		logic_expr_code = concode(
					first_op_code,
					makecode1(T_SKIPF,offset),
					second_op_code,
					makecode1(T_SKIP,2),
					make_ldint(0),
					endcode());
	}
	else{ //OR
		int exit = second_op_code.size+2;
		logic_expr_code = concode(
					first_op_code,
					makecode1(T_SKIPF,3),
					make_ldint(1),
					makecode1(T_SKIP,exit),
					second_op_code,	
					endcode());
	}
	//Ritorno il codice
	return logic_expr_code;
}




/*Genera il codice e definisce lo schema della math_expr*/
Code math_expr(Pnode math_expr_node, Pschema math_expr_schema){
	//Definisco i due figli del nodo math_expr
	Pnode first_op_node = math_expr_node->child;
	Pnode second_op_node = math_expr_node->child->brother;

	//Definisco il codice per i due operandi
	Code first_op_code;
	Code second_op_code;

	//Creo gli schemi per i due operandi
	Pschema first_op_schema = (Pschema) newmem(sizeof(Schema));
	Pschema second_op_schema = (Pschema) newmem(sizeof(Schema));

	//Genero ricorsivamente gli schemi e il codice dei due operandi
	first_op_code = expr(first_op_node, first_op_schema); 
	second_op_code = expr(second_op_node, second_op_schema);

	//Controllo gli errori semantici
	//Entrambi i tipi dei due operandi devono essere interi
	if(first_op_schema->type != INTEGER || second_op_schema->type != INTEGER) 
		semerror(math_expr_node, "Math operation requires integer types");

	//Imposto lo schema del risultato dell'espressione
	math_expr_schema->type = INTEGER;
	
	//Definisco il codice dell'operatore
	Operator op;

	//Analizzo il tipo dell'operazione
	switch(qualifier(math_expr_node)) {
		case '+' : op = T_PLUS; break;
		case '-' : op = T_MINUS; break;
		case '*' : op = T_TIMES; break;
		case '/' : op = T_DIV; break;
		default: noderror(math_expr_node);
	}
	//Ritorno il codice dell'operazione
	return concode(first_op_code,second_op_code,makecode(op),endcode());
}



/*Genera il codice, definisce lo schema e controlla i vincoli semantici*/
Code neg_expr(Pnode neg_expr_node, Pschema neg_expr_schema){
	//Definisco il figlio del nodo neg_expr
	Pnode expr_node = neg_expr_node->child;

	//Preparo la variabile che contiene il codice
	Code neg_expr_code;

	//Definisco il codice per il nodo figlio
	Code expr_code;

	//Creo lo schema per il nodo figlio
	Pschema expr_schema = (Pschema) newmem(sizeof(Schema));

	//Genero ricorsivamente lo schema e il codice per il nodo figlio
	expr_code = expr(expr_node, expr_schema); 

	//Definisco il codice dell'operatore
	Operator op;

	//La generazione di codice e gli errori semantici dipendono dal tipo di operazione
	if (qualifier(neg_expr_node) == '-') {
		//Controllo la semantica
		if (expr_schema->type != INTEGER)
			semerror(neg_expr_node,"Unary minus requires integer type");
		//Imposto lo schema di neg_expr
		neg_expr_schema->type = INTEGER;

		//Assegno il codice dell'operatore
		op = T_UMI;		
	}
	else { //NOT
		//Controllo la semantica		
		if (expr_schema->type != BOOLEAN)
			semerror(neg_expr_node,"Not operator requires boolean type");
	
		//Imposto lo schema di neg_expr
		neg_expr_schema->type = BOOLEAN;

		//Assegno il codice dell'operatore
		op = T_NEG;		
	}		

	//Definisco il codice da ritornare
	neg_expr_code = appcode(expr_code,makecode(op));

	return expr_code;
}




/**/
Code rename_expr(Pnode rename_expr_node, Pschema rename_expr_schema){
	return NULL;
}



/**/
Code select_kind_expr(Pnode select_expr_node, Pschema select_expr_schema){
return NULL;
}



/**/
Code update_expr(Pnode update_expr_node, Pschema update_expr_schema){
return NULL;
}



/**/
Code join_expr(Pnode join_expr_node, Pschema join_expr_schema){
return NULL;
}



/**/
Code extend_expr(Pnode extend_expr_node, Pschema extend_expr_schema){
return NULL;}



/**/
Code project_expr(Pnode project_expr, Pschema proj_schema){
	/*Code project_code = NULL;
	Pschema schema_expr = (Pschema) newmem(sizeof(Schema));
	
	//Prendo il nodo figlio
	Pnode expr_node = project_expr->child;
	
	//Calcolo il codice di expr
	Code expr_code = expr(expr_node,schema_expr);
	
	//Controllo i vincoli semantici
	if (schema_expr->type != NULL){ 
		semerror(expr_node,"Boolean result expected");
	}
	
	//Calcolo i nomi nell'id list
	*/
return NULL;
}

