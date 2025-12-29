#include <stdio.h>
#include <stdlib.h>

struct Todo {
  int id;
  char *title; // stores the address of the first character of a string
  int isCompleted;
};

struct todoList {
  struct Todo *items;
  int capacity;
  int size;
};

void initializeTodo(void) {
  struct todoList *todos = malloc(todos->capacity * sizeof(struct todoList));
  todos->capacity = 2;
  todos->size = 0;
  todos->items = malloc(todos->capacity * sizeof(struct Todo));
  if (todos->items == NULL) {
    printf("Memory allocation failed \n");
    return;
  }

  todos->items[0].id = 1;
  todos->items[0].title = malloc(6);
  todos->items[0].isCompleted = 0;
  todos->items[0].title[0] = 'n';
  todos->items[0].title[1] = 'i';
  todos->items[0].title[2] = 't';

  for (int i = 0; i < 1; i++) {
    printf("The first ID: %d\n", todos->items[0].id);
    printf("The first isCompleted: %d\n", todos->items[0].isCompleted);
    printf("The first title: %s\n", todos->items[0].title);
  }
}

int main(void) {
  initializeTodo();
  return 0;
}
