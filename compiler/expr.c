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
/**/
Code expr(Pnode expr_node,Pschema expr_schema){
	return NULL;
}

/**/
Code rename_expr(){
	return NULL;
}

/**/
Code select_expr(){
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
Code logic_expr(){
return NULL;
}

/**/
Code math_expr(){return NULL;
}

/**/
Code neg_expr(){return NULL;
}

/**/
Code extend_expr(){return NULL;}

/**/
Code comp_expr(){return NULL;}

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

