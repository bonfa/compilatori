
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include "def.h"
#define YYSTYPE pNode
extern char *yytext;
extern Value lexval;
extern int line;
extern FILE *yyin;
pNode root = NULL;


/* Line 189 of yacc.c  */
#line 84 "parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     THEN = 259,
     ELSE = 260,
     WHILE = 261,
     DO = 262,
     END = 263,
     INTEGER = 264,
     STRING = 265,
     BOOLEAN = 266,
     TABLE = 267,
     READ = 268,
     WRITE = 269,
     ID = 270,
     BOOL_OP = 271,
     UNARY_OP = 272,
     HIGH_BIN_OP = 273,
     LOW_BIN_OP = 274,
     COMP_OP = 275,
     INT_CONST = 276,
     STR_CONST = 277,
     BOOL_CONST = 278,
     AND = 279,
     OR = 280,
     NOT = 281,
     PROJECT = 282,
     SELECT = 283,
     EXISTS = 284,
     ALL = 285,
     UPDATE = 286,
     EXTEND = 287,
     RENAME = 288,
     JOIN = 289,
     PROGRAM = 290,
     EQ = 291,
     NOT_EQ = 292,
     GET = 293,
     LET = 294,
     ASSIGN = 295,
     END_OF_FILE = 296,
     ERROR = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 168 "parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNRULES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,    46,    51,    49,    44,    50,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      48,    55,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    13,    15,    17,    19,    21,
      23,    25,    28,    29,    34,    36,    38,    40,    42,    44,
      46,    51,    55,    57,    60,    61,    66,    70,    72,    74,
      76,    80,    82,    84,    86,    88,    90,    92,    94,    98,
     100,   102,   104,   108,   110,   112,   114,   116,   119,   123,
     125,   127,   129,   131,   133,   135,   137,   139,   141,   143,
     145,   150,   155,   160,   165,   170,   171,   180,   181,   189,
     194,   196,   198,   200,   202,   204,   208,   210,   212,   216,
     218,   222,   226,   228,   232,   234,   241,   244,   245,   251,
     252,   257,   261,   262
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    35,    60,     8,    -1,    61,    43,    60,
      -1,    61,    -1,    62,    -1,    70,    -1,   100,    -1,   102,
      -1,   103,    -1,   106,    -1,    65,    63,    -1,    -1,    15,
      64,    44,    63,    -1,    15,    -1,    66,    -1,    67,    -1,
       9,    -1,    10,    -1,    11,    -1,    12,    45,    68,    46,
      -1,    69,    44,    68,    -1,    69,    -1,    66,    15,    -1,
      -1,    15,    71,    40,    72,    -1,    72,    73,    74,    -1,
      74,    -1,    24,    -1,    25,    -1,    76,    75,    76,    -1,
      76,    -1,    36,    -1,    37,    -1,    47,    -1,    38,    -1,
      48,    -1,    39,    -1,    76,    77,    78,    -1,    78,    -1,
      49,    -1,    50,    -1,    78,    79,    80,    -1,    80,    -1,
      51,    -1,    52,    -1,    82,    -1,    81,    80,    -1,    45,
      72,    46,    -1,    15,    -1,    92,    -1,    50,    -1,    26,
      -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,    89,
      -1,    87,    -1,    91,    -1,    34,    53,    72,    54,    -1,
      27,    53,    63,    54,    -1,    28,    53,    72,    54,    -1,
      29,    53,    72,    54,    -1,    30,    53,    72,    54,    -1,
      -1,    32,    53,    66,    15,    88,    55,    72,    54,    -1,
      -1,    31,    53,    15,    90,    40,    72,    54,    -1,    33,
      53,    63,    54,    -1,    93,    -1,    94,    -1,    21,    -1,
      22,    -1,    23,    -1,    56,    95,    57,    -1,    96,    -1,
      99,    -1,    97,    44,    96,    -1,    97,    -1,    45,    98,
      46,    -1,    93,    44,    98,    -1,    93,    -1,    66,    44,
      99,    -1,    66,    -1,     3,    72,     4,    60,   101,     8,
      -1,     5,    60,    -1,    -1,     6,    72,     7,    60,     8,
      -1,    -1,    13,   105,    15,   104,    -1,    53,    72,    54,
      -1,    -1,    14,   105,    72,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    16,    16,    21,    22,    24,    25,    26,    27,    28,
      29,    31,    37,    37,    38,    40,    41,    43,    44,    45,
      47,    52,    53,    55,    57,    57,    63,    64,    66,    67,
      69,    76,    81,    82,    83,    84,    85,    86,    88,    93,
      95,    96,    98,   102,   104,   105,   106,   108,   109,   110,
     111,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     123,   128,   133,   138,   143,   148,   148,   155,   155,   161,
     166,   167,   169,   170,   171,   173,   175,   176,   178,   179,
     181,   183,   184,   186,   187,   189,   197,   201,   203,   210,
     210,   216,   220,   222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "THEN", "ELSE", "WHILE", "DO",
  "END", "INTEGER", "STRING", "BOOLEAN", "TABLE", "READ", "WRITE", "ID",
  "BOOL_OP", "UNARY_OP", "HIGH_BIN_OP", "LOW_BIN_OP", "COMP_OP",
  "INT_CONST", "STR_CONST", "BOOL_CONST", "AND", "OR", "NOT", "PROJECT",
  "SELECT", "EXISTS", "ALL", "UPDATE", "EXTEND", "RENAME", "JOIN",
  "PROGRAM", "EQ", "NOT_EQ", "GET", "LET", "ASSIGN", "END_OF_FILE",
  "ERROR", "';'", "','", "'('", "')'", "'>'", "'<'", "'+'", "'-'", "'*'",
  "'/'", "'['", "']'", "'='", "'{'", "'}'", "$accept", "program",
  "stat_list", "stat", "def_stat", "id_list", "@1", "type", "atomic_type",
  "table_type", "attr_list", "attr_decl", "assign_stat", "@2", "expr",
  "bool_op", "bool_term", "comp_op", "comp_term", "low_bin_op", "low_term",
  "high_bin_op", "factor", "unary_op", "join_op", "project_op",
  "select_op", "exists_op", "all_op", "extend_op", "@3", "update_op", "@4",
  "rename_op", "constant", "atomic_const", "table_const", "table_instance",
  "tuple_list", "tuple_const", "atomic_const_l", "atomic_type_l",
  "if_stat", "else_part", "while_stat", "read_stat", "@5", "specifier",
  "write_stat", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    59,    44,    40,    41,    62,    60,    43,
      45,    42,    47,    91,    93,    61,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    62,    64,    63,    63,    65,    65,    66,    66,    66,
      67,    68,    68,    69,    71,    70,    72,    72,    73,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    79,    80,    80,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    83,    84,    85,    86,    88,    87,    90,    89,    91,
      92,    92,    93,    93,    93,    94,    95,    95,    96,    96,
      97,    98,    98,    99,    99,   100,   101,   101,   102,   104,
     103,   105,   105,   106
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     4,     1,     1,     1,     1,     1,     1,
       4,     3,     1,     2,     0,     4,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     0,     8,     0,     7,     4,
       1,     1,     1,     1,     1,     3,     1,     1,     3,     1,
       3,     3,     1,     3,     1,     6,     2,     0,     5,     0,
       4,     3,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    17,    18,    19,     0,    92,
      92,    24,     0,     4,     5,     0,    15,    16,     6,     7,
       8,     9,    10,     1,    49,    72,    73,    74,    52,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
      27,    31,    39,    43,     0,    53,    54,    55,    56,    58,
      57,    59,    50,    70,    71,     0,     0,     0,     0,     0,
       0,     2,     0,    14,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,    76,    79,    77,     0,
      28,    29,     0,    32,    33,    35,    37,    34,    36,    40,
      41,     0,     0,     0,    44,    45,     0,    46,    47,     0,
       0,     0,    22,     0,    89,    93,     0,     3,     0,     0,
       0,     0,     0,    67,     0,     0,    48,    82,     0,     0,
      75,     0,    87,    26,    30,    38,     0,    42,     0,    23,
      20,     0,    91,    90,    25,     0,    61,    62,    63,    64,
       0,    65,    69,     0,    80,    83,    78,     0,     0,     0,
      88,    21,    13,     0,     0,    81,    86,    85,    60,     0,
       0,    68,     0,    66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    12,    13,    14,    64,   108,    15,    16,    17,
     101,   102,    18,    60,    39,    82,    40,    91,    41,    92,
      42,    96,    43,    44,    97,    45,    46,    47,    48,    49,
     154,    50,   140,    51,    52,    53,    54,    75,    76,    77,
     118,    78,    19,   148,    20,    21,   133,    58,    22
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
     -19,   118,    18,    15,    15,   -70,   -70,   -70,   -22,   -24,
     -24,   -70,    23,     7,   -70,    37,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,     6,
       8,    17,    24,    33,    34,    36,    15,   -70,     4,    54,
     -70,    70,   -17,   -70,    15,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,    66,    74,    15,    77,    15,
      53,   -70,   118,    59,   -70,    37,    15,    15,    15,    80,
      74,    37,   -18,    78,    60,    40,   -70,    67,   -70,   118,
     -70,   -70,    15,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,    15,    15,    57,   -70,   -70,    15,   -70,   -70,   118,
      97,    68,    69,   -15,   -70,   -13,    15,   -70,    71,    62,
      -3,     0,     2,   -70,   108,    72,   -70,    81,    88,    74,
     -70,    90,   131,   -70,    31,   -17,    15,   -70,   129,   -70,
     -70,    74,   -70,   -70,   -13,    37,   -70,   -70,   -70,   -70,
      98,   -70,   -70,    78,   -70,   -70,   -70,   118,   132,    42,
     -70,   -70,   -70,    15,    84,   -70,   -70,   -70,   -70,    44,
      15,   -70,    51,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   -59,   -70,   -70,   -63,   -70,   -70,   -37,   -70,
      10,   -70,   -70,   -70,    -4,   -70,    61,   -70,    55,   -70,
      50,   -70,   -39,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -69,   -70,   -70,    26,   -70,
       1,    29,   -70,   -70,   -70,   -70,   -70,   135,   -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -13
static const yytype_int16 yytable[] =
{
      55,    74,   109,   107,   117,    98,    80,    81,   115,    80,
      81,    80,    81,     5,     6,     7,     1,    93,    23,   100,
     122,    80,    81,    56,    80,    81,    80,    81,   116,    57,
      24,    61,    72,   114,    94,    95,    25,    26,    27,   132,
     128,    28,    29,    30,    31,    32,    33,    34,    35,    73,
      62,   137,    63,   103,   138,   105,   139,   127,    79,    65,
      36,    66,   110,   111,   112,    37,    80,    81,    80,    81,
      67,    38,   152,    99,   117,    80,    81,    68,    80,    81,
      89,    90,    74,     5,     6,     7,    69,    70,   156,    71,
      80,    81,   104,   106,   100,   113,   158,   120,   161,    25,
      26,    27,   134,   -12,   119,   163,    83,    84,    85,    86,
     126,   121,   129,   131,   130,   135,   136,    87,    88,    89,
      90,     3,   149,   141,     4,   143,   142,     5,     6,     7,
       8,     9,    10,    11,   144,    73,   147,   150,   153,   160,
     157,   151,   125,   123,   155,    59,   124,   146,   145,   159,
       0,     0,     0,     0,     0,     0,   162
};

static const yytype_int16 yycheck[] =
{
       4,    38,    65,    62,    73,    44,    24,    25,    71,    24,
      25,    24,    25,     9,    10,    11,    35,    34,     0,    56,
      79,    24,    25,    45,    24,    25,    24,    25,    46,    53,
      15,     8,    36,    70,    51,    52,    21,    22,    23,    54,
      99,    26,    27,    28,    29,    30,    31,    32,    33,    45,
      43,    54,    15,    57,    54,    59,    54,    96,     4,    53,
      45,    53,    66,    67,    68,    50,    24,    25,    24,    25,
      53,    56,   135,     7,   143,    24,    25,    53,    24,    25,
      49,    50,   119,     9,    10,    11,    53,    53,   147,    53,
      24,    25,    15,    40,   131,    15,    54,    57,    54,    21,
      22,    23,   106,    44,    44,    54,    36,    37,    38,    39,
      53,    44,    15,    44,    46,    44,    54,    47,    48,    49,
      50,     3,   126,    15,     6,    44,    54,     9,    10,    11,
      12,    13,    14,    15,    46,    45,     5,     8,    40,    55,
       8,   131,    92,    82,   143,    10,    91,   121,   119,   153,
      -1,    -1,    -1,    -1,    -1,    -1,   160
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    59,     3,     6,     9,    10,    11,    12,    13,
      14,    15,    60,    61,    62,    65,    66,    67,    70,   100,
     102,   103,   106,     0,    15,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    45,    50,    56,    72,
      74,    76,    78,    80,    81,    83,    84,    85,    86,    87,
      89,    91,    92,    93,    94,    72,    45,    53,   105,   105,
      71,     8,    43,    15,    63,    53,    53,    53,    53,    53,
      53,    53,    72,    45,    66,    95,    96,    97,    99,     4,
      24,    25,    73,    36,    37,    38,    39,    47,    48,    49,
      50,    75,    77,    34,    51,    52,    79,    82,    80,     7,
      66,    68,    69,    72,    15,    72,    40,    60,    64,    63,
      72,    72,    72,    15,    66,    63,    46,    93,    98,    44,
      57,    44,    60,    74,    76,    78,    53,    80,    60,    15,
      46,    44,    54,   104,    72,    44,    54,    54,    54,    54,
      90,    15,    54,    44,    46,    99,    96,     5,   101,    72,
       8,    68,    63,    40,    88,    98,    60,     8,    54,    72,
      55,    54,    72,    54
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 16 "parser.y"
    {	root = non_term_node(N_PROGRAM); 
						root->child = non_term_node(N_STAT_LIST); 
						root->child->child = (yyvsp[(2) - (3)]);
					;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 21 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]); (yyvsp[(1) - (3)])->brother = (yyvsp[(3) - (3)]);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 22 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 24 "parser.y"
    {(yyval) = non_term_node(N_STAT); (yyval)->child = (yyvsp[(1) - (1)]); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 25 "parser.y"
    {(yyval) = non_term_node(N_STAT); (yyval)->child = (yyvsp[(1) - (1)]); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 26 "parser.y"
    {(yyval) = non_term_node(N_STAT); (yyval)->child = (yyvsp[(1) - (1)]); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 27 "parser.y"
    {(yyval) = non_term_node(N_STAT); (yyval)->child = (yyvsp[(1) - (1)]); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 28 "parser.y"
    {(yyval) = non_term_node(N_STAT); (yyval)->child = (yyvsp[(1) - (1)]); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 29 "parser.y"
    {(yyval) = non_term_node(N_STAT); (yyval)->child = (yyvsp[(1) - (1)]); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 31 "parser.y"
    {	(yyval) = non_term_node(N_DEF_STAT); 
					(yyval)->child = (yyvsp[(1) - (2)]);
					(yyvsp[(1) - (2)])->brother = non_term_node(N_ID_LIST); 
					(yyvsp[(1) - (2)])->brother->child = (yyvsp[(2) - (2)]);
				;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 37 "parser.y"
    {(yyval) = id_node();;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 37 "parser.y"
    {(yyval) = (yyvsp[(2) - (4)]); (yyvsp[(2) - (4)])->brother = (yyvsp[(4) - (4)]); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 38 "parser.y"
    {(yyval) = id_node();;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 40 "parser.y"
    { (yyval) = non_term_node(N_TYPE); (yyval)->child = (yyvsp[(1) - (1)]); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 41 "parser.y"
    { (yyval) = non_term_node(N_TYPE); (yyval)->child = (yyvsp[(1) - (1)]); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 43 "parser.y"
    {(yyval) = non_term_node(N_ATOMIC_TYPE); (yyval)->child = key_node(T_INTEGER);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 44 "parser.y"
    {(yyval) = non_term_node(N_ATOMIC_TYPE); (yyval)->child = key_node(T_STRING);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 45 "parser.y"
    {(yyval) = non_term_node(N_ATOMIC_TYPE); (yyval)->child = key_node(T_BOOLEAN);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 47 "parser.y"
    { 	(yyval) = non_term_node(N_TABLE_TYPE); 
						(yyval)->child = non_term_node(N_ATTR_LIST); 
						(yyval)->child->child = (yyvsp[(3) - (4)]);
					  ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 52 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); (yyvsp[(1) - (3)])->brother = (yyvsp[(3) - (3)]);  ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 53 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 55 "parser.y"
    {(yyval) = non_term_node(N_ATTR_DECL); (yyval)->child = (yyvsp[(1) - (2)]); (yyvsp[(1) - (2)])->brother = id_node(); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 57 "parser.y"
    {(yyval) = id_node();;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 57 "parser.y"
    {	(yyval) = non_term_node(N_ASSIGN_STAT); 
							(yyval)->child = (yyvsp[(2) - (4)]); 						
							(yyvsp[(2) - (4)])->brother = non_term_node(N_EXPR);
							(yyvsp[(2) - (4)])->brother->child =  (yyvsp[(4) - (4)]);
						;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 63 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]); (yyvsp[(1) - (3)])->brother = (yyvsp[(2) - (3)]); (yyvsp[(2) - (3)])->brother = (yyvsp[(3) - (3)]); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 64 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 66 "parser.y"
    { (yyval) = key_node(T_AND);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 67 "parser.y"
    { (yyval) = key_node(T_OR);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 69 "parser.y"
    {	(yyval) = non_term_node(N_BOOL_TERM); 
						(yyval)->child = non_term_node(N_COMP_TERM);
						(yyval)->child->child = (yyvsp[(1) - (3)]);
						(yyval)->child->brother = (yyvsp[(2) - (3)]);
						(yyvsp[(2) - (3)])->brother = non_term_node(N_COMP_TERM);
						(yyvsp[(2) - (3)])->brother->child = (yyvsp[(3) - (3)]);
						;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    { 	(yyval) = non_term_node(N_BOOL_TERM);  
				(yyval)->child = non_term_node(N_COMP_TERM);
				(yyval)->child->child = (yyvsp[(1) - (1)]);
			    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    {(yyval) = key_node(T_EQ);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    {(yyval) = key_node(T_NOT_EQ);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    {(yyval) = key_node(T_GT);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    {(yyval) = key_node(T_GET);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    {(yyval) = key_node(T_LT);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 86 "parser.y"
    {(yyval) = key_node(T_LET);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    {(yyval)=(yyvsp[(1) - (3)]);
						 (yyvsp[(1) - (3)])->brother = (yyvsp[(2) - (3)]);
						 (yyvsp[(2) - (3)])->brother = non_term_node(N_LOW_TERM);
						 (yyvsp[(2) - (3)])->brother->child = (yyvsp[(3) - (3)]);
						;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    {(yyval) = non_term_node(N_LOW_TERM); (yyval)->child = (yyvsp[(1) - (1)]); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    {(yyval) = key_node(T_ADD);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
    {(yyval) = key_node(T_SUB);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]);
						(yyvsp[(1) - (3)])->brother = (yyvsp[(2) - (3)]);
						(yyvsp[(2) - (3)])->brother = (yyvsp[(3) - (3)]);
					      ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    {(yyval) = key_node(T_MUL);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    {(yyval) = key_node(T_DIV);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {(yyval) = non_term_node(N_FACTOR); (yyval)->child = (yyvsp[(1) - (2)]); (yyvsp[(1) - (2)])->brother = (yyvsp[(2) - (2)]);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    {(yyval) = non_term_node(N_FACTOR); (yyval)->child = non_term_node(N_EXPR); (yyval)->child->child = (yyvsp[(2) - (3)]);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    {(yyval) = non_term_node(N_FACTOR); (yyval)->child = id_node();;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    {(yyval) = non_term_node(N_FACTOR); (yyval)->child = (yyvsp[(1) - (1)]);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {(yyval) = non_term_node(N_UNARY_OP); (yyval)->child = key_node(T_UNARY_MINUS);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    {(yyval) = non_term_node(N_UNARY_OP); (yyval)->child = key_node(T_NOT);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    {(yyval) = non_term_node(N_UNARY_OP); (yyval)->child = (yyvsp[(1) - (1)]);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    {(yyval) = non_term_node(N_UNARY_OP); (yyval)->child = (yyvsp[(1) - (1)]);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    {(yyval) = non_term_node(N_UNARY_OP); (yyval)->child = (yyvsp[(1) - (1)]);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 118 "parser.y"
    {(yyval) = non_term_node(N_UNARY_OP); (yyval)->child = (yyvsp[(1) - (1)]);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    {(yyval) = non_term_node(N_UNARY_OP); (yyval)->child = (yyvsp[(1) - (1)]);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {(yyval) = non_term_node(N_UNARY_OP); (yyval)->child = (yyvsp[(1) - (1)]);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    {(yyval) = non_term_node(N_UNARY_OP); (yyval)->child = (yyvsp[(1) - (1)]);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {	(yyval) = non_term_node(N_JOIN_OP); 
					(yyval)->child = non_term_node(N_EXPR); 
					(yyval)->child->child = (yyvsp[(3) - (4)]);
				    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    { 	(yyval) = non_term_node(N_PROJECT_OP); 
						(yyval)->child = non_term_node(N_ID_LIST); 
						(yyval)->child->child = (yyvsp[(3) - (4)]);
					  ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    {	(yyval) = non_term_node(N_SELECT_OP); 
					(yyval)->child = non_term_node(N_EXPR); 
					(yyval)->child->child = (yyvsp[(3) - (4)]);
				      ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    { (yyval) = non_term_node(N_EXISTS_OP); 
					(yyval)->child = non_term_node(N_EXPR); 
					(yyval)->child->child = (yyvsp[(3) - (4)]);
				      ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    { 	(yyval) = non_term_node(N_ALL_OP); 
					(yyval)->child = non_term_node(N_EXPR); 
					(yyval)->child->child = (yyvsp[(3) - (4)]);
				   ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 148 "parser.y"
    {(yyval) = id_node();;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 148 "parser.y"
    {	(yyval) = non_term_node(N_EXTEND_OP); 
										(yyval)->child = (yyvsp[(3) - (8)]);
										(yyvsp[(3) - (8)])->brother = (yyvsp[(5) - (8)]);
										(yyvsp[(5) - (8)])->brother = non_term_node(N_EXPR); 
										(yyvsp[(5) - (8)])->brother->child = (yyvsp[(6) - (8)]);
							 		   ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    {(yyval) = id_node();;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    {(yyval) = non_term_node(N_UPDATE_OP);
								(yyval)->child = (yyvsp[(4) - (7)]);
								(yyvsp[(4) - (7)])->brother = non_term_node(N_EXPR); 
								(yyvsp[(4) - (7)])->brother->child = (yyvsp[(6) - (7)]);			
							       ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    { 	(yyval) = non_term_node(N_RENAME_OP); 
						(yyval)->child = non_term_node(N_ID_LIST); 
						(yyval)->child->child = (yyvsp[(3) - (4)]);
					  ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    {(yyval) = non_term_node(N_CONSTANT); (yyval)->child = (yyvsp[(1) - (1)]);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {(yyval) = non_term_node(N_CONSTANT); (yyval)->child = (yyvsp[(1) - (1)]);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {(yyval) = non_term_node(N_ATOMIC_CONST); (yyval)->child = int_const_node();;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    {(yyval) = non_term_node(N_ATOMIC_CONST); (yyval)->child = str_const_node();;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {(yyval) = non_term_node(N_ATOMIC_CONST); (yyval)->child = bool_const_node();;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    { (yyval) = non_term_node(N_TABLE_CONST); (yyval)->child = (yyvsp[(2) - (3)]); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 175 "parser.y"
    {(yyval) = non_term_node(N_TUPLE_LIST); (yyval)->child = (yyvsp[(1) - (1)]); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    { (yyval) = non_term_node(N_ATOMIC_TYPE_LIST); (yyval)->child = (yyvsp[(1) - (1)]); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    {(yyval) = non_term_node(N_TUPLE_CONST); (yyval)->brother = (yyvsp[(3) - (3)]); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {(yyval) = non_term_node(N_TUPLE_CONST); (yyval)->child = (yyvsp[(2) - (3)]);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]); (yyvsp[(1) - (3)])->brother = (yyvsp[(3) - (3)]);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 186 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]); (yyval)->brother = (yyvsp[(3) - (3)]);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 187 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {(yyval) = non_term_node(N_IF_STAT); 
							(yyval)->child = non_term_node(N_EXPR);
							(yyval)->child->child = (yyvsp[(2) - (6)]);
							(yyval)->child->brother = non_term_node(N_STAT_LIST);
							(yyval)->child->brother->child = (yyvsp[(4) - (6)]);
							(yyval)->child->brother->brother = (yyvsp[(5) - (6)]);
						       ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {	 
					(yyval) = non_term_node(N_STAT_LIST); 
					(yyval)->child = (yyvsp[(2) - (2)]);
				 ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    {(yyval) = NULL; ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    {	(yyval) = non_term_node(N_WHILE_STAT); 
						(yyval)->child = non_term_node(N_EXPR);
						(yyval)->child->child = (yyvsp[(2) - (5)]);
						(yyval)->child->brother = non_term_node(N_STAT_LIST);
						(yyval)->child->brother->child = (yyvsp[(4) - (5)]);
					      ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    {(yyval) = id_node();;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    { 	(yyval) = non_term_node(N_READ_STAT);
					(yyval)->child = (yyvsp[(2) - (4)]);
					(yyvsp[(2) - (4)])->brother = (yyvsp[(4) - (4)]);
					//$3 = id_node();	
				    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    {	(yyval) = non_term_node(N_SPECIFIER); 
					(yyval)->child = non_term_node(N_EXPR);
					(yyval)->child->child = (yyvsp[(2) - (3)]);
			       ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    {(yyval) = non_term_node(N_SPECIFIER); (yyval)->child = NULL; ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    {	(yyval) = non_term_node(N_WRITE_STAT); 
						(yyval)->child = (yyvsp[(1) - (3)]);
						(yyvsp[(1) - (3)])->brother = non_term_node(N_EXPR);				
						(yyvsp[(1) - (3)])->brother->child = (yyvsp[(3) - (3)]);			
					;}
    break;



/* Line 1455 of yacc.c  */
#line 2243 "parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 229 "parser.y"


/*Funzione per la creazione di un nodo generico.
  Crea il nodo e annulla i puntatori al figlio e al fratello
*/
pNode new_node(Typenode type_node){
	pNode p;

	p = (pNode) malloc(sizeof(Node));
	p->type = type_node;
	p->child = NULL;
	p->brother = NULL;
	return p;
}

/*Crea un nodo di tipo non_terminale.
  Chiama la funzione new_node e assegna al campo value.ival il tipo di terminale*/	
pNode non_term_node(Nonterminal nonterm){
	pNode p = new_node(T_NONTERMINAL);
	p->value.ival = nonterm;
	return p;
}


/*Crea un nodo di tipo id.
  Chiama la funzione new_node e assegna al campo value.sval il nome dell'id*/
pNode id_node(){
	pNode p = new_node(T_ID);
	p->value.sval = lexval.sval;
	return p;
}

/*Crea un nodo di tipo str_const.
  Chiama la funzione new_node e assegna al campo value.sval la stringa*/
pNode str_const_node(){
	pNode p = new_node(T_STRCONST);
	p->value.sval = lexval.sval;
	return p;
}


/*Crea un nodo di tipo int_const.
  Chiama la funzione new_node e assegna al campo value.ival il valore*/
pNode int_const_node(){
	pNode p = new_node(T_INTCONST);
	p->value.ival = lexval.ival;
	return p;
}


/*Crea un nodo di tipo bool_const.
  Chiama la funzione new_node e assegna al campo value.ival il valore*/
pNode bool_const_node(){
	pNode p = new_node(T_BOOLCONST);
	p->value.ival = lexval.ival;
	return p;
}


/*Crea un nodo di tipo keyword
  Questi nodi rappresentano anche gli operatori (tutti i binari e il '-' e il 'not' unari.
  Gli altri operatori unari non hanno bisogno di essere definiti con un tipo in quanto hanno un non_terminale associato.*/
pNode key_node(Typenode keyword){
	pNode p = new_node(keyword);
	return p;
}



int main(){
	int result;
	
	yyin = stdin;
	if ((result = yyparse())==0)
		tree_print(root,0);
	return(result);		
}


yyerror() {
  fprintf(stderr, "Line %d: syntax error on symbol \"%s\"\n",line, yytext);
  exit(-1);
}


