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
	//creo l'ambiente del programma
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
	return stat_list_code;
}



/*Genera il codice per il nodo def_stat e controlla i vincoli semantici*/
Code def_stat(Pnode p){
	Code def_stat_code = NULL;
	int var_type;
	//Prendo il tipo dell'espressione e genero il codice per il tipo
	Code type_code = type(p->child,var_type);
	Code id_list_code = NULL;
	//Analizzo gli id
	Pnode t = p->child->brother;
	for (t; t!=NULL ; t=t->brother ){
		Code id_code = NULL;
		//Verifico che i nomi non siano ripetuti
		for (s=t->brother;s!=NULL;s=s->brother)
			if (strcmp(valname(s),valname(p))) 
				semerror(t,"più variabili con lo stesso id");
		//Verifico che il nome non sia già presente nell'ambiente altrimenti lo inserisco
		if (s = lookup(name(t))!=NULL)
			semerror(t,"variabile già assegnata");
		else {	
			//Creo lo schema e lo inserisco nella tabella
			insert(newschema(name(t),var_type);
			//Creo il codice per l'id
			id_code = 
		}
	}	
}
	
Code type(Pnode p, int *t){	
}



