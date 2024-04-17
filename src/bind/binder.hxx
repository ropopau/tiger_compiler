/**
 ** \file bind/binder.hxx
 ** \brief Inline methods of bind::Binder.
 **/

// FIXME: Some code was deleted here.

#pragma once

#include <bind/binder.hh>


namespace bind
{
/// Check a set of definitions: unique names, browse headers, then bodies.
    template <class D> void Binder::chunk_visit(ast::Chunk<D>& e)
    {
        // Shorthand.
        using chunk_type = ast::Chunk<D>;
        // FIXME: Some code was deleted here (Two passes: once on headers, then on bodies).
        auto& dec = e.decs_get();

        for (auto i = dec.begin(); i != dec.end(); ++i)
        {
            visit_dec_header<D>(**i);
        }

        for (size_t i = 0; i != dec.size(); ++i)
        {
            visit_dec_body(*e.decs_get()[i]);
        }
    }

    /// Check a Function declaration header.
    template <>
    inline void Binder::visit_dec_header<ast::FunctionDec>(ast::FunctionDec& e)
    {
        scoped_func_.put(e.name_get(), &e);
    }

    template <>
    inline void Binder::visit_dec_header<ast::VarDec>(ast::VarDec& e)
    {
        scoped_var_.put(e.name_get(), &e);
    }

    /// Check a Function declaration body.
    template <>
    inline void Binder::visit_dec_body<ast::FunctionDec>(ast::FunctionDec& e)
    {
        begin();
        chunk_visit<ast::VarDec>(e.formals_get());
        auto result = e.result_get();
        if (result)
            result->accept(*this);
        auto body = e.body_get();
        if (body)
            body->accept(*this);
        end();
    }

    template <>
    inline void Binder::visit_dec_body<ast::VarDec>(ast::VarDec& e)
    {
        begin();
        auto result = e.type_name_get();
        auto init = e.init_get();
        if (result)
            result->accept(*this);
        if (init)
            init->accept(*this);
        end();
    }


}