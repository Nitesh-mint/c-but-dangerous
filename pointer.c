#include <stdio.h>

int main() {
  // normal Variable
  int var = 10;
  // Pointer variable ptr that stores address of var
  int *ptr = &var;

  // Directly accessing ptr will give us an address
  printf("%p", ptr); // this prints the memory address.

  // how to print the actual value of the address?
  // Dereferencing ptr to access the value
  printf("%d", *ptr);
  return 0;
}

void printVariableAdress() {
  int var = 10;
  printf("%p", &var);
}
