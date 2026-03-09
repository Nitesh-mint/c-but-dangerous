/* A simple bitwise permission manager where instead of
 * handling permission with multiple bits like
 * User {
 * 	char *Name;
 * 	int has_read;
 * 	int has_write;
 * }
 * We use a single no negative integer to store all of the
 * permissions.
 *
 * We use bitwise calculations to check and grant the
 * permission.
 *
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct User {
  char *Name;
  uint8_t permission; // use a single int to store the
                      // permissions
};

enum permission {
  READ = 1 << 0,   // 1
  CREATE = 1 << 1, // 2
  UPDATE = 1 << 2, // 4
  DELETE = 1 << 3, // 8
  ADMIN = 1 << 4   // 16
};

void check_permission(struct User *user, uint8_t permission) {
  if (user == NULL) {
    return;
  }
  // & -> only 1 if both of them are one.
  // user-> permission: 1001 and permission: 1000
  // result: 1000
  if ((user->permission & permission) == permission) {
    printf("The user: %s has the permission\n", user->Name);
  } else {
    printf("The user: %s doesn't have the permission!\n", user->Name);
  }
}

void grant_permission(struct User *user, uint8_t permission) {
  /*
   * Here we do not need to check if the user already has that
   * permissoin or not as BitWise OR handles this.
   * 0001 | 0001 = 0001
   * So No need to handle the duplicate permission
   */
  if (user == NULL) {
    return;
  }
  user->permission = user->permission | permission;
}

void revoke_all_permission(struct User *user) {
  if (user == NULL) {
    return;
  }
  user->permission = 0;
  printf("All of the permission for the user %s is removed\n", user->Name);
}

void remove_permission(struct User *user, int permission) {
  if (user == NULL) {
    return;
  };
  // flip the 8-bit permission int. (1000) : (0111)
  int flipped_permission = ~permission;
  user->permission = user->permission & flipped_permission;
  printf("The permission is removed");
}

int main(void) {
  struct User *Nitesh = malloc(sizeof(struct User));
  Nitesh->Name = "Nitesh";
  Nitesh->permission =
      CREATE |
      UPDATE; // biwise(OR) is like adding them if no carry occurs.(2 + 4 = 6)
  check_permission(Nitesh, CREATE | UPDATE | DELETE);
  grant_permission(Nitesh, DELETE);
  check_permission(Nitesh, CREATE | UPDATE | DELETE);
  remove_permission(Nitesh, CREATE);
  check_permission(Nitesh, CREATE | UPDATE | DELETE);
  revoke_all_permission(Nitesh);
  check_permission(Nitesh, CREATE);
  free(Nitesh->Name);
  free(Nitesh);
  return 0;
}
