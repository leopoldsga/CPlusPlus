/*
**Register two callback functions who call the other circularly.
*/
#include<stdio.h>

int counter = 0;
void A(void (*ptr)());
void B(void (*ptr)());
void (*thisA) = &A;
void (*thisB) = &B;

void A(void (*ptr)()){
  if (++counter == 25)
    return;
  printf("A: %u\n", counter);
  ptr(thisA);
}

void B(void (*ptr)()){
  if (++counter == 25)
    return;
  printf("B: %u\n", counter);
  ptr(thisB);
}

int main(){
  void (*pointer)() = &A;
  B(pointer);
  return 0;
}
