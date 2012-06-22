#include "def.h"
#include "parser.h"
#include <string.h>


void semerror(Pnode p, char *message)
{
  printf("Line %d: %s\n", p->line, message);
  exit(-1);
}



int qualifier(Pnode p)
{
  return (p->value.ival);
}



char *valname(Pnode p)
{
  return (p->value.sval);
}



/*Genera il codice per il nodo program*/
Code program(Pnode root){
	Code body = stat_list(root->child);	  
	return concode(makecode1(T_TCODE, body.size + 2), body, makecode(T_HALT), endcode());
}


//-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^


/*Genera il codice per il nodo stat_list e crea lo scope del programma*/
Code stat_list(Pnode p){
	Code stat_list_code = NULL;
	/*creo l'ambiente del programma*/
	push_environment();
	stat_node = p->child;
	/*Ciclo fino a che i figli di stat_list non sono terminati*/
	while (p!=NULL){
		/*Creo il codice di un figlio di stat_list_code*/
		Code stat_code = NULL;
		switch (p->type){
			case(N_DEF_STAT): 	stat_code = def_stat(p);
			case(N_ASSIGN_STAT): 	stat_code = assign_stat(p);
			case(N_IF_STAT): 	stat_code = if_stat(p);
			case(N_WHILE_STAT): 	stat_code = while_stat(p);
			case(N_READ_STAT): 	stat_code = read_stat(p);
			case(N_WRITE_STAT): 	stat_code = write_stat(p);
		}
		/*Appendo il codice a stat_list_code*/
		stat_list_code = appcode(stat_list_code,stat_code);
		/*Punto al fratello successivo*/
		p=p->brother;
	}
	//return stat_list_code;
	return "";
}



/*Genera il codice per il nodo def_stat e controlla i vincoli semantici*/
Code def_stat(Pnode p){
	Code def_stat_code = NULL;
	int var_type;
	/*Prendo il tipo dell'espressione e genero il codice per il tipo*/
	Pschema next_schema;
	Code type_code = type(p->child,var_type,next_schema);
			
	Code id_list_code = NULL;
	/*Analizzo gli id*/
	Pnode t = p->child->brother;
	for (t; t!=NULL ; t=t->brother ){
		Code id_code = NULL;
		/*Verifico che i nomi non siano ripetuti*/
		for (s=t->brother;s!=NULL;s=s->brother)
			if (strcmp(valname(s),valname(p))) 
				semerror(t,"più variabili con lo stesso id");
		/*Verifico che il nome non sia già presente nell'ambiente altrimenti lo inserisco*/
		if (name_in_environment(name(t)))
			semerror(t,"variabile già assegnata");
		else {	
			/*Creo lo schema e lo inserisco nella tabella*/
			Pschema toInsert = newschema(name(t),var_type);
			//Se è un tipo tabella, il next punterà a una lista di schemi
			if (next_schema!=NULL)
				toInsert->next = next_schema;
			insert(toInsert);
			/*Creo il codice per l'id*/
		}
		/*Appendo a def_stat_code l'id_code*/
		def_stat_code = appcode(def_stat_code,id_code);
	}	
	return "";
}



/*Ritorna il codice del type, il tipo e il puntatore al prossimo schema, che sarà nullo nel caso di tipi semplici, e non nullo per tipi tabella*/
Code type(Pnode type_node, int *tipo,  Pschema next){
	/*Imposto il next e il code*/
	Code code;
	Pschema schema_type = (Pschema) newmem(sizeof(Schema));
	if (type_node->type == N_ATOMIC_TYPE){
		code = atomic_type(type->node,schema_type);
	}
	else {//table type
		*tipo = qualifier(type_node)
		code = attr_list(type_node->child,next);
	}
	return code;
}



/*Ritorno il codice dello schema e il puntatore */
Code attr_list(Pnode attr_list_node, Pschema next){
	Code attr_list_code = NULL;
	//Sintetizzo il tipo della variabile
	int tipo = atomic_type(attr_list_node->child);
	
	//Inserisco nel contesto i tipi delle variabili
	Pnode first_id = attr_list_node->child->brother;
	while (Pnode id=first_id;id!=NULL;id=id->brother){
		//se la variabile è presente già nel contesto, genero l'errore, altrimenti la aggiungo al contesto
		if (name_in_constack(name(id))!=NULL)
			semerror(id,"Variabile già presente");
		else {
			//Genero il Pschema
			Pschema id_schema = newschema(name(id),tipo);
			//Aggiungo il Pschema al contesto
			push_context(id_schema);
			//Genero il codice
		}
	}
	return "";
}



/*Ritorna il codice e imposta il tipo nel campo type di schema*/
Code atomic_type(Pnode atomic_type_node,Pschema schema){
	Code atomic_type = NULL;
	schema->type = qualifier(atomic_type_node);
	return NULL;
}



/**/
Code assign_stat(Pnode assign_stat_node){
	Pnode id_node = assign_stat_node->child;
	Pnode expr_node = assign_stat_node->child->brother;
	Code assign_code;
	if (!name_in_environment(name(id_node)))
		semerror(id_node,"variabile non definita");
	else {
		Pschema schema_expr = (Pschema) newmem(sizeof(Schema));
		Code expr(expr_node,schema_expr);
		if (!type_equal(id_node,schema_expr))
			semerror(assign_stat_node,"id e expr non hanno lo stesso tipo");
		else {
			//genero il codice
			code = NULL;
		}	
	}
	return code;
}



/**/
Code if_stat(Pnode if_stat_node){
	//Imposto le tre parti del nodo	
	expr_node = if_stat_node->child;
	then_part = if_stat_node->child->brother;
	else_part = if_stat_node->child->brother->brother;
	
	Code if_stat_code = NULL;

	Pschema schema_expr = (Pschema) newmem(sizeof(Schema));
	Code expr_code = expr(expr_node,schema_expr);
	
	if (schema_expr->type!=BOOLEAN)
		semerror(expr_node,"il risultato dell'espressione dev'essere booleano");
	else {
		//Genero il codice dell'espressione
		
	}
	return if_stat_code;
}




/**/
Code read_stat(Pnode read_stat_node){
	//Imposto le due parti del nodo
	specifier = read_stat_node->child;
	id = read_stat_node->child->brother;
	Code read_stat_code = NULL;
	//Calcolo il codice di specifier
	Pschema schema_specifier = (Pschema) newmem(sizeof(Schema));
	specifier_code = specifier(specifier,schema_specifier);
	if (schema_specifier->type != STRING) || schema_specifier->type != NULL)
		semerror(read_stat,"Expected string type");
	else {
		//Genero il codice di readstat
		
	}
	return read_stat_code;
}



/**/
Code while_stat(Pnode while_stat_node){
	//Imposto le due parti del nodo	
	expr_node = if_stat_node->child;
	stat_list_part = if_stat_node->child->brother;
	
	Code while_stat_node = NULL;

	Pschema schema_expr = (Pschema) newmem(sizeof(Schema));
	Code expr_code = expr(expr_node,schema_expr);
	
	if (schema_expr->type!=BOOLEAN)
		semerror(expr_node,"il risultato dell'espressione dev'essere booleano");
	else {
		//Genero il codice dell'espressione
		
	}
	return while_stat_node;
}



/**/
Code write_stat(Pnode write_stat_node){
	//Imposto le due parti del nodo
	specifier = write_stat_node->child;
	expr = write_stat_node->child->brother;
	Code write_stat_code = NULL;
	
	//Calcolo il codice di specifier
	Pschema schema_specifier = (Pschema) newmem(sizeof(Schema));
	specifier_code = specifier(specifier,schema_specifier);
	if (schema_specifier->type != STRING) || schema_specifier->type != NULL)
		semerror(read_stat,"Expected string type");
	else {
		//Genero il codice di readstat
		
	}
	return write_stat_code;
}



/**/
Code bool_const(){}
/**/
Code str_const(){}
/**/
Code int_const(){}


/**/    
Code id(){}


/**/
Code specifier(Pnode specifier_node, Pschema schema){
	Code specifier_code = NULL;
	Pnode expr_node = specifier_node->child;
	if (expr_node==NULL){
		schema->type = NULL;
	}
	else {
		Code expr_code = expr(expr_node,schema);
	}
	return specifier_code;
}


/**/
Code table_const(){
	//No vincoli semantici ??
}

/**/
Code tuple_const(){
	//No vincoli semantici
}

/**/
Code table_type(){}



