#include <stdio.h>

enum calculatorOperations {
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE,
  EXIT,
  CALC_OP_COUNT
};

int takeMenuChoice() {
  int number;
  char input[100];
  printf("What do you want to do: \n");
  while (fgets(input, sizeof(input), stdin)) {
    if (sscanf(input, "%d", &number)) {
      return number;
    } else {
      printf("Invalid input. Try again.");
    }
  }
  return 0;
}

void showMenu() {
  const char *options[] = {"1. ADD", "2. SUBTRACT", "3. MULTIPLY", "4. DIVIDE"};
  int optionsCount = sizeof(options) / sizeof(options[0]);
  for (int i = 0; i < optionsCount; i++) {
    printf("%s \n", options[i]);
  }
}

int calculateNumbers(int firstNumber, int secondNumber, int action) {
  switch (action) {
  case 1:
    return firstNumber + secondNumber;
  case 2:
    return firstNumber - secondNumber;
  case 3:
    return firstNumber * secondNumber;
  case 4:
    return firstNumber / secondNumber;
  default:
    return 0;
  }
}

void takeNumberInput(int *a, int *b) {
  printf("Enter the first number:");
  scanf("%d", a);
  printf("Enter the second number:");
  scanf("%d", b);
}

int main(void) {
  while (1) {
    showMenu();
    int userChoice = takeMenuChoice();
    if (userChoice == 5) {
      break;
    }
    int firstNumber = 0, secondNumber = 0, result = 0;
    takeNumberInput(&firstNumber, &secondNumber);
    result = calculateNumbers(firstNumber, secondNumber, userChoice);
    printf("Result is : %d \n", result);
    userChoice = 0;
  }
  return 0;
}
