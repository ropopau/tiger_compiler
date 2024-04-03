/**
 ** \file bind/renamer.cc
 ** \brief Implementation of bind::Renamer.
 */

#include <bind/renamer.hh>

namespace bind
{
  using namespace ast;

  // FIXME: Some code was deleted here.
  void Renamer::operator()(ast::Ast& e) { super_type::operator()(e); }

  void Renamer::operator()(ast::VarDec& e)
  {
    visit(e, &e);
    super_type::operator()(e);
  }

  void Renamer::operator()(ast::SimpleVar& e)
  {
    visit(e, e.def_get());
    super_type::operator()(e);
  }
  void Renamer::operator()(ast::FunctionDec& e)
  {
    if (e.body_get() == nullptr || e.name_get() == "_main")
      {
        super_type::operator()(e);
        return;
      }
    super_type::operator()(e);
    visit(e, &e);
  }

  void Renamer::operator()(ast::CallExp& e)
  {
    visit(e, e.def_get());
    super_type::operator()(e);
  }
  void Renamer::operator()(ast::TypeDec& e)
  {
    visit(e, &e);
    super_type::operator()(e);
  }

  void Renamer::operator()(ast::NameTy& e)
  {
    if (e.def_get() == nullptr)
      {
        super_type::operator()(e);
        return;
      }
    visit(e, e.def_get());
    super_type::operator()(e);
  }

} // namespace bind
