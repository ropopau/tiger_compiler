/**
 ** \file ast/typable.cc
 ** \brief Implementation of ast::Typable.
 */

#include <ast/typable.hh>
#include <ast/visitor.hh>

namespace ast
{
  // FIXED: Some code was deleted here.
  Typable::Typable(const type::Type* t)
    : type_(t)
  {}
} // namespace ast
