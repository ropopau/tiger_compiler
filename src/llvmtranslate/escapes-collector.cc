#include <ast/all.hh>
#include <ast/default-visitor.hh>
#include <ast/non-object-visitor.hh>
#include <llvmtranslate/escapes-collector.hh>

namespace llvmtranslate
{
  /// LLVM IR doesn't support static link and nested functions.
  /// In order to translate those functions to LLVM IR, we use a technique
  /// called Lambda Lifting, which consists in passing a pointer to
  /// the escaped variables to the nested function using that variable.
  ///
  /// In order to do that, we need a visitor to collect these kind of
  /// variables and associate them to each function.

  class EscapesCollector
    : public ast::DefaultConstVisitor
    , public ast::NonObjectConstVisitor
  {
  public:
    /// Super class.
    using super_type = ast::DefaultConstVisitor;
    /// Import overloaded operator() methods.
    using super_type::operator();

    EscapesCollector()
      : did_modify_{false}
      , escaped_{}
    {}

    escaped_map_type& escaped_get() { return escaped_; }

    void operator()(const ast::FunctionChunk& e) override
    {
      bool saved_did_modify = did_modify_;

      // Iterate on the chunk in order to iteratively collect all the callee
      // functions' escaped variables.
      did_modify_ = !e.empty();
      while (did_modify_)
        {
          did_modify_ = false;
          super_type::operator()(e);
        }

      did_modify_ = saved_did_modify;
    }

    void operator()(const ast::FunctionDec& e) override
    {
      // Keep track of the current function
      // FIXME: Some code was deleted here.
    }

    void operator()(const ast::CallExp& e) override
    {
      super_type::operator()(e);

      // FIXME: Some code was deleted here.

      // Check whether there are any newly collected escaped variables.
      // If there are, mark the iteration as modified.
      // FIXME: Some code was deleted here.
    }

    void operator()(const ast::SimpleVar& e) override
    {
      // Associate escaped variables declared in parent frames with their
      // functions
      // FIXME: Some code was deleted here.
    }

  private:
    /// Whether any modification was done during the iteration.
    bool did_modify_ = false;

    /// Associate a set of variables with their function.
    escaped_map_type escaped_;

    /// Current visiting function.
    // FIXME: Some code was deleted here.
  };

  escaped_map_type collect_escapes(const ast::Ast& ast)
  {
    EscapesCollector collect;
    collect(ast);

    return std::move(collect.escaped_get());
  }

} // namespace llvmtranslate
