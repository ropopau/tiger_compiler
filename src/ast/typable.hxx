/**
 ** \file ast/typable.hxx
 ** \brief Inline methods of ast::Typable.
 */

#pragma once

#include <ast/typable.hh>

namespace ast
{
  // FIXED: Some code was deleted here.
  inline void Typable::type_set(const type::Type* t)
  {
    type_ = t;
  }

  inline const type::Type* Typable::type_get() const
  {
    return type_;
  }
} // namespace ast
