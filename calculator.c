#include <stdbool.h>
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
  const char *options[] = {"1. ADD", "2. SUBTRACT", "3. MULTIPLY", "4. DIVIDE",
                           "5. EXIT"};
  int optionsCount = sizeof(options) / sizeof(options[0]);
  for (int i = 0; i < optionsCount; i++) {
    printf("%s \n", options[i]);
  }
}

bool calculateNumbers(double firstNumber, double secondNumber, int action,
                      double *result_output) {
  if (result_output == NULL)
    return false;
  switch (action) {
  case 1: {
    *result_output = firstNumber + secondNumber;
    return true;
  }
  case 2:
    *result_output = firstNumber - secondNumber;
    return true;
  case 3:
    *result_output = firstNumber * secondNumber;
    return true;
  case 4:
    if (secondNumber == 0) {
      return false;
    }
    *result_output = firstNumber / secondNumber;
    return true;
  default:
    return false;
  }
}

void takeNumberInput(double *a, double *b) {
  printf("Enter the first number:");
  scanf("%lf", a);
  printf("Enter the second number:");
  scanf("%lf", b);
}

int main(void) {
  while (1) {
    showMenu();
    int userChoice = takeMenuChoice();
    if (userChoice == 5) {
      break;
    }
    double firstNumber = 0, secondNumber = 0, result = 0;
    takeNumberInput(&firstNumber, &secondNumber);
    calculateNumbers(firstNumber, secondNumber, userChoice, &result);
    printf("Result is : %lf \n", result);
    userChoice = 0;
  }
  return 0;
}
