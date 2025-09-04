/**
 ** \file type/builtin-types.hh
 ** \brief The classes Int, String, Void.
 */
#pragma once

#include <misc/singleton.hh>
#include <type/fwd.hh>
#include <type/type.hh>

namespace type
{
  // FIXME: Some code was deleted here (Other types : Int, String, Void).
    class Int : public Type
    {
    public:
        ~Int() = default;
        
        void accept(ConstVisitor& v) const;
        void accept(Visitor& v);
        
    
    };

    class String : public Type
    {
    public:
        ~String() = default;
        
        void accept(ConstVisitor& v) const;
        void accept(Visitor& v);
        
    
    };

    class Void : public Type
    {
    public:
        ~Void() = default;
        
        void accept(ConstVisitor& v) const;
        void accept(Visitor& v);
        
    
    };

} // namespace type
