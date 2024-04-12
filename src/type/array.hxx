/**
 ** \file type/array.hxx
 ** \brief Inline methods for type::Array.
 */
#pragma once

#include <misc/contract.hh>
#include <type/array.hh>

namespace type
{
  // FIXED: Some code was deleted here.
  inline const Type& Array::type_get() const { return *type_; }
  inline Type& Array::type_get() { return *type_; }

} // namespace type
