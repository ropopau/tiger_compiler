/**
 ** \file bind/binder.cc
 ** \brief Implementation for bind/binder.hh.
 */

#include <ast/all.hh>
#include <bind/binder.hh>

#include <misc/contract.hh>

namespace bind
{
  /*-----------------.
  | Error handling.  |
  `-----------------*/

  /// The error handler.
  const misc::error& Binder::error_get() const { return error_; }

  // FIXME: Some code was deleted here.

  void Binder::begin()
  {
    this->scoped_var_.scope_begin();
    this->scoped_func_.scope_begin();
    this->scoped_type_.scope_begin();
  }

  void Binder::end()
  {
    this->scoped_var_.scope_end();
    this->scoped_func_.scope_end();
    this->scoped_type_.scope_end();
  }

  void Binder::operator()(ast::Ast& e)
  {
    begin();
    e.accept(*this);
    end();
  }

  void Binder::operator()(ast::VarDec& e)
  {
    this->scoped_var_.put(e.name_get(), &e);
    super_type::operator()(e);
  }

  void Binder::operator()(ast::SimpleVar& e)
  {
    // Error ??
    auto g = this->scoped_var_.get(e.name_get());
    if (g == nullptr)
      {
        this->error_ << misc::error::error_type::bind;
        std::cerr << "Error at " << e.location_get()
                  << ": Undeclared variable.\n";
        this->error_.exit();
      }
    e.def_set(g);
  }

  void Binder::operator()(ast::FunctionDec& e)
  {
    this->scoped_func_.put(e.name_get(), &e);
    this->begin();
    e.formals_get().accept(*this);
    if (e.result_get() != nullptr)
      e.result_get()->accept(*this);
    if (e.body_get() != nullptr)
      e.body_get()->accept(*this);
    this->end();
  }

  void Binder::operator()(ast::CallExp& e)
  {
    // Error ??

    auto g = this->scoped_func_.get(e.name_get());
    if (g == nullptr)
      {
        this->error_ << misc::error::error_type::bind;
        std::cerr << "Error at " << e.location_get()
                  << ": Undeclared function.\n";
        this->error_.exit();
      }

    e.def_set(g);
    auto rgs = e.args_get();
    for (size_t i = 0; i < rgs.size(); i++)
      {
        rgs[i]->accept(*this);
      }
  }

  void Binder::operator()(ast::TypeDec& e)
  {
    this->scoped_type_.put(e.name_get(), &e);
    super_type::operator()(e);
  }

  void Binder::operator()(ast::NameTy& e)
  {
    // Error ??
    if (e.name_get().get().compare("string") == 0
        || e.name_get().get().compare("int") == 0
        || e.name_get().get().compare("float") == 0
        || e.name_get().get().compare("double") == 0)
      return;

    auto g = this->scoped_type_.get(e.name_get());
    if (g == nullptr)
      {
        this->error_ << misc::error::error_type::bind;
        std::cerr << "Error at " << e.location_get() << ": Undeclared type.\n";
        this->error_.exit();
      }

    e.def_set(this->scoped_type_.get(e.name_get()));
  }

  void Binder::operator()(ast::LetExp& e)
  {
    this->begin(); // OPEN ALL 3 SCOPES
    e.chunks_get().accept(*this);
    e.body_get().accept(*this);
    this->end(); // END ALL 3 SCOPES
  }

  void Binder::operator()(ast::ForExp& e)
  {
    this->array_loops_.push_back(&e);
    super_type::operator()(e);
  }

  void Binder::operator()(ast::BreakExp& e)
  {
    if (this->array_loops_.size() <= 0)
      {
        // Error
        return;
      }
    this->array_loops_.pop_back();
  }

  void Binder::operator()(ast::WhileExp& e)
  {
    this->array_loops_.push_back(&e);
    super_type::operator()(e);
  }

} // namespace bind
