
%{
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


%}

%union{
        int ival;
        char* sval;
}


%token EQEQUAL
%token NOTEQUAL
%token LESSEQUAL
%token GREATEREQUAL
%token <sval> STRING
%token TILDE                   
%token CIRCUMFLEX              
%token LEFTSHIFT               
%token RIGHTSHIFT              
%token DOUBLESTAR              
%token PLUSEQUAL               
%token MINEQUAL                
%token STAREQUAL               
%token SLASHEQUAL              
%token PERCENTEQUAL            
%token AMPEREQUAL              
%token VBAREQUAL               
%token CIRCUMFLEXEQUAL         
%token LEFTSHIFTEQUAL          
%token RIGHTSHIFTEQUAL         
%token DOUBLESTAREQUAL         
%token DOUBLESLASH             
%token DOUBLESLASHEQUAL        
%token AT                      
%token ATEQUAL                 
%token RARROW                  
%token ELLIPSIS                
%token COLONEQUAL              

%token LPAR
%token RPAR
%token LSQB
%token RSQB
%token COLON
%token COMMA
%token SEMI
%token PLUS
%token MINUS
%token STAR
%token SLASH
%token VBAR
%token AMPER
%token LESS
%token GREATER
%token EQUAL
%token DOT
%token PERCENT
%token LBRACE
%token RBRACE
%token HASH

%token AND
%token BREAK
%token DEF
%token ELIF
%token CLASS
%token ELSE 
%token FOR
%token IF
%token IN
%token TRY
%token CATCH
%token FINALLY
%token IMPORT
%token FROM
%token AS


%token NOT 
%token IS
%token OR
%token RETURN 
%token WHILE
%token TRUE
%token FALSE
%token LAMBDA 
%token <sval> VAR 
%token <ival> NUMBER
%token INDENT
%token DEDENT
%token NEWLINE
%token END 0

%token ITEMS
%token SETDEFAULT


%left OR
%left AND
%right NOT
%left VBAR 
%left AMPER
%left PLUS MINUS
%left STAR SLASH PERCENT 

%%

program 	: statements END
    		;

newline         : NEWLINE      {line_count++; }
                ;

statements	: stmt
                | stmt statements
		;

stmt 		: simple_stmt
                | compound_stmt
		| newline { printf("NEWLINE\n\n\n"); }
       		;
                       


simple_stmt 	: small_stmt newline
	     	| small_stmt SEMI simple_stmt
		;

small_stmt 	: expr_stmt
                | import_stmt
	    	;

expr_stmt  	: atom_expr 
	    	| atomlist augassign expr 
                | atomlist EQUAL VAR DOT ITEMS LPAR RPAR { // 1 shift reduce warning
                                                struct Var* dictionary = search_VarList(vars, $<sval>3);
                                                if(dictionary->type == t_DICT) { 
                                                        int *newValue = (int *)malloc(sizeof(int));
                                                        *newValue = $<ival>1;
                                                        char* newVar = strdup($<sval>1);
                                                        update_VarList(vars, newVar, t_INT, (void*)newValue);
                                                        printf("List the dictionary '%s' : \n", $<sval>3);
                                                        print_DictList((struct DictList*)dictionary->ptr);
                                                        dont=1;
                                                }
                                                else printf("'%s' is not a dictionary\n", $<sval>3);
                                        }       
        
		| atomlist EQUAL testlist { 
                                           if(isLambda==1){
                                                printf("sdsdsdsdsds");
                                                char* newValue;
                                                newValue = strdup("lambda");
                                                char* newVar = strdup($<sval>1);
                                                update_VarList(vars, newVar, t_STRING, (void*)newValue);
                                                printf("ASSIGN -- %s = %s\n",newVar, newValue);
                                                free($<sval>1);
                                                isLambda=0;
                                           }
                                                
                                           else if (varType == t_INT){
                                                int *newValue = (int *)malloc(sizeof(int)); // this is nesessary
                                                *newValue = $<ival>3;
                                                char* newVar = strdup($<sval>1);
                                                update_VarList(vars, newVar, t_INT, (void*)newValue);
                                                
                                                printf("ASSIGN -- %s = %d\n",newVar, *newValue);
                                                free($<sval>1);
                                           }
                                           else if (varType == t_STRING){
                                                char* newValue;
                                                newValue = strdup($<sval>3);
                                                char* newVar = strdup($<sval>1);
                                                update_VarList(vars, newVar, t_STRING, (void*)newValue);
                                                printf("ASSIGN -- %s = %s\n",newVar, newValue);
                                                free($<sval>1);
                                           }
                                           else if(varType == t_DICT){
                                                   char* newVar = strdup($<sval>1);
                                                   update_VarList(vars, newVar, t_DICT, (void*)dict);
                                                    free($<sval>1);
                                                    dict = init_DictList();
                                           } 
                                               
                                         } 
                | atomlist EQUAL VAR DOT SETDEFAULT {isSetDefault=1;} trailer{    
                                                                struct Var* dictionary = search_VarList(vars, $<sval>3);
                                                                if(dictionary->type == t_DICT) { 
                                                                      
                                                                       
                                                                        char* newVar = strdup($<sval>1);
                                                                        
                                                                        printf("List the dictionary '%s' : ", $<sval>3);
                                                                        print_DictList((struct DictList*)dictionary->ptr);
                                                                        dont=1;
                                                                        if(varType==t_STRING){
                                                                                char* newKey1 = strdup((char*)dict->head->key);
                                                                                char* newValue1 = strdup((char*)dict->head->value);
                                                                                int rtn = setDefault_DictList((struct DictList*)dictionary->ptr, newKey1, t_STRING, newValue1, t_STRING);
                                                                                (rtn==1)?(printf("updating '%s' with the key '%s' and value '%s'\n",$<sval>3,newKey1,newValue1)):(printf("'%s' already contains the key '%s'\n",$<sval>3,(char*)newKey1));
                                                                                dict = init_DictList();

                                                                                char* newValue = strdup("0");
                                                                                update_VarList(vars, newVar, t_STRING, (void*)newValue);

                                                                                

                                                                        }
                                                                        else
                                                                        {
                                                                                char* newKey2 = strdup((char*)dict->head->key);
                                                                                int *newValue2 = (int *)dict->head->value;
                                                                                int rtn = setDefault_DictList((struct DictList*)dictionary->ptr, (void*)newKey2, t_STRING, (void*)newValue2, t_INT);
                                                                                (rtn==1)?(printf("updating '%s' with the key '%s' and value '%d'\n",$<sval>3,newKey2,*newValue2)):(printf("%s already contains the key %s\n",$<sval>3,(char*)newKey2));
                                                                                dict= init_DictList();
                                                                                
                                                                                int *newValue = (int *)malloc(sizeof(int));
                                                                                *newValue = 0; //$<ival>1;
                                                                                 update_VarList(vars, newVar, t_INT, (void*)newValue);
                                                                        }
                                                                        
                                                                }
                                                                else printf("'%s' is not a dictionary\n", $<sval>3);
                                                                }

		;
// IMPORT STMT

import_stmt     : import_name
                | import_from
                ;
import_name     : IMPORT import_var as_name
                ;
import_var      : VAR
                | dotted VAR
                ;
dotted          : DOT dotted
                | ELLIPSIS dotted
                |
                ;
as_name         : AS VAR
                |
                ;

import_from     : FROM import_var IMPORT VAR as_name import_names;

import_names    : COMMA VAR as_name import_names
                |
                ;
		
augassign  	: PLUSEQUAL 
	    	| MINEQUAL 
		| STAREQUAL 
		| SLASHEQUAL 
		| PERCENTEQUAL
		| AMPEREQUAL 
		| VBAREQUAL 
		| CIRCUMFLEXEQUAL
		| LEFTSHIFTEQUAL
		| RIGHTSHIFTEQUAL 
		| DOUBLESTAREQUAL
		| DOUBLESLASHEQUAL 
		;

// COMPOUND STATEMENTS

compound_stmt   : if_statement
                | def_function
                | while_loop
                | for_loop
                | try_stmt
                | class_stmt
                ;

suite           : simple_stmt
                | newline newline_or_not INDENT statements DEDENT // Is this correct? the python documentation is not though.
                ;

newline_or_not  : newline newline_or_not
                |
                ;

condition	: atom cmp_symbols condition
                | atom
		;

cmp_symbols	: EQEQUAL
		| NOTEQUAL
		| LESSEQUAL
		| GREATEREQUAL
		| LESS
		| GREATER
		| IN
		| IS
		| IS NOT
		;

if_statement	: IF condition COLON suite elif else	
		;


elif		: ELIF condition COLON suite elif
		|
		;

else		: ELSE COLON suite
		|
		;


def_function	: DEF VAR LPAR arguments RPAR COLON suite {$<sval>$ = $<sval>2; varType = t_STRING; stringIsVar = 1;  
                                                                printf("fuction nanme:  %s \n", $<sval>2); 
                                                                char* newVar = strdup($<sval>2);
                                                                update_VarList(vars,newVar,t_FUNC,(void*)$<sval>2);}
                                                                

	     	;

arguments	: VAR COMMA arguments
		| VAR
		|
		; 

while_loop      : WHILE condition COLON suite;

for_loop        : FOR VAR IN VAR COLON suite;

try_stmt        : TRY COLON suite catch_stmt finally_stmt;

catch_stmt      : CATCH COLON suite
                | 
                ;

finally_stmt   : FINALLY COLON suite
                |
                ;

class_stmt      : CLASS VAR inheritance COLON suite;

inheritance     : LPAR VAR RPAR
                |
                ;

// ATOMIC EXPRESION
atom 		: VAR                           {$<sval>$ = $<sval>1; varType = t_STRING; stringIsVar = 1;  printf("VAR -- %s \n", $<sval>1); }
       		| STRING                        {topntail($<sval>1); $<sval>$ = $<sval>1; varType = t_STRING; stringIsVar = 0; printf("STRING\n");}
		| NUMBER                        { $<ival>$=$<ival>1; varType = t_INT; printf("NUMBER --\t %d\n", $<ival>1);}
		| LSQB testlist RSQB {  printf("LIST\n"); }
		| LBRACE key_datum_list RBRACE { varType = t_DICT;  printf("DICT\n"); }
		| LBRACE testlist RBRACE { printf("SET\n");}
		| TRUE
		| FALSE
		;

key_datum_list 	: key_datum
		| key_datum COMMA key_datum_list
		;

key_datum  	: expr COLON expr              {
                                                if(varType == t_INT){
                                                        int *newValue = (int *)malloc(sizeof(int)); // this is nesessary
                                                        *newValue = $<ival>3;
                                                        update_DictList(dict, (void*)$<sval>1, t_STRING, (void*)newValue, t_INT);
                                                        printf("Dictionary --- %s : %d\n", $<sval>1, $<ival>3);
                                                }else if (varType == t_STRING ){
                                                        update_DictList(dict, (void*)$<sval>1, t_STRING, (void*)$<sval>3, t_STRING);
                                                        printf("Dictionary --- %s : %s\n", $<sval>1, $<sval>3);
                                                }
                                                else if( varType == t_DICT){
                                                         update_DictList(dict, (void*)$<sval>1, t_STRING, (void*)$<sval>3, t_DICT);
                                                }
                                                }
	    	;

// EXPRESSIONS


testlist 	: test
	  	| test COMMA testlist
		;

atomlist  	: atom_expr
	   	| atom_expr COMMA atomlist 
		;

test 		: expr
       		| lambdadef
		;

lambdadef  	: LAMBDA arglist COLON test {isLambda=1; printf("LAMDA\n"); }
	    	;

expr 		: expr AND expr { printf("AND\n"); }
	  	| expr OR expr { printf("OR\n"); }
	  	| expr PLUS expr { 
                                        if (varType == t_INT){
                                                $<ival>$=$<ival>1+$<ival>3;
                                                printf("+ -- %d = %d + %d\n", $<ival>$ , $<ival>1 , $<ival>3);
                                        }
                                        else{
                                            
                                                //$<sval>1[strlen($<sval>1) - 1] = '\0'; // removing the " from the strings
                                                //$<sval>3[0] = '-';
                                                $<sval>$ = strcat($<sval>1 , $<sval>3);
                                                printf("+ -- %s = %s + %s\n", $<sval>$ , $<sval>1 , $<sval>3);
                                        }
                                         
                                 } 
      		| expr MINUS expr { $<ival>$=$<ival>1-$<ival>3; printf("- -- %d = %d - %d\n", $<ival>$ , $<ival>1 , $<ival>3);  }
		| expr STAR expr  { $<ival>$=$<ival>1*$<ival>3; printf("* -- %d = %d * %d\n", $<ival>$ , $<ival>1 , $<ival>3);  }
		| expr SLASH expr  { $<ival>$=$<ival>1/$<ival>3; printf("/ -- %d = %d / %d\n", $<ival>$ , $<ival>1 , $<ival>3);  }
		| expr VBAR expr  { printf("|\n"); }
		| expr AMPER expr  { printf("&\n"); }
		| expr PERCENT expr   { printf("%%\n"); }
		| NOT expr { printf("NOT\n"); }
		| MINUS expr
		| PLUS expr 
                | LPAR expr RPAR {$<ival>$ = $<ival>2;}
		| atom_expr {
                        if(varType == t_STRING && stringIsVar ==1) {
                                if(search_VarList(vars, $<sval>1)==NULL){
                                        printf("error in line %d --- variable '%s' has not been found\n",line_count,$<sval>1);
                                        exit(1);
                                }
                                int type_of_var = search_VarList(vars, $<sval>1)->type;
                                if (type_of_var == t_INT){
                                        varType = t_INT;
                                        $<ival>$ = *(int*)search_VarList(vars, $<sval>1)->ptr;
                                        printf("================ %d\n", *(int*)search_VarList(vars, $<sval>1)->ptr );
                                        free($<sval>1);
                                }else if( type_of_var == t_STRING){
                                        varType = t_STRING;
                                         $<sval>$ = (char*)search_VarList(vars, $<sval>1)->ptr;
                                         printf("================ %s\n", (char*)search_VarList(vars, $<sval>1)->ptr );
                                        free($<sval>1);
                                }
                                else if( type_of_var == t_DICT){
                                        varType = t_DICT;
                                        $<sval>$ = search_VarList(vars, $<sval>1)->ptr;
                                         free($<sval>1);
                                }
                        }else if(varType == t_STRING && stringIsVar ==0) {
                                 $<sval>$ = $<sval>1;
                        }
                        else if( varType == t_INT) $<ival>$ = $<ival>1;
                        }
		;

atom_expr 	: atom {dont=0;}
	   	| atom_expr trailer {            
                        if(dont==0){

                                if(isFunction==1){

                                printf("you called the function '%s' \n",$<sval>1);

                                if(strcmp($<sval>1,"print")==0){
                                        int *newValue = (int *)malloc(sizeof(int)); // this is nesessary
                                        *newValue = $<ival>1;
                                        update_VarList(vars,$<sval>1,t_FUNC,(void*)newValue);
                                        isFunction=1;
                                        isPrint=1;
                                        if(varType == t_INT){
                                                       printf("Print:  %d \n", $<ival>2); 
                                        }
                                        else{
                                                        printf("Print:  %s \n", $<sval>2); 
                                        }
                                }
                                else
                                {
                                        if(search_VarList(vars,$<sval>1)==NULL){
                                                printf("Error function '%s' in line %d is missing\n",$<sval>1,line_count);
                                                exit(0);
                                        }
                                        else
                                        {
                                                printf("you called the function '%s'\n",$<sval>1);
                                                isFunction=1;
                                        }
                                        
                                }
                                }
                                
                                if(isFunction==0){
                                printf("OHOHOH %s\n", $<sval>1);
                                 struct Var* dictionary = search_VarList(vars, $<sval>1);
                                 if(dictionary==NULL){
                                         printf("error in line %d --- there is no dictionary with the name '%s'\n",line_count,$<sval>1);
                                         exit(0);
                                 }
                                print_DictList((struct DictList*)dictionary->ptr);
                                struct DictPair* dict_pair = search_DictList((struct DictList*)dictionary->ptr , $<sval>2, t_STRING);
                                if (dict_pair == NULL) {
                                        printf("error in line %d --- there is not such key in the dictionary \n",line_count);
                                        exit(0);
                                }
                               if (dict_pair->value_type == t_INT){
                                        varType = t_INT;
                                        $<ival>$ = *(int*)dict_pair->value;
                                        printf("================ %d\n", *(int*)search_VarList(vars, $<sval>1)->ptr );
                                        free($<sval>1);
                                }else if( dict_pair->value_type == t_STRING){
                                        varType = t_STRING;
                                         $<sval>$ = (char*)dict_pair->value;
                                         printf("================ %s\n", (char*)search_VarList(vars, $<sval>1)->ptr );
                                        free($<sval>1);
                                }
                                else if( dict_pair->value_type == t_DICT){
                                        varType = t_DICT;
                                        $<sval>$ = dict_pair->value;
                                         free($<sval>1);
                                }
                        }  
                                dont = 0;
                        
                                    }
                   }
		;

trailer 	: LPAR arglist RPAR { dont=0; isFunction = 1; 
                                                if(varType == t_INT){
                                                         $<ival>$ = $<ival>2; } 
                                                else{
                                                        $<sval>$ = $<sval>2;
                                                }
                                                //if(isPrint=1) print(vars,$<sval>1); 
                                    }
		| LSQB subscriptlist RSQB {     
                                               
                                                $<sval>$ = $<sval>2;
                                                isFunction=0;
                                                dont=0;
                                                printf("subscript - %s\n", $<sval>2); 
                                                   //
                                        }
		| DOT VAR { dont = 1 ; printf("dot\nVAR\n"); }
                | DOT VAR LPAR arglist RPAR {dont=1;printf("hello");}
		;

arglist 	: argument 
		| argument COMMA arglist  {     
                                              if(isSetDefault==1)  {
                                                if(varType==t_STRING){
                                                        char* newKey = strdup($<sval>1);
                                                        char* newValue = strdup($<sval>3);
                                                        update_DictList(dict, (void*)newKey, t_STRING, (void*)newValue, t_STRING);
                                                }
                                                else if(varType==t_INT){
                                                        char* newKey = strdup($<sval>1);
                                                        int *newValue = (int *)malloc(sizeof(int)); // this is nesessary
                                                        *newValue = $<ival>3;
                                                        update_DictList(dict, (void*)newKey, t_STRING, (void*)newValue, t_INT);
                                                }
                                                else
                                                        printf("please enter a string, an integer, or leave empty the second argument\n");
                                                        isSetDefault=0;
                                              }
                                        
                                        
                                        }
                |  
		;

argument 	: test 
	  	| VAR EQUAL expr 
		;

subscriptlist 	: subscript 
	       	| subscript COMMA subscriptlist 
		;

subscript 	: expr
	   	| expr COLON expr
	   	;

%%


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
