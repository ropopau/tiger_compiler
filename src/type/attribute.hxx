/**
 ** \file type/attribute.hxx
 ** \brief Inline methods for type::Attribute.
 */
#pragma once

namespace type
{
  inline misc::symbol Attribute::name_get() const { return def_->name_get(); }

  inline const Type& Attribute::type_get() const
  {
    // FIXED: Some code was deleted here.
    return dynamic_cast<const Type&>(*def_->type_name_get());
  }

  inline const ast::VarDec* Attribute::def_get() const { return def_; }

  inline void Attribute::def_set(const ast::VarDec* def) { def_ = def; }

} // namespace type
