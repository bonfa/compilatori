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
		case(N_NEG_EXPR): 	expr_code = (expr_node,expr_schema); break;
		case(N_SELECT_EXPR): 	expr_code = select_kind_expr(expr_node,expr_schema); break;
		case(N_PROJECT_EXPR):	expr_code = project_expr(expr_node,expr_schema); break;
		case(N_UPDATE_EXPR):	expr_code = update_expr(expr_node,expr_schema); break;
		case(N_EXTEND_EXPR):	expr_code = extend_expr(expr_node,expr_schema); break;
		case(N_RENAME_EXPR):	expr_code = rename_expr(expr_node,expr_schema); break;
	}
	return expr_code;
}




/**/
Code comp_expr(){
return NULL;
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
		semerror(root, "Logic operation requires boolean types");

	//Imposto lo schema del risultato dell'espressione
	logic_expr_schema-­>type = BOOLEAN;

	//Le operazioni booleane vengono valutate in corto circuito
	//Genero il codice in modo diverso per l'AND e per l'OR
	if(qualifier(logic_expr_node)==AND){
		int offset = second_op_code->size+2;
		logic_expr_code = concode(
					first_op_code,
					makecode1(T_SKIPF,offset),
					second_op_code,
					makecode1(T_SKIP,2),
					make_ldint(0),
					endcode());
	}
	else{ //OR
		int exit = second_op_code->size+2;
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
		semerror(root, "Math operation requires integer types");

	//Imposto lo schema del risultato dell'espressione
	math_expr_schema-­>type = INTEGER;
	
	//Analizzo il tipo dell'operazione
	switch(qualifier(math_expr_node)) {
		case '+' : op = T_PLUS; break;
		case '-' : op = T_MINUS; break;
		case '*' : op = T_TIMES; break;
		case '/' : op = T_DIV; break;
		default: noderror(math_expr_node);
	}
	//Ritorno il codice dell'operazione
	return concode(code1,code2,makecode(op),endcode());
}



/**/
Code neg_expr(){return NULL;
}






/**/
Code rename_expr(){
	return NULL;
}

/**/
Code select_kind_expr(){
return NULL;
}

/**/
Code update_expr(){
return NULL;
}

/**/
Code join_expr(){
return NULL;
}





/**/
Code extend_expr(){return NULL;}



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

