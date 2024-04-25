/**
 ** \file ast/type-constructor.cc
 ** \brief Implementation of ast::TypeConstructor.
 */

#include <ast/type-constructor.hh>
#include <ast/visitor.hh>

namespace ast
{
    // FIXED: Some code was deleted here.
    TypeConstructor::TypeConstructor()
        : type_c_(nullptr)
    {}
    TypeConstructor::TypeConstructor(const type::Type* t)
        : type_c_(t)
    {}

} // namespace ast
