#include <stdio.h>
#include <stdlib.h>

#define TOT_BUCKETS 1009

typedef enum { FALSE, TRUE } Boolean;

typedef enum 
{
    N_ASSIGN_STAT,
    N_ATOMIC_TYPE,
    N_ATTR_DECL,
    N_BOOLCONST,
    N_COMP_EXPR,
    N_DEF_STAT,
    N_EXTEND_EXPR,
    N_ID,
    N_IF_STAT,
    N_INTCONST,
    N_JOIN_EXPR,
    N_LOGIC_EXPR,
    N_MATH_EXPR,
    N_NEG_EXPR,
    N_PROGRAM,
    N_PROJECT_EXPR,
    N_READ_STAT,
    N_RENAME_EXPR,
    N_SELECT_EXPR,
    N_SPECIFIER,
    N_STAT_LIST,
    N_STRCONST,
    N_TABLE_CONST,
    N_TABLE_TYPE,
    N_TUPLE_CONST,
    N_TYPE,
    N_UPDATE_EXPR,
    N_WHILE_STAT,
    N_WRITE_STAT
} Typenode;



/*value dell'analizzatore lessicale*/
typedef union
{
    int ival;
    char *sval;
} Value;



/*nodo di una lista di nomi*/
typedef struct s_name
{
    char *name;
    struct s_name *next;
} Name;

typedef Name *Pname;



/*nodo dell'albero astratto generato dall'analizzatore lessicale*/
typedef struct snode
{
    int type;
    Value value;
    int line;
    struct snode *child, *brother;
} Node;

typedef Node *Pnode;



/*rappresenta una variabile nella symbol table.
name è il nome della variabile.
type è il tipo della variabile.
se la variabile è di tipo semplice, il campo next è nullo.
se la variabile è di tipo table, il campo next punta al primo dei parametri della tabella, che a sua volta sarà uno schema. */
typedef struct s_schema
{
    char *name;
    int type;
    struct s_schema *next;
} Schema;

typedef Schema *Pschema;


/*Rappresenta un simbolo della symble-table.
Contiene il proprio numero, la dimensione e il puntatore al prossimo simbolo nella stessa posizione.*/
typedef struct s_symbol
{
    int oid;
    int size;
    Schema schema;
    struct s_symbol *next;
} Symbol;

typedef Symbol *Psymbol;



/*Rappresenta un elemento del contesto.
Il contesto è l'insieme delle variabili dell'ambiente sql*/
typedef struct s_context
{
    int level;
    Pschema pschema;
    struct s_context *next;
} Context;

typedef Context *Pcontext;



/*Rappresenta un elemento dello stack dell'ambiente.
L'ambiente è l'insieme delle variabili di una parte di codice */
typedef struct s_environment
{
    int level;
    int numobj;
    Pname pname;
    struct s_environment *next;
} Environment;

typedef Environment *Penvironment;

/* --------- For code generation --------- */

#define MAXARGS 3

typedef enum
{
    T_TCODE,
    T_NEWATOM,
    T_NEWTAB,
    T_POP,
    T_LDINT,
    T_LDSTR,
    T_LDTAB,
    T_IATTR,
    T_SATTR,
    T_ENDTAB,
    T_LOB,
    T_LAT,
    T_STO,
    T_SKIP,
    T_SKIPF,
    T_EQU,
    T_NEQ,
    T_IGT,
    T_IGE,
    T_ILT,
    T_ILE,
    T_SGT,
    T_SGE,
    T_SLT,
    T_SLE,
    T_PLUS,
    T_MINUS,
    T_TIMES,
    T_DIV,
    T_JOIN,
    T_ENDJOIN,
    T_UMI,
    T_NEG,
    T_PROJ,
    T_ATTR,
    T_ENDPROJ,
    T_SEL,
    T_ENDSEL,
    T_EXS,
    T_ENDEXS,
    T_ALL,
    T_ENDALL,
    T_UPD,
    T_ENDUPD,
    T_REMDUP,
    T_EXT,
    T_ENDEXT,
    T_GET,
    T_FGET,
    T_PRINT,
    T_FPRINT,
    T_HALT
} Operator;

/*Per le strutture necessarie alla generazione di codice, vedere lucido 61 della specifica table*/
typedef struct t_stat
{
    int address;
    Operator op;
    Value args[MAXARGS];
    struct t_stat *next;
} Tstat;

typedef struct
{
    Tstat *head;
    int size;
    Tstat *tail;
} Code;

typedef struct
{
    Operator op;
    char *name;
    int indent;
    char *format;
} Opdescr;

/* ------------- Prototypes ------------- */
/*non è detto che tutte le funzioni siano implementate*/


Boolean compatible(char*, char*),	/*dice se due nomi sono compatibili (ad esempio due tabelle con stesso numero di attributi, una con nomi, l'altra senza nomi (ad esempio è una costante)) 
i due tipi sono compatibili se attributo per attributo hanno stesso nome e stesso tipo, oppure se uno dei due (o entrambi) non hanno nome ma hanno tipi compatibili*/
        duplicated(char*, Pschema),	/*dice se ci sono già variabili con il nome puntato nello schema*/
        homonyms(Pschema, Pschema),	/*dice se ci sono omonimie negli attributi (in caso di join)-da implementare*/
        name_in_environment(char*),	/*dice se il nome c'è in quell'ambiente (comodo per la definizione di variabili)*/
        name_in_list(char*, Pname),	/*dice se il nome c'è nella lista (comodo per proiezione)*/
        repeated_names(Pname),		/*dice se ci sono nomi ripetuti nella lista di nomi*/
        type_equal(Schema, Schema);	/*dice se i due schemi sono compatibili (atomici--> tipo; tabelle-->schema)*/

char *clear_string(char *s),
     *get_format(Schema),	/*dallo schema tira fuori il suo formato (utile per le funzioni di read e write)*/
     *nameop(Operator),
     *operator(int),
     *strcat( char*, const char*),
     *strcpy (char*, const char*),
     *update_lextab(char*),	/*fa l'aggiornamento della tabella dei simboli dell'analizzatore lessicale (non serve)*/
     *valname(Pnode);		/*tira fuori dal nodo il campo sval (per il nome dell'id)*/
     
Code appcode(Code, Code),	/*appende al primo codice, il secondo e libera la memoria del secondo*/
     assign_stat(Pnode),	/* fa sia analisi semantica che generazione di codice*/
     attr_code(Pnode),
     def_stat(Pnode),
     concode(Code, Code, ...),	/*usata per accodare tra loro più di due stringhe di codice. DEVE CHIAMARE ENDCODE*/
     endcode(),			/*genera un descrittore che indica alla concode di smettere di concatenare*/
     expr(Pnode, Pschema),	/*riceve il nodo dell'albero e il puntatore allo schema e genera il codice corrispondente all'espressione e restituisce in un attributo sintetizzato lo schema risultante dell'espressione. Ogni ramo del case deve fare in modo di resituire il descrittore dello schema che computa. 
Deve garantire due cose: il risultato dello schema, + il codice computato*/
     if_stat(Pnode),
     makecode(Operator),				/*costruisce codice di uno statement che non ha argomenti*/
     makecode1(Operator, int),
     makecode2(Operator, int, int),
     makecode3(Operator, int, int, int),
     make_get_fget(Operator, int, char*),		/*serve per la lettura (read)*/
     make_ldint(int),					/*carica costante intera*/
     make_ldstr(char *s),				/*carica costante stringa*/
     make_print_fprint(Operator, char*),		/*serve per la write*/
     make_sattr(char*),					/*serve per generare gli schemi*/
     /*Questi qui non hanno schema perchè non sono espressioni e non devono ritornare degli schemi
       Gli stat non devono generare schemi*/
     program(Pnode),
     read_stat(Pnode),
//     specifier(Pnode),
     stat(Pnode),
     stat_list(Pnode),
     tuple_const(Pnode, Pschema),
     while_stat(Pnode),
     write_stat(Pnode);
     
Opdescr *get_descr(Operator);

Operator codop(char*);

Pname id_list(Pnode, int*);
     
Pnode boolconstnode(int),
      idnode(char*),
      intconstnode(int),
      newnode(Typenode),
      qualnode(Typenode, int),
      strconstnode(char*);
     
Pschema append_schemas(Pschema, Pschema),	/*appende due schemi tra loro*/	
        atomic_type(Pnode),			/*Genera come risultato il puntatore a schema del tipo atomico*/
        clone_schema(Pschema),			/*clona lo schema passato come argomento*/
        name_in_constack(char*, int*, int*), /*cerca il nome nello stack dei contesti: prima cosa da fare quando si trova un id. restituisce lo schema, se esiste + la distanza del contesto + la posizione nel contesto (offset)*/
        name_in_context(char*),			/*cerca il nome nel contesto*/
        name_in_schema(char*, Pschema),		/*cerca il nome nello schema*/
        schemanode(char*, int),			/*genera un nodo dello schema (non serve)*/
        table_type(Pnode);			/*genera la table type*/
	
/*Funzioni per la tabella dei simboli*/
Psymbol insert(Schema),				/*insert nella tabella dei simboli-inserisci lo schema (Nome->attributi)*/
        lookup(char*);				/*cerca in base al nome: (nome del primo elemento sia se atomico che tabella)*/
	
//Schema type(Pnode);

size_t strlen (const char*);

Tstat *newstat(Operator);

void codeprint(Code, int),
     freemem(void*, int),
     idlprint(Pname),			/*stampa l'id_list*/
     init_compiler(),
     init_lextab(),
     init_symtab(),
     insert_name_into_environment(char*),
     *newmem(int),			/*alloca memoria*/
     noderror(Pnode),
     pop_context(),			/*elimina il contesto alla fine di un'operazione tipo select*/
     pop_environmet(),  		/*elimina l'ambiente nel momento dell'uscita da un blocco di codice*/
     push_context(Pschema),
     push_environment(),
     eliminate(char*),			/*Elimina un elemento dalla tabella dei simboli - quando esco da un ambiente*/
     relocate_address(Code, int),
     schprint(Schema),			/*Stampa in modo leggibile lo schema*/
     semerror(Pnode, char*),
     symprint(),		/*Stampa in modo leggibile la tabella dei simboli, solo per i banchi che sono non-nulli*/
     syserror(char*),		/**/
     treeprint(Pnode, int);


//^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-
void schema_copy(Pschema src,Pschema dst);
Pschema attr_list(Pnode attr_list_node);
Pname get_name_list_in_environment();
Code specifier(Pnode specifier_node, Pschema schema);
Pschema type(Pnode);
Code comp_expr(Pnode expr_node,Pschema expr_schema); 
Code logic_expr(Pnode expr_node,Pschema expr_schema); 		
Code math_expr(Pnode expr_node,Pschema expr_schema); 
Code neg_expr(Pnode expr_node,Pschema expr_schema); 
Code select_kind_expr(Pnode expr_node,Pschema expr_schema); 
Code project_expr(Pnode expr_node,Pschema expr_schema); 
Code update_expr(Pnode expr_node,Pschema expr_schema); 
Code extend_expr(Pnode expr_node,Pschema expr_schema); 
Code rename_expr(Pnode expr_node,Pschema expr_schema);

Code bool_const(Pnode bool_const_node,Pschema schema);
Code str_const(Pnode str_const_node,Pschema schema);
Code int_const(Pnode int_const_node,Pschema schema);
Code id_expr(Pnode id_node,Pschema schema);
Code table_const(Pnode table_const_node, Pschema schema_tabella);
//Code tuple_const(Pnode tuple_const_node,Pschema schema);

//#define DEBUG_REPEATED_NAMES
//#define DEBUG_DEF_STAT
//#define DEBUG_ATOMIC_TYPE
//#define DEBUG_TYPE
//#define DEBUG_TABLE_TYPE
//#define DEBUG_STAT_LIST
//#define DEBUG_ATTR_DECL
//#define DEBUG_ATTR_LIST
//#define DEBUG_ASSIGN_STAT
//#define DEBUG_NEG_EXPR
//#define DEBUG_TABLE_CONST
//#define DEBUG_TUPLE_CONST
//#define DEBUG_COMP_EXPR
//#define DEBUG_ID
//#define DEBUG_IF_STAT
//#define DEBUG_READ_STAT
//#define DEBUG_SPECIFIER
