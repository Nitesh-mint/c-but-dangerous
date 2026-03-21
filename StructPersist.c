#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
  char *Name;
  int Permission;
};

struct TeamManager {
  int count;
  int size;
  struct User *Users;
};

enum PERMISSIONS { READ, CREATE, UPDATE, DELETE };

void writeToFile(struct TeamManager *teamManager) {
  const char *FILE_NAME = "structPersist.bin";
  if (teamManager == NULL) {
    return;
  }
  // open file in binary write mode
  FILE *f = fopen(FILE_NAME, "wb");

  if (f == NULL) {
    return;
  }

  printf("About to write %s\n", teamManager->Users[0].Name);
  int totalUsers = teamManager->count;
  fwrite(&totalUsers, sizeof(int), 1, f);
  for (int i = 0; i < teamManager->count; i++) {
    int len = strlen(teamManager->Users[i].Name);
    fwrite(&len, sizeof(int), 1, f);
    fwrite(teamManager->Users[i].Name, 1, len, f);
    fwrite(&teamManager->Users[i].Permission, sizeof(int), 1, f);
  }

  fclose(f);
}

// void readFromFile() {
// 	FILE *f = fopen("structPersist.bin", "rb");

// }

int main(void) {
  struct TeamManager *shantidanda = malloc(sizeof(struct TeamManager));
  shantidanda->count = 2;
  shantidanda->size = 5;
  shantidanda->Users = malloc(sizeof(struct User) * shantidanda->size);
  shantidanda->Users[0].Name = "Messi";
  shantidanda->Users[1].Name = "Ronaldo";
  shantidanda->Users[0].Permission = 1;
  shantidanda->Users[1].Permission = 0;
  printf("The User %s has permssion %d\n", shantidanda->Users[0].Name,
         shantidanda->Users[0].Permission);
  writeToFile(shantidanda);
  return 0;
}
