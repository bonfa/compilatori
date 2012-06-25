#include "def.h"
#include "parser.h"

/*Ci sono due stack, uno per l'ambiente di funzioni, l'altro per gli schemi sql */
static Penvironment envstack = NULL;
static Pcontext constack = NULL;

int oid_counter = 0;


/*Ritorna il numero di oggetti presenti nell'ambiente corrente*/
int numobj_in_current_env()
{
  return (envstack->numobj);
}



/*Crea un nuovo ambiente*/
void push_environment()
{
    Penvironment temp = envstack;
    int lev = (temp == NULL ? 0 : temp->level + 1);

    envstack = (Penvironment) newmem(sizeof(Environment));
    envstack->level = lev;
    envstack->numobj = 0;
    envstack->pname = NULL;
    envstack->next = temp;
}



/*Inserisce il nome della variabile nell'ambiente*/
void insert_name_into_environment(char *name)
{
  Pname tempname = envstack->pname;
  
  envstack->pname = (Pname)newmem(sizeof(Name));
  envstack->pname->name = name;
  envstack->numobj++;
  envstack->pname->next = tempname;
}



/*Ritorna true se il nome è presente nell'ambiente*/
Boolean name_in_environment(char *name)
{
  return(name_in_list(name, envstack->pname));
}



/*Ritorna true se il nome è presente nella lista di nomi*/
Boolean name_in_list(char *name, Pname pname)
{
  while(pname)
  {
    if(name == pname->name)
      return(TRUE);
    pname = pname->next;
  }
  return(FALSE);
}



/*Elimina il primo ambiente (all'uscita di blocchi di codice - tipo if o while)*/
void pop_environment()
{
    Penvironment penv = envstack;
    Pname pname, next;

    if(penv == NULL) syserror("pop_environment()");
    next= penv->pname;
    while(next)
    {
      pname = next;
      eliminate(pname->name);
      next = pname->next;
      freemem(pname, sizeof(Name));
    }
    oid_counter -= penv->numobj;
    envstack = penv->next;
    freemem((void*)penv, sizeof(Environment));
}

//^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-

/*Crea un nuovo contesto*/
void push_context(Pschema pschema)
{
    Pcontext temp = constack;
    int lev = (temp == NULL ? 0 : temp->level + 1);

    constack = (Pcontext) newmem(sizeof(Context));
    constack->level = lev;
    constack->pschema = pschema;
    constack->next = temp;
}



/*Elimina il primo contesto (per operazioni tipo select)*/
void pop_context()
{
    Pcontext tempcontext;

    tempcontext = constack;
    if(tempcontext == NULL) syserror("pop_context()");
    constack = tempcontext->next;
    freemem((void*) tempcontext, sizeof(Context));
}



/* Cerca il nome nello stack dei contesti: prima cosa da fare quando si trova un id. 
   Restituisce lo schema, se esiste, + la distanza del contesto + la posizione nel contesto (offset)*/
Pschema name_in_constack(char *name, int *pcontext_offset, int *pattribute_context)
{
  Pcontext pcontext = constack;
  Pschema pschema;
    
  for(*pcontext_offset = 0; pcontext != NULL; ++(*pcontext_offset), pcontext = pcontext->next)
    if((pschema = name_in_schema(name, pcontext->pschema)) != NULL)
    {
      *pattribute_context = get_attribute_offset(pcontext->pschema, name);
      return(pschema);
    }
    return(NULL);
}



/* Cerca il nome nello schema */
Pschema name_in_schema(char *name, Pschema pschema)
{
  while(pschema != NULL)
  {
    if(pschema->name == name)
      return(pschema);
    pschema = pschema->next;
  };
  return(NULL);
}


//^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^

/*crea un nodo schema*/
Pschema newschema(char* name, int type){
	Pschema p = (Pschema) newmem(sizeof(Schema));
	p->type = name;
	p->line = type;
	p->next = NULL;
	return(p);
}
