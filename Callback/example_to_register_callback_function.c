#include <stdio.h>

/*
**Implement the act-as-argument callback function which is same as normal function.
*/

void called_func(){
  printf("Based on the code, I act as the called function.\n");
}

/*
**Implement a normal function of which the argument list contains a function pointer.
*/
void calling_func(void (*pointer)()){
  printf("Here I am going to receive a callback function argument.\n");
  pointer();
}

int main(){

  /*
  **Registerring one function pointer with the callback function.
  */
  void (*ptr)() = &called_func;
  calling_func(ptr);
  return 0;
}
