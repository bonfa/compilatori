
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
#define YYSTYPE Pnode
#define YYDEBUG 1

extern char *yytext;
extern int line;
extern Value lexval;

int yydebug = 0;
Pnode root = NULL;


/* Line 189 of yacc.c  */
#line 87 "parser.c"

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
     ALL = 258,
     AND = 259,
     BOOLCONST = 260,
     BOOLEAN = 261,
     DO = 262,
     ELSE = 263,
     END = 264,
     EQ = 265,
     ERROR = 266,
     EXISTS = 267,
     EXTEND = 268,
     GE = 269,
     ID = 270,
     IF = 271,
     INTCONST = 272,
     INTEGER = 273,
     JOIN = 274,
     LE = 275,
     NE = 276,
     NOT = 277,
     OR = 278,
     PROGRAM = 279,
     PROJECT = 280,
     READ = 281,
     RENAME = 282,
     SELECT = 283,
     STRCONST = 284,
     STRING = 285,
     TABLE = 286,
     THEN = 287,
     UPDATE = 288,
     WHILE = 289,
     WRITE = 290
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
#line 164 "parser.c"

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
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,    39,    45,    43,    37,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
      42,    40,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      35
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
     145,   150,   155,   160,   165,   170,   171,   179,   180,   189,
     194,   196,   198,   200,   202,   204,   208,   210,   212,   216,
     218,   222,   226,   228,   232,   234,   241,   244,   245,   251,
     255,   259,   260
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    24,    53,     9,    -1,    54,    36,    53,
      -1,    54,    -1,    55,    -1,    63,    -1,    93,    -1,    95,
      -1,    96,    -1,    98,    -1,    58,    56,    -1,    -1,    15,
      57,    37,    56,    -1,    15,    -1,    59,    -1,    60,    -1,
      18,    -1,    30,    -1,     6,    -1,    31,    38,    61,    39,
      -1,    62,    37,    61,    -1,    62,    -1,    59,    15,    -1,
      -1,    15,    64,    40,    65,    -1,    65,    66,    67,    -1,
      67,    -1,     4,    -1,    23,    -1,    69,    68,    69,    -1,
      69,    -1,    10,    -1,    21,    -1,    41,    -1,    14,    -1,
      42,    -1,    20,    -1,    69,    70,    71,    -1,    71,    -1,
      43,    -1,    44,    -1,    71,    72,    73,    -1,    73,    -1,
      45,    -1,    46,    -1,    75,    -1,    74,    73,    -1,    38,
      65,    39,    -1,    15,    -1,    85,    -1,    44,    -1,    22,
      -1,    76,    -1,    77,    -1,    78,    -1,    79,    -1,    80,
      -1,    82,    -1,    84,    -1,    19,    47,    65,    48,    -1,
      25,    47,    56,    48,    -1,    28,    47,    65,    48,    -1,
      12,    47,    65,    48,    -1,     3,    47,    65,    48,    -1,
      -1,    33,    47,    15,    81,    40,    65,    48,    -1,    -1,
      13,    47,    59,    15,    83,    40,    65,    48,    -1,    27,
      47,    56,    48,    -1,    86,    -1,    87,    -1,    17,    -1,
      29,    -1,     5,    -1,    49,    88,    50,    -1,    89,    -1,
      92,    -1,    90,    37,    89,    -1,    90,    -1,    38,    91,
      39,    -1,    86,    37,    91,    -1,    86,    -1,    59,    37,
      92,    -1,    59,    -1,    16,    65,    32,    53,    94,     9,
      -1,     8,    53,    -1,    -1,    34,    65,     7,    53,     9,
      -1,    26,    97,    15,    -1,    47,    65,    48,    -1,    -1,
      35,    97,    65,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    20,    20,    23,    24,    27,    28,    29,    30,    31,
      32,    35,    38,    38,    39,    42,    43,    46,    47,    48,
      51,    54,    55,    58,    61,    61,    64,    65,    68,    69,
      72,    73,    76,    77,    78,    79,    80,    81,    84,    85,
      88,    89,    92,   104,   107,   108,   109,   112,   122,   123,
     124,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     138,   141,   144,   147,   150,   153,   153,   156,   156,   159,
     162,   163,   166,   167,   168,   171,   174,   175,   178,   179,
     182,   185,   186,   189,   190,   193,   196,   197,   200,   203,
     206,   207,   210
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ALL", "AND", "BOOLCONST", "BOOLEAN",
  "DO", "ELSE", "END", "EQ", "ERROR", "EXISTS", "EXTEND", "GE", "ID", "IF",
  "INTCONST", "INTEGER", "JOIN", "LE", "NE", "NOT", "OR", "PROGRAM",
  "PROJECT", "READ", "RENAME", "SELECT", "STRCONST", "STRING", "TABLE",
  "THEN", "UPDATE", "WHILE", "WRITE", "';'", "','", "'('", "')'", "'='",
  "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'['", "']'", "'{'", "'}'",
  "$accept", "program", "stat_list", "stat", "def_stat", "id_list", "@1",
  "type", "atomic_type", "table_type", "attr_list", "attr_decl",
  "assign_stat", "@2", "expr", "bool_op", "bool_term", "comp_op",
  "comp_term", "low_bin_op", "low_term", "high_bin_op", "factor",
  "unary_op", "join_op", "project_op", "select_op", "exists_op", "all_op",
  "update_op", "@3", "extend_op", "@4", "rename_op", "const",
  "atomic_const", "table_const", "table_instance", "tuple_list",
  "tuple_const", "atomic_const_list", "atomic_type_list", "if_stat",
  "else_part", "while_stat", "read_stat", "specifier", "write_stat", 0
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
     285,   286,   287,   288,   289,   290,    59,    44,    40,    41,
      61,    62,    60,    43,    45,    42,    47,    91,    93,   123,
     125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    55,    57,    56,    56,    58,    58,    59,    59,    59,
      60,    61,    61,    62,    64,    63,    65,    65,    66,    66,
      67,    67,    68,    68,    68,    68,    68,    68,    69,    69,
      70,    70,    71,    71,    72,    72,    72,    73,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      75,    76,    77,    78,    79,    81,    80,    83,    82,    84,
      85,    85,    86,    86,    86,    87,    88,    88,    89,    89,
      90,    91,    91,    92,    92,    93,    94,    94,    95,    96,
      97,    97,    98
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
       4,     4,     4,     4,     4,     0,     7,     0,     8,     4,
       1,     1,     1,     1,     1,     3,     1,     1,     3,     1,
       3,     3,     1,     3,     1,     6,     2,     0,     5,     3,
       3,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    19,    24,     0,    17,    91,    18,     0,
       0,    91,     0,     4,     5,     0,    15,    16,     6,     7,
       8,     9,    10,     1,     0,     0,    74,     0,     0,    49,
      72,    52,     0,     0,     0,    73,     0,     0,    51,     0,
       0,    27,    31,    39,    43,     0,    53,    54,    55,    56,
      57,    58,    59,    50,    70,    71,     0,     0,     0,     0,
       0,     2,     0,    14,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,    76,    79,    77,
      28,    29,     0,     0,    32,    35,    37,    33,    34,    36,
      40,    41,     0,     0,     0,    44,    45,     0,    46,    47,
       0,    89,     0,     0,    22,     0,    92,     3,     0,    25,
       0,     0,     0,     0,     0,     0,    65,    48,    82,     0,
       0,    75,     0,    87,    26,    30,    38,     0,    42,    90,
      23,    20,     0,     0,     0,    64,    63,    67,    61,    69,
      62,     0,     0,    80,    83,    78,     0,     0,     0,    21,
      88,    13,     0,     0,    81,    86,    85,    60,     0,     0,
       0,    66,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    12,    13,    14,    64,   108,    15,    16,    17,
     103,   104,    18,    24,    40,    83,    41,    92,    42,    93,
      43,    97,    44,    45,    98,    46,    47,    48,    49,    50,
     141,    51,   152,    52,    53,    54,    55,    76,    77,    78,
     119,    79,    19,   147,    20,    21,    57,    22
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -72
static const yytype_int16 yypact[] =
{
     -16,    85,    13,   -72,   -72,     4,   -72,   -29,   -72,   -24,
       4,   -29,    14,   -11,   -72,    21,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,     9,    18,   -72,    28,    29,   -72,
     -72,   -72,    42,    45,    49,   -72,    61,     4,   -72,    60,
      70,   -72,    63,    -7,   -72,     4,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,     4,    52,    34,   106,
       4,   -72,    85,    50,   -72,     4,     4,     4,    34,    21,
      21,     4,    97,    58,   104,    77,    68,   -72,    86,   -72,
     -72,   -72,    85,     4,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,     4,     4,    75,   -72,   -72,     4,   -72,   -72,
      11,   -72,   109,    87,    88,    85,    76,   -72,    90,    76,
      20,    24,   113,    82,    83,    31,   -72,   -72,    95,    96,
      34,   -72,    98,   126,   -72,   -33,    -7,     4,   -72,   -72,
     -72,   -72,    34,   128,    21,   -72,   -72,   -72,   -72,   -72,
     -72,    99,   104,   -72,   -72,   -72,    85,   129,    37,   -72,
     -72,   -72,   100,     4,   -72,   -72,   -72,   -72,     4,    40,
      47,   -72,   -72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -60,   -72,   -72,   -65,   -72,   -72,   -38,   -72,
      10,   -72,   -72,   -72,   -10,   -72,    62,   -72,    54,   -72,
      48,   -72,   -39,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -71,   -72,   -72,    22,   -72,
       5,    30,   -72,   -72,   -72,   -72,   138,   -72
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -13
static const yytype_int16 yytable[] =
{
      59,    75,   107,   118,   113,   114,    99,    25,     1,    26,
      90,    91,    94,    23,    58,    80,    27,    28,    56,    29,
     102,    30,   123,    61,    80,    62,    31,    73,    80,    32,
     112,    33,    34,    35,    81,    80,    63,    36,    95,    96,
       3,    80,    37,    81,    80,   133,   100,    81,    38,    65,
     106,    80,     6,    39,    81,   109,   110,   111,   128,   129,
      81,   115,    80,    81,     8,    66,     3,   101,   135,   151,
      81,   118,   136,    84,    80,    67,    68,    85,     6,   140,
      80,    81,    75,    86,    87,   157,   155,   -12,   161,    69,
       8,     3,    70,    81,   102,   162,    71,   117,    74,    81,
       4,     5,    82,     6,    88,    89,    90,    91,    72,    26,
      80,     7,   116,   105,   120,     8,     9,   148,   121,    10,
      11,    30,   127,   122,   130,   132,   131,   134,   137,    81,
     138,   139,   142,    35,   146,   143,    74,   150,   156,   153,
     158,   126,   149,   159,   145,   124,   125,   154,   160,    60,
     144
};

static const yytype_uint8 yycheck[] =
{
      10,    39,    62,    74,    69,    70,    45,     3,    24,     5,
      43,    44,    19,     0,    38,     4,    12,    13,    47,    15,
      58,    17,    82,     9,     4,    36,    22,    37,     4,    25,
      68,    27,    28,    29,    23,     4,    15,    33,    45,    46,
       6,     4,    38,    23,     4,   105,    56,    23,    44,    40,
      60,     4,    18,    49,    23,    65,    66,    67,    97,    48,
      23,    71,     4,    23,    30,    47,     6,    15,    48,   134,
      23,   142,    48,    10,     4,    47,    47,    14,    18,    48,
       4,    23,   120,    20,    21,    48,   146,    37,    48,    47,
      30,     6,    47,    23,   132,    48,    47,    39,    38,    23,
      15,    16,    32,    18,    41,    42,    43,    44,    47,     5,
       4,    26,    15,     7,    37,    30,    31,   127,    50,    34,
      35,    17,    47,    37,    15,    37,    39,    37,    15,    23,
      48,    48,    37,    29,     8,    39,    38,     9,     9,    40,
      40,    93,   132,   153,   122,    83,    92,   142,   158,    11,
     120
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    52,     6,    15,    16,    18,    26,    30,    31,
      34,    35,    53,    54,    55,    58,    59,    60,    63,    93,
      95,    96,    98,     0,    64,     3,     5,    12,    13,    15,
      17,    22,    25,    27,    28,    29,    33,    38,    44,    49,
      65,    67,    69,    71,    73,    74,    76,    77,    78,    79,
      80,    82,    84,    85,    86,    87,    47,    97,    38,    65,
      97,     9,    36,    15,    56,    40,    47,    47,    47,    47,
      47,    47,    47,    65,    38,    59,    88,    89,    90,    92,
       4,    23,    32,    66,    10,    14,    20,    21,    41,    42,
      43,    44,    68,    70,    19,    45,    46,    72,    75,    73,
      65,    15,    59,    61,    62,     7,    65,    53,    57,    65,
      65,    65,    59,    56,    56,    65,    15,    39,    86,    91,
      37,    50,    37,    53,    67,    69,    71,    47,    73,    48,
      15,    39,    37,    53,    37,    48,    48,    15,    48,    48,
      48,    81,    37,    39,    92,    89,     8,    94,    65,    61,
       9,    56,    83,    40,    91,    53,     9,    48,    40,    65,
      65,    48,    48
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
#line 20 "parser.y"
    {root = (yyval) = newnode(N_PROGRAM); (yyval)->child = newnode(N_STAT_LIST); (yyval)->child->child = (yyvsp[(2) - (3)]);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 23 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]); (yyvsp[(1) - (3)])->brother = (yyvsp[(3) - (3)]);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 35 "parser.y"
    {(yyval) = newnode(N_DEF_STAT); (yyval)->child = (yyvsp[(1) - (2)]); (yyvsp[(1) - (2)])->brother = (yyvsp[(2) - (2)]);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 38 "parser.y"
    {(yyval) = idnode(lexval.sval);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 38 "parser.y"
    {(yyval) = (yyvsp[(2) - (4)]); (yyvsp[(2) - (4)])->brother = (yyvsp[(4) - (4)]);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 39 "parser.y"
    {(yyval) = idnode(lexval.sval);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 42 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 43 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 46 "parser.y"
    {(yyval) = qualnode(N_ATOMIC_TYPE, INTEGER);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 47 "parser.y"
    {(yyval) = qualnode(N_ATOMIC_TYPE, STRING);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 48 "parser.y"
    {(yyval) = qualnode(N_ATOMIC_TYPE, BOOLEAN);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 51 "parser.y"
    {(yyval) = qualnode(N_TABLE_TYPE, TABLE); (yyval)->child = (yyvsp[(3) - (4)]);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 54 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]); (yyvsp[(1) - (3)])->brother = (yyvsp[(3) - (3)]);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 58 "parser.y"
    {(yyval) = newnode(N_ATTR_DECL); (yyval)->child = (yyvsp[(1) - (2)]); (yyvsp[(1) - (2)])->brother = idnode(lexval.sval);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 61 "parser.y"
    {(yyval) = idnode(lexval.sval);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 61 "parser.y"
    {(yyval) = newnode(N_ASSIGN_STAT); (yyval)->child = (yyvsp[(2) - (4)]); (yyvsp[(2) - (4)])->brother = (yyvsp[(4) - (4)]);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 64 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]); (yyval)->child = (yyvsp[(1) - (3)]); (yyvsp[(1) - (3)])->brother = (yyvsp[(3) - (3)]);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 68 "parser.y"
    {(yyval) = qualnode(N_LOGIC_EXPR, AND);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 69 "parser.y"
    {(yyval) = qualnode(N_LOGIC_EXPR, OR);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]); (yyval)->child = (yyvsp[(1) - (3)]); (yyvsp[(1) - (3)])->brother = (yyvsp[(3) - (3)]);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    {(yyval) = qualnode(N_COMP_EXPR, EQ);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 77 "parser.y"
    {(yyval) = qualnode(N_COMP_EXPR, NE);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    {(yyval) = qualnode(N_COMP_EXPR, '>');;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    {(yyval) = qualnode(N_COMP_EXPR, GE);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    {(yyval) = qualnode(N_COMP_EXPR, '<');;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    {(yyval) = qualnode(N_COMP_EXPR, LE);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]); (yyval)->child = (yyvsp[(1) - (3)]); (yyvsp[(1) - (3)])->brother = (yyvsp[(3) - (3)]);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    {(yyval) = qualnode(N_MATH_EXPR, '+');;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    {(yyval) = qualnode(N_MATH_EXPR, '-');;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 92 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]); 
                                        if((yyval)->type == N_JOIN_EXPR) 
                                        {
                                          (yyvsp[(1) - (3)])->brother = (yyval)->child;
                                          (yyvsp[(1) - (3)])->brother->brother = (yyvsp[(3) - (3)]);
                                          (yyval)->child = (yyvsp[(1) - (3)]); 
                                        }
                                        else
                                        {
                                          (yyval)->child = (yyvsp[(1) - (3)]); 
                                          (yyvsp[(1) - (3)])->brother = (yyvsp[(3) - (3)]);
                                        };}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    {(yyval) = qualnode(N_MATH_EXPR, '*');;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {(yyval) = qualnode(N_MATH_EXPR, '/');;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]); if((yyvsp[(1) - (2)])->type == N_SELECT_EXPR) 
                                     (yyvsp[(1) - (2)])->child->brother = (yyvsp[(2) - (2)]);
                                    else if((yyval)->type == N_PROJECT_EXPR || (yyval)->type == N_RENAME_EXPR || (yyval)->type == N_UPDATE_EXPR || (yyval)->type == N_EXTEND_EXPR)
                                    {
				      (yyval)->child = (yyvsp[(2) - (2)]); 
                                      (yyval)->child->brother = (yyval)->brother;
                                      (yyval)->brother = NULL;
                                    }
                                    else 
                                      (yyval)->child = (yyvsp[(2) - (2)]);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {(yyval) = idnode(lexval.sval);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    {(yyval) = qualnode(N_NEG_EXPR, '-');;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {(yyval) = qualnode(N_NEG_EXPR, NOT);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    {(yyval) = newnode(N_JOIN_EXPR); (yyval)->child = (yyvsp[(3) - (4)]);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    {(yyval) = newnode(N_PROJECT_EXPR); (yyval)->brother = (yyvsp[(3) - (4)]);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    {(yyval) = qualnode(N_SELECT_EXPR, SELECT); (yyval)->child = (yyvsp[(3) - (4)]);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    {(yyval) = qualnode(N_SELECT_EXPR, EXISTS); (yyval)->child = (yyvsp[(3) - (4)]);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {(yyval) = qualnode(N_SELECT_EXPR, ALL); (yyval)->child = (yyvsp[(3) - (4)]);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {(yyval) = idnode(lexval.sval);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {(yyval) = newnode(N_UPDATE_EXPR); (yyval)->brother = (yyvsp[(4) - (7)]); (yyvsp[(4) - (7)])->brother = (yyvsp[(6) - (7)]);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {(yyval) = idnode(lexval.sval);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {(yyval) = newnode(N_EXTEND_EXPR); (yyval)->brother = (yyvsp[(3) - (8)]); (yyvsp[(3) - (8)])->brother = (yyvsp[(5) - (8)]); (yyvsp[(5) - (8)])->brother = (yyvsp[(7) - (8)]);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    {(yyval) = newnode(N_RENAME_EXPR); (yyval)->brother = (yyvsp[(3) - (4)]);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    {(yyval) = intconstnode(lexval.ival);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {(yyval) = strconstnode(lexval.sval);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    {(yyval) = boolconstnode(lexval.ival);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {(yyval) = newnode(N_TABLE_CONST); (yyval)->child = (yyvsp[(2) - (3)]);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]); (yyvsp[(1) - (3)])->brother = (yyvsp[(3) - (3)]);;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {(yyval) = newnode(N_TUPLE_CONST); (yyval)->child = (yyvsp[(2) - (3)]);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]); (yyvsp[(1) - (3)])->brother = (yyvsp[(3) - (3)]);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]); (yyvsp[(1) - (3)])->brother = (yyvsp[(3) - (3)]);;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    {(yyval) = newnode(N_IF_STAT); (yyval)->child = (yyvsp[(2) - (6)]); (yyvsp[(2) - (6)])->brother = newnode(N_STAT_LIST); (yyvsp[(2) - (6)])->brother->child = (yyvsp[(4) - (6)]); (yyvsp[(2) - (6)])->brother->brother = (yyvsp[(5) - (6)]);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 196 "parser.y"
    {(yyval) = newnode(N_STAT_LIST); (yyval)->child = (yyvsp[(2) - (2)]);;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {(yyval) = NULL;;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 200 "parser.y"
    {(yyval) = newnode(N_WHILE_STAT); (yyval)->child = (yyvsp[(2) - (5)]); (yyvsp[(2) - (5)])->brother = newnode(N_STAT_LIST); (yyvsp[(2) - (5)])->brother->child = (yyvsp[(4) - (5)]);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    {(yyval) = newnode(N_READ_STAT); (yyval)->child = (yyvsp[(2) - (3)]); (yyvsp[(2) - (3)])->brother = idnode(lexval.sval);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    {(yyval) = newnode(N_SPECIFIER); (yyval)->child = (yyvsp[(2) - (3)]);;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    {(yyval) = newnode(N_SPECIFIER);;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    {(yyval) = newnode(N_WRITE_STAT); (yyval)->child = (yyvsp[(2) - (3)]); (yyvsp[(2) - (3)])->brother = (yyvsp[(3) - (3)]);;}
    break;



/* Line 1455 of yacc.c  */
#line 1972 "parser.c"
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
#line 213 "parser.y"


Pnode newnode(Typenode tn)
{
    Pnode p = malloc(sizeof(Node));
    p->type = tn;
    p->line = line;
    p->child = p->brother = NULL;
    return(p);
}

Pnode qualnode(Typenode tn, int qual)
{
    Pnode p = newnode(tn);
    p->value.ival = qual;
    return(p);
}

Pnode intconstnode(int i)
{
    Pnode p = newnode(N_INTCONST);
    p->value.ival = i;
    return(p);
}

Pnode strconstnode(char *s)
{
    Pnode p = newnode(N_STRCONST);
    p->value.sval = s;
    return(p);
}

Pnode boolconstnode(int b)
{
    Pnode p = newnode(N_BOOLCONST);
    p->value.ival = b;
    return(p);
}

Pnode idnode(char *s)
{
    Pnode p = newnode(N_ID);
    p->value.sval = s;
    return(p);
}

int yyerror()
{
  printf("Line %d: syntax error on symbol \"%s\"\n", line, yytext);
  exit(-1);
}


