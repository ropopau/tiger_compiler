/**
 ** \file ast/call-exp.hxx
 ** \brief Inline methods of ast::CallExp.
 */

#pragma once

#include <ast/call-exp.hh>

namespace ast
{

  inline misc::symbol CallExp::name_get() const { return name_; }
  inline void CallExp::name_set(misc::symbol name) { name_ = name; }

  inline const exps_type& CallExp::args_get() const { return *args_; }
  inline exps_type& CallExp::args_get() { return *args_; }

  // FIXME: Some code was deleted here.
  inline const FunctionDec* CallExp::def_get() const {return def_;}
  /// Return definition site.
  inline FunctionDec* CallExp::def_get() {return def_;}
  /// Set definition site.
  inline void CallExp::def_set(FunctionDec*def) { def_ = def ;}
  // FIXME: Some code was deleted here.

} // namespace ast
