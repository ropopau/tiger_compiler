// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison GLR parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// C++ GLR parser skeleton written by Valentin Tolmer.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_PARSE_SRC_PARSE_PARSETIGER_HH_INCLUDED
# define YY_PARSE_SRC_PARSE_PARSETIGER_HH_INCLUDED
// "%code requires" blocks.
#line 47 "parse/parsetiger.yy"

#include <string>
#include <misc/algorithm.hh>
#include <misc/separator.hh>
#include <misc/symbol.hh>
#include <parse/fwd.hh>
#include <parse/tiger-driver.hh>
  // Pre-declare parse::parse to allow a ``reentrant'' parsing within
  // the parser.
  namespace parse
  {
    ast_type parse(Tweast& input);
  }
#line 78 "parse/parsetiger.yy"

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

#line 74 "parse/parsetiger.hh"

#include <algorithm>
#include <cstddef> // ptrdiff_t
#include <cstring> // memcpy
#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <stdint.h>
#include <string>
#include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"


/* Debug traces.  */
#ifndef PARSEDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define PARSEDEBUG 1
#  else
#   define PARSEDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define PARSEDEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined PARSEDEBUG */

#line 6 "parse/parsetiger.yy"
namespace parse {
#line 141 "parse/parsetiger.hh"




  /// A Bison parser.
  class parser
  {
  public:
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // chunks
      // classfields
      char dummy1[sizeof (ast::ChunkList*)];

      // exps.2
      // exp
      // funcall.2
      char dummy2[sizeof (ast::Exp*)];

      // tyfield
      char dummy3[sizeof (ast::Field*)];

      // rec.2
      char dummy4[sizeof (ast::FieldInit*)];

      // funchunk
      char dummy5[sizeof (ast::FunctionChunk*)];

      // fundec
      char dummy6[sizeof (ast::FunctionDec*)];

      // methchunk
      char dummy7[sizeof (ast::MethodChunk*)];

      // methdec
      char dummy8[sizeof (ast::MethodDec*)];

      // typeid
      char dummy9[sizeof (ast::NameTy*)];

      // ty
      char dummy10[sizeof (ast::Ty*)];

      // tychunk
      char dummy11[sizeof (ast::TypeChunk*)];

      // tydec
      char dummy12[sizeof (ast::TypeDec*)];

      // lvalue
      char dummy13[sizeof (ast::Var*)];

      // varchunk
      // tyvarchunks
      // tyvarchunks.1
      char dummy14[sizeof (ast::VarChunk*)];

      // vardec
      // tyvardec
      char dummy15[sizeof (ast::VarDec*)];

      // exps
      // exps.1
      // funcall
      // funcall.1
      char dummy16[sizeof (ast::exps_type*)];

      // rec
      // rec.1
      char dummy17[sizeof (ast::fieldinits_type*)];

      // tyfields
      // tyfields.1
      char dummy18[sizeof (ast::fields_type*)];

      // "integer"
      char dummy19[sizeof (int)];

      // "identifier"
      char dummy20[sizeof (misc::symbol)];

      // "string"
      char dummy21[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        TOK_PARSEEMPTY = -2,
    TOK_EOF = 0,                   // "end of file"
    TOK_PARSEerror = 256,          // error
    TOK_PARSEUNDEF = 257,          // "invalid token"
    TOK_STRING = 258,              // "string"
    TOK_ID = 259,                  // "identifier"
    TOK_INT = 260,                 // "integer"
    TOK_AND = 261,                 // "&"
    TOK_ARRAY = 262,               // "array"
    TOK_ASSIGN = 263,              // ":="
    TOK_BREAK = 264,               // "break"
    TOK_CAST = 265,                // "_cast"
    TOK_CLASS = 266,               // "class"
    TOK_COLON = 267,               // ":"
    TOK_COMMA = 268,               // ","
    TOK_DIVIDE = 269,              // "/"
    TOK_DO = 270,                  // "do"
    TOK_DOT = 271,                 // "."
    TOK_ELSE = 272,                // "else"
    TOK_END = 273,                 // "end"
    TOK_EQ = 274,                  // "="
    TOK_EXTENDS = 275,             // "extends"
    TOK_FOR = 276,                 // "for"
    TOK_FUNCTION = 277,            // "function"
    TOK_GE = 278,                  // ">="
    TOK_GT = 279,                  // ">"
    TOK_IF = 280,                  // "if"
    TOK_IMPORT = 281,              // "import"
    TOK_IN = 282,                  // "in"
    TOK_LBRACE = 283,              // "{"
    TOK_LBRACK = 284,              // "["
    TOK_LE = 285,                  // "<="
    TOK_LET = 286,                 // "let"
    TOK_LPAREN = 287,              // "("
    TOK_LT = 288,                  // "<"
    TOK_MINUS = 289,               // "-"
    TOK_METHOD = 290,              // "method"
    TOK_NE = 291,                  // "<>"
    TOK_NEW = 292,                 // "new"
    TOK_NIL = 293,                 // "nil"
    TOK_OF = 294,                  // "of"
    TOK_OR = 295,                  // "|"
    TOK_PLUS = 296,                // "+"
    TOK_PRIMITIVE = 297,           // "primitive"
    TOK_RBRACE = 298,              // "}"
    TOK_RBRACK = 299,              // "]"
    TOK_RPAREN = 300,              // ")"
    TOK_SEMI = 301,                // ";"
    TOK_THEN = 302,                // "then"
    TOK_TIMES = 303,               // "*"
    TOK_TO = 304,                  // "to"
    TOK_TYPE = 305,                // "type"
    TOK_VAR = 306,                 // "var"
    TOK_WHILE = 307,               // "while"
    TOK_EXP = 308,                 // "_exp"
    TOK_LVALUE = 309,              // "_lvalue"
    TOK_CHUNKS = 310,              // "_chunks"
    TOK_NAMETY = 311               // "_namety"
      };
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 57, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_STRING = 3,                            // "string"
        S_ID = 4,                                // "identifier"
        S_INT = 5,                               // "integer"
        S_AND = 6,                               // "&"
        S_ARRAY = 7,                             // "array"
        S_ASSIGN = 8,                            // ":="
        S_BREAK = 9,                             // "break"
        S_CAST = 10,                             // "_cast"
        S_CLASS = 11,                            // "class"
        S_COLON = 12,                            // ":"
        S_COMMA = 13,                            // ","
        S_DIVIDE = 14,                           // "/"
        S_DO = 15,                               // "do"
        S_DOT = 16,                              // "."
        S_ELSE = 17,                             // "else"
        S_END = 18,                              // "end"
        S_EQ = 19,                               // "="
        S_EXTENDS = 20,                          // "extends"
        S_FOR = 21,                              // "for"
        S_FUNCTION = 22,                         // "function"
        S_GE = 23,                               // ">="
        S_GT = 24,                               // ">"
        S_IF = 25,                               // "if"
        S_IMPORT = 26,                           // "import"
        S_IN = 27,                               // "in"
        S_LBRACE = 28,                           // "{"
        S_LBRACK = 29,                           // "["
        S_LE = 30,                               // "<="
        S_LET = 31,                              // "let"
        S_LPAREN = 32,                           // "("
        S_LT = 33,                               // "<"
        S_MINUS = 34,                            // "-"
        S_METHOD = 35,                           // "method"
        S_NE = 36,                               // "<>"
        S_NEW = 37,                              // "new"
        S_NIL = 38,                              // "nil"
        S_OF = 39,                               // "of"
        S_OR = 40,                               // "|"
        S_PLUS = 41,                             // "+"
        S_PRIMITIVE = 42,                        // "primitive"
        S_RBRACE = 43,                           // "}"
        S_RBRACK = 44,                           // "]"
        S_RPAREN = 45,                           // ")"
        S_SEMI = 46,                             // ";"
        S_THEN = 47,                             // "then"
        S_TIMES = 48,                            // "*"
        S_TO = 49,                               // "to"
        S_TYPE = 50,                             // "type"
        S_VAR = 51,                              // "var"
        S_WHILE = 52,                            // "while"
        S_EXP = 53,                              // "_exp"
        S_LVALUE = 54,                           // "_lvalue"
        S_CHUNKS = 55,                           // "_chunks"
        S_NAMETY = 56,                           // "_namety"
        S_YYACCEPT = 57,                         // $accept
        S_program = 58,                          // program
        S_exps = 59,                             // exps
        S_60_exps_1 = 60,                        // exps.1
        S_61_exps_2 = 61,                        // exps.2
        S_rec = 62,                              // rec
        S_63_rec_1 = 63,                         // rec.1
        S_64_rec_2 = 64,                         // rec.2
        S_exp = 65,                              // exp
        S_lvalue = 66,                           // lvalue
        S_funcall = 67,                          // funcall
        S_68_funcall_1 = 68,                     // funcall.1
        S_69_funcall_2 = 69,                     // funcall.2
        S_chunks = 70,                           // chunks
        S_funchunk = 71,                         // funchunk
        S_fundec = 72,                           // fundec
        S_varchunk = 73,                         // varchunk
        S_vardec = 74,                           // vardec
        S_tychunk = 75,                          // tychunk
        S_tydec = 76,                            // tydec
        S_ty = 77,                               // ty
        S_tyfields = 78,                         // tyfields
        S_79_tyfields_1 = 79,                    // tyfields.1
        S_tyfield = 80,                          // tyfield
        S_tyvarchunks = 81,                      // tyvarchunks
        S_82_tyvarchunks_1 = 82,                 // tyvarchunks.1
        S_tyvardec = 83,                         // tyvardec
        S_classfields = 84,                      // classfields
        S_methchunk = 85,                        // methchunk
        S_methdec = 86,                          // methdec
        S_typeid = 87                            // typeid
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        value.move< ast::ChunkList* > (std::move (that.value));
        break;

      case symbol_kind::S_61_exps_2: // exps.2
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_69_funcall_2: // funcall.2
        value.move< ast::Exp* > (std::move (that.value));
        break;

      case symbol_kind::S_tyfield: // tyfield
        value.move< ast::Field* > (std::move (that.value));
        break;

      case symbol_kind::S_64_rec_2: // rec.2
        value.move< ast::FieldInit* > (std::move (that.value));
        break;

      case symbol_kind::S_funchunk: // funchunk
        value.move< ast::FunctionChunk* > (std::move (that.value));
        break;

      case symbol_kind::S_fundec: // fundec
        value.move< ast::FunctionDec* > (std::move (that.value));
        break;

      case symbol_kind::S_methchunk: // methchunk
        value.move< ast::MethodChunk* > (std::move (that.value));
        break;

      case symbol_kind::S_methdec: // methdec
        value.move< ast::MethodDec* > (std::move (that.value));
        break;

      case symbol_kind::S_typeid: // typeid
        value.move< ast::NameTy* > (std::move (that.value));
        break;

      case symbol_kind::S_ty: // ty
        value.move< ast::Ty* > (std::move (that.value));
        break;

      case symbol_kind::S_tychunk: // tychunk
        value.move< ast::TypeChunk* > (std::move (that.value));
        break;

      case symbol_kind::S_tydec: // tydec
        value.move< ast::TypeDec* > (std::move (that.value));
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.move< ast::Var* > (std::move (that.value));
        break;

      case symbol_kind::S_varchunk: // varchunk
      case symbol_kind::S_tyvarchunks: // tyvarchunks
      case symbol_kind::S_82_tyvarchunks_1: // tyvarchunks.1
        value.move< ast::VarChunk* > (std::move (that.value));
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_tyvardec: // tyvardec
        value.move< ast::VarDec* > (std::move (that.value));
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_60_exps_1: // exps.1
      case symbol_kind::S_funcall: // funcall
      case symbol_kind::S_68_funcall_1: // funcall.1
        value.move< ast::exps_type* > (std::move (that.value));
        break;

      case symbol_kind::S_rec: // rec
      case symbol_kind::S_63_rec_1: // rec.1
        value.move< ast::fieldinits_type* > (std::move (that.value));
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_79_tyfields_1: // tyfields.1
        value.move< ast::fields_type* > (std::move (that.value));
        break;

      case symbol_kind::S_INT: // "integer"
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_ID: // "identifier"
        value.move< misc::symbol > (std::move (that.value));
        break;

      case symbol_kind::S_STRING: // "string"
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::ChunkList*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::ChunkList*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::Exp*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::Exp*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::Field*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::Field*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::FieldInit*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::FieldInit*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::FunctionChunk*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::FunctionChunk*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::FunctionDec*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::FunctionDec*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::MethodChunk*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::MethodChunk*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::MethodDec*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::MethodDec*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::NameTy*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::NameTy*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::Ty*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::Ty*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::TypeChunk*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::TypeChunk*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::TypeDec*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::TypeDec*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::Var*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::Var*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::VarChunk*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::VarChunk*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::VarDec*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::VarDec*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::exps_type*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::exps_type*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::fieldinits_type*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::fieldinits_type*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::fields_type*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::fields_type*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, misc::symbol&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const misc::symbol& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }


      /// Copy assignment.
      basic_symbol& operator= (const basic_symbol& that)
      {
        Base::operator= (that);
        switch (this->kind ())
    {
      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        value.copy< ast::ChunkList* > (that.value);
        break;

      case symbol_kind::S_61_exps_2: // exps.2
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_69_funcall_2: // funcall.2
        value.copy< ast::Exp* > (that.value);
        break;

      case symbol_kind::S_tyfield: // tyfield
        value.copy< ast::Field* > (that.value);
        break;

      case symbol_kind::S_64_rec_2: // rec.2
        value.copy< ast::FieldInit* > (that.value);
        break;

      case symbol_kind::S_funchunk: // funchunk
        value.copy< ast::FunctionChunk* > (that.value);
        break;

      case symbol_kind::S_fundec: // fundec
        value.copy< ast::FunctionDec* > (that.value);
        break;

      case symbol_kind::S_methchunk: // methchunk
        value.copy< ast::MethodChunk* > (that.value);
        break;

      case symbol_kind::S_methdec: // methdec
        value.copy< ast::MethodDec* > (that.value);
        break;

      case symbol_kind::S_typeid: // typeid
        value.copy< ast::NameTy* > (that.value);
        break;

      case symbol_kind::S_ty: // ty
        value.copy< ast::Ty* > (that.value);
        break;

      case symbol_kind::S_tychunk: // tychunk
        value.copy< ast::TypeChunk* > (that.value);
        break;

      case symbol_kind::S_tydec: // tydec
        value.copy< ast::TypeDec* > (that.value);
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.copy< ast::Var* > (that.value);
        break;

      case symbol_kind::S_varchunk: // varchunk
      case symbol_kind::S_tyvarchunks: // tyvarchunks
      case symbol_kind::S_82_tyvarchunks_1: // tyvarchunks.1
        value.copy< ast::VarChunk* > (that.value);
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_tyvardec: // tyvardec
        value.copy< ast::VarDec* > (that.value);
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_60_exps_1: // exps.1
      case symbol_kind::S_funcall: // funcall
      case symbol_kind::S_68_funcall_1: // funcall.1
        value.copy< ast::exps_type* > (that.value);
        break;

      case symbol_kind::S_rec: // rec
      case symbol_kind::S_63_rec_1: // rec.1
        value.copy< ast::fieldinits_type* > (that.value);
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_79_tyfields_1: // tyfields.1
        value.copy< ast::fields_type* > (that.value);
        break;

      case symbol_kind::S_INT: // "integer"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ID: // "identifier"
        value.copy< misc::symbol > (that.value);
        break;

      case symbol_kind::S_STRING: // "string"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }
;
        location = that.location;
        return *this;
      }

      /// Move assignment.
      basic_symbol& operator= (basic_symbol&& that)
      {
        Base::operator= (std::move (that));
        switch (this->kind ())
    {
      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        value.move< ast::ChunkList* > (std::move (that.value));
        break;

      case symbol_kind::S_61_exps_2: // exps.2
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_69_funcall_2: // funcall.2
        value.move< ast::Exp* > (std::move (that.value));
        break;

      case symbol_kind::S_tyfield: // tyfield
        value.move< ast::Field* > (std::move (that.value));
        break;

      case symbol_kind::S_64_rec_2: // rec.2
        value.move< ast::FieldInit* > (std::move (that.value));
        break;

      case symbol_kind::S_funchunk: // funchunk
        value.move< ast::FunctionChunk* > (std::move (that.value));
        break;

      case symbol_kind::S_fundec: // fundec
        value.move< ast::FunctionDec* > (std::move (that.value));
        break;

      case symbol_kind::S_methchunk: // methchunk
        value.move< ast::MethodChunk* > (std::move (that.value));
        break;

      case symbol_kind::S_methdec: // methdec
        value.move< ast::MethodDec* > (std::move (that.value));
        break;

      case symbol_kind::S_typeid: // typeid
        value.move< ast::NameTy* > (std::move (that.value));
        break;

      case symbol_kind::S_ty: // ty
        value.move< ast::Ty* > (std::move (that.value));
        break;

      case symbol_kind::S_tychunk: // tychunk
        value.move< ast::TypeChunk* > (std::move (that.value));
        break;

      case symbol_kind::S_tydec: // tydec
        value.move< ast::TypeDec* > (std::move (that.value));
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.move< ast::Var* > (std::move (that.value));
        break;

      case symbol_kind::S_varchunk: // varchunk
      case symbol_kind::S_tyvarchunks: // tyvarchunks
      case symbol_kind::S_82_tyvarchunks_1: // tyvarchunks.1
        value.move< ast::VarChunk* > (std::move (that.value));
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_tyvardec: // tyvardec
        value.move< ast::VarDec* > (std::move (that.value));
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_60_exps_1: // exps.1
      case symbol_kind::S_funcall: // funcall
      case symbol_kind::S_68_funcall_1: // funcall.1
        value.move< ast::exps_type* > (std::move (that.value));
        break;

      case symbol_kind::S_rec: // rec
      case symbol_kind::S_63_rec_1: // rec.1
        value.move< ast::fieldinits_type* > (std::move (that.value));
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_79_tyfields_1: // tyfields.1
        value.move< ast::fields_type* > (std::move (that.value));
        break;

      case symbol_kind::S_INT: // "integer"
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_ID: // "identifier"
        value.move< misc::symbol > (std::move (that.value));
        break;

      case symbol_kind::S_STRING: // "string"
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }
;
        location = std::move (that.location);
        return *this;
      }


      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        value.template destroy< ast::ChunkList* > ();
        break;

      case symbol_kind::S_61_exps_2: // exps.2
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_69_funcall_2: // funcall.2
        value.template destroy< ast::Exp* > ();
        break;

      case symbol_kind::S_tyfield: // tyfield
        value.template destroy< ast::Field* > ();
        break;

      case symbol_kind::S_64_rec_2: // rec.2
        value.template destroy< ast::FieldInit* > ();
        break;

      case symbol_kind::S_funchunk: // funchunk
        value.template destroy< ast::FunctionChunk* > ();
        break;

      case symbol_kind::S_fundec: // fundec
        value.template destroy< ast::FunctionDec* > ();
        break;

      case symbol_kind::S_methchunk: // methchunk
        value.template destroy< ast::MethodChunk* > ();
        break;

      case symbol_kind::S_methdec: // methdec
        value.template destroy< ast::MethodDec* > ();
        break;

      case symbol_kind::S_typeid: // typeid
        value.template destroy< ast::NameTy* > ();
        break;

      case symbol_kind::S_ty: // ty
        value.template destroy< ast::Ty* > ();
        break;

      case symbol_kind::S_tychunk: // tychunk
        value.template destroy< ast::TypeChunk* > ();
        break;

      case symbol_kind::S_tydec: // tydec
        value.template destroy< ast::TypeDec* > ();
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.template destroy< ast::Var* > ();
        break;

      case symbol_kind::S_varchunk: // varchunk
      case symbol_kind::S_tyvarchunks: // tyvarchunks
      case symbol_kind::S_82_tyvarchunks_1: // tyvarchunks.1
        value.template destroy< ast::VarChunk* > ();
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_tyvardec: // tyvardec
        value.template destroy< ast::VarDec* > ();
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_60_exps_1: // exps.1
      case symbol_kind::S_funcall: // funcall
      case symbol_kind::S_68_funcall_1: // funcall.1
        value.template destroy< ast::exps_type* > ();
        break;

      case symbol_kind::S_rec: // rec
      case symbol_kind::S_63_rec_1: // rec.1
        value.template destroy< ast::fieldinits_type* > ();
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_79_tyfields_1: // tyfields.1
        value.template destroy< ast::fields_type* > ();
        break;

      case symbol_kind::S_INT: // "integer"
        value.template destroy< int > ();
        break;

      case symbol_kind::S_ID: // "identifier"
        value.template destroy< misc::symbol > ();
        break;

      case symbol_kind::S_STRING: // "string"
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;


      /// Copy assignment.
      by_kind& operator= (const by_kind& that);

      /// Move assignment.
      by_kind& operator= (by_kind&& that);


      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const int& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, misc::symbol v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const misc::symbol& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
    };


    // FIXME: should be private eventually.
    class glr_stack;
    class glr_state;

    /// Build a parser object.
    parser (::parse::TigerDriver& td_yyarg, ::parse::Lexer& lexer_yyarg);
    ~parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    int parse ();

#if PARSEDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    using debug_level_type = int;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    void error (const location_type& loc, const std::string& msg);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EOF (location_type l)
      {
        return symbol_type (token::TOK_EOF, std::move (l));
      }
#else
      static
      symbol_type
      make_EOF (const location_type& l)
      {
        return symbol_type (token::TOK_EOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PARSEerror (location_type l)
      {
        return symbol_type (token::TOK_PARSEerror, std::move (l));
      }
#else
      static
      symbol_type
      make_PARSEerror (const location_type& l)
      {
        return symbol_type (token::TOK_PARSEerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PARSEUNDEF (location_type l)
      {
        return symbol_type (token::TOK_PARSEUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_PARSEUNDEF (const location_type& l)
      {
        return symbol_type (token::TOK_PARSEUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::TOK_STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (misc::symbol v, location_type l)
      {
        return symbol_type (token::TOK_ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID (const misc::symbol& v, const location_type& l)
      {
        return symbol_type (token::TOK_ID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (int v, location_type l)
      {
        return symbol_type (token::TOK_INT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INT (const int& v, const location_type& l)
      {
        return symbol_type (token::TOK_INT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::TOK_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::TOK_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY (location_type l)
      {
        return symbol_type (token::TOK_ARRAY, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRAY (const location_type& l)
      {
        return symbol_type (token::TOK_ARRAY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (location_type l)
      {
        return symbol_type (token::TOK_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (location_type l)
      {
        return symbol_type (token::TOK_BREAK, std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const location_type& l)
      {
        return symbol_type (token::TOK_BREAK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAST (location_type l)
      {
        return symbol_type (token::TOK_CAST, std::move (l));
      }
#else
      static
      symbol_type
      make_CAST (const location_type& l)
      {
        return symbol_type (token::TOK_CAST, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLASS (location_type l)
      {
        return symbol_type (token::TOK_CLASS, std::move (l));
      }
#else
      static
      symbol_type
      make_CLASS (const location_type& l)
      {
        return symbol_type (token::TOK_CLASS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::TOK_COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::TOK_COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::TOK_COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::TOK_COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIVIDE (location_type l)
      {
        return symbol_type (token::TOK_DIVIDE, std::move (l));
      }
#else
      static
      symbol_type
      make_DIVIDE (const location_type& l)
      {
        return symbol_type (token::TOK_DIVIDE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO (location_type l)
      {
        return symbol_type (token::TOK_DO, std::move (l));
      }
#else
      static
      symbol_type
      make_DO (const location_type& l)
      {
        return symbol_type (token::TOK_DO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (location_type l)
      {
        return symbol_type (token::TOK_DOT, std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const location_type& l)
      {
        return symbol_type (token::TOK_DOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::TOK_ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::TOK_ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::TOK_END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::TOK_END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ (location_type l)
      {
        return symbol_type (token::TOK_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_EQ (const location_type& l)
      {
        return symbol_type (token::TOK_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTENDS (location_type l)
      {
        return symbol_type (token::TOK_EXTENDS, std::move (l));
      }
#else
      static
      symbol_type
      make_EXTENDS (const location_type& l)
      {
        return symbol_type (token::TOK_EXTENDS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (location_type l)
      {
        return symbol_type (token::TOK_FOR, std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const location_type& l)
      {
        return symbol_type (token::TOK_FOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNCTION (location_type l)
      {
        return symbol_type (token::TOK_FUNCTION, std::move (l));
      }
#else
      static
      symbol_type
      make_FUNCTION (const location_type& l)
      {
        return symbol_type (token::TOK_FUNCTION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE (location_type l)
      {
        return symbol_type (token::TOK_GE, std::move (l));
      }
#else
      static
      symbol_type
      make_GE (const location_type& l)
      {
        return symbol_type (token::TOK_GE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT (location_type l)
      {
        return symbol_type (token::TOK_GT, std::move (l));
      }
#else
      static
      symbol_type
      make_GT (const location_type& l)
      {
        return symbol_type (token::TOK_GT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::TOK_IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::TOK_IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IMPORT (location_type l)
      {
        return symbol_type (token::TOK_IMPORT, std::move (l));
      }
#else
      static
      symbol_type
      make_IMPORT (const location_type& l)
      {
        return symbol_type (token::TOK_IMPORT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IN (location_type l)
      {
        return symbol_type (token::TOK_IN, std::move (l));
      }
#else
      static
      symbol_type
      make_IN (const location_type& l)
      {
        return symbol_type (token::TOK_IN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACE (location_type l)
      {
        return symbol_type (token::TOK_LBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACE (const location_type& l)
      {
        return symbol_type (token::TOK_LBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACK (location_type l)
      {
        return symbol_type (token::TOK_LBRACK, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACK (const location_type& l)
      {
        return symbol_type (token::TOK_LBRACK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE (location_type l)
      {
        return symbol_type (token::TOK_LE, std::move (l));
      }
#else
      static
      symbol_type
      make_LE (const location_type& l)
      {
        return symbol_type (token::TOK_LE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LET (location_type l)
      {
        return symbol_type (token::TOK_LET, std::move (l));
      }
#else
      static
      symbol_type
      make_LET (const location_type& l)
      {
        return symbol_type (token::TOK_LET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (location_type l)
      {
        return symbol_type (token::TOK_LPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const location_type& l)
      {
        return symbol_type (token::TOK_LPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT (location_type l)
      {
        return symbol_type (token::TOK_LT, std::move (l));
      }
#else
      static
      symbol_type
      make_LT (const location_type& l)
      {
        return symbol_type (token::TOK_LT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::TOK_MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::TOK_MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_METHOD (location_type l)
      {
        return symbol_type (token::TOK_METHOD, std::move (l));
      }
#else
      static
      symbol_type
      make_METHOD (const location_type& l)
      {
        return symbol_type (token::TOK_METHOD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE (location_type l)
      {
        return symbol_type (token::TOK_NE, std::move (l));
      }
#else
      static
      symbol_type
      make_NE (const location_type& l)
      {
        return symbol_type (token::TOK_NE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEW (location_type l)
      {
        return symbol_type (token::TOK_NEW, std::move (l));
      }
#else
      static
      symbol_type
      make_NEW (const location_type& l)
      {
        return symbol_type (token::TOK_NEW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NIL (location_type l)
      {
        return symbol_type (token::TOK_NIL, std::move (l));
      }
#else
      static
      symbol_type
      make_NIL (const location_type& l)
      {
        return symbol_type (token::TOK_NIL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OF (location_type l)
      {
        return symbol_type (token::TOK_OF, std::move (l));
      }
#else
      static
      symbol_type
      make_OF (const location_type& l)
      {
        return symbol_type (token::TOK_OF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (location_type l)
      {
        return symbol_type (token::TOK_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const location_type& l)
      {
        return symbol_type (token::TOK_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::TOK_PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::TOK_PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRIMITIVE (location_type l)
      {
        return symbol_type (token::TOK_PRIMITIVE, std::move (l));
      }
#else
      static
      symbol_type
      make_PRIMITIVE (const location_type& l)
      {
        return symbol_type (token::TOK_PRIMITIVE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACE (location_type l)
      {
        return symbol_type (token::TOK_RBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACE (const location_type& l)
      {
        return symbol_type (token::TOK_RBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACK (location_type l)
      {
        return symbol_type (token::TOK_RBRACK, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACK (const location_type& l)
      {
        return symbol_type (token::TOK_RBRACK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (location_type l)
      {
        return symbol_type (token::TOK_RPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const location_type& l)
      {
        return symbol_type (token::TOK_RPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMI (location_type l)
      {
        return symbol_type (token::TOK_SEMI, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMI (const location_type& l)
      {
        return symbol_type (token::TOK_SEMI, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THEN (location_type l)
      {
        return symbol_type (token::TOK_THEN, std::move (l));
      }
#else
      static
      symbol_type
      make_THEN (const location_type& l)
      {
        return symbol_type (token::TOK_THEN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIMES (location_type l)
      {
        return symbol_type (token::TOK_TIMES, std::move (l));
      }
#else
      static
      symbol_type
      make_TIMES (const location_type& l)
      {
        return symbol_type (token::TOK_TIMES, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TO (location_type l)
      {
        return symbol_type (token::TOK_TO, std::move (l));
      }
#else
      static
      symbol_type
      make_TO (const location_type& l)
      {
        return symbol_type (token::TOK_TO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE (location_type l)
      {
        return symbol_type (token::TOK_TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE (const location_type& l)
      {
        return symbol_type (token::TOK_TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR (location_type l)
      {
        return symbol_type (token::TOK_VAR, std::move (l));
      }
#else
      static
      symbol_type
      make_VAR (const location_type& l)
      {
        return symbol_type (token::TOK_VAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (location_type l)
      {
        return symbol_type (token::TOK_WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const location_type& l)
      {
        return symbol_type (token::TOK_WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXP (location_type l)
      {
        return symbol_type (token::TOK_EXP, std::move (l));
      }
#else
      static
      symbol_type
      make_EXP (const location_type& l)
      {
        return symbol_type (token::TOK_EXP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LVALUE (location_type l)
      {
        return symbol_type (token::TOK_LVALUE, std::move (l));
      }
#else
      static
      symbol_type
      make_LVALUE (const location_type& l)
      {
        return symbol_type (token::TOK_LVALUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHUNKS (location_type l)
      {
        return symbol_type (token::TOK_CHUNKS, std::move (l));
      }
#else
      static
      symbol_type
      make_CHUNKS (const location_type& l)
      {
        return symbol_type (token::TOK_CHUNKS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NAMETY (location_type l)
      {
        return symbol_type (token::TOK_NAMETY, std::move (l));
      }
#else
      static
      symbol_type
      make_NAMETY (const location_type& l)
      {
        return symbol_type (token::TOK_NAMETY, l);
      }
#endif


    class context
    {
    public:
      context (glr_stack& yystack, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      glr_stack& yystack_;
      const symbol_type& yyla_;
    };

# if PARSEDEBUG
  public:
    /// \brief Report a symbol value on the debug stream.
    /// \param yykind   The symbol kind.
    /// \param yyval    Its semantic value.
    /// \param yyloc    Its location.
    void yy_symbol_value_print_ (symbol_kind_type yykind,
                                 const value_type& yyval,
                                 const location_type& yyloc) const;
    /// \brief Report a symbol on the debug stream.
    /// \param yykind   The symbol kind.
    /// \param yyval    Its semantic value.
    /// \param yyloc    Its location.
    void yy_symbol_print_ (symbol_kind_type yykind,
                           const value_type& yyval,
                           const location_type& yyloc) const;
  private:
    /// Debug stream.
    std::ostream* yycdebug_;
#endif


  private:
    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yykind    The symbol kind.
    void yy_destroy_ (const char* yymsg, symbol_kind_type yykind,
                      value_type& yyval,
                      location_type& yyloc);


    // User arguments.
    ::parse::TigerDriver& td;
    ::parse::Lexer& lexer;
    // Needs access to yy_destroy_, report_syntax_error, etc.
    friend glr_stack;
  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
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
      55,    56
    };
    // Last valid token kind.
    const int code_max = 311;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        value.copy< ast::ChunkList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_61_exps_2: // exps.2
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_69_funcall_2: // funcall.2
        value.copy< ast::Exp* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tyfield: // tyfield
        value.copy< ast::Field* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_64_rec_2: // rec.2
        value.copy< ast::FieldInit* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_funchunk: // funchunk
        value.copy< ast::FunctionChunk* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fundec: // fundec
        value.copy< ast::FunctionDec* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_methchunk: // methchunk
        value.copy< ast::MethodChunk* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_methdec: // methdec
        value.copy< ast::MethodDec* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_typeid: // typeid
        value.copy< ast::NameTy* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ty: // ty
        value.copy< ast::Ty* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tychunk: // tychunk
        value.copy< ast::TypeChunk* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tydec: // tydec
        value.copy< ast::TypeDec* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.copy< ast::Var* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_varchunk: // varchunk
      case symbol_kind::S_tyvarchunks: // tyvarchunks
      case symbol_kind::S_82_tyvarchunks_1: // tyvarchunks.1
        value.copy< ast::VarChunk* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_tyvardec: // tyvardec
        value.copy< ast::VarDec* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_60_exps_1: // exps.1
      case symbol_kind::S_funcall: // funcall
      case symbol_kind::S_68_funcall_1: // funcall.1
        value.copy< ast::exps_type* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_rec: // rec
      case symbol_kind::S_63_rec_1: // rec.1
        value.copy< ast::fieldinits_type* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_79_tyfields_1: // tyfields.1
        value.copy< ast::fields_type* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // "integer"
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // "identifier"
        value.copy< misc::symbol > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "string"
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }





  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        value.move< ast::ChunkList* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_61_exps_2: // exps.2
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_69_funcall_2: // funcall.2
        value.move< ast::Exp* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tyfield: // tyfield
        value.move< ast::Field* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_64_rec_2: // rec.2
        value.move< ast::FieldInit* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_funchunk: // funchunk
        value.move< ast::FunctionChunk* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_fundec: // fundec
        value.move< ast::FunctionDec* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_methchunk: // methchunk
        value.move< ast::MethodChunk* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_methdec: // methdec
        value.move< ast::MethodDec* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_typeid: // typeid
        value.move< ast::NameTy* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ty: // ty
        value.move< ast::Ty* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tychunk: // tychunk
        value.move< ast::TypeChunk* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tydec: // tydec
        value.move< ast::TypeDec* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.move< ast::Var* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_varchunk: // varchunk
      case symbol_kind::S_tyvarchunks: // tyvarchunks
      case symbol_kind::S_82_tyvarchunks_1: // tyvarchunks.1
        value.move< ast::VarChunk* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_tyvardec: // tyvardec
        value.move< ast::VarDec* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_60_exps_1: // exps.1
      case symbol_kind::S_funcall: // funcall
      case symbol_kind::S_68_funcall_1: // funcall.1
        value.move< ast::exps_type* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_rec: // rec
      case symbol_kind::S_63_rec_1: // rec.1
        value.move< ast::fieldinits_type* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_79_tyfields_1: // tyfields.1
        value.move< ast::fields_type* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // "integer"
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ID: // "identifier"
        value.move< misc::symbol > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STRING: // "string"
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}


  inline
  parser::by_kind&
  parser::by_kind::by_kind::operator= (const by_kind& that)
  {
    kind_ = that.kind_;
    return *this;
  }

  inline
  parser::by_kind&
  parser::by_kind::by_kind::operator= (by_kind&& that)
  {
    kind_ = that.kind_;
    that.clear ();
    return *this;
  }


  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }



#line 6 "parse/parsetiger.yy"
} // parse
#line 2837 "parse/parsetiger.hh"




#endif // !YY_PARSE_SRC_PARSE_PARSETIGER_HH_INCLUDED
