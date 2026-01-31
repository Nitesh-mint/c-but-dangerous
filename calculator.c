#include <stdio.h>

int main(void) {
  const char *options[] = {"1. Add a Todo", "2. View List", "3. Delete Todo",
                           "4. Exit"};
  printf("The size of options is : %lu", sizeof(options) / sizeof(options[0]));
  printf("This works fine: ");
  return 0;
}
