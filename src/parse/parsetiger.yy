                                                                // -*- C++ -*-
%require "3.8"
%language "c++"
// Set the namespace name to `parse', instead of `yy'.
%define api.prefix {parse}
%define api.namespace {parse}
%define api.parser.class {parser}
%define api.value.type variant
%define api.token.constructor

// We use a GLR parser because it is able to handle Shift-Reduce and
// Reduce-Reduce conflicts by forking and testing each way at runtime. GLR
// permits, by allowing few conflicts, more readable and maintainable grammars.
%glr-parser
%skeleton "glr2.cc"

// In TC, we expect the GLR to resolve one Shift-Reduce and zero Reduce-Reduce
// conflict at runtime. Use %expect and %expect-rr to tell Bison about it.
  // FIXME: Some code was deleted here (Other directives).

%define parse.error verbose
%defines
%debug
// Prefix all the tokens with TOK_ to avoid colisions.
%define api.token.prefix {TOK_}

/* We use pointers to store the filename in the locations.  This saves
   space (pointers), time (no deep copy), but leaves the problem of
   deallocation.  This would be a perfect job for a misc::symbol
   object (passed by reference), however Bison locations require the
   filename to be passed as a pointer, thus forcing us to handle the
   allocation and deallocation of this object.

   Nevertheless, all is not lost: we can still use a misc::symbol
   object to allocate a flyweight (constant) string in the pool of
   symbols, extract it from the misc::symbol object, and use it to
   initialize the location.  The allocated data will be freed at the
   end of the program (see the documentation of misc::symbol and
   misc::unique).  */
%define api.filename.type {const std::string}
%locations

/*---------------------.
| Support for tokens.  |
`---------------------*/
%code requires
{
#include <string>
#include <misc/algorithm.hh>
#include <misc/separator.hh>
#include <misc/symbol.hh>
#include <parse/fwd.hh>

  // Pre-declare parse::parse to allow a ``reentrant'' parsing within
  // the parser.
  namespace parse
  {
    ast_type parse(Tweast& input);
  }
}

// The parsing context.
%param { ::parse::TigerDriver& td }
%parse-param { ::parse::Lexer& lexer }

%printer { yyo << $$; } <int> <std::string> <misc::symbol>;

%token <std::string>    STRING "string"
%token <misc::symbol>   ID     "identifier"
%token <int>            INT    "integer"


/*-----------------------------------------.
| Code output in the implementation file.  |
`-----------------------------------------*/

%code
{
# include <parse/tweast.hh>
# include <misc/separator.hh>
# include <misc/symbol.hh>

  namespace
  {

    /// Get the metavar from the specified map.
    template <typename T>
    T*
    metavar(parse::TigerDriver& td, unsigned key)
    {
      parse::Tweast* input = td.input_;
      return input->template take<T>(key);
    }

  }
}

%code
{
  #include <parse/scantiger.hh>  // header file generated with reflex --header-file
  #undef yylex
  #define yylex lexer.lex  // Within bison's parse() we should invoke lexer.lex(), not the global lex()
}

// Definition of the tokens, and their pretty-printing.
%token AND          "&"
       ARRAY        "array"
       ASSIGN       ":="
       BREAK        "break"
       CAST         "_cast"
       CLASS        "class"
       COLON        ":"
       COMMA        ","
       DIVIDE       "/"
       DO           "do"
       DOT          "."
       ELSE         "else"
       END          "end"
       EQ           "="
       EXTENDS      "extends"
       FOR          "for"
       FUNCTION     "function"
       GE           ">="
       GT           ">"
       IF           "if"
       IMPORT       "import"
       IN           "in"
       LBRACE       "{"
       LBRACK       "["
       LE           "<="
       LET          "let"
       LPAREN       "("
       LT           "<"
       MINUS        "-"
       METHOD       "method"
       NE           "<>"
       NEW          "new"
       NIL          "nil"
       OF           "of"
       OR           "|"
       PLUS         "+"
       PRIMITIVE    "primitive"
       RBRACE       "}"
       RBRACK       "]"
       RPAREN       ")"
       SEMI         ";"
       THEN         "then"
       TIMES        "*"
       TO           "to"
       TYPE         "type"
       VAR          "var"
       WHILE        "while"
       EOF 0        "end of file"
       EXP "_exp";

// FIXED: Some code was deleted here (Priorities/associativities).
%precedence THEN
%precedence ELSE DO OF ASSIGN


%left "|"
%left "&"
%nonassoc "<" ">" "<=" ">=" "<>"
%left "+" "-"
%left "*" "/"





// Solving conflicts on:
// let type foo = bar
//     type baz = bat
// which can be understood as a list of two TypeChunk containing
// a unique TypeDec each, or a single TypeChunk containing two TypeDec.
// We want the latter.

// FIXED: Some code was deleted here (Other declarations).

%precedence CHUNKS

%precedence TYPE
%precedence FUNCTION
%precedence PRIMITIVE
%precedence CLASS
  

%start program

%%
program:
  /* Parsing a source program.  */
  exp
   
| /* Parsing an imported file.  */
  chunks
   
;

exps:
  %empty
  | exps.1           
  ;
exps.1:
   exps.1 ";" exps.2
   | exps.2
   ;
exps.2:
   exp
   ;


exp:
  "nil"
  | INT
  | STRING

  /* Array and record creations. */
  | typeid "[" exp "]" "of" exp
  | typeid "{" idexp "}"

  /* Variables, field, elements of an array. */
  | lvalue

  /* Function call. */
  | ID "(" funcall ")"

  /* Operations. */
  | "-" exp
  | exp "+" exp
  | exp "-" exp
  | exp "*" exp
  | exp "/" exp
  | exp ">=" exp
  | exp "<=" exp
  | exp "<>" exp
  | exp ">" exp
  | exp "<" exp
  | exp "&" exp
  | exp "|" exp
  | "(" exps ")"
  /* Assignment. */
  | lvalue ":=" exp

  /* Control structures. */
  | "if" exp "then" exp "else" exp
  | "if" exp "then" exp
  | "while" exp "do" exp
  | "for" ID ":=" exp "to" exp "do" exp
  | "break"
  | "let" chunks "in" exps "end"
  
  /* object-oriented */
  | "new" typeid
  | lvalue "." ID "(" funcall ")"
  /* Cast of an expression to a given type */
  | CAST "(" exp "," ty ")"
  /* An expression metavariable */
  | EXP "(" INT ")"
  ;
%token LVALUE "_lvalue";
lvalue:
  ID
  | lvalue "." ID
  | lvalue "{" exp "}"
  /* A l-value metavariable */
  | LVALUE "(" INT ")"
  ;


funcall:
  %empty
  | funcall.1           
  ;
funcall.1:
   funcall.1 "," funcall.2
   | funcall.2
   ;
funcall.2:
   exp
   ;

idexp:
  %empty
  | idexp.1           
  ;
idexp.1:
   idexp.1 "," idexp.2
   | idexp.2
   ;
idexp.2:
   ID "=" exp
   ;
  // FIXME: Some code was deleted here (More rules).

/*---------------.
| Declarations.  |
`---------------*/

%token CHUNKS "_chunks";
chunks:
  /* Chunks are contiguous series of declarations of the same type
     (TypeDec, FunctionDec...) to which we allow certain specfic behavior like
     self referencing.
     They are held by a ChunkList, that can be empty, like in this case:
        let
        in
            ..
        end
     which is why we end the recursion with a %empty. */
  %empty                  
| tychunk   chunks        
| funchunk chunks
| vardec
/* A list of chunk metavariable */
| CHUNKS "(" INT ")" chunks
// FIXME: Some code was deleted here (More rules).
;
funchunk:
  fundec %prec CHUNKS  
| fundec funchunk       
;  

fundec:
  "function" ID "(" tyfields ")" type.1 "=" exp
  | "primitive" ID "(" tyfields ")" type.1
  ;

vardec:
  "var" ID type.1 ":=" exp
  ;

type.1:
  %empty
  | ":" typeid
  ;
/*--------------------.
| Type Declarations.  |
`--------------------*/

tychunk:
  /* Use `%prec CHUNKS' to do context-dependent precedence and resolve a
     shift-reduce conflict. */
  tydec %prec CHUNKS  
| tydec tychunk       
;

tydec:
  "type" ID "=" ty
  /* object-oriented */
  | "class" ID ext "{" classfields "}"
  ;
ty:
  typeid               
| "{" tyfields "}"     
| "array" "of" typeid
/* object-oriented */
| "class" ext "{" classfields "}"
;

tyfields:
  %empty               
| tyfields.1           
;

tyfields.1:
  tyfields.1 "," tyfield 
| tyfield                
;

tyfield:
  ID ":" typeid     
;

ext:
  %empty
  | "extends" typeid
  ;

classfields:
  %empty
  | classfields classfield
  ;
classfield:
  vardec
  | meth.1
  ;

meth.1:
  %empty
  | meth.1 meth
  ;
meth:
  "method" ID "(" tyfields ")" type.1 "=" exp
  ;

%token NAMETY "_namety";
typeid:
  ID                    
  /* This is a metavariable. It it used internally by TWEASTs to retrieve
     already parsed nodes when given an input to parse. */
| NAMETY "(" INT ")"    
;

%%

void
parse::parser::error(const location_type& l, const std::string& m)
{
  // FIXME: Some code was deleted here.
}
