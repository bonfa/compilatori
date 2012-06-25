#include "def.h"
#include "parser.h"
#include <string.h>

#define NIHIL -1

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


//^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-


/*Controlla la semantica della read e ritorna il codice della read*/
Code read_stat(Pnode read_stat_node){
	//Imposto le due parti del nodo
	Pnode specifier_node = read_stat_node->child;
	Pnode id_node = read_stat_node->child->brother;
	
	//Definisco il codice del nodo
	Code read_stat_code;

	//Calcolo il codice di specifier
	Pschema schema_specifier = (Pschema) newmem(sizeof(Schema));
	Code specifier_code = specifier(specifier_node,schema_specifier);

	//Controllo che non ci siano errori semantici
	//Controllo che il tipo di specifier sia corretto
	if ((schema_specifier->type != STRING) && (schema_specifier->type != NIHIL))
		semerror(read_stat_node,"Expected string type");
	//Controllo che il nome dell'id sia visibile
	if (!name_in_environment(valname(id_node)))
		semerror(id_node,"Variable not defined");

	//Genero il codice di readstat
	//La sintassi della read dipende dalla presenza dello specifier
	Psymbol symbol = lookup(valname(id_node));
	if (specifier_node->child == NULL)		
		read_stat_code = make_get_fget(T_GET,symbol->oid,get_format((symbol->schema)));
	else
		read_stat_code = appcode(specifier_code,make_get_fget(T_FGET,symbol->oid,get_format((symbol->schema))));

	return read_stat_code;
}



/*Controlla la semantica della write e ne ritorna il codice*/
Code write_stat(Pnode write_stat_node){
	//Imposto le due parti del nodo
	Pnode specifier_node = write_stat_node->child;
	Pnode expr_node = write_stat_node->child->brother;

	//Definisco la variabile che contiene il codice da ritornare
	Code write_stat_code;
	
	//Calcolo il codice di specifier
	Pschema schema_specifier = (Pschema) newmem(sizeof(Schema));
	Code specifier_code = specifier(specifier_node,schema_specifier);

	//Controllo che non ci siano errori semantici
	//Controllo che il tipo di specifier sia corretto
	if (schema_specifier->type != STRING && schema_specifier->type != NIHIL)
		semerror(write_stat_node,"Expected string type");

	//Genero il codice di write_stat
	//Genero il codice di expr
	Pschema schema_expr = (Pschema) newmem(sizeof(Schema));
	Code expr_code = expr(expr_node,schema_expr);

	//La sintassi della write dipende dalla presenza dello specifier
	if (specifier_node->child == NULL)
		write_stat_code = appcode(expr_code,make_print_fprint(T_PRINT,get_format(*schema_expr)));
	else
		write_stat_code = concode(expr_code,specifier_code,make_print_fprint(T_FPRINT,get_format(*schema_expr)),endcode());

	return write_stat_code;
}


/*Controlla la semantica del nodo while e ne restituisce il codice*/
Code while_stat(Pnode while_stat_node){
	//Imposto le due parti del nodo	
	Pnode expr_node = while_stat_node->child;
	Pnode stat_list_node = while_stat_node->child->brother;

	//Definisco la variabile che contiene il codice da ritornare
	Code while_stat_code;

	//La generazione dell'ambiente viene fatta all'interno della funzione stat_list

	//Genero il codice di expr
	Pschema schema_expr = (Pschema) newmem(sizeof(Schema));
	Code expr_code = expr(expr_node,schema_expr);
	
	//Controllo i vincoli semantici
	if (schema_expr->type!=BOOLEAN)
		semerror(expr_node,"il risultato dell'espressione dev'essere booleano");
	
	//Genero il codice di stat_list
	Code stat_list_code = stat_list(stat_list_node);
	//Calcolo gli offset
	int exit = stat_list_code.size + 2;
	int up = expr_code.size + stat_list_code.size + 1;
	
	//Genero il codice di while_stat
	while_stat_code = concode(expr_code,makecode1(T_SKIPF,exit),stat_list_code,makecode1(T_SKIP,up),endcode());

	return while_stat_code;
}



/*Controlla la semantica del nodo if e ne ritorna il codice*/
Code if_stat(Pnode if_stat_node){
	//Imposto le tre parti del nodo	
	Pnode expr_node = if_stat_node->child;
	Pnode then_node = if_stat_node->child->brother;
	Pnode else_node = if_stat_node->child->brother->brother;
	
	//Definisco la variabile che contiene il codice da ritornare
	Code if_stat_code ;

	//La generazione dell'ambiente viene fatta all'interno della funzione stat_list
	
	//Genero il codice di expr
	Pschema schema_expr = (Pschema) newmem(sizeof(Schema));
	Code expr_code = expr(expr_node,schema_expr);
	
	//Controllo i vincoli semantici
	if (schema_expr->type!=BOOLEAN)
		semerror(expr_node,"il risultato dell'espressione dev'essere booleano");

	//Genero il codice di then_node
	Code then_code = stat_list(then_node);
	
	if (else_node==NULL){//if then endif
		//Calcolo l'offset
		int offset = then_code.size + 1;
		//Genero il codice di if_stat
		if_stat_code = concode(expr_code,makecode1(T_SKIPF,offset),then_code,endcode());
	}
	else {//if then else
		//Genero il codice di else_node
		Code else_code = stat_list(else_node);
		//Calcolo gli offset
		int offset_then = then_code.size + 2;
		int offset_else = else_code.size + 1;
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
	Code def_stat_code ;

	//Sintetizzo il type
	Pschema schema_type = type(type_node);
	//Ottengo la id_list
	int id_list_len;
	Pname id_list_name = id_list(id_list_head_node,&id_list_len);
	
	//Controllo gli errori semantici
	//id ripetuti	
	if (repeated_names(id_list_name))
		semerror(def_stat_node,"id ripetuti");
	//variabili già assegnate
	Pnode id_node;
	for (id_node = id_list_head_node; id_node!=NULL; id_node=id_node->brother)
		if (name_in_environment(valname(id_node)))
			semerror(id_node,"variabile già definita");

		
	//Genero il codice per la definizione delle variabili
	for (id_node = id_list_head_node; id_node!=NULL; id_node=id_node->brother){
		//Genero il codice dell'id
		Code id_code ;
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
	schema->name = NULL;

	//Imposto il type (che sarà TABLE)
	schema->type = qualifier(type_node);
	
	//Genero la lista di attributi
	schema->next = attr_list(type_node->child);
	
	return schema;
}



/*Riceve la testa della id_list e ritorna una lista di nomi più il numero di id presenti nella lista*/
Pname id_list(Pnode id_list_head, int *length){
	Pname head_name,id_name,prev_name;
	
	//Creo head_name e ne imposto i campi
	head_name = (Pname) newmem(sizeof(Name)); 
	head_name->name = valname(id_list_head);
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
	if (bool_const_node->value.ival == TRUE)
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
	return make_ldint(int_const_node->value.ival);
}



/*Genera il codice per il nodo stat_list e crea lo scope del programma*/
Code stat_list(Pnode stat_list_node){
	//Definisco la variabile che contiene il codice da ritornare
	Code stat_list_code ;

	//Creo l'ambiente del programma
	push_environment();
	
	//Punto al primo stat
	Pnode stat_node = stat_list_node->child;
	//Ciclo lungo tutti gli stat_node
	while (stat_node!=NULL){
		//Creo il codice dello stat_node
		Code stat_code ;
		switch (stat_node->type){
			case(N_DEF_STAT): 	stat_code = def_stat(stat_node);break;
			case(N_ASSIGN_STAT): 	stat_code = assign_stat(stat_node);break;
			case(N_IF_STAT): 	stat_code = if_stat(stat_node);break;
			case(N_WHILE_STAT): 	stat_code = while_stat(stat_node);break;
			case(N_READ_STAT): 	stat_code = read_stat(stat_node);break;
			case(N_WRITE_STAT): 	stat_code = write_stat(stat_node);break;
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



/*Controlla i vincoli semantici dell'assegnamento e ne ritorna il codice*/
Code assign_stat(Pnode assign_stat_node){
	//Imposto le due parti del nodo	
	Pnode id_node = assign_stat_node->child;
	Pnode expr_node = assign_stat_node->child->brother;

	//Definisco la variabile che contiene il codice da ritornare
	Code assign_stat_code ;
	
	//Controllo i vincoli semantici
	//Visibilità del nome
	if (!name_in_environment(valname(id_node)))
		semerror(id_node,"undefined variabile");
	//Compatibilità degli schemi
	Pschema schema_expr = (Pschema) newmem(sizeof(Schema));
	Code expr_code = expr(expr_node,schema_expr);

	Psymbol symbol = lookup(valname(id_node)); 
	if (!type_equal((symbol->schema),*(schema_expr)))
		semerror(assign_stat_node,"id e expr non hanno lo stesso tipo");

	//Genero il codice
	assign_stat_code = appcode(expr_code,makecode1(T_STO,symbol->oid));

	return assign_stat_code;
}



/*Genera lo schema della tupla e ritorna il codice*/
Code tuple_const(Pnode tuple_const_node,Pschema schema){
	//Non ci sono vincoli semantici

	//Preparo il codice della tupla
	Code tuple_const_code;

	//Punto al primo elemento della tupla
	Pnode atomic_const_node = tuple_const_node->child;

	//Preparo la variabile che contiene il codice dell'id
	Code atomic_const_code;
	
	do{
		//Calcolo il codice della prima costante
		switch(atomic_const_node->type){
		case (N_INTCONST): 
		case (N_BOOLCONST):	atomic_const_code = makecode1(T_IATTR,atomic_const_node->value.ival);
					break;	
		case (N_STRCONST):	atomic_const_code = make_sattr(atomic_const_node->value.sval);
					break;
		}	
		//Appendo il codice della costante al codice della tupla
		tuple_const_code = appcode(tuple_const_code,atomic_const_code);
		
		//Passo al fratello
		atomic_const_node = atomic_const_node->brother;	
	}while(atomic_const_node!=NULL);

	return tuple_const_code;
}



/*Genera il codice per la creazione della tabella e ritorna lo schema della tabella*/
Code table_const(Pnode table_const_node, Pschema schema_tabella){
	//Il codice per la costante tupla dipende dal fatto che la tabella sia vuota o meno

	//Preparo il codice della tabella
	Code table_const_code ;

	//Preparo il codice della tuple_list
	Code tuple_list_code ;

	//Testo se la tabella è vuota
	Pnode first_attribute = table_const_node->child;
	if (first_attribute->type == N_ATOMIC_TYPE){
		//calcolo lo schema della tabella
	
		//calcolo lo schema del primo attributo
		schema_tabella = atomic_type(first_attribute);
		
		//se ci sono altri attributi, aggiungo altri schemi
		Pnode attr_node = first_attribute->brother;
		Pschema attr_schema = schema_tabella->next;
		while (attr_node != NULL){
			attr_schema = atomic_type(attr_node);
			attr_schema = attr_schema->next;
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
		
		int tuple_number = 1;
		
		//Aggiungo il codice e lo schema della tabella
		Pnode tuple_node = first_tuple->brother;
		
		while(tuple_node != NULL){
			//Calcolo il codice e lo schema della tupla
			Pschema schema_tupla = (Pschema) newmem(sizeof(Schema));
			Code tuple_code = tuple_const(tuple_node,schema_tupla);

			//Controllo i vincoli semantici
			//Controllo che gli schemi siano compatibili
			if (!type_equal(*first_tupla_schema,*schema_tupla))
				semerror(tuple_node,"Incompatible tuple in table");
	
			//Appendo il codice della tupla a quello della lista di tuple
			tuple_list_code = appcode(tuple_list_code,tuple_code);
			//Passo al fratello successivo
			tuple_node = tuple_node->brother;

			//Aggiorno il numero di tuple
			tuple_number++;	
		}
		int size = get_size(first_tupla_schema);
		//Creo il codice per la generazione della tabella
		table_const_code = concode(makecode2(T_LDTAB,size,tuple_number),tuple_list_code,makecode(T_ENDTAB),endcode());
	}

	return table_const_code;
}




/*Genera il codice dello specifier e ne ritorna lo schema.
Lo schema dello specifier può essere una costante stringa o NULL*/
Code specifier(Pnode specifier_node, Pschema schema){
	Code specifier_code ;
	Pnode expr_node = specifier_node->child;
	if (expr_node==NULL){
		schema->type = NIHIL;
	}
	else {
		Code expr_code = expr(expr_node,schema);
	}
	return specifier_code;
}



/*Ritorno lo schema dell'attr_decl*/
Pschema attr_decl(Pnode attr_decl_node){
	//Prendo i due figli del nodo
	Pnode type_node = attr_decl_node->child;
	Pnode id_node = attr_decl_node->child->brother;
	
	//Analizzo il tipo 
	Pschema schema = atomic_type(type_node);

	//Dall'id_node prendo il nome e lo aggiungo a schema
	schema->name = valname(id_node);

	return schema;	
}



/*Ritorno lo schema dell'attr_list*/
Pschema attr_list(Pnode attr_list_node){
	//Punto al primo figlio
	Pnode first_attr_decl_node = attr_list_node->child;

	//Estraggo lo schema del primo figlio
	Pschema schema = attr_decl(first_attr_decl_node);
	
	//Punto al secondo figlio
	Pnode attr_decl_node = first_attr_decl_node->brother;
	//Punto al secondo schema
	Pschema prev_schema=schema->next;
	//Prendo gli schemi degli attributi successivi
	while (attr_decl_node != NULL){
		//Prendo lo schema del nodo
		Pschema attr_schema = attr_decl(attr_decl_node);
		//Controllo che nell'elenco dei nomi non ci sia già un id con quel nome
		if(name_in_schema(attr_schema->name,schema)!=NULL)
			semerror(attr_decl_node,"Variabile già presente nella tabella");
		//Aggiungo lo schema allo schema della attr_list
		prev_schema->next = attr_schema;
		prev_schema = prev_schema->next;
	}
	return schema;
}





