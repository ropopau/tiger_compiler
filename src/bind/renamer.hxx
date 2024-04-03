/**
 ** \file bind/renamer.hxx
 ** \brief Template methods of bind::Renamer.
 */

#pragma once

#include <bind/renamer.hh>

namespace bind
{
  // FIXME: Some code was deleted here.

  template <class E, class Def> void Renamer::visit(E& e, const Def* def)
  {
    // FIXME: Some code was deleted here.
     if(this->map_.contains(def))
    {

      auto res = this->map_.find(def);
      e.name_set(res->second);
      return;

    }
    auto new_name = misc::symbol::fresh(e.name_get());
    e.name_set(new_name);
    this->map_.insert(std::pair(&e,e.name_get()));
    return;
  }
} // namespace bind
