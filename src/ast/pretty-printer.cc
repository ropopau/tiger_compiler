/**
 ** \file ast/pretty-printer.cc
 ** \brief Implementation of ast::PrettyPrinter.
 */

#include <ast/all.hh>
#include <ast/libast.hh>
#include <ast/pretty-printer.hh>
#include <misc/escape.hh>
#include <misc/indent.hh>
#include <misc/separator.hh>

namespace ast
{
  // Anonymous namespace: these functions are private to this file.
  namespace
  {

    /// \brief Output \a e on \a ostr.
    ///
    /// Used to factor the output of the name declared,
    /// and its possible additional attributes.
    inline std::ostream& operator<<(std::ostream& ostr, const Dec& e)
    {
      ostr << e.name_get();
      return ostr;
    }
  } // namespace

  PrettyPrinter::PrettyPrinter(std::ostream& ostr)
    : ostr_(ostr)
  {}

  void PrettyPrinter::operator()(const SimpleVar& e) { ostr_ << e.name_get(); }

  void PrettyPrinter::operator()(const FieldVar& e)
  {
    // FIXED: Some code was deleted here.
    this->ostr_ << e.var_get();
  }

  /* Foo[10]. */
  void PrettyPrinter::operator()(const SubscriptVar& e)
  {
    ostr_ << e.var_get() << '[' << misc::incindent << e.index_get()
          << misc::decindent << ']';
  }

  void PrettyPrinter::operator()(const CastExp& e)
  {
    ostr_ << "_cast(" << e.exp_get() << ", " << e.ty_get() << ')';
  }

  void PrettyPrinter::operator()(const CallExp& e)
  {
    ostr_ << e.name_get() << "(" << misc::separate(e.args_get(), ", ") << ")";
  }

  void PrettyPrinter::operator()(const OpExp& e)
  {
    ostr_ << e.left_get() << " " << str(e.oper_get()) << " " << e.right_get();
  }

  void PrettyPrinter::operator()(const RecordExp& e)
  {
    ostr_ << e.type_name_get() << "{" <<misc::separate(e.fields_get(), ", ") << "}";
  }

  void PrettyPrinter::operator()(const SeqExp& e)
  {
    // FIXED: Some code was deleted here.
    ostr_ << "(" << misc::separate(e.exps_get(), ", ") << ")";
  }

  void PrettyPrinter::operator()(const AssignExp& e)
  {
    // FIXED: Some code was deleted here.
    ostr_ << e.var_get() << " := " << e.exp_get();
  }


  void PrettyPrinter::operator()(const IfExp& e)
  {
    // FIXED: Some code was deleted here.
    ostr_ << "if " << e.test_get() << misc::incendl << "then " << e.thenclause_get();

  }

  void PrettyPrinter::operator()(const WhileExp& e)
  {
    ostr_ << "while " << e.test_get() << misc::incendl << "do " << e.body_get();
  }

  void PrettyPrinter::operator()(const ForExp& e)
  {
    ostr_ << "for " << e.vardec_get().name_get() << " := " << e.vardec_get().init_get() 
    << " to " << e.hi_get() << " do " << misc::incendl << e.body_get();
  }


  void PrettyPrinter::operator()(const LetExp& e)
  {
    ostr_ << "let" << misc::incendl << e.chunks_get() << misc::decindent << "in" << misc::decindent
    << e.body_get() << misc::decendl << "end";
  }

  void PrettyPrinter::operator()(const ArrayExp& e)
  {
  
    ostr_ << e.type_name_get() << "[" << e.size_get() << "] of " << e.init_get();
  }

  void PrettyPrinter::operator()(const FieldInit& e)
  {
    ostr_ << e.name_get() << " " << e.init_get();
  }

  void PrettyPrinter::operator()(const ChunkList& e)
  {
    // FIXED: Some code was deleted here.
    for (auto& chunks : e.chunks_get())
      chunks->accept(*this);
  }

  void PrettyPrinter::operator()(const ChunkInterface& e)
  {
    e.accept(*this);
  }

  void PrettyPrinter::operator()(const VarChunk& e)
  {
    chunk_visit<VarChunk>(e);
  }

  void PrettyPrinter::operator()(const VarDec& e)
  {
    // `type_name' might be omitted.
    this->accept(e.type_name_get());
    // `init' can be null in case of formal parameter.
    this->accept(e.init_get());
  }

  void PrettyPrinter::operator()(const FunctionChunk& e)
  {
    chunk_visit<FunctionChunk>(e);
  }

  void PrettyPrinter::operator()(const FunctionDec& e)
  {
    // FIXED: Some code was deleted here.
    e.formals_get().accept(*this);
    e.result_get()->accept(*this);
    e.body_get()->accept(*this);
  }

  void PrettyPrinter::operator()(const TypeChunk& e)
  {
    chunk_visit<TypeChunk>(e);
  }

  void PrettyPrinter::operator()(const TypeDec& e)
  {
    e.ty_get().accept(*this);
  }


  void PrettyPrinter::operator()(const RecordTy& e)
  {
    // FIXED: Some code was deleted here.
    for (auto& exp : e.fields_get())
      exp->accept(*this);
  }

  void PrettyPrinter::operator()(const ArrayTy& e)
  {
    e.base_type_get().accept(*this);
  }

  void PrettyPrinter::operator()(const Field& e)
  {
    e.type_name_get().accept(*this);
  }


  


  // FIXME: Some code was deleted here.
} // namespace ast
