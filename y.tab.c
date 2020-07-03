/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "calc.y"

#include <stdio.h>
#include <math.h>
#include "list.h"
#include <assert.h>

void yyerror(char *);
extern FILE *yyin;
extern FILE *yyout;
int yylex();

int line_count=1;

struct VarList* vars;
struct DictList* dict;

int varType = -1;

int stringIsVar = -1;

int dont = 0;

int isFunction=0;

int isPrint=0;

int isLambda=0;

int isSetDefault=0;

void topntail(char *str) {
    size_t len = strlen(str);
    assert(len >= 2); // or whatever you want to do with short strings
    memmove(str, str+1, len-2);
    str[len-2] = 0;
}



#line 110 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 331 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   415

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

#define YYUNDEFTOK  2
#define YYMAXUTOK   336


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   145,   145,   148,   151,   152,   155,   156,   157,   162,
     163,   166,   167,   170,   171,   172,   186,   223,   223,   266,
     267,   269,   271,   272,   274,   275,   276,   278,   279,   282,
     284,   285,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   304,   305,   306,   307,   308,   309,
     312,   313,   316,   317,   320,   321,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   335,   339,   340,   343,   344,
     348,   356,   357,   358,   361,   363,   365,   367,   368,   371,
     372,   375,   377,   378,   382,   383,   384,   385,   386,   387,
     388,   389,   392,   393,   396,   415,   416,   419,   420,   423,
     424,   427,   430,   431,   432,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   486,   487,   562,   570,
     578,   579,   582,   583,   603,   606,   607,   610,   611,   614,
     615
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "END", "error", "$undefined", "EQEQUAL", "NOTEQUAL", "LESSEQUAL",
  "GREATEREQUAL", "STRING", "TILDE", "CIRCUMFLEX", "LEFTSHIFT",
  "RIGHTSHIFT", "DOUBLESTAR", "PLUSEQUAL", "MINEQUAL", "STAREQUAL",
  "SLASHEQUAL", "PERCENTEQUAL", "AMPEREQUAL", "VBAREQUAL",
  "CIRCUMFLEXEQUAL", "LEFTSHIFTEQUAL", "RIGHTSHIFTEQUAL",
  "DOUBLESTAREQUAL", "DOUBLESLASH", "DOUBLESLASHEQUAL", "AT", "ATEQUAL",
  "RARROW", "ELLIPSIS", "COLONEQUAL", "LPAR", "RPAR", "LSQB", "RSQB",
  "COLON", "COMMA", "SEMI", "PLUS", "MINUS", "STAR", "SLASH", "VBAR",
  "AMPER", "LESS", "GREATER", "EQUAL", "DOT", "PERCENT", "LBRACE",
  "RBRACE", "HASH", "AND", "BREAK", "DEF", "ELIF", "CLASS", "ELSE", "FOR",
  "IF", "IN", "TRY", "CATCH", "FINALLY", "IMPORT", "FROM", "AS", "NOT",
  "IS", "OR", "RETURN", "WHILE", "TRUE", "FALSE", "LAMBDA", "VAR",
  "NUMBER", "INDENT", "DEDENT", "NEWLINE", "ITEMS", "SETDEFAULT",
  "$accept", "program", "newline", "statements", "stmt", "simple_stmt",
  "small_stmt", "expr_stmt", "$@1", "import_stmt", "import_name",
  "import_var", "dotted", "as_name", "import_from", "import_names",
  "augassign", "compound_stmt", "suite", "newline_or_not", "condition",
  "cmp_symbols", "if_statement", "elif", "else", "def_function",
  "arguments", "while_loop", "for_loop", "try_stmt", "catch_stmt",
  "finally_stmt", "class_stmt", "inheritance", "atom", "key_datum_list",
  "key_datum", "testlist", "atomlist", "test", "lambdadef", "expr",
  "atom_expr", "trailer", "arglist", "argument", "subscriptlist",
  "subscript", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336
};
# endif

#define YYPACT_NINF (-166)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     169,  -166,   198,   198,   -66,   -56,   -50,    20,     1,   -12,
     -12,    20,  -166,  -166,  -166,  -166,  -166,    29,  -166,    41,
     169,  -166,   -25,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,   354,    15,     6,     6,     6,
       6,   219,     9,    11,  -166,   344,    56,    10,    25,    14,
     297,    34,    40,    12,    31,   148,    99,   -19,   -19,  -166,
      24,    16,    33,    66,  -166,  -166,  -166,    35,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,   249,     6,   219,     6,    20,    45,  -166,   265,   -10,
     -10,   221,    58,  -166,    74,    80,  -166,   198,     6,     6,
       6,     6,     6,     6,     6,     6,     6,  -166,     6,  -166,
       6,    49,    50,    91,    53,    99,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,    62,    20,    51,  -166,    69,  -166,  -166,
      71,  -166,  -166,    75,    99,  -166,    86,  -166,   344,   112,
     312,   115,   119,  -166,   -15,   125,  -166,     6,   198,   219,
    -166,   -10,   -10,  -166,  -166,   271,   120,  -166,   221,   363,
    -166,   297,   344,   126,   133,   135,    99,   134,   122,  -166,
    -166,    51,    93,   144,   117,  -166,    24,  -166,   -47,  -166,
       6,  -166,     6,   219,   344,  -166,  -166,    49,   147,  -166,
    -166,    99,    20,   130,  -166,   169,    99,   153,  -166,   154,
     152,  -166,   344,  -166,   157,  -166,    99,  -166,   159,   164,
    -166,   123,  -166,    99,   128,  -166,   168,    56,  -166,  -166,
      99,    99,  -166,  -166,    24,  -166,  -166,   122,  -166,   154,
    -166,  -166
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    84,    86,     3,     0,     8,     0,
       4,     6,     0,    11,    12,    19,    20,     7,    44,    45,
      46,    47,    48,    49,   116,     0,    97,     0,     0,     0,
       0,   124,     0,    95,   100,    99,   115,     0,    92,     0,
      99,     0,    83,     0,     0,    55,     0,    26,    26,    22,
      28,     0,     0,     0,     1,     2,     5,     0,     9,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,     0,   124,     0,     0,     0,   117,     0,   113,
     112,   111,    84,   125,     0,   122,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,     0,    89,
       0,    73,     0,     0,     0,     0,    56,    57,    58,    59,
      60,    61,    62,    63,     0,    53,    50,    78,    25,    24,
       0,    21,    23,     0,     0,    10,    84,    16,    14,     0,
     129,     0,   127,    98,    97,   120,   114,     0,     0,   124,
      96,   104,   105,   106,   107,   108,   109,   110,   102,   103,
      93,     0,    94,    72,     0,     0,     0,     0,    67,    64,
      54,    53,     0,     0,    80,    27,    28,    74,     0,   118,
       0,   119,     0,   124,   126,   101,   123,    73,     0,    82,
      81,     0,     0,    69,    52,     0,     0,     0,    76,    31,
       0,    17,   130,   128,     0,    71,     0,    75,     0,     0,
      65,     0,    77,     0,     0,    29,     0,     0,   121,    70,
       0,     0,    51,    79,    28,    15,    18,    67,    68,    31,
      66,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,     2,   -14,  -166,     3,  -166,  -166,  -166,  -166,
    -166,   194,    -8,  -165,  -166,   -22,  -166,  -166,  -108,    38,
      -7,  -166,  -166,   -17,  -166,  -166,    27,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,    -6,   103,  -166,     5,   127,   -26,
    -166,    37,     0,    -2,   -69,  -166,    42,  -166
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,   125,    19,    20,   126,    22,    23,   217,    24,
      25,    60,    61,   131,    26,   215,    82,    27,   127,   172,
      54,   124,    28,   193,   210,    29,   164,    30,    31,    32,
     174,   198,    33,   113,    34,    47,    48,    42,    35,    43,
      44,    45,    46,    87,    94,    95,   141,   142
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    55,    18,    21,    63,    55,    66,   168,    49,    51,
      57,   199,    67,     1,   139,    93,    83,    57,    84,    52,
      36,    85,    18,    21,    68,    53,   177,     1,    58,    64,
     100,   101,    86,   200,   201,    58,    56,    37,   104,     2,
      50,    65,     1,    96,    38,    39,    83,    97,    84,   128,
     129,    85,   -13,     2,    16,     3,    36,    93,   190,   229,
     107,   108,    86,    59,   109,   111,   115,    36,     2,     3,
     135,   112,   114,    40,    88,    89,    90,    91,    12,    13,
     186,    14,    15,   207,     3,   144,   137,    83,   212,    84,
     130,   132,    12,    13,   -13,    14,    15,   133,   219,     9,
      10,   134,   150,    86,   147,   223,     1,    12,    13,   148,
      14,    15,   227,   228,   204,    36,   149,   170,    55,   138,
     145,   140,   185,    93,   163,   165,   166,   171,   167,   169,
      16,   173,     2,   178,    36,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   179,   161,   175,   162,     3,   181,
     176,   116,   117,   118,   119,   182,   183,    93,    98,    99,
     100,   101,   187,     9,    10,   188,    36,   189,   104,   191,
     195,    12,    13,   171,    14,    15,     1,   192,    16,   196,
     197,   211,   206,   216,   184,   208,    55,   209,   213,   218,
     214,    36,   120,   121,   220,    36,    36,    18,    21,   221,
     225,   222,     2,   224,    62,     1,    36,   231,   122,   194,
     230,   160,   143,    36,   205,   226,   123,   202,     3,   140,
      36,    36,     0,     4,   203,     5,     1,     6,     7,    37,
       8,     2,     0,     9,    10,     0,    38,    39,     0,     0,
      11,    12,    13,     0,    14,    15,     0,     3,    16,     0,
      37,     0,     2,     0,     0,     0,     1,    38,    39,    98,
      99,   100,   101,   102,   103,    40,     0,     0,     3,   104,
      12,    13,    41,    14,    15,     0,     0,     0,     0,     0,
      37,     0,     2,     0,     0,     0,    40,    38,    39,     0,
       0,    12,    13,    41,    92,    15,     0,   146,     3,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,    98,
      99,   100,   101,   104,   103,     0,    40,   105,     0,   104,
       0,    12,    13,    41,   136,    15,     0,     0,     0,     0,
       0,     0,   110,     0,   106,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,   104,     0,   180,     0,   105,
      98,    99,   100,   101,   102,   103,     0,     0,     0,     0,
     104,     0,     0,     0,   105,     0,   106,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,    80,
       0,   106,    98,    99,   100,   101,   102,   103,     0,     0,
       0,     0,   104,     0,     0,     0,   105,     0,     0,     0,
      81,    98,    99,   100,   101,   102,   103,     0,     0,     0,
       0,   104,     0,   106,     0,   105
};

static const yytype_int16 yycheck[] =
{
       0,     7,     0,     0,    11,    11,    20,   115,     3,    75,
      29,   176,    37,     7,    83,    41,    31,    29,    33,    75,
      20,    36,    20,    20,    22,    75,   134,     7,    47,     0,
      40,    41,    47,    80,    81,    47,    35,    31,    48,    33,
       3,     0,     7,    34,    38,    39,    31,    36,    33,    57,
      58,    36,    37,    33,    79,    49,    56,    83,   166,   224,
      50,    36,    47,    75,    50,    31,    35,    67,    33,    49,
      67,    31,    60,    67,    37,    38,    39,    40,    72,    73,
     149,    75,    76,   191,    49,    85,    81,    31,   196,    33,
      66,    75,    72,    73,    79,    75,    76,    64,   206,    64,
      65,    35,    97,    47,    46,   213,     7,    72,    73,    35,
      75,    76,   220,   221,   183,   115,    36,   124,   124,    82,
      75,    84,   148,   149,    75,    75,    35,   125,    75,    67,
      79,    62,    33,    47,   134,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    32,   108,    75,   110,    49,    34,
      75,     3,     4,     5,     6,    36,    31,   183,    38,    39,
      40,    41,    36,    64,    65,    32,   166,    32,    48,    35,
      77,    72,    73,   171,    75,    76,     7,    55,    79,    35,
      63,   195,    35,    31,   147,   192,   192,    57,    35,    32,
      36,   191,    44,    45,    35,   195,   196,   195,   195,    35,
      32,    78,    33,    75,    10,     7,   206,   229,    60,   171,
     227,   108,    85,   213,   187,   217,    68,   180,    49,   182,
     220,   221,    -1,    54,   182,    56,     7,    58,    59,    31,
      61,    33,    -1,    64,    65,    -1,    38,    39,    -1,    -1,
      71,    72,    73,    -1,    75,    76,    -1,    49,    79,    -1,
      31,    -1,    33,    -1,    -1,    -1,     7,    38,    39,    38,
      39,    40,    41,    42,    43,    67,    -1,    -1,    49,    48,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,    -1,    -1,    -1,    67,    38,    39,    -1,
      -1,    72,    73,    74,    75,    76,    -1,    32,    49,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    38,
      39,    40,    41,    48,    43,    -1,    67,    52,    -1,    48,
      -1,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    69,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    35,    -1,    52,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    52,    -1,    69,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      -1,    69,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      46,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    69,    -1,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    33,    49,    54,    56,    58,    59,    61,    64,
      65,    71,    72,    73,    75,    76,    79,    83,    84,    85,
      86,    87,    88,    89,    91,    92,    96,    99,   104,   107,
     109,   110,   111,   114,   116,   120,   124,    31,    38,    39,
      67,    74,   119,   121,   122,   123,   124,   117,   118,   119,
     123,    75,    75,    75,   102,   116,    35,    29,    47,    75,
      93,    94,    93,   102,     0,     0,    85,    37,    84,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      25,    46,    98,    31,    33,    36,    47,   125,   123,   123,
     123,   123,    75,   121,   126,   127,    34,    36,    38,    39,
      40,    41,    42,    43,    48,    52,    69,    50,    36,    50,
      35,    31,    31,   115,    60,    35,     3,     4,     5,     6,
      44,    45,    60,    68,   103,    84,    87,   100,    94,    94,
      66,    95,    75,    64,    35,    87,    75,   119,   123,   126,
     123,   128,   129,   120,   124,    75,    32,    46,    35,    36,
     119,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     117,   123,   123,    75,   108,    75,    35,    75,   100,    67,
     102,    84,   101,    62,   112,    75,    75,   100,    47,    32,
      35,    34,    36,    31,   123,   121,   126,    36,    32,    32,
     100,    35,    55,   105,   101,    77,    35,    63,   113,    95,
      80,    81,   123,   128,   126,   108,    35,   100,   102,    57,
     106,    85,   100,    35,    36,    97,    31,    90,    32,   100,
      35,    35,    78,   100,    75,    32,   125,   100,   100,    95,
     105,    97
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    85,    85,    86,    86,    86,    87,
      87,    88,    88,    89,    89,    89,    89,    90,    89,    91,
      91,    92,    93,    93,    94,    94,    94,    95,    95,    96,
      97,    97,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    99,    99,    99,    99,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   104,   105,   105,   106,   106,
     107,   108,   108,   108,   109,   110,   111,   112,   112,   113,
     113,   114,   115,   115,   116,   116,   116,   116,   116,   116,
     116,   116,   117,   117,   118,   119,   119,   120,   120,   121,
     121,   122,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   124,   124,   125,   125,
     125,   125,   126,   126,   126,   127,   127,   128,   128,   129,
     129
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     1,     1,     1,     2,
       3,     1,     1,     1,     3,     7,     3,     0,     7,     1,
       1,     3,     1,     2,     2,     2,     0,     2,     0,     6,
       4,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     2,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     6,     5,     0,     3,     0,
       7,     3,     1,     0,     4,     6,     5,     3,     0,     3,
       0,     5,     3,     0,     1,     1,     1,     3,     3,     3,
       1,     1,     1,     3,     3,     1,     3,     1,     3,     1,
       1,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     1,     1,     2,     3,     3,
       2,     5,     1,     3,     0,     1,     3,     1,     3,     1,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3:
#line 148 "calc.y"
                               {line_count++; }
#line 1728 "y.tab.c"
    break;

  case 8:
#line 157 "calc.y"
                          { printf("NEWLINE\n\n\n"); }
#line 1734 "y.tab.c"
    break;

  case 15:
#line 172 "calc.y"
                                                         { // 1 shift reduce warning
                                                struct Var* dictionary = search_VarList(vars, (yyvsp[-4].sval));
                                                if(dictionary->type == t_DICT) { 
                                                        int *newValue = (int *)malloc(sizeof(int));
                                                        *newValue = (yyvsp[-6].ival);
                                                        char* newVar = strdup((yyvsp[-6].sval));
                                                        update_VarList(vars, newVar, t_INT, (void*)newValue);
                                                        printf("List the dictionary '%s' : \n", (yyvsp[-4].sval));
                                                        print_DictList((struct DictList*)dictionary->ptr);
                                                        dont=1;
                                                }
                                                else printf("'%s' is not a dictionary\n", (yyvsp[-4].sval));
                                        }
#line 1752 "y.tab.c"
    break;

  case 16:
#line 186 "calc.y"
                                          { 
                                           if(isLambda==1){
                                                printf("sdsdsdsdsds");
                                                char* newValue;
                                                newValue = strdup("lambda");
                                                char* newVar = strdup((yyvsp[-2].sval));
                                                update_VarList(vars, newVar, t_STRING, (void*)newValue);
                                                printf("ASSIGN -- %s = %s\n",newVar, newValue);
                                                free((yyvsp[-2].sval));
                                                isLambda=0;
                                           }
                                                
                                           else if (varType == t_INT){
                                                int *newValue = (int *)malloc(sizeof(int)); // this is nesessary
                                                *newValue = (yyvsp[0].ival);
                                                char* newVar = strdup((yyvsp[-2].sval));
                                                update_VarList(vars, newVar, t_INT, (void*)newValue);
                                                
                                                printf("ASSIGN -- %s = %d\n",newVar, *newValue);
                                                free((yyvsp[-2].sval));
                                           }
                                           else if (varType == t_STRING){
                                                char* newValue;
                                                newValue = strdup((yyvsp[0].sval));
                                                char* newVar = strdup((yyvsp[-2].sval));
                                                update_VarList(vars, newVar, t_STRING, (void*)newValue);
                                                printf("ASSIGN -- %s = %s\n",newVar, newValue);
                                                free((yyvsp[-2].sval));
                                           }
                                           else if(varType == t_DICT){
                                                   char* newVar = strdup((yyvsp[-2].sval));
                                                   update_VarList(vars, newVar, t_DICT, (void*)dict);
                                                    free((yyvsp[-2].sval));
                                                    dict = init_DictList();
                                           } 
                                               
                                         }
#line 1794 "y.tab.c"
    break;

  case 17:
#line 223 "calc.y"
                                                    {isSetDefault=1;}
#line 1800 "y.tab.c"
    break;

  case 18:
#line 223 "calc.y"
                                                                             {    
                                                                struct Var* dictionary = search_VarList(vars, (yyvsp[-4].sval));
                                                                if(dictionary->type == t_DICT) { 
                                                                      
                                                                       
                                                                        char* newVar = strdup((yyvsp[-6].sval));
                                                                        
                                                                        printf("List the dictionary '%s' : ", (yyvsp[-4].sval));
                                                                        print_DictList((struct DictList*)dictionary->ptr);
                                                                        dont=1;
                                                                        if(varType==t_STRING){
                                                                                char* newKey1 = strdup((char*)dict->head->key);
                                                                                char* newValue1 = strdup((char*)dict->head->value);
                                                                                int rtn = setDefault_DictList((struct DictList*)dictionary->ptr, newKey1, t_STRING, newValue1, t_STRING);
                                                                                (rtn==1)?(printf("updating '%s' with the key '%s' and value '%s'\n",(yyvsp[-4].sval),newKey1,newValue1)):(printf("'%s' already contains the key '%s'\n",(yyvsp[-4].sval),(char*)newKey1));
                                                                                dict = init_DictList();

                                                                                char* newValue = strdup("0");
                                                                                update_VarList(vars, newVar, t_STRING, (void*)newValue);

                                                                                

                                                                        }
                                                                        else
                                                                        {
                                                                                char* newKey2 = strdup((char*)dict->head->key);
                                                                                int *newValue2 = (int *)dict->head->value;
                                                                                int rtn = setDefault_DictList((struct DictList*)dictionary->ptr, (void*)newKey2, t_STRING, (void*)newValue2, t_INT);
                                                                                (rtn==1)?(printf("updating '%s' with the key '%s' and value '%d'\n",(yyvsp[-4].sval),newKey2,*newValue2)):(printf("%s already contains the key %s\n",(yyvsp[-4].sval),(char*)newKey2));
                                                                                dict= init_DictList();
                                                                                
                                                                                int *newValue = (int *)malloc(sizeof(int));
                                                                                *newValue = 0; //$<ival>1;
                                                                                 update_VarList(vars, newVar, t_INT, (void*)newValue);
                                                                        }
                                                                        
                                                                }
                                                                else printf("'%s' is not a dictionary\n", (yyvsp[-4].sval));
                                                                }
#line 1844 "y.tab.c"
    break;

  case 70:
#line 348 "calc.y"
                                                          {(yyval.sval) = (yyvsp[-5].sval); varType = t_STRING; stringIsVar = 1;  
                                                                printf("fuction nanme:  %s \n", (yyvsp[-5].sval)); 
                                                                char* newVar = strdup((yyvsp[-5].sval));
                                                                update_VarList(vars,newVar,t_FUNC,(void*)(yyvsp[-5].sval));}
#line 1853 "y.tab.c"
    break;

  case 84:
#line 382 "calc.y"
                                                {(yyval.sval) = (yyvsp[0].sval); varType = t_STRING; stringIsVar = 1;  printf("VAR -- %s \n", (yyvsp[0].sval)); }
#line 1859 "y.tab.c"
    break;

  case 85:
#line 383 "calc.y"
                                                {topntail((yyvsp[0].sval)); (yyval.sval) = (yyvsp[0].sval); varType = t_STRING; stringIsVar = 0; printf("STRING\n");}
#line 1865 "y.tab.c"
    break;

  case 86:
#line 384 "calc.y"
                                                { (yyval.ival)=(yyvsp[0].ival); varType = t_INT; printf("NUMBER --\t %d\n", (yyvsp[0].ival));}
#line 1871 "y.tab.c"
    break;

  case 87:
#line 385 "calc.y"
                                     {  printf("LIST\n"); }
#line 1877 "y.tab.c"
    break;

  case 88:
#line 386 "calc.y"
                                               { varType = t_DICT;  printf("DICT\n"); }
#line 1883 "y.tab.c"
    break;

  case 89:
#line 387 "calc.y"
                                         { printf("SET\n");}
#line 1889 "y.tab.c"
    break;

  case 94:
#line 396 "calc.y"
                                               {
                                                if(varType == t_INT){
                                                        int *newValue = (int *)malloc(sizeof(int)); // this is nesessary
                                                        *newValue = (yyvsp[0].ival);
                                                        update_DictList(dict, (void*)(yyvsp[-2].sval), t_STRING, (void*)newValue, t_INT);
                                                        printf("Dictionary --- %s : %d\n", (yyvsp[-2].sval), (yyvsp[0].ival));
                                                }else if (varType == t_STRING ){
                                                        update_DictList(dict, (void*)(yyvsp[-2].sval), t_STRING, (void*)(yyvsp[0].sval), t_STRING);
                                                        printf("Dictionary --- %s : %s\n", (yyvsp[-2].sval), (yyvsp[0].sval));
                                                }
                                                else if( varType == t_DICT){
                                                         update_DictList(dict, (void*)(yyvsp[-2].sval), t_STRING, (void*)(yyvsp[0].sval), t_DICT);
                                                }
                                                }
#line 1908 "y.tab.c"
    break;

  case 101:
#line 427 "calc.y"
                                            {isLambda=1; printf("LAMDA\n"); }
#line 1914 "y.tab.c"
    break;

  case 102:
#line 430 "calc.y"
                                { printf("AND\n"); }
#line 1920 "y.tab.c"
    break;

  case 103:
#line 431 "calc.y"
                               { printf("OR\n"); }
#line 1926 "y.tab.c"
    break;

  case 104:
#line 432 "calc.y"
                                 { 
                                        if (varType == t_INT){
                                                (yyval.ival)=(yyvsp[-2].ival)+(yyvsp[0].ival);
                                                printf("+ -- %d = %d + %d\n", (yyval.ival) , (yyvsp[-2].ival) , (yyvsp[0].ival));
                                        }
                                        else{
                                            
                                                //$<sval>1[strlen($<sval>1) - 1] = '\0'; // removing the " from the strings
                                                //$<sval>3[0] = '-';
                                                (yyval.sval) = strcat((yyvsp[-2].sval) , (yyvsp[0].sval));
                                                printf("+ -- %s = %s + %s\n", (yyval.sval) , (yyvsp[-2].sval) , (yyvsp[0].sval));
                                        }
                                         
                                 }
#line 1945 "y.tab.c"
    break;

  case 105:
#line 446 "calc.y"
                                  { (yyval.ival)=(yyvsp[-2].ival)-(yyvsp[0].ival); printf("- -- %d = %d - %d\n", (yyval.ival) , (yyvsp[-2].ival) , (yyvsp[0].ival));  }
#line 1951 "y.tab.c"
    break;

  case 106:
#line 447 "calc.y"
                                  { (yyval.ival)=(yyvsp[-2].ival)*(yyvsp[0].ival); printf("* -- %d = %d * %d\n", (yyval.ival) , (yyvsp[-2].ival) , (yyvsp[0].ival));  }
#line 1957 "y.tab.c"
    break;

  case 107:
#line 448 "calc.y"
                                   { (yyval.ival)=(yyvsp[-2].ival)/(yyvsp[0].ival); printf("/ -- %d = %d / %d\n", (yyval.ival) , (yyvsp[-2].ival) , (yyvsp[0].ival));  }
#line 1963 "y.tab.c"
    break;

  case 108:
#line 449 "calc.y"
                                  { printf("|\n"); }
#line 1969 "y.tab.c"
    break;

  case 109:
#line 450 "calc.y"
                                   { printf("&\n"); }
#line 1975 "y.tab.c"
    break;

  case 110:
#line 451 "calc.y"
                                      { printf("%%\n"); }
#line 1981 "y.tab.c"
    break;

  case 111:
#line 452 "calc.y"
                           { printf("NOT\n"); }
#line 1987 "y.tab.c"
    break;

  case 114:
#line 455 "calc.y"
                                 {(yyval.ival) = (yyvsp[-1].ival);}
#line 1993 "y.tab.c"
    break;

  case 115:
#line 456 "calc.y"
                            {
                        if(varType == t_STRING && stringIsVar ==1) {
                                if(search_VarList(vars, (yyvsp[0].sval))==NULL){
                                        printf("error in line %d --- variable '%s' has not been found\n",line_count,(yyvsp[0].sval));
                                        exit(1);
                                }
                                int type_of_var = search_VarList(vars, (yyvsp[0].sval))->type;
                                if (type_of_var == t_INT){
                                        varType = t_INT;
                                        (yyval.ival) = *(int*)search_VarList(vars, (yyvsp[0].sval))->ptr;
                                        printf("================ %d\n", *(int*)search_VarList(vars, (yyvsp[0].sval))->ptr );
                                        free((yyvsp[0].sval));
                                }else if( type_of_var == t_STRING){
                                        varType = t_STRING;
                                         (yyval.sval) = (char*)search_VarList(vars, (yyvsp[0].sval))->ptr;
                                         printf("================ %s\n", (char*)search_VarList(vars, (yyvsp[0].sval))->ptr );
                                        free((yyvsp[0].sval));
                                }
                                else if( type_of_var == t_DICT){
                                        varType = t_DICT;
                                        (yyval.sval) = search_VarList(vars, (yyvsp[0].sval))->ptr;
                                         free((yyvsp[0].sval));
                                }
                        }else if(varType == t_STRING && stringIsVar ==0) {
                                 (yyval.sval) = (yyvsp[0].sval);
                        }
                        else if( varType == t_INT) (yyval.ival) = (yyvsp[0].ival);
                        }
#line 2026 "y.tab.c"
    break;

  case 116:
#line 486 "calc.y"
                       {dont=0;}
#line 2032 "y.tab.c"
    break;

  case 117:
#line 487 "calc.y"
                                    {            
                        if(dont==0){

                                if(isFunction==1){

                                      

                                     

                                printf("you called the function '%s' \n",(yyvsp[-1].sval));

                                if(strcmp((yyvsp[-1].sval),"print")==0){
                                        int *newValue = (int *)malloc(sizeof(int)); // this is nesessary
                                        *newValue = (yyvsp[-1].ival);
                                        update_VarList(vars,(yyvsp[-1].sval),t_FUNC,(void*)newValue);
                                        isFunction=1;
                                        isPrint=1;
                                        if(varType == t_INT){
                                                       printf("Print:  %d \n", (yyvsp[0].ival)); 
                                        }
                                        else{
                                                        printf("Print:  %s \n", (yyvsp[0].sval)); 
                                        }
                                }
                                else
                                {
                                        if(search_VarList(vars,(yyvsp[-1].sval))==NULL){
                                                printf("Error function '%s' in line %d is missing\n",(yyvsp[-1].sval),line_count);
                                                exit(0);
                                        }
                                        else
                                        {
                                                printf("you called the function '%s'\n",(yyvsp[-1].sval));
                                                isFunction=1;
                                        }
                                        
                                }
                                }
                                
                                if(isFunction==0){
                                printf("OHOHOH %s\n", (yyvsp[-1].sval));
                                 struct Var* dictionary = search_VarList(vars, (yyvsp[-1].sval));
                                 if(dictionary==NULL){
                                         printf("error in line %d --- there is no dictionary with the name '%s'\n",line_count,(yyvsp[-1].sval));
                                         exit(0);
                                 }
                                print_DictList((struct DictList*)dictionary->ptr);
                                struct DictPair* dict_pair = search_DictList((struct DictList*)dictionary->ptr , (yyvsp[0].sval), t_STRING);
                                if (dict_pair == NULL) {
                                        printf("error in line %d --- there is not such key in the dictionary \n",line_count);
                                        exit(0);
                                }
                               if (dict_pair->value_type == t_INT){
                                        varType = t_INT;
                                        (yyval.ival) = *(int*)dict_pair->value;
                                        printf("================ %d\n", *(int*)search_VarList(vars, (yyvsp[-1].sval))->ptr );
                                        free((yyvsp[-1].sval));
                                }else if( dict_pair->value_type == t_STRING){
                                        varType = t_STRING;
                                         (yyval.sval) = (char*)dict_pair->value;
                                         printf("================ %s\n", (char*)search_VarList(vars, (yyvsp[-1].sval))->ptr );
                                        free((yyvsp[-1].sval));
                                }
                                else if( dict_pair->value_type == t_DICT){
                                        varType = t_DICT;
                                        (yyval.sval) = dict_pair->value;
                                         free((yyvsp[-1].sval));
                                }
                        }  
                                dont = 0;
                        
                                    }
                   }
#line 2110 "y.tab.c"
    break;

  case 118:
#line 562 "calc.y"
                                    { dont=0; isFunction = 1; 
                                                if(varType == t_INT){
                                                         (yyval.ival) = (yyvsp[-1].ival); } 
                                                else{
                                                        (yyval.sval) = (yyvsp[-1].sval);
                                                }
                                                //if(isPrint=1) print(vars,$<sval>1); 
                                    }
#line 2123 "y.tab.c"
    break;

  case 119:
#line 570 "calc.y"
                                          {     
                                               
                                                (yyval.sval) = (yyvsp[-1].sval);
                                                isFunction=0;
                                                dont=0;
                                                printf("subscript - %s\n", (yyvsp[-1].sval)); 
                                                   //
                                        }
#line 2136 "y.tab.c"
    break;

  case 120:
#line 578 "calc.y"
                          { dont = 1 ; printf("dot\nVAR\n"); }
#line 2142 "y.tab.c"
    break;

  case 121:
#line 579 "calc.y"
                                            {dont=1;printf("hello");}
#line 2148 "y.tab.c"
    break;

  case 123:
#line 583 "calc.y"
                                          {     
                                              if(isSetDefault==1)  {
                                                if(varType==t_STRING){
                                                        char* newKey = strdup((yyvsp[-2].sval));
                                                        char* newValue = strdup((yyvsp[0].sval));
                                                        update_DictList(dict, (void*)newKey, t_STRING, (void*)newValue, t_STRING);
                                                }
                                                else if(varType==t_INT){
                                                        char* newKey = strdup((yyvsp[-2].sval));
                                                        int *newValue = (int *)malloc(sizeof(int)); // this is nesessary
                                                        *newValue = (yyvsp[0].ival);
                                                        update_DictList(dict, (void*)newKey, t_STRING, (void*)newValue, t_INT);
                                                }
                                                else
                                                        printf("please enter a string, an integer, or leave empty the second argument\n");
                                                        isSetDefault=0;
                                              }
                                        
                                        
                                        }
#line 2173 "y.tab.c"
    break;


#line 2177 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 618 "calc.y"



void yyerror(char *s) {
    	fprintf(stderr, "At line %d :: %s\n", line_count, s );
}


int main ( int argc, char **argv  ) {

         vars = init_VarList();
         dict = init_DictList();

	++argv; --argc;

	if ( argc > 0 ) yyin = fopen( argv[0], "r" );
  	else yyin = stdin;

	yyout = fopen ( "output", "w" );
  	yyparse ();

        print_VarList(vars);

  	return 0;
}
