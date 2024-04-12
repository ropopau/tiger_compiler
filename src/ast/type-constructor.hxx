/**
 ** \file ast/type-constructor.hxx
 ** \brief Inline methods of ast::TypeConstructor.
 */

#pragma once

#include <ast/type-constructor.hh>
#include <type/types.hh>

namespace ast
{
  // FIXED: Some code was deleted here.
  inline void TypeConstructor::created_type_set(const type::Type* t)
  {
    type_c_ = t;
  }
  inline const type::Type* TypeConstructor::created_type_get() const
  {
    return type_c_;
  }
} // namespace ast
