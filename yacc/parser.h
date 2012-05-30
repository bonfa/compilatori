
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


