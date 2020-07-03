/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END = 0,
    EQEQUAL = 258,
    NOTEQUAL = 259,
    LESSEQUAL = 260,
    GREATEREQUAL = 261,
    STRING = 262,
    TILDE = 263,
    CIRCUMFLEX = 264,
    LEFTSHIFT = 265,
    RIGHTSHIFT = 266,
    DOUBLESTAR = 267,
    PLUSEQUAL = 268,
    MINEQUAL = 269,
    STAREQUAL = 270,
    SLASHEQUAL = 271,
    PERCENTEQUAL = 272,
    AMPEREQUAL = 273,
    VBAREQUAL = 274,
    CIRCUMFLEXEQUAL = 275,
    LEFTSHIFTEQUAL = 276,
    RIGHTSHIFTEQUAL = 277,
    DOUBLESTAREQUAL = 278,
    DOUBLESLASH = 279,
    DOUBLESLASHEQUAL = 280,
    AT = 281,
    ATEQUAL = 282,
    RARROW = 283,
    ELLIPSIS = 284,
    COLONEQUAL = 285,
    LPAR = 286,
    RPAR = 287,
    LSQB = 288,
    RSQB = 289,
    COLON = 290,
    COMMA = 291,
    SEMI = 292,
    PLUS = 293,
    MINUS = 294,
    STAR = 295,
    SLASH = 296,
    VBAR = 297,
    AMPER = 298,
    LESS = 299,
    GREATER = 300,
    EQUAL = 301,
    DOT = 302,
    PERCENT = 303,
    LBRACE = 304,
    RBRACE = 305,
    HASH = 306,
    AND = 307,
    BREAK = 308,
    DEF = 309,
    ELIF = 310,
    CLASS = 311,
    ELSE = 312,
    FOR = 313,
    IF = 314,
    IN = 315,
    TRY = 316,
    CATCH = 317,
    FINALLY = 318,
    IMPORT = 319,
    FROM = 320,
    AS = 321,
    NOT = 322,
    IS = 323,
    OR = 324,
    RETURN = 325,
    WHILE = 326,
    TRUE = 327,
    FALSE = 328,
    LAMBDA = 329,
    VAR = 330,
    NUMBER = 331,
    INDENT = 332,
    DEDENT = 333,
    NEWLINE = 334,
    ITEMS = 335,
    SETDEFAULT = 336
  };
#endif
/* Tokens.  */
#define END 0
#define EQEQUAL 258
#define NOTEQUAL 259
#define LESSEQUAL 260
#define GREATEREQUAL 261
#define STRING 262
#define TILDE 263
#define CIRCUMFLEX 264
#define LEFTSHIFT 265
#define RIGHTSHIFT 266
#define DOUBLESTAR 267
#define PLUSEQUAL 268
#define MINEQUAL 269
#define STAREQUAL 270
#define SLASHEQUAL 271
#define PERCENTEQUAL 272
#define AMPEREQUAL 273
#define VBAREQUAL 274
#define CIRCUMFLEXEQUAL 275
#define LEFTSHIFTEQUAL 276
#define RIGHTSHIFTEQUAL 277
#define DOUBLESTAREQUAL 278
#define DOUBLESLASH 279
#define DOUBLESLASHEQUAL 280
#define AT 281
#define ATEQUAL 282
#define RARROW 283
#define ELLIPSIS 284
#define COLONEQUAL 285
#define LPAR 286
#define RPAR 287
#define LSQB 288
#define RSQB 289
#define COLON 290
#define COMMA 291
#define SEMI 292
#define PLUS 293
#define MINUS 294
#define STAR 295
#define SLASH 296
#define VBAR 297
#define AMPER 298
#define LESS 299
#define GREATER 300
#define EQUAL 301
#define DOT 302
#define PERCENT 303
#define LBRACE 304
#define RBRACE 305
#define HASH 306
#define AND 307
#define BREAK 308
#define DEF 309
#define ELIF 310
#define CLASS 311
#define ELSE 312
#define FOR 313
#define IF 314
#define IN 315
#define TRY 316
#define CATCH 317
#define FINALLY 318
#define IMPORT 319
#define FROM 320
#define AS 321
#define NOT 322
#define IS 323
#define OR 324
#define RETURN 325
#define WHILE 326
#define TRUE 327
#define FALSE 328
#define LAMBDA 329
#define VAR 330
#define NUMBER 331
#define INDENT 332
#define DEDENT 333
#define NEWLINE 334
#define ITEMS 335
#define SETDEFAULT 336

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "calc.y"

        int ival;
        char* sval;

#line 226 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
