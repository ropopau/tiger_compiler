/**
 ** \file ast/dec.cc
 ** \brief Implementation of ast::Dec.
 */

#include <ast/dec.hh>
#include <ast/visitor.hh>

namespace ast
{
  Dec::Dec(const Location& location, misc::symbol name)
    : Ast(location)
    , name_(name)
  {}

} // namespace ast
