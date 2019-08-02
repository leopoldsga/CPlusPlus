# 1 Compiling source code to be executable
`g++ -std=c++14 <*.cpp> -lpthread -o <nameit>`

# 2 Linking pthread library
Because the <pthread.h> is not one of the Linux default library, we should link the static library of pthread.h when compiling.
