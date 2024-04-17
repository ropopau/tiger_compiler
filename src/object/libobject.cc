/**
 ** \file object/libobject.cc
 ** \brief Define exported object functions.
 */

// FIXME: Some code was deleted here.
#include <object/binder.hh>
#include <object/libobject.hh>
#include <object/type-checker.hh>

namespace object
{
  /*-------.
  | Bind.  |
  `-------*/

  // FIXME: Some code was deleted here.


  void object_bind_compute(ast::Ast& tree)
  {
    object::Binder binder_compute;
    binder_compute(tree);
  }

  void object_type_compute(ast::Ast& tree);

  /*----------------.
  | Compute types.  |
  `----------------*/

  misc::error types_check(ast::Ast& tree)
  {
    TypeChecker type;
    type(tree);
    return type.error_get();
  }

} // namespace object
