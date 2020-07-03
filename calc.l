
%{
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "y.tab.h"

int current_line_indent = 0;
int line_counter = 1;
struct Stack* level;

bool term = 0;

#define yyterminate() return (term = !term)? END : YY_NULL;

#define YY_USER_INIT { \
        BEGIN(indent); \
        level = init_stack(); \
        push(level, 0); \
}

%}

NUMBER [0-9]*
VAR [a-zA-Z_][a-zA-Z0-9_]*
STRING \"([^\\\"]|\\.)*\"|\'([^\\\"]|\\.)*\'


%option noyywrap

%x indent
%s normal
%s comment

%%
<indent>" "     { current_line_indent++; }
<indent>"\t"    { current_line_indent = (current_line_indent + 8) & ~7; }
<indent>"\n"    { current_line_indent = 0; line_counter++; printf("new line\n"); return NEWLINE; }
<indent>.       {
                    unput(*yytext);
                    if(current_line_indent > peek(level)) {
                        push(level, current_line_indent);
                        BEGIN(normal);
                        printf("indent\n"); 
                        return INDENT;

                    }
                    else {

                        while (is_empty(level) != true && peek(level) != current_line_indent) {
                            pop(level);
                            printf("dedent\n"); 
                            return DEDENT;
                        }


                        if (is_empty(level)) {
                            printf("error");
                            return 1;
                        }

                        BEGIN(normal);
                    }
                }
<normal>"\n"    { current_line_indent = 0; line_counter++; printf("new line\n");  BEGIN indent; return NEWLINE; }


<indent><<EOF>>     	{
	              	while(peek(level) != 0) {
				pop(level);
				return DEDENT;
	              	}
			yyterminate();	
	 	}

<normal>"=="		{ return EQEQUAL; }
<normal>"!="		{ return NOTEQUAL; }
<normal>"<="		{ return LESSEQUAL; }
<normal>">="		{ return GREATEREQUAL; }
<normal>"~"		{ return TILDE; }                   
<normal>"^"		{ return CIRCUMFLEX; }              
<normal>"<<"		{ return LEFTSHIFT; }               
<normal>">>"		{ return RIGHTSHIFT; }              
<normal>"**"		{ return DOUBLESTAR; }              
<normal>"+="		{ return PLUSEQUAL; }               
<normal>"-="		{ return MINEQUAL; }                
<normal>"*="		{ return STAREQUAL; }               
<normal>"/="		{ return SLASHEQUAL; }              
<normal>"%="		{ return PERCENTEQUAL; }            
<normal>"&="		{ return AMPEREQUAL; }              
<normal>"|="		{ return VBAREQUAL; }               
<normal>"^="		{ return CIRCUMFLEXEQUAL; }         
<normal>"<<="		{ return LEFTSHIFTEQUAL; }          
<normal>">>="		{ return RIGHTSHIFTEQUAL; }         
<normal>"**="		{ return DOUBLESTAREQUAL; }         
<normal>"//"		{ return DOUBLESLASH; }             
<normal>"//="		{ return DOUBLESLASHEQUAL; }        
<normal>"@"		{ return AT; }                      
<normal>"@="		{ return ATEQUAL; }                 
<normal>"->"		{ return RARROW; }                  
<normal>"..."		{ return ELLIPSIS; }                
<normal>":="		{ return COLONEQUAL; }              


<normal>"("		{ return LPAR; }
<normal>")"		{ return RPAR; }
<normal>"["		{ return LSQB; }
<normal>"]"		{ return RSQB; }
<normal>":"		{ return COLON; }
<normal>","		{ return COMMA; }
<normal>";"		{ return SEMI; }
<normal>"+"		{ return PLUS; }
<normal>"-"		{ return MINUS; }
<normal>"*"		{ return STAR; }
<normal>"/"		{ return SLASH; }
<normal>"|"		{ return VBAR; }
<normal>"&"		{ return AMPER; }
<normal>"<"		{ return LESS; }
<normal>">"		{ return GREATER; }
<normal>"="		{ return EQUAL; }
<normal>"."		{ return DOT; }
<normal>"%"		{ return PERCENT; }
<normal>"{"		{ return LBRACE; }
<normal>"}"		{ return RBRACE; }

<normal>"#"		{ BEGIN comment; }
<comment>"\n"		{ BEGIN normal; }
<comment>.      {}

<normal>"and"       { printf("and"); return AND; }
<normal>"break"     { printf("break "); return BREAK; }
<normal>"def"       {  printf("def "); return DEF; }
<normal>"elif"      { return ELIF; }
<normal>"else"      { return ELSE; }
<normal>"for"       { printf("for "); return FOR; }
<normal>"in"       { return IN; }
<normal>"if"        { {printf("IF ");} return IF; }
<normal>"not"       { return NOT; }
<normal>"is"       { return IS; }
<normal>"or"        { return OR; }
<normal>"return"    { printf("return "); return RETURN; }
<normal>"while"     { printf("while "); return WHILE; }
<normal>"try"     { printf("try "); return TRY; }
<normal>"catch"     { printf("catch "); return CATCH; }
<normal>"finally"     { printf("finally "); return FINALLY; }
<normal>"class"     { printf("class "); return CLASS; }

<normal>"import"       { return IMPORT; }
<normal>"from"       { return FROM; }
<normal>"as"       { return AS; }

<normal>"lambda" 	{ return LAMBDA; }

<normal>"True"      	{ return TRUE; }
<normal>"False"     	{ return FALSE;}

<normal>"items"     	{ return ITEMS;}
<normal>"setdefault"     	{ return SETDEFAULT;}

<normal>{VAR}       	{ yylval.sval = strdup(yytext); return VAR; }
<normal>{NUMBER}    	{ yylval.ival = atoi(yytext); return NUMBER; }
<normal>{STRING}    	{ yylval.sval = strdup(yytext); return STRING; }

%%
