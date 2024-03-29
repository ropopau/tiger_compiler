/**
 ** \file bind/tasks.hh
 ** \brief Bind module related tasks.
 */

// FIXME: Some code was deleted here.

#pragma once

#include <task/libtask.hh>

namespace bind::tasks
{
    TASK_GROUP("4. Bind");

    TASK_DECLARE("b|bindings-compute",
               "Bind the name uses to their definitions (objects forbidden).",
               bind_compute,
               "parse");
    TASK_DECLARE("B|bindings-display",
               "Enable the bindings display in the next --ast-display invocation." 
               "This option does not imply --bindings-compute.",
               bind_display,
               "parse");
     TASK_DECLARE("bound",
               "Make sure bindings (regular or taking overloading or objects constructs into account) are computed.",
               bind_bound,
               "parse");

}