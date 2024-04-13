/**
 ** \file type/array.hh
 ** \brief The class Array.
 */
#pragma once

#include <type/fwd.hh>
#include <type/type.hh>

namespace type
{
  /// Array types.
  class Array : public Type
  {
    // FIXED: Some code was deleted here.
  public:
    virtual ~Array() = default;
    Array(Type* type);

    void accept(ConstVisitor& v) const override;
    void accept(Visitor& v) override;

    const Type& type_get() const;
    Type& type_get();

  private:
    Type* type_;
  };

} // namespace type

#include <type/array.hxx>
