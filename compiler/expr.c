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




//^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^

/**/
Code rename_expr(){}

/**/
Code select_expr(){}

/**/
Code update_expr(){}

/**/
Code join_expr(){}

/**/
Code logic_expr(){}

/**/
Code math_expr(){}

/**/
Code neg_expr(){}

/**/
Code extend_expr(){}

/**/
Code comp_expr(){}

/**/
Code project_expr(){}

