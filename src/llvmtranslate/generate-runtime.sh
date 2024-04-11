#!/bin/sh

[ -z "$1" ] && echo "$0: Missing input file" && exit
[ -z "$2" ] && echo "$0: Missing output file" && exit

input=$1
output=$2

awk 'BEGIN {
      print("#include <string>");
      print("#include <llvmtranslate/libllvmtranslate.hh>");
      print("");
      print("namespace llvmtranslate");
      print("{");
      print("const char* runtime_string()");
      print("{");
      print("  return");
      printf("R\"(");
    }
    /^#(<<|>>)/ {
      next;
    }
    {
      print($0);
    }
    END {
      print(")\";");
      print("}");
      print("} // namespace llvmtranslate");
    }' "$input" > "$output".tmp

mv "$output".tmp "$output"
