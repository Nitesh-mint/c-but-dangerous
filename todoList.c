#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// why *title and not the title? *title holds the memory address of the actual
// title which will be in another memory which can be dynamic eg: [title =
// malloc(100)]
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

enum MenuChoices { ADD_TODO = 1, VIEW_TODOS, DELETE_TODO, EXIT_APP };

struct todoList *createList(void) {
  struct todoList *todos = malloc(sizeof(struct todoList));
  if (todos == NULL)
    return NULL;
  todos->capacity = 2;
  todos->size = 0;
  todos->items = malloc(todos->capacity * sizeof(struct Todo));
  if (todos->items == NULL) {
    free(todos);
    return NULL;
  }
  return todos;
}

void addTodo(struct todoList *list, char *userTitle) {
  if (list->size == list->capacity) {
    int newCapacity = list->capacity * 2;

    struct Todo *temp = realloc(list->items, newCapacity * sizeof(struct Todo));

    if (temp == NULL) {
      printf("Failed to expand list!\n");
      return;
    }
    list->items = temp;
    list->capacity = newCapacity;
    printf("List expanded to %d slots\n", list->capacity);
  }

  int i = list->size;
  list->items[i].id = i + 1;
  list->items[i].isCompleted = 0;
  list->items[i].title = strdup(userTitle);
  list->size++;
  printf("Todo added succesfully!");
}

void markTodoCompleted(struct todoList *list, int index) {
  if (list == NULL) {
    printf("The list is empty");
  };
  list->items[index].isCompleted = 1;
  printf("%s is marked completed", list->items[index].title);
}

void removeTodo(struct todoList *list, int index) {
  if (list->items[index].id < 1) {
    printf("The todo doesn't exist!");
  };
  free(list->items[index].title);

  for (int i = index; i < list->size - 1; i++) {
    list->items[i] = list->items[i + 1];
  }
  list->size--;
}

void printMyList(struct todoList *list) {
  if (list == NULL) {
    printf("The list is empty");
  };
  for (int i = 0; i < list->size; i++) {
    printf("Id: %d\n", list->items[i].id);
    printf("Title: %s\n", list->items[i].title);
    printf("IsCompleted: %d\n", list->items[i].isCompleted);
  };
};

void displayMenu(void) {
  const char *options[] = {"1. Add a Todo", "2. View List", "3. Delete Todo",
                           "4. Exit"};

  printf("\n--- TODO APP MENU ---\n");
  int numOptions = sizeof(options) / sizeof(options[0]);

  for (int i = 0; i < numOptions; i++) {
    printf("%s\n", options[i]);
  }
}

void takeTitleString(char input[], int size) {
  fgets(input, size, stdin);
  // Remove the newline that fgets stores
  input[strcspn(input, "\n")] = '\0';
}

// take the user action input
int takeInput() {
  int number;
  char input[100];
  printf("Choose the input: \n");
  while (fgets(input, sizeof(input), stdin)) {
    if (sscanf(input, "%d", &number) == 1) {
      return number;
    } else {
      printf("Invalid input. Try again: ");
    }
  }
  return 0;
}

int main(void) {
  struct todoList *myTodoList = createList();
  int userChoice = 0;

  printf("=====================================\n");
  printf(" Welcome to the TodoList in CLI \n");
  printf("=====================================\n");
  printf("It's a regular todo list but written in dangerous c code.\n\n");
  printf("Good luck with the todo!\n\n");

  displayMenu();

  while (userChoice != EXIT_APP) {
    displayMenu();
    userChoice = takeInput();
    char todoTitle[100];

    switch (userChoice) {
    case ADD_TODO: {
      takeTitleString(todoTitle, sizeof(todoTitle));
      addTodo(myTodoList, todoTitle);
    }
    case VIEW_TODOS: {
      printMyList(myTodoList);
    }
    case DELETE_TODO: {
      int indexToDelete;
      indexToDelete = takeInput();
      removeTodo(myTodoList, indexToDelete);
    }
		      case View
    }
  }
  switch (userChoice) {}

  return 0;
}
