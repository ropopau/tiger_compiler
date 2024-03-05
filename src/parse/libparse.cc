/**
 ** \file parse/libparse.cc
 ** \brief Functions and variables exported by the parse module.
 */

#include <misc/file-library.hh>
#include <misc/indent.hh>
#include <misc/symbol.hh>
#include <parse/libparse.hh>
#include <parse/location.hh>
#include <parse/tasks.hh>
#include <parse/tiger-driver.hh>
#include <parse/tweast.hh>

// Define exported parse functions.
namespace parse
{
  // Parse a Tiger file, return the corresponding abstract syntax.
  std::pair<ast::ChunkList*, misc::error> parse(const std::string& prelude,
                                                const std::string& fname,
                                                misc::file_library& library,
                                                bool scan_trace_p,
                                                bool parse_trace_p,
                                                bool enable_object_extensions_p)
  {
    // Current directory must be that of the file currently processed.
    library.push_current_directory(misc::path(fname).parent_path());

    TigerDriver td(library);
    td.scan_trace(scan_trace_p).parse_trace(parse_trace_p);
    td.enable_object_extensions(enable_object_extensions_p);

    ast::ChunkList* res = nullptr;

    ast_type tree = td.parse_file(fname);

    return std::pair(res, td.error_get());
  }

  ast_type parse(Tweast& input)
  {
    TigerDriver td;
    td.enable_extensions();
    td.enable_object_extensions();
    ast_type res = td.parse(input);
    if (td.error_get())
      {
        misc::error e;
        e << "Failed to resolve Tweast:" << misc::incendl << input;
        e << "Got: " << td.error_get();
        e.ice_here();
      }
    return res;
  }

  ast::Exp* parse(const std::string& str, bool enable_object_extensions_p)
  {
    TigerDriver td;
    td.enable_object_extensions(enable_object_extensions_p);
    ast::Exp* res = td.parse(str);
    td.error_get().ice_on_error_here();
    return res;
  }

  ast::ChunkList* parse_unit(const std::string& str,
                             bool enable_object_extensions_p)
  {
    TigerDriver td;
    td.enable_object_extensions(enable_object_extensions_p);
    std::string rewrite = "function _main() = (" + str + "; ())";
    ast::ChunkList* res = td.parse(rewrite);
    td.error_get().ice_on_error_here();
    return res;
  }

} // namespace parse
