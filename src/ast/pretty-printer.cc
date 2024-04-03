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
    /// Output \a e on \a ostr.
    inline std::ostream& operator<<(std::ostream& ostr, const Escapable& e)
    {
      if (escapes_display(ostr)
          // FIXME: Some code was deleted here.
      )
        ostr << "/* escaping */ ";

      return ostr;
    }

    /// \brief Output \a e on \a ostr.
    ///
    /// Used to factor the output of the name declared,
    /// and its possible additional attributes.
    inline std::ostream& operator<<(std::ostream& ostr, const Dec& e)
    {
      ostr << e.name_get();
      if (bindings_display(ostr))
        ostr << " /* " << &e << " */";
      return ostr;
    }

  } // namespace

  PrettyPrinter::PrettyPrinter(std::ostream& ostr)
    : ostr_(ostr)
  {}

  void PrettyPrinter::operator()(const SimpleVar& e)
  {
    ostr_ << e.name_get();
    if (bindings_display(ostr_))

      ostr_ << " /* " << e.def_get() << " */";
  }

  void PrettyPrinter::operator()(const FieldVar& e)
  {
    // FIXED: Some code was deleted here.
    this->ostr_ << e.var_get() << "." << e.name_get();
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
    if (e.args_get().size() != 0)
      {
        ostr_ << e.name_get();
        if (bindings_display(ostr_))
          ostr_ << " /* " << e.def_get() << " */";
        ostr_ << "(" << misc::separate(e.args_get(), ", ") << ")";
      }
  }

  void PrettyPrinter::operator()(const IntExp& e) { ostr_ << e.value_get(); }

  void PrettyPrinter::operator()(const OpExp& e)
  {
    e.left_get().accept(*this);
    ostr_ << " " << str(e.oper_get()) << " ";
    e.right_get().accept(*this);
  }

  void PrettyPrinter::operator()(const RecordExp& e)
  {
    ostr_ << e.type_name_get() << " {" << misc::separate(e.fields_get(), ", ")
          << "}";
  }

  void PrettyPrinter::operator()(const SeqExp& e)
  {
    // FIXED: Some code was deleted here.

    auto exps = e.exps_get();
    auto size = exps.size();

    if (size == 0)
      {
        ostr_ << "()";
        return;
      }
    if (size == 1)
      {
        ostr_ << *e.exps_get()[0];
        return;
      }
    ostr_ << "(";
    // seq1;seq2;seq3 ...
    for (size_t i = 0; i < size; i++)
      {
        // Dernier element sans le pv
        if (i == size - 1)
          {
            ostr_ << *e.exps_get()[i];
          }

        else
          {
            ostr_ << *e.exps_get()[i] << ";" << misc::iendl;
          }
      }
    ostr_ << ")";
  }

  void PrettyPrinter::operator()(const BreakExp& e)
  {
    ostr_ << "break";
    if (bindings_display(ostr_))
      ostr_ << " /* " << e.def_get() << " */";
  }

  void PrettyPrinter::operator()(const StringExp& e)
  {
    ostr_ << "\"" << e.value_get() << "\"";
  }

  void PrettyPrinter::operator()(const NameTy& e)
  {
    // FIXED: Some code was deleted here.
    ostr_ << e.name_get();
    if (bindings_display(ostr_))
      ostr_ << " /* " << e.def_get() << " */";
  }

  void PrettyPrinter::operator()(const AssignExp& e)
  {
    // FIXED: Some code was deleted here.
    ostr_ << e.var_get() << " := " << e.exp_get() << misc::iendl;
  }

  void PrettyPrinter::operator()(const IfExp& e)
  {
    // FIXED: Some code was deleted here.
    ostr_ << "if " << e.test_get() << misc::iendl << "then " << misc::incendl
          << e.thenclause_get() << misc::decendl;

    auto a = &e.elseclause_get();

    auto c = const_cast<ast::Exp*>(a);

    auto ok = dynamic_cast<ast::SeqExp*>(c);

    if (ok == nullptr)
      ostr_ << misc::iendl << "else " << e.elseclause_get();
  }

  void PrettyPrinter::operator()(const WhileExp& e)
  {
    ostr_ << "while ";
    if (bindings_display(ostr_))
      ostr_ << " /* " << &e << " */";

    ostr_ << e.test_get() << " do " << misc::iendl << e.body_get();
  }

  void PrettyPrinter::operator()(const ForExp& e)
  {
    ostr_ << "for ";
    if (bindings_display(ostr_))
      ostr_ << " /* " << &e << " */";
    ostr_ << e.vardec_get().name_get();
    if (bindings_display(ostr_))
      ostr_ << " /* " << &e.vardec_get() << " */";
    ostr_ << " := " << *e.vardec_get().init_get() << " to " << e.hi_get()
          << " do " << misc::incendl << e.body_get();
  }
  void PrettyPrinter::operator()(const LetExp& e)
  {
    ostr_ << "let" << misc::incendl;
    ostr_ << e.chunks_get();
    ostr_ << misc::decendl << "in" << misc::incendl;

    auto a = &e.body_get();
    auto c = const_cast<ast::Exp*>(a);
    auto ok = dynamic_cast<ast::SeqExp*>(c);
    if (ok->exps_get().size() > 0)
      ostr_ << e.body_get();

    //ostr_ << e.body_get();
    ostr_ << misc::decendl << "end";
  }

  void PrettyPrinter::operator()(const ArrayExp& e)
  {
    //ostr_ << e.type_name_get() << "[" << e.size_get() << "] of "
    //      << e.init_get();
  }

  void PrettyPrinter::operator()(const FieldInit& e)
  {
    ostr_ << e.name_get() << " = " << e.init_get();
  }

  void PrettyPrinter::operator()(const ChunkList& e)
  {
    // FIXED: Some code was deleted here.
    for (auto& chunks : e.chunks_get())
      chunks->accept(*this);
  }

  void PrettyPrinter::operator()(const ChunkInterface& e) { e.accept(*this); }

  void PrettyPrinter::operator()(const VarChunk& e)
  {
    ostr_ << misc::separate(e);
    ostr_ << misc::iendl;
  }

  void PrettyPrinter::operator()(const NilExp& e) { ostr_ << "nil"; }

  void PrettyPrinter::operator()(const VarDec& e)
  {
    // `type_name' might be omitted.
    if (e.init_get() == nullptr)
      {
        ostr_ << e.name_get();
        if (bindings_display(ostr_))
          ostr_ << " /* " << &e << " */";
        ostr_ << ": ";
        ostr_ << *e.type_name_get();
        return;
      }
    ostr_ << "var ";
    ostr_ << e.name_get();
    if (bindings_display(ostr_))
      ostr_ << " /* " << &e << " */";

    // `init' can be null in case of formal parameter.
    if (e.type_name_get() != nullptr)
      {
        ostr_ << " : ";
        ostr_ << *e.type_name_get();
      }
    ostr_ << " := ";
    if (e.init_get() != nullptr)
      ostr_ << *e.init_get();
  }

  void PrettyPrinter::operator()(const FunctionChunk& e)
  {
    chunk_visit<FunctionChunk>(e);
  }

  void PrettyPrinter::operator()(const FunctionDec& e)
  {
    // FIXED: Some code was deleted here.
    if (e.body_get())
      {
        if (bindings_display(ostr_))
          ostr_ << "function " << e << "(";
        else
          ostr_ << "function " << e.name_get() << "(";
        ostr_ << misc::separate(e.formals_get().decs_get(), ", ");
        ostr_ << ")";
        if (e.result_get() != nullptr)
          {
            ostr_ << " : ";
            ostr_ << *e.result_get();
          }
        ostr_ << " = ";
        ostr_ << misc::incendl; //<< "(" << misc::incendl;
        ostr_ << *e.body_get();
        ostr_ << misc::decendl; //<< ")";
      }
    else
      {
        if (bindings_display(ostr_))
          ostr_ << "primitive " << e << "(";
        else
          ostr_ << "primitive " << e.name_get() << "(";
        ostr_ << misc::separate(e.formals_get().decs_get(), ", ");
        ostr_ << ")";
        if (e.result_get() != nullptr)
          {
            ostr_ << " : ";
            ostr_ << *e.result_get();
          }
        ostr_ << misc::iendl;
      }
  }

  void PrettyPrinter::operator()(const TypeChunk& e)
  {
    chunk_visit<TypeChunk>(e);
  }

  void PrettyPrinter::operator()(const TypeDec& e)
  {
    ostr_ << "type " << e.name_get();
    if (bindings_display(ostr_))
      ostr_ << " /* " << &e << " */";
    auto a = &e.ty_get();
    auto c = const_cast<ast::Ty*>(a);
    auto ok = dynamic_cast<ast::ClassTy*>(c);
    if (ok == nullptr)
      ostr_ << " = {" << e.ty_get() << "}" << misc::iendl;
    else
      ostr_ << " = " << e.ty_get() << misc::iendl;
  }

  // OBJECTS ------------------------------------------------------------------------------------

  void PrettyPrinter::operator()(const ObjectExp& e)
  {
    ostr_ << "new " << e.type_name_get();
  }

  void PrettyPrinter::operator()(const MethodChunk& e)
  {
    ostr_ << misc::separate(e, ", ");
  }

  void PrettyPrinter::operator()(const MethodCallExp& e)
  {
    ostr_ << e.object_get() << "." << e.name_get();
    if (ast::bindings_display(ostr_))
      ostr_ << " /* " << e.def_get() << " */";
    if (e.args_get().size() > 0)
      ostr_ << "(" << misc::separate(e.args_get(), ", ") << ")";
    else
      ostr_ << "()";
  }

  void PrettyPrinter::operator()(const MethodDec& e)
  {
    ostr_ << "method ";
    if (e.formals_get().decs_get().size() > 0) // CHANGE
      ostr_ << e.name_get() << '(' << e.formals_get() << ')';
    else
      ostr_ << e.name_get() << "()";
    if (e.result_get() != nullptr)
      ostr_ << " : " << *e.result_get();
    ostr_ << " =" << misc::incendl << *e.body_get() << misc::decindent;
  }

  void PrettyPrinter::operator()(const ClassTy& e)
  {
    ostr_ << "class extends " << e.super_get();
    if (e.chunks_get().chunks_get().size() > 0)
      {
        ostr_ << misc::iendl << "{" << misc::incendl;
        for (auto& chunks : e.chunks_get())
          ostr_ << *chunks;
        ostr_ << misc::decendl << "}" << misc::iendl;
      }
    else
      ostr_ << misc::iendl << "{}";
  }

  void PrettyPrinter::operator()(const RecordTy& e)
  {
    ostr_ << misc::separate(e.fields_get(), ", ");
    // FIXED: Some code was deleted here.
    //for (auto& exp : e.fields_get())
    //  exp->accept(*this);
  }

  void PrettyPrinter::operator()(const ArrayTy& e)
  {
    ostr_ << "OK??2";
    //e.base_type_get().accept(*this);
  }

  void PrettyPrinter::operator()(const Field& e)
  {
    ostr_ << e.name_get() << " : " << e.type_name_get();
  }

  // FIXME: Some code was deleted here.
} // namespace ast