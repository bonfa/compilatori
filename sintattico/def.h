#include <stdio.h>
#include <stdlib.h>

#define ERROR 		-1

#define IF		300
#define THEN		301
#define ELSE		302
#define WHILE		303
#define DO		304
#define END 		305

#define INTEGER		310
#define STRING		311
#define BOOLEAN		312
#define TABLE		313

#define READ		320
#define WRITE		321

#define ID		325

#define BOOL_OP		330
#define UNARY_OP	331
#define HIGH_BIN_OP	332
#define LOW_BIN_OP	333
#define COMP_OP		334

#define INT_CONST	340
#define STR_CONST	341
#define BOOL_CONST	342

#define AND		350
#define OR		351
#define NOT		352

#define PROJECT		360
#define SELECT		361
#define EXISTS		362
#define ALL		363
#define UPDATE		364
#define EXTEND		365
#define RENAME		366
#define JOIN		367

#define PROGRAM		370

#define EQ		375
#define NOT_EQ		376
#define GET		377
#define LET		378

#define ASSIGN		385
#define END_OF_FILE	0

typedef union{
	int ival;
	char *sval;
} Value;

Value lexval;

char *my_copy(char *s);
int assign_id();

//---------------------------------------------------
void error(int err_code);
void match(int simbolo);
void program();
void stat_list();
void stat();
void def_stat();
void assign_stat();
void if_stat();
void while_stat();
void read_stat();
void write_stat();
void type();
void atomic_type();
void table_type();
void attr_list();
void attr_decl();
void expr();
void bool_term();
void comp_term();
void low_term();
void factor();
void join_op();
void unary_op();
void constant();
void unary_op();
void project_op();
void select_op();
void exists_op();
void all_op();
void update_op();
void extend_op();
void rename_op();
void id_list();
void atomic_const();
void table_const();
void tuple_const();
void specifier();
void next();
void parse();
