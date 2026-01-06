#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
  char *name;
};

void changeName(struct User *u, char *newName) { strcpy(u->name, newName); }

int main(void) {
  struct User *myUser = malloc(sizeof(struct User));
  myUser->name = malloc(7); // to store my name;
  strcpy(myUser->name, "Nitesh");
  printf("My name is: %s\n", myUser->name);
  changeName(myUser, "NiteshRaya");
  printf("My name after the update is: %s\n", myUser->name);
  free(myUser->name); // first free the paper
  free(myUser);       // then free the book
  return 0;
}
