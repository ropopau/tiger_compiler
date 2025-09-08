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
    class Int : public misc::Singleton<Int>, public Type
    {
    public:

        // Delete implicite methods (Copy, Move, move assign, copy assign)
        Int(const Int&) = delete;
        Int(Int&&) = delete;
        Int& operator=(const Int&) = delete;
        Int& operator=(Int&) = delete;
        
        // Method from Type. for ast visitor
        void accept(ConstVisitor& v) const;
        void accept(Visitor& v);
    
        friend class misc::Singleton<Int>;     
    private:
        Int() = default;
        ~Int() = default;
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
