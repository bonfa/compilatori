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
#ifdef DEBUG_READ_STAT
	printf("READ_STAT - enter\n");
#endif
	//Imposto le due parti del nodo
	Pnode specifier_node = read_stat_node->child;
	Pnode id_node = read_stat_node->child->brother;
	
	//Definisco il codice del nodo
	Code read_stat_code;
	read_stat_code.head = NULL;

	//Calcolo il codice di specifier
	Pschema schema_specifier = (Pschema) newmem(sizeof(Schema));
	Code specifier_code = specifier(specifier_node,schema_specifier);

	//Controllo che non ci siano errori semantici
	//Controllo che il tipo di specifier sia corretto
	if ((schema_specifier->type != STRING) && (schema_specifier->type != NIHIL))
		semerror(read_stat_node,"Expected string type");
	//Controllo che il nome dell'id sia visibile
	if (lookup(valname(id_node))==NULL)
		semerror(id_node,"Variable not defined");

#ifdef DEBUG_READ_STAT
	printf("ok semantica\n");
	printf("p = %p\n",specifier_node->child);
//	printf
	if (specifier_node->child != NULL)
		codeprint(specifier_code,1);
	printf("endprint\n");
#endif
	//Genero il codice di readstat
	//La sintassi della read dipende dalla presenza dello specifier
	Psymbol symbol = lookup(valname(id_node));
	if (specifier_node->child == NULL)		
		read_stat_code = make_get_fget(T_GET,symbol->oid,get_format((symbol->schema)));
	else
		read_stat_code = appcode(specifier_code,make_get_fget(T_FGET,symbol->oid,get_format((symbol->schema))));
#ifdef DEBUG_READ_STAT
	printf("READ_STAT - exit\n");
#endif
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
	int up = -(expr_code.size + stat_list_code.size + 1);
	
	//Genero il codice di while_stat
	while_stat_code = concode(expr_code,makecode1(T_SKIPF,exit),stat_list_code,makecode1(T_SKIP,up),endcode());

	return while_stat_code;
}



/*Controlla la semantica del nodo if e ne ritorna il codice*/
Code if_stat(Pnode if_stat_node){
#ifdef DEBUG_IF_STAT
	printf("IF_STAT - enter\n");
#endif
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
#ifdef DEBUG_IF_STAT
	printf("before if\n");
	printf("then_node->type = %d\n",then_node->type);
#endif	
	if (else_node==NULL){//if then endif
#ifdef DEBUG_IF_STAT
	printf("without else\n");
	codeprint(then_code,2);
	codeprint(expr_code,1);
#endif	
		//Calcolo l'offset
		int offset = then_code.size + 1;
		//Genero il codice di if_stat
		if_stat_code = concode(expr_code,makecode1(T_SKIPF,offset),then_code,endcode());
#ifdef DEBUG_IF_STAT
	printf("end codegen\n");
#endif	
	}
	else {//if then else
#ifdef DEBUG_IF_STAT
	printf("with else\n");
	codeprint(then_code,2);
	codeprint(expr_code,1);
#endif		
		//Genero il codice di else_node
		Code else_code = stat_list(else_node);
#ifdef DEBUG_IF_STAT
	codeprint(else_code,2);
#endif
		//Calcolo gli offset
		int offset_then = then_code.size + 2;
		int offset_else = else_code.size + 1;
		//Genero il codice di if_stat
		if_stat_code = concode(expr_code,makecode1(T_SKIPF,offset_then),then_code,makecode1(T_SKIP,offset_else),else_code,endcode());

	}
#ifdef DEBUG_IF_STAT
	printf("IF_STAT - exit\n");
#endif	
	return if_stat_code;
}



/*Genera il codice per il nodo def_stat e controlla i vincoli semantici*/
Code def_stat(Pnode def_stat_node){
	//Imposto le due parti del nodo	
	Pnode type_node = def_stat_node->child;
	Pnode id_list_head_node = def_stat_node->child->brother;
 
	//Definisco la variabile che contiene il codice da ritornare	
	Code def_stat_code ;
	def_stat_code.head = NULL;
	def_stat_code.tail = NULL;
	def_stat_code.size = 0;

#ifdef DEBUG_DEF_STAT
	printf("__TEST__\n");
	
#endif
	//Sintetizzo il type
	Pschema schema_type = type(type_node);
	//Ottengo la id_list
	int id_list_len;
	Pname id_list_name = id_list(id_list_head_node,&id_list_len);
	
	//Controllo gli errori semantici
	//id ripetuti
	Boolean repetition = repeated_names(id_list_name);
#ifdef DEBUG_DEF_STAT
	idlprint(id_list_name);
	printf("Repeated_names =%d\n",repetition);
#endif
	if (repetition == TRUE){
#ifdef DEBUG_DEF_STAT
		printf("error\n");
#endif
		semerror(def_stat_node,"Variable redeclaration");
	}
	//variabili già assegnate
#ifdef DEBUG_DEF_STAT
	printf("not_error_in_repetition_check\n");	
#endif

	Pnode id_node;
	for (id_node = id_list_head_node; id_node!=NULL; id_node=id_node->brother)
		if (name_in_environment(valname(id_node)))
			semerror(id_node,"Variable already defined");

#ifdef DEBUG_DEF_STAT
	printf("not_error_in declaration_check\n");	
#endif		
	//Genero il codice per la definizione delle variabili e inserisco i nomi nel contesto
	for (id_node = id_list_head_node; id_node!=NULL; id_node=id_node->brother){
		//Genero il codice dell'id
		Code id_code ;
		int spazio_da_allocare = get_size(schema_type);
#ifdef DEBUG_DEF_STAT
		printf("len = %s\n",valname(id_node));
		printf("dim = %d\n",get_size(schema_type));
#endif
		if (schema_type->type == TABLE)
			id_code = makecode1(T_NEWTAB,spazio_da_allocare);
		else		
			id_code = makecode1(T_NEWATOM,spazio_da_allocare);
		//Inserisco il nome nell'ambiente
		insert_name_into_environment(valname(id_node));
		//Inserisco il nome nella symbol table
		Pschema schema_symbol = clone_schema(schema_type);
		schema_symbol->name = valname(id_node);
		insert(*schema_symbol);
		//Appendo a def_stat_code l'id_code
		def_stat_code = appcode(def_stat_code,id_code);
	}
	
#ifdef DEBUG_DEF_STAT
	printf("not_error_in definition_code\n");
	codeprint(def_stat_code,1);	
#endif

	return def_stat_code;
}



/*Ritorna lo schema e imposta il tipo nel campo type di schema*/
Pschema atomic_type(Pnode atomic_type_node){
#ifdef DEBUG_ATOMIC_TYPE
	printf( "ATOMIC_TYPE_NODE - enter\n");
#endif
	//Creo lo schema
	Pschema schema = (Pschema) newmem(sizeof(Schema));
	//Imposto tutti i campi a null
	schema->name = NULL;
	schema->next = NULL;
	//Imposto il type
	schema->type = qualifier(atomic_type_node);
#ifdef DEBUG_ATOMIC_TYPE
	printf("schema_atomic\n");
	schprint(*schema);
	printf( "ATOMIC_TYPE_NODE - exit\n");
#endif
	return schema;
}



/*Ritorna lo schema del type.
Il puntatore allo schema successivo che sarà NULL nel caso di tipi semplici, e non nullo per tipi tabella*/
Pschema type(Pnode type_node){
#ifdef DEBUG_TYPE
	printf( "TYPE_NODE - enter\n");
#endif

	if (type_node->type == N_ATOMIC_TYPE)
		return atomic_type(type_node);
	else 		
		return table_type(type_node);
}


/*
Ritorna lo schema del table_type.
*/
Pschema table_type(Pnode type_node){
#ifdef DEBUG_TABLE_TYPE
	printf( "TABLE_TYPE - enter\n");
#endif
	//Creo lo schema
	Pschema schema = (Pschema) newmem(sizeof(Schema));
	schema->name = NULL;
#ifdef DEBUG_TABLE_TYPE
	printf( "TABLE_TYPE - ok schema def\n");
#endif

	//Imposto il type (che sarà TABLE)
	schema->type = qualifier(type_node);
	
#ifdef DEBUG_TABLE_TYPE
	printf( "TABLE_TYPE - pre_attr_list\n");
#endif
	//Genero la lista di attributi
	schema->next = attr_list(type_node->child);
	
#ifdef DEBUG_TABLE_TYPE
	printf( "TABLE_TYPE - ok attr_list definition\n");
#endif
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




/*Genera il codice per il nodo stat_list e crea lo scope del programma*/
Code stat_list(Pnode stat_list_node){
	//Definisco la variabile che contiene il codice da ritornare
	Code stat_list_code;
	stat_list_code.head = NULL;
	stat_list_code.tail = NULL;
	stat_list_code.size = 0;

	//Creo l'ambiente del programma
	push_environment();
#ifdef DEBUG_STAT_LIST
		printf("STAT_LIST - creato nuovo environment\n");
		//printf("level = %d\n",envstack->level);
#endif	
	//Punto al primo stat
	Pnode stat_node = stat_list_node->child;
	//Ciclo lungo tutti gli stat_node
	while (stat_node!=NULL){
		//Creo il codice dello stat_node
		Code stat_code;
		switch (stat_node->type){
			case(N_DEF_STAT): 	stat_code = def_stat(stat_node);break;
			case(N_ASSIGN_STAT): 	stat_code = assign_stat(stat_node);break;
			case(N_IF_STAT): 	stat_code = if_stat(stat_node);break;
			case(N_WHILE_STAT): 	stat_code = while_stat(stat_node);break;
			case(N_READ_STAT): 	stat_code = read_stat(stat_node);break;
			case(N_WRITE_STAT): 	stat_code = write_stat(stat_node);break;
		}
#ifdef DEBUG_STAT_LIST
		printf("not_error_in_statement\n");
		codeprint(stat_code,0);
#endif		
		
		//Appendo il codice a stat_list_code
		stat_list_code = appcode(stat_list_code,stat_code);
#ifdef DEBUG_STAT_LIST
		printf("not_error_in_appcode\n");	
#endif
		//Punto al fratello successivo
		stat_node = stat_node->brother;
	}
	
	//Appendo il codice per fare il pop dell'environment a stat_list_code
	if(numobj_in_current_env()!=0)
		stat_list_code = appcode(stat_list_code,makecode1(T_POP,numobj_in_current_env()));
#ifdef DEBUG_STAT_LIST
printf("STAT_LIST - aggiunto il codice per fare il pop delle variabile\n");	
printf("%d\n",numobj_in_current_env());
printf("symbol table");
symprint();
printf("--------");
#endif
	//elimino l'ambiente creato (elimina già le variabili dall'ambiente)
	pop_environment();


#ifdef DEBUG_STAT_LIST
printf("STAT_LIST - effettuato il pop dell'ambiente\n");	
//printf("%d\n",numobj_in_current_env());
#endif


	return stat_list_code;
}



/*Controlla i vincoli semantici dell'assegnamento e ne ritorna il codice*/
Code assign_stat(Pnode assign_stat_node){
#ifdef DEBUG_ASSIGN_STAT
	printf("ASSIGN_STAT - enter\n");
#endif
	//Imposto le due parti del nodo	
	Pnode id_node = assign_stat_node->child;
	Pnode expr_node = assign_stat_node->child->brother;

	//Definisco la variabile che contiene il codice da ritornare
	Code assign_stat_code ;
	
	//Controllo i vincoli semantici
	//Visibilità del nome
	if (lookup(valname(id_node))==NULL)
		semerror(id_node,"undefined variabile");
	//Compatibilità degli schemi
	Pschema schema_expr = (Pschema) newmem(sizeof(Schema));
	Code expr_code = expr(expr_node,schema_expr);

	Psymbol symbol = lookup(valname(id_node)); 
#ifdef DEBUG_ASSIGN_STAT
	printf("schema_expr\n");
	schprint(*schema_expr);
	printf("------------\n");
	
	printf("schema_var\n");
	schprint(symbol->schema);
	printf("------------\n");
	//symprint();
#endif

	if (!type_equal((symbol->schema),*(schema_expr)))
		semerror(assign_stat_node,"id e expr non hanno lo stesso tipo");

	//Genero il codice
	assign_stat_code = appcode(expr_code,makecode1(T_STO,symbol->oid));

#ifdef DEBUG_ASSIGN_STAT
	printf("ASSIGN_STAT - exit\n");
#endif
	return assign_stat_code;
}



/*Genera lo schema della tupla e ritorna il codice*/
Code tuple_const(Pnode tuple_const_node,Pschema schema){
	//Non ci sono vincoli semantici
#ifdef DEBUG_TUPLE_CONST
	printf( "TUPLE_CONST - enter\n");
#endif
	//Preparo il codice della tupla
	Code tuple_const_code;
	tuple_const_code.head = NULL;
	

	//Punto al primo elemento della tupla
	Pnode atomic_const_node = tuple_const_node->child;
#ifdef DEBUG_TUPLE_CONST
	printf("%p\n",tuple_const_node->child);
	printf("type node = %d\n",tuple_const_node->type);
	printf("type child = %d\n",tuple_const_node->child->type);
	printf("q = %d\n",qualifier(tuple_const_node->child));
#endif
	//Preparo la variabile che contiene il codice dell'id
	Code atomic_const_code;
	Pschema prev_schema = schema;	
	do{
		//Calcolo il codice e lo schema della prima costante
		switch(atomic_const_node->type){
		case (N_INTCONST): 	atomic_const_code = makecode1(T_IATTR,qualifier(atomic_const_node));
					prev_schema->type = INTEGER;
					break;
		case (N_BOOLCONST):	atomic_const_code = makecode1(T_IATTR,qualifier(atomic_const_node));
					prev_schema->type = BOOLEAN;
					break;	
		case (N_STRCONST):	atomic_const_code = make_sattr(valname(atomic_const_node));
					prev_schema->type = STRING;
					break;
		}
#ifdef DEBUG_TUPLE_CONST
	printf("ciaociao\n");
	codeprint(atomic_const_code,1);
	print("type = ",prev_schema->type);
#endif	
		//Appendo il codice della costante al codice della tupla
		tuple_const_code = appcode(tuple_const_code,atomic_const_code);
#ifdef DEBUG_TUPLE_CONST
	printf( "provaprova\n");
	codeprint(tuple_const_code,1);
#endif			
		
		//Passo al fratello
		atomic_const_node = atomic_const_node->brother;	
		//Creo un nuovo schema
		if (atomic_const_node!=NULL){
			Pschema newSchema = (Pschema) newmem(sizeof(Schema));
			prev_schema->next = newSchema;
			prev_schema = prev_schema->next;
		}
	}while(atomic_const_node!=NULL);
#ifdef DEBUG_TUPLE_CONST
	printf( "TUPLE_CONST - exit\n");
#endif
	return tuple_const_code;
}




/*Genera il codice dello specifier e ne ritorna lo schema.
Lo schema dello specifier può essere una costante stringa o NULL*/
Code specifier(Pnode specifier_node, Pschema schema){
#ifdef DEBUG_SPECIFIER
	printf( "SPECIFIER - enter\n");
#endif
	Code specifier_code ;
	Pnode expr_node = specifier_node->child;
	if (expr_node==NULL){
		schema->type = NIHIL;
	}
	else {
		specifier_code = expr(expr_node,schema);
	}
#ifdef DEBUG_SPECIFIER
	codeprint(specifier_code,1);
	printf( "SPECIFIER - exit\n");
	
#endif
	return specifier_code;
}



/*Ritorno lo schema dell'attr_decl*/
Pschema attr_decl(Pnode attr_decl_node){
#ifdef DEBUG_ATTR_DECL
	printf( "ATTR_DECL - enter\n");
	printf("pnode = %p\n",attr_decl_node);
	printf("Node_type = %d\n",attr_decl_node->type);
	enumprint("N_ATOMIC_TYPE",N_ATOMIC_TYPE);
	//printf("Node_child = %p\n",attr_decl_node->child);
	//printf("Node_child_2 = %p\n",attr_decl_node->child->brother);
#endif
	//Prendo i due figli del nodo
	Pnode type_node = attr_decl_node->child;
	Pnode id_node = attr_decl_node->child->brother;

#ifdef DEBUG_ATTR_DECL
	fprintf(stderr, "ATTR_DECL - ok two child nodes\n");
#endif	
	//Analizzo il tipo 
	Pschema schema = atomic_type(type_node);

#ifdef DEBUG_ATTR_DECL
	printf( "ATTR_DECL - ok get atomic schema\n");
#endif

	//Dall'id_node prendo il nome e lo aggiungo a schema
	schema->name = valname(id_node);

#ifdef DEBUG_ATTR_DECL
	printf( "ATTR_DECL - exit\n");
#endif

	return schema;	
}



/*Ritorno lo schema dell'attr_list*/
Pschema attr_list(Pnode attr_list_node){
#ifdef DEBUG_ATTR_LIST
	printf( "ATTR_LIST - enter\n");
#endif
	//Punto al primo figlio
	Pnode first_attr_decl_node = attr_list_node;

	//Estraggo lo schema del primo figlio
	Pschema schema = attr_decl(first_attr_decl_node);

#ifdef DEBUG_ATTR_LIST
	printf( "ATTR_LIST - ok attr_decl_call\n");
#endif	

	//Punto al secondo figlio
	Pnode attr_decl_node = first_attr_decl_node->brother;
	//Punto al primo schema
	Pschema prev_schema = schema;
#ifdef DEBUG_ATTR_LIST
	printf( "ATTR_LIST - ok attr_decl brother\n");
	int c=1;
#endif	
	//Prendo gli schemi degli attributi successivi
	while (attr_decl_node != NULL) {
		//Prendo lo schema del nodo
		Pschema attr_schema = attr_decl(attr_decl_node);
#ifdef DEBUG_ATTR_LIST
		printf( "ATTR_LIST - ok attr_decl schema\n");
		printf("			ciaociaociao");
		printf("%d\n",c);
#endif
		
		//Controllo che nell'elenco dei nomi non ci sia già un id con quel nome
		if(name_in_schema(attr_schema->name,schema)!=NULL)
			semerror(attr_decl_node,"Variabile già presente nella tabella");
#ifdef DEBUG_ATTR_LIST
		printf("			ciaociaociao\n\n");
		printf("prev_schema = %p\n",prev_schema);
		printf("prev_schema->next = %p\n",prev_schema->next);
		
#endif
		//Aggiungo lo schema allo schema della attr_list
		prev_schema->next = attr_schema;
		prev_schema = prev_schema->next;
#ifdef DEBUG_ATTR_LIST
	printf( "ATTR_LIST - ok insert schema\n");
#endif
		//Passo al fratello di attr_decl
		attr_decl_node = attr_decl_node->brother;
#ifdef DEBUG_ATTR_LIST
	printf( "ATTR_LIST - ok attr_decl brother\n");
#endif	
	}

#ifdef DEBUG_ATTR_LIST
	printf( "ATTR_LIST - exit\n");
#endif

	return schema;
}





