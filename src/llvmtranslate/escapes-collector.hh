#pragma once

#include <ast/fwd.hh>
#include <llvmtranslate/fwd.hh>

namespace llvmtranslate
{

  /// Collect all escapes for every function in the ast, and store it in a map.
  /// This is used for Lambda Lifting.
  escaped_map_type collect_escapes(const ast::Ast& ast);

} // namespace llvmtranslate
