/**
 ** \file misc/symbol.hxx
 ** \brief Inline implementation of misc::symbol.
 */

#pragma once

#include <misc/symbol.hh>

namespace misc
{
  inline symbol& symbol::operator=(const symbol& rhs)
  {
    // FIXED: Some code was deleted here.
    if (*this != rhs)
      {
        this->obj_ = &rhs.get();
      }
    return *this;
  }

  inline bool symbol::operator==(const symbol& rhs) const
  {
    // FIXED: Some code was deleted here.
    return this->get() == rhs.get();
  }

  inline bool symbol::operator!=(const symbol& rhs) const
  {
    // FIXED: Some code was deleted here.
    return this->get() != rhs.get();
  }

  inline std::ostream& operator<<(std::ostream& ostr, const symbol& the)
  {
    // FIXED: Some code was deleted here.
    ostr << the.get();
    return ostr;
  }

} // namespace misc
