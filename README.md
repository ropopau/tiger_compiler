# tiger-compiler

Simple compiler frontend for the toy language Tiger.
This project was made in a group project at EPITA engineering school.

## Getting started

### Dependencies

boost, llvm, RE-flex (not reflex), lex, bison

### Quick start

To compile :
```bash
./bootstrap
./configure
make -j
```

To test, you can execute the tc binary and give it any file from the tests directory as argument.

Example:

```bash
./src/tc ./tests/good/test27.tig

```

To clean:

```bash
make clean
make distclean
```




