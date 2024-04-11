// -*- C++ -*-

%module tiger_llvmtranslate

%include "std_string.i"

%{
  #include <llvmtranslate/libllvmtranslate.hh>
  #include <llvmtranslate/tasks.hh>
  #include <llvm/IR/IRPrintingPasses.h>
  #include <llvm/Linker/Linker.h>
  #include <llvm/IR/Module.h>
%}

%inline
{
  std::string translate(const ast::Ast& tree)
  {
    auto module = llvmtranslate::translate(tree);
    auto runtime = llvmtranslate::runtime_get(*module.first);
#if LLVM_VERSION_MAJOR == 3 && LLVM_VERSION_MINOR <= 7
    auto link = llvm::Linker::LinkModules(module.second.get(), runtime.get());
#else
    auto link = llvm::Linker::linkModules(*module.second, std::move(runtime));
#endif
    postcondition(!link); // Returns true on error

    std::string str;
    llvm::raw_string_ostream out(str);
    llvm::PrintModulePass printer{out};
#if LLVM_VERSION_MAJOR == 3 && LLVM_VERSION_MINOR <= 8
    printer.run(*module.second);
#else
    llvm::ModuleAnalysisManager dummy_mam;
    printer.run(*module.second, dummy_mam);
#endif
    return out.str();
  }
}
