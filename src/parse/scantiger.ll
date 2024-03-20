                                                            /* -*- C++ -*- */
// %option defines the parameters with which the reflex will be launched
%option noyywrap
// To enable compatibility with bison
%option bison-complete
%option bison-cc-parser=parser
%option bison_cc_namespace=parse
%option bison-locations

%option lex=lex
// Add a param of function lex() generate in Lexer class
%option params="::parse::TigerDriver& td"
%option namespace=parse
// Name of the class generate by reflex
%option lexer=Lexer

%top{

#define YY_EXTERN_C extern "C" // For linkage rule

#include <cerrno>
#include <climits>
#include <regex>
#include <string>

#include <boost/lexical_cast.hpp>

#include <misc/contract.hh>
  // Using misc::escape is very useful to quote non printable characters.
  // For instance
  //
  //    std::cerr << misc::escape('\n') << '\n';
  //
  // reports about `\n' instead of an actual new-line character.
#include <misc/escape.hh>
#include <misc/symbol.hh>
#include <parse/parsetiger.hh>
#include <parse/tiger-driver.hh>

  // FIXED: Some code was deleted here (Define YY_USER_ACTION to update locations)
#define YY_USER_ACTION td.location_.columns(yyleng);


#define TOKEN(Type)                             \
  parser::make_ ## Type(td.location_)

#define TOKEN_VAL(Type, Value)                  \
  parser::make_ ## Type(Value, td.location_)

# define CHECK_EXTENSION()                              \
  do {                                                  \
    if (!td.enable_extensions_p_)                       \
      td.error_ << misc::error::error_type::scan        \
                << td.location_                         \
                << ": invalid identifier: `"            \
                << misc::escape(text()) << "'\n";       \
  } while (false)


%}

%x SC_COMMENT SC_STRING

/* Abbreviations.  */
int             [0-9]+
num             [0-7]{3}
xnum            [0-9A-Fa-f]{2}
string          "\""([^\\]|\\.)*"\""

/* FIXED: Some code was deleted here. */
id              [a-zA-Z][_a-zA-Z0-9]*
id_main         "_main"

%class{
  // FIXED: Some code was deleted here (Local variables).
  int nb_comment = 0;
  int string_len = 0;
  std::string actu = "";
 
}

%%
/* The rules.  */
{int}         {
                int val = 0;
                val = atoi(text());
  // FIXED: Some code was deleted here (Decode, and check the value).
                return TOKEN_VAL(INT, val);
              }
  /* FIXED: Some code was deleted here. */

[\n\r(\n\r)(\r\n)]     {td.location_.lines(yyleng);}
"&"           {return TOKEN(AND);}
"array"       {return TOKEN(ARRAY);}
":="          {return TOKEN(ASSIGN);}
"break"       {return TOKEN(BREAK);}
"cast"        {return TOKEN(CAST);}
"class"       {return TOKEN(CLASS);}
":"           {return TOKEN(COLON);}
","           {return TOKEN(COMMA);}
"/"           {return TOKEN(DIVIDE);}
"do"          {return TOKEN(DO);}
"."           {return TOKEN(DOT);}
"else"        {return TOKEN(ELSE);}
"end"         {return TOKEN(END);}
"="           {return TOKEN(EQ);}
"extends"     {return TOKEN(EXTENDS);}
"for"         {return TOKEN(FOR);}
"function"    {return TOKEN(FUNCTION);}
">="          {return TOKEN(GE);}
">"           {return TOKEN(GT);}
"if"          {return TOKEN(IF);}
"import"      {return TOKEN(IMPORT);}
"in"          {return TOKEN(IN);}
"{"           {return TOKEN(LBRACE);}
"["           {return TOKEN(LBRACK);}
"<="          {return TOKEN(LE);}
"let"         {return TOKEN(LET);}
"("           {return TOKEN(LPAREN);}
"<"           {return TOKEN(LT);}
"-"           {return TOKEN(MINUS);}
"method"      {return TOKEN(METHOD);}
"<>"          {return TOKEN(NE);}
"new"         {return TOKEN(NEW);}
"nil"         {return TOKEN(NIL);}
"of"          {return TOKEN(OF);}
"|"           {return TOKEN(OR);}
"+"           {return TOKEN(PLUS);}
"primitive"   {return TOKEN(PRIMITIVE);}
"}"           {return TOKEN(RBRACE);}
"]"           {return TOKEN(RBRACK);}
")"           {return TOKEN(RPAREN);}
";"           {return TOKEN(SEMI);}
"then"        {return TOKEN(THEN);}   
"*"           {return TOKEN(TIMES);}
"to"          {return TOKEN(TO);}
"type"        {return TOKEN(TYPE);}
"var"         {return TOKEN(VAR);}
"while"       {return TOKEN(WHILE);}

{id}     {return TOKEN_VAL(ID, text());}
"\""      {start(SC_STRING);}


// STRING


<SC_STRING>{
[\n\r(\n\r)(\r\n)]  {td.error_ << td.location_ << ": " << misc::error::error_type::scan  << "Unexpected \\n found\n"; start(INITIAL);}
"\""      {return TOKEN_VAL(STRING,actu);}
. { actu = actu.append(text());}
<<EOF>> { td.error_ << td.location_ << ": " << misc::error::error_type::scan << "Unexpected EOF found\n" ; start(INITIAL); }
}

// COMMENT

"/*"         { nb_comment += 1; start(SC_COMMENT);}

<SC_COMMENT>{
"/*" { nb_comment += 1 ;}
"*/" { if (nb_comment == 1)
 {
  nb_comment -=1;
  start(INITIAL);
 } 
 else 
 {
  nb_comment -=1;
  } ;}
. {}
<<EOF>> {  td.error_ << td.location_ << ": "  << misc::error::error_type::scan << "Unexpected EOF found\n" ; start(INITIAL); }
}
<<EOF>>    { return TOKEN(EOF);}
%%
