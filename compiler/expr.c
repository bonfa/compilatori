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
		case(N_ID):		expr_code = id_expr(expr_node,expr_schema); break;
		case(N_BOOLCONST):	expr_code = bool_const(expr_node,expr_schema); break;
		case(N_INTCONST):	expr_code = int_const(expr_node,expr_schema); break;
		case(N_STRCONST):	expr_code = str_const(expr_node,expr_schema); break;
		case(N_TABLE_CONST):	expr_code = table_const(expr_node,expr_schema); break;
		case(N_JOIN_EXPR):	expr_code = join_expr(expr_node,expr_schema); break;
#ifdef DEBUG_EXPR		
		default: printf("mi sono dimenticato qualcosa\nN_TYPE = %d\n",expr_node->type);
#endif
	}
	return expr_code;
}




/*Genera lo schema della comp_expr e ritorna il codice pcode*/
Code comp_expr(Pnode comp_expr_node, Pschema comp_expr_schema){
#ifdef DEBUG_COMP_EXPR
	printf("COMP_EXPR - enter\n");
#endif

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

		comp_expr_code = concode(first_op_code,second_op_code,makecode(op),endcode());				
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
		comp_expr_code = concode(first_op_code,second_op_code,makecode(op),endcode());
	}
#ifdef DEBUG_COMP_EXPR
	printf("COMP_EXPR - exit\n");
#endif	
	return comp_expr_code;
}




/*Genera il codice e definisce lo schema della logic_expr*/
Code logic_expr(Pnode logic_expr_node, Pschema logic_expr_schema){
#ifdef DEBUG_LOGIC_EXPR
	printf("LOGIC_EXPR - enter\n");
#endif
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
		int exit = second_op_code.size+1;
		logic_expr_code = concode(
					first_op_code,
					makecode1(T_SKIPF,3),
					make_ldint(1),
					makecode1(T_SKIP,exit),
					second_op_code,	
					endcode());
	}

#ifdef DEBUG_LOGIC_EXPR
	printf("LOGIC_EXPR - exit\n");
#endif
	//Ritorno il codice
	return logic_expr_code;
}




/*Genera il codice e definisce lo schema della math_expr*/
Code math_expr(Pnode math_expr_node, Pschema math_expr_schema){
#ifdef DEBUG_MATH_EXPR
	printf("MATH_EXPR - enter\n");
#endif
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
#ifdef DEBUG_MATH_EXPR
	printf("MATH_EXPR - enter\n");
#endif
	//Ritorno il codice dell'operazione
	return concode(first_op_code,second_op_code,makecode(op),endcode());
}



/*Genera il codice, definisce lo schema e controlla i vincoli semantici*/
Code neg_expr(Pnode neg_expr_node, Pschema neg_expr_schema){
#ifdef DEBUG_NEG_EXPR
	printf("NEG_EXPR - enter\n");
#endif
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
			semerror(neg_expr_node,"'Not' requires boolean type");
	
		//Imposto lo schema di neg_expr
		neg_expr_schema->type = BOOLEAN;

		//Assegno il codice dell'operatore
		op = T_NEG;		
	}		

	//Definisco il codice da ritornare
	neg_expr_code = appcode(expr_code,makecode(op));
#ifdef DEBUG_NEG_EXPR
	printf("NEG_EXPR - exit\n");
#endif
	return neg_expr_code;
}


//^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^


/*Genera il codice della expr e lo schema risultante*/
Code project_expr(Pnode project_expr_node, Pschema proj_schema){
#ifdef DEBUG_PROJECT_EXPR
	printf("PROJECT_EXPR - enter\n");
#endif
	//Definisco i figli del nodo project_expr
	Pnode expr_node = project_expr_node->child;
	Pnode id_list_node = project_expr_node->child->brother;

	//Definisco il codice per i due operandi
	Code first_op_code;
	Code second_op_code;

	//Preparo la variabile che contiene il codice
	Code project_code;

	//Creo lo schema per expr
	Pschema schema_expr = (Pschema) newmem(sizeof(Schema));

	//Calcolo il codice di expr
	Code expr_code = expr(expr_node,schema_expr);

	//Calcolo l'elenco di nomi di id_list
	int len;
	Pname name_list = id_list(id_list_node,&len);

	//Analisi semantica
	//Controllo il tipo di expr
	if(schema_expr->type != TABLE)
		semerror(project_expr_node,"Project needs table type");
	//Controllo che non ci siano nomi duppi nella lista
	if (repeated_names(name_list))
		semerror(project_expr_node,"Repeated names in id list");
	//Controllo che ciascun nome nella lista appartenga alla tabella
	Pname n = name_list;
	while(n != NULL){
		if (name_in_schema(n->name,schema_expr) == NULL)
			semerror(project_expr_node,"Attribute must exist in table");
		n = n->next;
	}

	//Metto nel constack il codice di expr
	push_context(schema_expr->next);
	
	//Imposto lo schema di proj expr e genero il codice
	proj_schema->type = TABLE;
	Pschema prec = proj_schema;
	Pschema p;
	n = name_list;
	len = 0;
	Code attr_list_code;
	attr_list_code.head = NULL;
	while(n != NULL){
		//Estraggo lo schema della variabile e l'indirizzo della variabile
		int context_offset,attribute_offset;
		//Prendo la variable 
		Pschema schema_var = name_in_constack(n->name,&context_offset,&attribute_offset);

		Code attr_code = makecode2(T_ATTR,attribute_offset,get_size(schema_var));
		attr_list_code = appcode(attr_list_code,attr_code);

		prec->next = clone_schema(schema_var);
		prec = prec->next;
		prec->next = NULL;
		n = n->next;
		len++;
	}
	//Genero il pcode
	n = name_list;
	project_code = concode(
				expr_code,
				makecode1(T_PROJ,len),
				attr_list_code,
				makecode(T_ENDPROJ),
				makecode(T_REMDUP),
				endcode());
#ifdef DEBUG_PROJECT_EXPR
	printf("PROJECT_EXPR - exit\n");
#endif

	return project_code;
}



/*Genera il codice della expr e lo schema risultante*/
Code rename_expr(Pnode rename_expr_node, Pschema rename_expr_schema){
#ifdef DEBUG_RENAME_EXPR
	printf("RENAME_EXPR - enter\n");
#endif
	//Definisco i figli del nodo rename_expr
	Pnode expr_node = rename_expr_node->child;
	Pnode id_list_node = rename_expr_node->child->brother;

	//Preparo la variabile che contiene il codice
	Code rename_code;

	//Creo lo schema per expr
	Pschema schema_expr = (Pschema) newmem(sizeof(Schema));

	//Calcolo il codice di expr
	Code expr_code = expr(expr_node,schema_expr);

	//Calcolo l'elenco di nomi di id_list
	int id_list_len;
	Pname name_list = id_list(id_list_node,&id_list_len);

	//Controllo la semantica
	//Tipo di expr dev'essere table
	if(schema_expr->type != TABLE)
		semerror(rename_expr_node,"Rename needs table type");
	//Controllo che la lunghezza delle due liste di nomi sia uguale
	//Calcolo la lunghezza della seconda lista
	int len_schema = 0;
	Pschema s;	
	for(s=schema_expr->next;s!=NULL;s=s->next)
		len_schema++;

	if (len_schema != id_list_len)
		semerror(rename_expr_node,"New names number different from old names number");
	//Controllo che non ci siano nomi duppi nella lista
	if (repeated_names(name_list))
		semerror(rename_expr_node,"Repeated names in id list");
	
	//Creo lo schema
	//copio lo schema della tabella originale
	schema_copy(clone_schema(schema_expr),rename_expr_schema);
	//Cambio i nomi di rename schema expr
	rename_expr_schema->name = NULL;
	Pschema p = rename_expr_schema->next;
	while (p!=NULL){
		p->name = name_list->name;
		p = p->next;
		name_list = name_list->next;
	}

	//Il codice della rename è il codice della expr
	rename_code = expr_code;

#ifdef DEBUG_RENAME_EXPR
	printf("RENAME_EXPR - exit\n");
#endif
	return rename_code;
}



/*Genera il codice della expr e lo schema risultante*/
Code select_kind_expr(Pnode select_expr_node, Pschema select_expr_schema){
#ifdef DEBUG_SELECT_EXPR
	printf("SELECT_EXPR - enter\n");
#endif
	//Definisco i figli del nodo
	Pnode expr1_node = select_expr_node->child;
	Pnode expr2_node = select_expr_node->child->brother;

	//Preparo la variabile che contiene il codice
	Code select_code;

	//Creo lo schema per le due expr
	Pschema schema_expr1 = (Pschema) newmem(sizeof(Schema));
	Pschema schema_expr2 = (Pschema) newmem(sizeof(Schema));

	//Genero il codice di expr_2 (che è il nome della tabella)
	Code expr_code2 = expr(expr2_node,schema_expr2);
	//Controllo la semantica per expr2	
	if (schema_expr2->type != TABLE)	
		semerror(select_expr_node,"Expected table type");
	//Inserisco nello stack lo schema di expr_2
	push_context(schema_expr2->next);

	//Calcolo il codice delle due expr
	Code expr_code1 = expr(expr1_node,schema_expr1);
	//Controllo la semantica di expr_1
	if (schema_expr1->type != BOOLEAN)
		semerror(select_expr_node,"Expected boolean type");
	

	//Imposto il tipo di ritorno
	if (qualifier(select_expr_node)==SELECT)
		schema_copy(clone_schema(schema_expr2),select_expr_schema); 
	else
		select_expr_schema->type = BOOLEAN; 

		
	int gap = expr_code1.size;
	//Genero il codice
	switch(qualifier(select_expr_node)){
	case(SELECT): select_code = concode(expr_code2,makecode1(T_SEL,gap),expr_code1,makecode1(T_ENDSEL,gap),endcode());break;
	case(EXISTS): select_code = concode(expr_code2,makecode1(T_EXS,gap),expr_code1,makecode1(T_ENDEXS,gap),endcode());break;
	case(ALL): select_code = concode(expr_code2,makecode1(T_ALL,gap),expr_code1,makecode1(T_ENDALL,gap),endcode());break;
	}

	//Faccio il pop del context
	pop_context();

#ifdef DEBUG_SELECT_EXPR
	printf("SELECT_EXPR - exit\n");
#endif

	return select_code;
}



/*Genera il codice della expr e lo schema risultante*/
Code update_expr(Pnode update_expr_node, Pschema update_expr_schema){
#ifdef DEBUG_UPDATE_EXPR
	printf("UPDATE_EXPR - enter\n");
#endif
	//Definisco i figli del nodo
	Pnode expr1_node = update_expr_node->child;
	Pnode id_node = update_expr_node->child->brother;
	Pnode expr2_node = update_expr_node->child->brother->brother;

	//Preparo la variabile che contiene il codice
	Code update_code;

	//Creo lo schema per le due expr e per l'id
	Pschema schema_expr1 = (Pschema) newmem(sizeof(Schema));
	Pschema schema_expr2 = (Pschema) newmem(sizeof(Schema));

	//Calcolo il codice dei expr1
	Code expr_code1 = expr(expr1_node,schema_expr1);
	//Controllo la semantica
	//expr1 dev'essere di tipo tabella
	if (schema_expr1->type != TABLE)
		semerror(update_expr_node,"Expected table type");
	//id deve appartenere all'elenco degli attributi di expr1
	Pschema schema_id = name_in_schema(valname(id_node),schema_expr1);
	if (schema_id == NULL)
		semerror(update_expr_node,"Attribute must exist in table");

	//Push del context
	push_context(schema_expr1->next);

	//Calcolo il codice dei expr2
	Code expr_code2 = expr(expr2_node,schema_expr2);
	//tipo di expr2 e di id devono essere compatibili
	if (!type_equal(*schema_id,*schema_expr2))	
		semerror(update_expr_node,"Id and expr must have same type");

	//Imposto il tipo di ritorno
	schema_copy(clone_schema(schema_expr1),update_expr_schema);
	
	//Genero il codice
	int gap = expr_code2.size;
	int context_offset,attribute_offset;
	Pschema schema_var = name_in_constack(valname(id_node),&context_offset,&attribute_offset);
	update_code = concode(
				expr_code1,
				makecode3(T_UPD,attribute_offset,get_size(schema_var),gap),
				expr_code2,
				makecode1(T_ENDUPD,gap),
				makecode(T_REMDUP),
				endcode());		

	//Pop del context
	pop_context();

#ifdef DEBUG_UPDATE_EXPR
	printf("UPDATE_EXPR - exit\n");
#endif
	return update_code;
}



/*Genera il codice della expr e lo schema risultante*/
Code join_expr(Pnode join_expr_node, Pschema join_expr_schema){
#ifdef DEBUG_JOIN_EXPR
	printf("JOIN_EXPR - enter\n");
#endif
	//Definisco i figli del nodo
	Pnode expr1_node = join_expr_node->child;
	Pnode expr2_node = join_expr_node->child->brother;
	Pnode expr3_node = join_expr_node->child->brother->brother;

	//Preparo la variabile che contiene il codice
	Code join_code;

	//Creo lo schema per le expr
	Pschema schema_expr1 = (Pschema) newmem(sizeof(Schema));
	Pschema schema_expr2 = (Pschema) newmem(sizeof(Schema));
	Pschema schema_expr3 = (Pschema) newmem(sizeof(Schema));

	//Calcolo il codice delle tabelle
	Code expr_code1 = expr(expr1_node,schema_expr1);
	Code expr_code3 = expr(expr3_node,schema_expr3);	

	//Controllo la semantica delle tabella
	//expr1 dev'essere di tipo tabella
	if (schema_expr1->type != TABLE)
		semerror(join_expr_node,"Expected table type");
	//expr3 dev'essere di tipo tabella
	if (schema_expr3->type != TABLE)
		semerror(join_expr_node,"Expected table type");
	//le due tabelle non devono avere nomi in comune
	Pschema p = schema_expr1;
	while(p!=NULL){	
		if(name_in_schema(p->name,schema_expr3))
			semerror(join_expr_node,"Tables have attribute with the same name");
		p=p->next;
	}

	//Creo il context
	push_context(append_schemas(clone_schema(schema_expr1->next),clone_schema(schema_expr3->next)));

	//Imposto lo schema dell'espressione ritornata
	schema_copy(append_schemas(clone_schema(schema_expr1),clone_schema(schema_expr3->next)	),join_expr_schema);

	//Controllo la semantica dell'espressione vera e propria
	Code expr_code2 = expr(expr2_node,schema_expr2);
	//expr2 dev'essere di tipo boolean
	if (schema_expr2->type != BOOLEAN)
		semerror(join_expr_node,"Expected boolean type");
	

	//Genero il codice
	int gap = expr_code2.size;
	join_code = concode(
				expr_code1,
				expr_code3,
				makecode1(T_JOIN,gap),
				expr_code2,
				makecode1(T_ENDJOIN,gap),
				endcode());
	//Faccio il pop del context
	pop_context();
#ifdef DEBUG_JOIN_EXPR
	printf("JOIN_EXPR - exit\n");
#endif
	return join_code;
}



/*Genera il codice della expr e lo schema risultante*/
Code extend_expr(Pnode extend_expr_node, Pschema extend_expr_schema){
#ifdef DEBUG_EXTEND_EXPR
	printf("EXTEND_EXPR - enter\n");
#endif
	//Definisco i figli del nodo
	Pnode expr1_node = extend_expr_node->child;
	Pnode atomic_type_node = extend_expr_node->child->brother;
	Pnode id_node = extend_expr_node->child->brother->brother;
	Pnode expr2_node = extend_expr_node->child->brother->brother->brother;

	//Preparo la variabile che contiene il codice
	Code extend_code;
	
	//Creo lo schema per le due expr
	Pschema schema_expr1 = (Pschema) newmem(sizeof(Schema));
	Pschema schema_expr2 = (Pschema) newmem(sizeof(Schema));

	//Calcolo il codice di expr1
	Code expr_code1 = expr(expr1_node,schema_expr1);

	//Controllo la semantica per expr1
	//expr1 dev'essere di tipo tabella
	if (schema_expr1->type != TABLE)
		semerror(extend_expr_node,"Expected table type");
	//id non deve appartenere all'elenco degli attributi di expr1
	Pschema schema_id = name_in_schema(valname(id_node),schema_expr1);
	if (schema_id != NULL)
		semerror(extend_expr_node,"Attribute already exists in table");

	//Faccio il push del context
	push_context(schema_expr1->next);
	
	//Calcolo il codice di expr2
	Code expr_code2 = expr(expr2_node,schema_expr2);

	//Controllo la semantica per expr2
	//Calcolo il tipo dell'elemento
	Pschema	atomic_type_schema = atomic_type(atomic_type_node);

	//il tipo di expr2 dev'essere uguale al tipo di atomic type
	if (!type_equal(*schema_expr2, *atomic_type_schema))
		semerror(extend_expr_node,"Different types");
		
	//Definisco il nuovo schema
	//Aggiorno lo schema di type
	atomic_type_schema->name = valname(id_node);
	//Appendo lo schema del nuovo attributo a quello della tabella
	schema_copy(append_schemas(clone_schema(schema_expr1),clone_schema(atomic_type_schema)),extend_expr_schema);
	
	//Genero il codice
	int gap = expr_code2.size;
	int size = get_size(atomic_type_schema);
	extend_code = concode(
				expr_code1,
				makecode2(T_EXT,size,gap),
				expr_code2,
				makecode1(T_ENDEXT,gap),
				endcode());
	//Pop context
	pop_context();	

#ifdef DEBUG_EXTEND_EXPR
	printf("EXTEND_EXPR - exit\n");
#endif

	return extend_code;
}



/*Genera il codice per il caricamento di una variabile booleana*/
Code bool_const(Pnode bool_const_node,Pschema schema){
	schema->type = BOOLEAN;
	if (bool_const_node->value.ival == TRUE)
		return make_ldint(1);
	else 
		return make_ldint(0);
}



/*Genera il codice per il caricamento di una variabile stringa*/
Code str_const(Pnode str_const_node,Pschema schema){
	schema->type = STRING;
	return make_ldstr(valname(str_const_node));
}



/*Genera il codice per il caricamento di una variabile intera*/
Code int_const(Pnode int_const_node,Pschema schema){
	schema->type = INTEGER;
	return make_ldint(int_const_node->value.ival);
}


/*Genera il codice per il caricamento dell'id e ritorna lo schema*/
Code id_expr(Pnode id_node,Pschema schema){
#ifdef DEBUG_ID
	printf("ID_EXPR - enter\n");
	
#endif
	//Cerca il simbolo nello stack dei contesti
	int context_offset,attribute_context;
	Pschema schema_context = name_in_constack(valname(id_node),&context_offset,&attribute_context);

	if (schema_context != NULL){
		//Copio lo schema
		schema_copy(clone_schema(schema_context),schema);
		//Ritorno il codice
		return makecode3(T_LAT,context_offset,attribute_context,get_size(schema));
	}
	else {
		//Altrimenti
		//Cerca il simbolo nella tabella dei simboli
		Psymbol symbol = lookup(valname(id_node));
		if(symbol == NULL)
			semerror(id_node,"Variable not found in stack");
		//imposto lo schema
		schema_copy(clone_schema(&(symbol->schema)),schema);

#ifdef DEBUG_ID
	printf("ID_EXPR - exit\n");
#endif
		//Ritorno il codice
		return makecode1(T_LOB,symbol->oid);
	}
}



/*Genera il codice per la creazione della tabella e ritorna lo schema della tabella*/
Code table_const(Pnode table_const_node, Pschema schema_tabella){
	//Il codice per la costante tupla dipende dal fatto che la tabella sia vuota o meno
#ifdef DEBUG_TABLE_CONST
	printf("DEBUG_TABLE_CONST - enter\n");
#endif
	//Preparo il codice della tabella
	Code table_const_code ;
	table_const_code.head = NULL;
	table_const_code.tail = NULL;
	table_const_code.size = 0;

	//Preparo il codice della tuple_list
	Code tuple_list_code ;

	//Testo se la tabella è vuota
	Pnode first_attribute = table_const_node->child;
	
	//Imposto il tipo dello schema
	schema_tabella->type = TABLE;

	if (first_attribute->type == N_ATOMIC_TYPE){
		//calcolo lo schema della tabella
		//calcolo lo schema del primo attributo
		Pschema schema_first_attr = atomic_type(first_attribute);
		//lo aggiungo in coda a tabella
		schema_tabella->next = schema_first_attr;		
		//se ci sono altri attributi, aggiungo altri schemi
		Pnode attr_node = first_attribute->brother;
		Pschema prev_attr_schema = schema_first_attr;
		while (attr_node != NULL){
			prev_attr_schema->next = atomic_type(attr_node);
			prev_attr_schema = prev_attr_schema->next;
			attr_node = attr_node->brother;
		}
		//Estraggo la dimensione dello schema di attributi
		int size = get_size(schema_tabella);
		//Genero il codice nel caso di tabella vuota
		table_const_code = appcode(makecode2(T_LDTAB,size,0),makecode(T_ENDTAB));
	}
	else {
		//calcolo la lista di tuple della tabella
		//Punto alla prima tupla
		Pnode first_tuple = table_const_node->child;

		//Calcolo il codice della prima tupla
		Pschema first_tupla_schema = (Pschema) newmem(sizeof(Schema));
		Code tuple_list_code = tuple_const(first_tuple,first_tupla_schema);
#
		//Imposto lo schema della tupla in coda alla tabella
		schema_tabella->next = first_tupla_schema;		

		int tuple_number = 1;
		
		//Aggiungo il codice e lo schema della tabella
		Pnode tuple_node = first_tuple->brother;

		while(tuple_node != NULL){
			//Calcolo il codice e lo schema della tupla
			Pschema schema_tupla = (Pschema) newmem(sizeof(Schema));

			Code tuple_code = tuple_const(tuple_node,schema_tupla);

			//Controllo i vincoli semantici
			//Controllo che gli schemi siano compatibili
			Pschema p1 = first_tupla_schema;
			Pschema p2 = schema_tupla;
			while (p1!=NULL){
				if (!type_equal(*p1,*p2))
					semerror(tuple_node,"Incompatible tuple in table");
				p1=p1->next;
				p2=p2->next;		
			}
			//Appendo il codice della tupla a quello della lista di tuple
			tuple_list_code = appcode(tuple_list_code,tuple_code);
			//Passo al fratello successivo
			tuple_node = tuple_node->brother;

			//Aggiorno il numero di tuple
			tuple_number++;	
		}
		int size = get_size(schema_tabella);

		//Creo il codice per la generazione della tabella
		table_const_code = concode(makecode2(T_LDTAB,size,tuple_number),tuple_list_code,makecode(T_ENDTAB),endcode());

	}
#ifdef DEBUG_TABLE_CONST
	printf("DEBUG_TABLE_CONST - exit\n");
#endif

	return table_const_code;
}



