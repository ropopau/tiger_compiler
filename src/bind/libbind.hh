/**
 ** \file bind/libbind.hh
 ** \brief Interface of the bind module.
 */

// FIXME: Some code was deleted here.
#pragma once

#include <ast/fwd.hh>
#include <misc/error.hh>

/// Computing escape and static link related information.
namespace bind
{
  /// Compute the escaping variables.
  void bind_compute(ast::Ast& tree);
  void rename_compute(ast::Ast& tree);

  extern bool bind;

} // namespace bind
