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
	//Prende body, gli mette TCODE prima e THALT dopo.	  
	return concode(makecode1(T_TCODE, body.size + 2), body, makecode(T_HALT), endcode());
}


//-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^



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




//^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-




/*Controlla la semantica della read e ritorna il codice della read*/
Code read_stat(Pnode read_stat_node){
	//Imposto le due parti del nodo
	specifier_node = read_stat_node->child;
	id_node = read_stat_node->child->brother;
	
	//Definisco il codice del nodo
	Code read_stat_code = NULL;

	//Calcolo il codice di specifier
	Pschema schema_specifier = (Pschema) newmem(sizeof(Schema));
	specifier_code = specifier(specifier_node,schema_specifier);

	//Controllo che non ci siano errori semantici
	//Controllo che il tipo di specifier sia corretto
	if (schema_specifier->type != STRING && schema_specifier->type != NULL)
		semerror(read_stat_node,"Expected string type");
	//Controllo che il nome dell'id sia visibile
	if (!name_in_environment(name(id_node)))
		semerror(id_node,"Variable not defined");

	//Genero il codice di readstat
	//La sintassi della read dipende dalla presenza dello specifier
	Psymbol symbol = lookup(name(id_node));
	if (specifier_node->child == NULL)		
		read_stat_code = make_get_fget(T_GET,symbol->oid,get_format(name(symbol->type)))
	else
		read_stat_Code = appcode(specifier_code,make_get_fget(T_FGET,symbol->oid,get_format(name(symbol->type)));

	return read_stat_code;
}



/*Controlla la semantica della write e ne ritorna il codice*/
Code write_stat(Pnode write_stat_node){
	//Imposto le due parti del nodo
	specifier_node = write_stat_node->child;
	expr_node = write_stat_node->child->brother;

	//Definisco la variabile che contiene il codice da ritornare
	Code write_stat_code = NULL;
	
	//Calcolo il codice di specifier
	Pschema schema_specifier = (Pschema) newmem(sizeof(Schema));
	specifier_code = specifier(specifier_node,schema_specifier);

	//Controllo che non ci siano errori semantici
	//Controllo che il tipo di specifier sia corretto
	if (schema_specifier->type != STRING && schema_specifier->type != NULL)
		semerror(read_stat_node,"Expected string type");

	//Genero il codice di write_stat
	//Genero il codice di expr
	Pschema schema_expr = (Pschema) newmem(sizeof(Schema));
	expr_code = expr(expr_node,schema_expr);

	//La sintassi della write dipende dalla presenza dello specifier
	if (specifier_node->child == NULL)
		write_stat_code = appcode(expr_code,make_print_fprint(T_PRINT,get_format(schema_expr)));
	else
		write_stat_code = concode(expr_code,specifier_code,make_print_fprint(T_FPRINT,get_format(schema_expr)),endcode());

	return write_stat_code;
}


/*Controlla la semantica del nodo while e ne restituisce il codice*/
Code while_stat(Pnode while_stat_node){
	//Imposto le due parti del nodo	
	expr_node = while_stat_node->child;
	stat_list_code = while_stat_node->child->brother;

	//Definisco la variabile che contiene il codice da ritornare
	Code while_stat_node = NULL;

	//La generazione dell'ambiente viene fatta all'interno della funzione stat_list

	//Genero il codice di expr
	Pschema schema_expr = (Pschema) newmem(sizeof(Schema));
	Code expr_code = expr(expr_node,schema_expr);
	
	//Controllo i vincoli semantici
	if (schema_expr->type!=BOOLEAN)
		semerror(expr_node,"il risultato dell'espressione dev'essere booleano");
	
	//Genero il codice di stat_list
	Code stat_list_code = stat_list(stat_list_code);
	//Calcolo gli offset
	int exit = stat_list_code->size + 2;
	int up = schema_expr->size + stat_list_code->size + 1;
	
	//Genero il codice di while_stat
	while_stat_node = concode(expr_code,makecode1(T_SKIPF,exit),stat_list_code,makecode1(T_SKIP,up),endcode());

	return while_stat_node;
}



/*Controlla la semantica del nodo if e ne ritorna il codice*/
Code if_stat(Pnode if_stat_node){
	//Imposto le tre parti del nodo	
	expr_node = if_stat_node->child;
	then_node = if_stat_node->child->brother;
	else_node = if_stat_node->child->brother->brother;
	
	//Definisco la variabile che contiene il codice da ritornare
	Code if_stat_code = NULL;

	//La generazione dell'ambiente viene fatta all'interno della funzione stat_list
	
	//Genero il codice di expr
	Pschema schema_expr = (Pschema) newmem(sizeof(Schema));
	Code expr_code = expr(expr_node,schema_expr);
	
	//Controllo i vincoli semantici
	if (schema_expr->type!=BOOLEAN)
		semerror(expr_node,"il risultato dell'espressione dev'essere booleano");

	//Genero il codice di then_node
	then_code = stat_list(then_node);
	
	if (else_node==NULL){//if then endif
		//Calcolo l'offset
		int offset = then_code->size + 1;
		//Genero il codice di if_stat
		if_stat_code = concode(expr_code,makecode1(T_SKIPF,offset),then_code,endcode());
	}
	else {//if then else
		//Genero il codice di else_node
		else_code = stat_list(else_node);
		//Calcolo gli offset
		int offset_then = then_code->size + 2;
		int offset_else = else_code->size + 1;
		//Genero il codice di if_stat
		if_stat_code = concode(expr_code,makecode1(T_SKIPF,offset_then),then_code,makecode1(T_SKIP,offset_else),else_code,endcode());

	}
	
	return if_stat_code;
}



/*Genera il codice per il nodo def_stat e controlla i vincoli semantici*/
Code def_stat(Pnode def_stat_node){
	//Imposto le due parti del nodo	
	Pnode type_node = def_stat_node->child;
	Pnode id_list_head_node = def_stat_node->child->brother;
 
	//Definisco la variabile che contiene il codice da ritornare	
	Code def_stat_code = NULL;

	//Sintetizzo il type
	Pschema schema_type = type(type_node);
	//Ottengo la id_list
	int id_list_len;
	Pname id_list_name = id_list(id_list_head_node,&id_list_len);
	
	//Controllo gli errori semantici
	//id ripetuti	
	if (repeated_names(id_list_name))
		semerror("id ripetuti");
	//variabili già assegnate
	for (Pnode id_node = id_list_head_node; id_node!=NULL; id_node=id_node->brother)
		if (name_in_environment(valname(id_node)))
			semerror(id_node,"variabile già definita");

		
	//Genero il codice per la definizione delle variabili
	for (Pnode id_node = id_list_head_node; id_node!=NULL; id_node=id_node->brother){
		//Genero il codice dell'id
		Code id_code = NULL;
		int spazio_da_allocare = get_size(schema_type);
		if (schema_type->type == TABLE)
			id_code = makecode1(T_NEWTAB,spazio_da_allocare);
		else		
			id_code = makecode1(T_NEWATOM,spazio_da_allocare);
		//Appendo a def_stat_code l'id_code
		def_stat_code = appcode(def_stat_code,id_code);
	}
	
	return def_stat_code;
}



/*Ritorna lo schema e imposta il tipo nel campo type di schema*/
Pschema atomic_type(Pnode atomic_type_node){
	//Creo lo schema
	Pschema schema = (Pschema) newmem(sizeof(Schema));
	//Imposto tutti i campi a null
	schema->name = NULL;
	schema->next = NULL;
	//Imposto il type
	schema->type = qualifier(atomic_type_node);
	return schema;
}



/*Ritorna lo schema del type.
Il puntatore allo schema successivo che sarà NULL nel caso di tipi semplici, e non nullo per tipi tabella*/
Pschema type(Pnode type_node){
	if (type_node->type == N_ATOMIC_TYPE)
		return atomic_type(type_node);
	else 		
		return table_type(type_node);
}


/*
Ritorna lo schema del table_type.
*/
Pschema table_type(Pnode type_node){
	//Creo lo schema
	Pschema schema = (Pschema) newmem(sizeof(Schema));
	//Imposto tutti i campi a null
	schema->name = NULL;
	schema->next = NULL;
	//Imposto il type (che sarà TABLE)
	schema->type = qualifier(type_node);
	
	//Imposto i tipi semplici
	"//TODO: analizzare gli attributi del table type (eventualmente creare un nuovo contesto - prob no)"
	return schema;
}



/*Riceve la testa della id_list e ritorna una lista di nomi più il numero di id presenti nella lista*/
Pname id_list(Pnode id_list_head, int *length){
	Pname head_name,id_name,prev_name;
	
	//Creo head_name e ne imposto i campi
	head_name = (Pname) newmem(sizeof(Name)); 
	head_name->name = valname(id);
	head_name->next = NULL;

	//Imposto il numero di id a 1
	*length = 1;
	
	//Punto al secondo id
	Pnode id = id_list_head->brother;

	//Salvo l'indirizzo di prev_name
	prev_name = head_name;
	while(id != NULL) {
		//Creo un nodo pname
		id_name = (Pname) newmem(sizeof(Name));

		//Imposto valname e next
		id_name->name = valname(id);
		id_name->next = NULL;
	
		//Imposto il puntatore al prossimo elemento della lista
		prev_name->next = id_name;

		//Incremento il numero di id
		*length = *length + 1;
		//Passo all'id successivo
		id = id->brother;
		//Prev_name punta all'ultimo nome nella lista
		prev_name = id_name;
	}
	return head_name;
}



/*Genera il codice per il caricamento di una variabile booleana*/
Code bool_const(Pnode bool_const_node){
	if (bool_const_node->ival == TRUE)
		return make_ldint(1);
	else 
		return make_ldint(0);
}



/*Genera il codice per il caricamento di una variabile stringa*/
Code str_const(Pnode str_const_node){
	return make_ldstr(valname(str_const_node));
}



/*Genera il codice per il caricamento di una variabile intera*/
Code int_const(Pnode int_const_node){
	return make_ldint(bool_const_node->ival);
}



/*Genera il codice per il nodo stat_list e crea lo scope del programma*/
Code stat_list(Pnode stat_list_node){
	//Definisco la variabile che contiene il codice da ritornare
	Code stat_list_code = NULL;

	//Creo l'ambiente del programma
	push_environment();
	
	//Punto al primo stat
	stat_node = stat_list_node->child;
	//Ciclo lungo tutti gli stat_node
	while (stat_node!=NULL){
		//Creo il codice dello stat_node
		Code stat_code = NULL;
		switch (p->type){
			case(N_DEF_STAT): 	stat_code = def_stat(stat_node);
			case(N_ASSIGN_STAT): 	stat_code = assign_stat(stat_node);
			case(N_IF_STAT): 	stat_code = if_stat(stat_node);
			case(N_WHILE_STAT): 	stat_code = while_stat(stat_node);
			case(N_READ_STAT): 	stat_code = read_stat(stat_node);
			case(N_WRITE_STAT): 	stat_code = write_stat(stat_node);
		}
		/*Appendo il codice a stat_list_code*/
		stat_list_code = appcode(stat_list_code,stat_code);
		/*Punto al fratello successivo*/
		stat_node=stat_node->brother;
	}
	
	//elimino l'ambiente creato
	pop_environment();

	return stat_list_code;
}
