#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *next;
};

struct List {
  struct Node *head;
  int size;
};

void Add(struct List *list, int number) {
  struct Node *newNode = malloc(sizeof(struct Node));

  newNode->value = number;
  newNode->next = list->head;

  list->head = newNode;
  list->size++;
}

void PrintList(const struct List *list) {
  if (list->head == NULL) {
    printf("The list is empty!");
  }
  struct Node *current = list->head;

  while (current != NULL) {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

// delets the first item of the list (last inserted)
int DeleteItem(struct List *list) {
  if (list->head == NULL) {
    return 0;
  }

  struct Node *temp = list->head;
  list->head = temp->next;
  list->size--;
  free(temp);
  return temp->value;
}

// prints the last inserted item of the list
void peek(const struct List *list) {
  if (list == NULL) {
    printf("The list is currently empty!");
    return;
  }
  printf("%d \n", list->head->value);
}

void printListMenu() {
  const char *options[] = {"1. Add", "2.Delete", "3. PrintList", "4. Peek",
                           "5. Exit"};
  int numItems = sizeof(options) / sizeof(options[0]);
  printf("Available operations \n");
  for (int i = 0; i < numItems; i++) {
    printf("%s \n", options[i]);
  }
}

int takeActionChoice() {
  int number;
  char input[100];
  printf("Enter your choise: \n");
  while (fgets(input, sizeof(input), stdin)) {
    if (sscanf(input, "%d", &number) == 1) {
      return number;
    } else {
      printf("Invalid input please try again...");
    }
  }
  return 0;
}

int takeInputValue() {
  int number;
  char input[100];
  printf("Enter the number to add to the list: \n");
  while (fgets(input, sizeof(input), stdin)) {
    if (sscanf(input, "%d", &number) == 1) {
      return number;
    } else {
      printf("Please enter a valid number to input.");
    }
  }
  return 0;
}

void handleUserChoice(struct List *list, int action) {
  switch (action) {
  case 1: {
    int inputNumber = takeInputValue();
    Add(list, inputNumber);
    break;
  }
  case 2: {
    int deletedItem = DeleteItem(list);
    if (deletedItem == 0) {
      printf("The list is empty!");
    } else {
      printf("Succesfully deleted %d", deletedItem);
    }
    break;
  }
  case 3:
    PrintList(list);
    break;
  case 4:
    peek(list);
    break;
  }
}
void destroyList(struct List *list) {
  struct Node *current = list->head;
  while (current != NULL) {
    struct Node *next = current->next;
    free(current);
    current = next;
  }
  free(list);
}

int main() {
  struct List *myList = malloc(sizeof(struct List));
  int actionChoice;
  printListMenu();
  actionChoice = takeActionChoice();
  while ((actionChoice > 0 && actionChoice != 5)) {
    handleUserChoice(myList, actionChoice);
    actionChoice = takeActionChoice();
  }
  return 0;
}
