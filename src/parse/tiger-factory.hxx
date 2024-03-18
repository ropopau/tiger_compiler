#pragma once
#include <parse/tiger-factory.hh>

namespace parse
{
  inline ast::IntExp* make_IntExp(const location& location, int num)
  {
    return new ast::IntExp(location, num);
  }

  inline ast::StringExp* make_StringExp(const location& location,
                                        std::string string)
  {
    // FIXME: Some code was deleted here (Constructor of StringExp).
  }

  inline ast::ObjectExp* make_ObjectExp(const location& location,
                                        ast::NameTy* type_name)
  {
    // FIXME: Some code was deleted here (Constructor of Object).
  }

  inline ast::CallExp* make_CallExp(const location& location,
                                    misc::symbol name,
                                    ast::exps_type* args)
  {
    // FIXME: Some code was deleted here (Constructor of CallExp).
  }

  inline ast::MethodCallExp* make_MethodCallExp(const location& location,
                                                misc::symbol name,
                                                ast::exps_type* args,
                                                ast::Var* object)
  {
    // FIXME: Some code was deleted here (Constructor of MethodCallExp).
  }

  inline ast::RecordExp* make_RecordExp(const location& location,
                                        ast::NameTy* type_name,
                                        ast::fieldinits_type* fields)
  {
    // FIXME: Some code was deleted here (Constructor of RecordExp).
  }

  inline ast::ArrayExp* make_ArrayExp(const location& location,
                                      ast::NameTy* type_name,
                                      ast::Exp* size,
                                      ast::Exp* init)
  {
    // FIXME: Some code was deleted here (Constructor of ArrayExp).
  }

  inline ast::NilExp* make_NilExp(const location& location)
  {
    return new ast::NilExp(location);
  }

  inline ast::SeqExp* make_SeqExp(const location& location,
                                  ast::exps_type* exps)
  {
    // FIXME: Some code was deleted here (Constructor of SeqExp).
  }

  inline ast::AssignExp*
  make_AssignExp(const location& location, ast::Var* var, ast::Exp* exp)
  {
    // FIXME: Some code was deleted here (Constructor of AssignExp).
  }

  inline ast::IfExp* make_IfExp(const location& location,
                                ast::Exp* test,
                                ast::Exp* thenclause,
                                ast::Exp* elseclause)
  {
    // FIXME: Some code was deleted here (Constructor of IfExp).
  }

  inline ast::IfExp*
  make_IfExp(const location& location, ast::Exp* test, ast::Exp* thenclause)
  {
    // FIXME: Some code was deleted here (Constructor of IfExp).
  }

  inline ast::WhileExp*
  make_WhileExp(const location& location, ast::Exp* test, ast::Exp* body)
  {
    return new ast::WhileExp(location, test, body);
  }

  inline ast::ForExp* make_ForExp(const location& location,
                                  ast::VarDec* vardec,
                                  ast::Exp* hi,
                                  ast::Exp* body)
  {
    return new ast::ForExp(location, vardec, hi, body);
  }

  inline ast::BreakExp* make_BreakExp(const location& location)
  {
    // FIXME: Some code was deleted here (Constructor of BreakExp).
  }

  inline ast::LetExp*
  make_LetExp(const location& location, ast::ChunkList* decs, ast::Exp* body)
  {
    // FIXME: Some code was deleted here (Constructor of LetExp).
  }

  inline ast::OpExp* make_OpExp(const location& location,
                                ast::Exp* left,
                                ast::OpExp::Oper oper,
                                ast::Exp* right)
  {
    return new ast::OpExp(location, left, oper, right);
  }

  inline ast::CastExp*
  make_CastExp(const location& location, ast::Exp* exp, ast::Ty* ty)
  {
    return new ast::CastExp(location, exp, ty);
  }

  inline ast::SimpleVar* make_SimpleVar(const location& location,
                                        misc::symbol name)
  {
    return new ast::SimpleVar(location, name);
  }

  inline ast::FieldVar*
  make_FieldVar(const location& location, ast::Var* var, misc::symbol name)
  {
    // FIXME: Some code was deleted here (Constructor of FieldVar).
  }

  inline ast::SubscriptVar*
  make_SubscriptVar(const location& location, ast::Var* var, ast::Exp* index)
  {
    return new ast::SubscriptVar(location, var, index);
  }

  /* Use expansion parameter pack to handle one or empty arguments */
  template <class... T> inline ast::exps_type* make_exps_type(T... exps)
  {
    return new ast::exps_type{exps...};
  }

  inline ast::ChunkList* make_ChunkList(const location& location)
  {
    return new ast::ChunkList(location);
  }

  inline ast::TypeChunk* make_TypeChunk(const location& location)
  {
    return new ast::TypeChunk(location);
  }

  inline ast::TypeDec*
  make_TypeDec(const location& location, misc::symbol name, ast::Ty* ty)
  {
    return new ast::TypeDec(location, name, ty);
  }

  inline ast::RecordTy* make_RecordTy(const location& location,
                                      ast::fields_type* fields)
  {
    // FIXME: Some code was deleted here (Constructor of RecordTy).
  }

  inline ast::ArrayTy* make_ArrayTy(const location& location,
                                    ast::NameTy* base_type)
  {
    return new ast::ArrayTy(location, base_type);
  }

  template <class... T> inline ast::fields_type* make_fields_type(T... types)
  {
    return new ast::fields_type{types...};
  }

  inline ast::Field* make_Field(const location& location,
                                misc::symbol name,
                                ast::NameTy* type_name)
  {
    return new ast::Field(location, name, type_name);
  }

  inline ast::NameTy* make_NameTy(const location& location, misc::symbol name)
  {
    return new ast::NameTy(location, name);
  }

  template <class... T>
  inline ast::fieldinits_type* make_fieldinits_type(T... inits_types)
  {
    return new ast::fieldinits_type{inits_types...};
  }

  inline ast::FieldInit*
  make_FieldInit(const location& location, misc::symbol name, ast::Exp* init)
  {
    return new ast::FieldInit(location, name, init);
  }

  inline ast::ClassTy* make_ClassTy(const location& location,
                                    ast::NameTy* super,
                                    ast::ChunkList* decs)
  {
    return new ast::ClassTy(location, super, decs);
  }

  inline ast::VarChunk* make_VarChunk(const location& location)
  {
    return new ast::VarChunk(location);
  }

  inline ast::VarDec* make_VarDec(const location& location,
                                  misc::symbol name,
                                  ast::NameTy* type_name,
                                  ast::Exp* init)
  {
    return new ast::VarDec(location, name, type_name, init);
  }

  inline ast::MethodChunk* make_MethodChunk(const location& location)
  {
    return new ast::MethodChunk(location);
  }

  inline ast::MethodDec* make_MethodDec(const location& location,
                                        misc::symbol name,
                                        ast::VarChunk* formals,
                                        ast::NameTy* result,
                                        ast::Exp* body)
  {
    return new ast::MethodDec(location, name, formals, result, body);
  }

  inline ast::FunctionDec* make_FunctionDec(const location& location,
                                            misc::symbol name,
                                            ast::VarChunk* formals,
                                            ast::NameTy* result,
                                            ast::Exp* body)
  {
    return new ast::FunctionDec(location, name, formals, result, body);
  }

  template <class... T> inline ast::FunctionChunk* make_FunctionChunk(T... args)
  {
    return new ast::FunctionChunk(args...);
  }
} // namespace parse
