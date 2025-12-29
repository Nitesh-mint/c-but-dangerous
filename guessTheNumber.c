#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(void) {
  int upper_range = 20;
  int lower_range = 1;
  return rand() % (upper_range - lower_range + 1) + lower_range;
}

int takeInput() {
  int number;
  char input[100];

  printf("Enter your guess: ");

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
  srand(time(NULL));
  int guessedNumber, generatedNumber, tries = 1;
  generatedNumber = generateRandomNumber();

  printf("=====================================\n");
  printf("  Number Guessing Game (C)\n");
  printf("=====================================\n");
  printf("Guess a number between 1 and 20.\n");
  printf("Good luck!\n\n");

  guessedNumber = takeInput();

  while (guessedNumber != generatedNumber) {
    printf("Wrong guess! ---  %d tries \n", tries);
    guessedNumber = takeInput();
    tries++;
  }

  printf("Correct guess the number is %d", guessedNumber);

  return 0;
}
