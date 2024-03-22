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


/*--------------------------------.
| Support for the non-terminals.  |
`--------------------------------*/

%code requires
{
# include <ast/fwd.hh>
// Provide the declarations of the following classes for the
// %destructor clauses below to work properly.
# include <ast/exp.hh>
# include <ast/var.hh>
# include <ast/ty.hh>
# include <ast/name-ty.hh>
# include <ast/field.hh>
# include <ast/field-init.hh>
# include <ast/function-dec.hh>
# include <ast/type-dec.hh>
# include <ast/var-dec.hh>
# include <ast/chunk.hh>
# include <ast/chunk-list.hh>
}

  // FIXME: Some code was deleted here (Printers and destructors).

/*-----------------------------------------.
| Code output in the implementation file.  |
`-----------------------------------------*/

%code
{
# include <parse/tweast.hh>
# include <misc/separator.hh>
# include <misc/symbol.hh>
# include <ast/all.hh>
# include <ast/libast.hh>
# include <parse/tiger-factory.hh>

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



%type <ast::Exp*>             exp exps.2 funcall.2
%type <ast::ChunkList*>       chunks

%type <ast::TypeChunk*>       tychunk
%type <ast::TypeDec*>         tydec
%type <ast::NameTy*>          typeid
%type <ast::Ty*>              ty

%type <ast::Field*>           tyfield 
%type <ast::fields_type*>     tyfields tyfields.1 


// FIXME: Some code was deleted here (More %types).
%type <ast::exps_type*>       exps exps.1 funcall funcall.1
%type <ast::FunctionChunk*>   funchunk
%type <ast::Var*>             lvalue
%type <ast::VarDec*>          vardec
%type <ast::VarChunk*>        varchunk
%type <ast::FunctionDec*>     fundec
%type <ast::FieldInit*>       rec.2 
%type <ast::fieldinits_type*> rec rec.1   


// Solving conflicts on:
// let type foo = bar
//     type baz = bat
// which can be understood as a list of two TypeChunk containing
// a unique TypeDec each, or a single TypeChunk containing two TypeDec.
// We want the latter.

// FIXED: Some code was deleted here (Other declarations).
%precedence VAR
%precedence CHUNKS

%precedence TYPE
%precedence FUNCTION
%precedence PRIMITIVE
%precedence CLASS
  

%start program

%%
program:
  /* Parsing a source program.  */
  exp { td.ast_ = $1; }
| /* Parsing an imported file.  */
  chunks { td.ast_ = $1; }
;

exps: 
  %empty { $$ = make_exps_type(); }
  | exps.1  {$$ = $1; }    
  ;

exps.1:
   exps.1 ";" exps.2  { $$ = $1; $$->emplace_back($3);}
   | exps.2 { $$ = make_exps_type(); $$->emplace_back($1);}
   ;

exps.2:
   exp { $$ = $1; }
   ;


rec:
  %empty          { $$ =  make_fieldinits_type(); }
| rec.1           { $$ =  $1; }
;
rec.1:
  rec.1 "," rec.2 { $$ = $1; $$->emplace_back($3); }
| rec.2        { $$ =  make_fieldinits_type(); $$->emplace_back($1); }
;

rec.2:
  ID "=" exp   { $$ =  make_FieldInit(@$, $1, $3); }
;



exp:
  INT { $$ = make_IntExp(@$, $1); }
  // FIXME: Some code was deleted here (More rules).
  | "nil" { $$ = make_NilExp(@$); }
  | STRING { $$ = make_StringExp(@$, $1); }

  /* Array and record creations. */
  | ID "[" exp "]" "of" exp { $$ = make_ArrayExp(@$, make_NameTy(@$, $1), $3, $6); }
  | ID "{" rec "}" { $$ = make_RecordExp(@$, make_NameTy(@$, $1),$3); }

  /* Variables, field, elements of an array. */
  | lvalue {$$ = $1;}

  /* Function call. */
  | ID "(" funcall ")"  {$$ = make_CallExp(@$, $1, $3);}
  /* Operations. */
  | "-" exp { $$ = make_OpExp(@$, make_IntExp(@$, 0), ast::OpExp::Oper::sub, $2); }
  | exp "+" exp { $$ = make_OpExp(@$, $1, ast::OpExp::Oper::add, $3); }
  | exp "-" exp { $$ = make_OpExp(@$, $1, ast::OpExp::Oper::sub, $3); }
  | exp "*" exp { $$ = make_OpExp(@$, $1, ast::OpExp::Oper::mul, $3); }
  | exp "/" exp { $$ = make_OpExp(@$, $1, ast::OpExp::Oper::div, $3); }
  | exp ">=" exp { $$ = make_OpExp(@$, $1, ast::OpExp::Oper::ge, $3); }
  | exp "<=" exp { $$ = make_OpExp(@$, $1, ast::OpExp::Oper::le, $3); }
  | exp "<>" exp { $$ = make_OpExp(@$, $1, ast::OpExp::Oper::ne, $3); }
  | exp ">" exp { $$ = make_OpExp(@$, $1, ast::OpExp::Oper::gt, $3); }
  | exp "<" exp { $$ = make_OpExp(@$, $1, ast::OpExp::Oper::lt, $3); }
  | exp "&" exp  //{$$ = make_IntExp(@$, $1 & $3);}
  | exp "|" exp  //{$$ = make_IntExp(@$, $1 | $3);}
  | "(" exps ")" { $$ = make_SeqExp(@$, $2); }
  /* Assignment. */
  | lvalue ":=" exp {$$ = make_AssignExp(@$, $1, $3);}

  /* Control structures. */
  | "if" exp "then" exp "else" exp { $$ = make_IfExp(@$, $2, $4, $6); }
  | "if" exp "then" exp { $$ = make_IfExp(@$, $2, $4); }
  | "while" exp "do" exp { $$ = make_WhileExp(@$, $2, $4); }
  | "for" ID ":=" exp "to" exp "do" exp 
   { $$ = make_ForExp(@$, make_VarDec(@$, $2, nullptr, $4), $6, $8); }
  | "break" { $$ = make_BreakExp(@$); }
  | "let" chunks "in" exps "end" {$$ = make_LetExp(@$, $2, make_SeqExp(@$, $4)); }
  
  /* object-oriented */
  //| "new" typeid    {}
  //| lvalue "." ID "(" funcall ")"
  /* Cast of an expression  to a given type */
  | CAST "(" exp "," ty ")" { $$ = make_CastExp(@$, $3, $5); }
  /* An expression metavariable */
  | EXP "(" INT ")" {$$ = metavar<ast::Exp>(td, $3);}
  ;
%token LVALUE "_lvalue";

lvalue:
  ID {$$ = make_SimpleVar(@$, $1);}
  | lvalue "." ID {$$ = make_FieldVar(@$, $1, $3);}
  | lvalue "[" exp "]" {$$ = make_SubscriptVar(@$, $1, $3);}
  /* A l-value metavariable */
  | LVALUE "(" INT ")" {$$ = metavar<ast::Var>(td, $3);}
  ;

funcall:
  %empty               {$$ = make_exps_type(); }
| funcall.1           { $$ = $1; }
;

funcall.1:
  funcall.1 "," funcall.2 { $$ = $1; $$->emplace_back($3); }
| funcall.2                { $$ = make_exps_type(); $$->emplace_back($1);}
;
funcall.2:
  exp     { $$ = $1; }
;
/*
:idexp:
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
*/
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
  %empty                  {$$ = make_ChunkList(@$); }
| tychunk chunks        { $$ = $2; $$->push_front($1);}
| funchunk chunks         { $$ = $2; $$->push_front($1);}//
| varchunk chunks         { $$ = $2; $$->push_front($1); }
/* A list of chunk metavariable */
//| CHUNKS "(" INT ")" chunks { $$ = metavar<ast::ChunkList>(td, $3); $$->push_front($5->list)}
  // FIXME: Some code was deleted here (More rules).
;
funchunk:
  fundec %prec CHUNKS  { $$ = make_FunctionChunk(@1); $$->push_front(*$1);}
| fundec funchunk { $$ = $2; $$->push_front(*$1); }
;  

fundec:
  "function" ID "(" tyfields ")" "=" exp 
  {$$ = make_FunctionDec(@$, $2, make_VarChunk(@4), nullptr,  $7); }
  | "function" ID "(" tyfields ")" typeid "=" exp 
   { $$ = make_FunctionDec(@$, $2, make_VarChunk(@4), $6,  $8); }
  | "primitive" ID "(" tyfields ")"
  { $$ = make_FunctionDec(@$, $2, make_VarChunk(@4), nullptr, nullptr); }
  | "primitive" ID "(" tyfields ")" typeid
   { $$ = make_FunctionDec(@$, $2, make_VarChunk(@4), $6, nullptr); }
  ;

varchunk:
  vardec  { $$ = make_VarChunk(@1); $$->push_front(*$1); }


vardec:
  "var" ID ":=" exp { $$ = make_VarDec(@$, $2, nullptr, $4); }
  | "var" ID ":" typeid ":=" exp { $$ = make_VarDec(@$, $2, $4, $6); }
  ;

/*--------------------.
| Type Declarations.  |
`--------------------*/

tychunk:
  /* Use `%prec CHUNKS' to do context-dependent precedence and resolve a
     shift-reduce conflict. */
  tydec %prec CHUNKS  { $$ = make_TypeChunk(@1); $$->push_front(*$1); }
| tydec tychunk       { $$ = $2; $$->push_front(*$1); }
;

tydec:
  "type" ID "=" ty { $$ = make_TypeDec(@$, $2, $4); }
;

ty:
  typeid               { $$ = $1; }
| "{" tyfields "}"     { $$ = make_RecordTy(@$, $2); }
| "array" "of" typeid  { $$ = make_ArrayTy(@$, $3); }
;

tyfields:
  %empty               { $$ = make_fields_type(); }
| tyfields.1           { $$ = $1; }
;

tyfields.1:
  tyfields.1 "," tyfield { $$ = $1; $$->emplace_back($3); }
| tyfield                { $$ = make_fields_type($1); }
;

tyfield:
  ID ":" typeid     { $$ = make_Field(@$, $1, $3); }
;

//ext:
//  %empty
//  | "extends" typeid
//  ;

//classfields:
//  %empty
//  | classfields classfield
//  ;
//classfield:
//  vardec
//  | meth.1
//  ;

//meth.1:
//  %empty
//  | meth.1 meth
//  ;
//meth:
//  "method" ID "(" tyfields ")" "=" exp
//  | "method" ID "(" tyfields ")" typeid "=" exp
//  ;

%token NAMETY "_namety";
typeid:
  ID                    { $$ = make_NameTy(@$, $1); }
  /* This is a metavariable. It it used internally by TWEASTs to retrieve
     already parsed nodes when given an input to parse. */
| NAMETY "(" INT ")"    { $$ = metavar<ast::NameTy>(td, $3); }
;

%%

void
parse::parser::error(const location_type& l, const std::string& m)
{
  // FIXED
  td.error_ << l << ": " << m << misc::error::error_type::parse << "\n";

}
