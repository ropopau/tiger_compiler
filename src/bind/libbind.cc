/**
 ** \file bind/libbind.cc
 ** \brief Define exported bind functions.
 */

// FIXME: Some code was deleted here.

#include <bind/binder.hh>
#include <bind/libbind.hh>
#include <bind/renamer.hh>

namespace bind
{
  /** Walk the tree, and set the escape flag of variables and arguments
      if they do escape. */
  void bind_compute(ast::Ast& tree)
  {
    /// boolean to check if an escapes pass was done in desugar
    bind::bind = true;
    Binder binder_compute;
    binder_compute(tree);
  }
  void rename_compute(ast::Ast& tree)
  {
    Renamer rename_compute;
    rename_compute(tree);
  }

  bool bind = false;
} // namespace bind
