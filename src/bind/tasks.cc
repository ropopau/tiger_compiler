/**
 ** \file bind/tasks.cc
 ** \brief Bind module tasks implementation.
 */

// FIXME: Some code was deleted here.


#include <ostream>

#include <ast/libast.hh>
#include <ast/tasks.hh>
#include <bind/libbind.hh>
#define DEFINE_TASKS 1
#include <bind/tasks.hh>
#undef DEFINE_TASKS
#include <misc/xalloc.hh>

namespace bind::tasks
{
    void bind_compute()
    {
        bind::bind_compute(*ast::tasks::the_program);
    }

    void bind_display(){ast::bindings_display(std::cout) = true;}

    void rename_compute()
    {
        bind::bind_compute(*ast::tasks::the_program);
        bind::rename_compute(*ast::tasks::the_program);
    }

    void bind_bound(){}

}