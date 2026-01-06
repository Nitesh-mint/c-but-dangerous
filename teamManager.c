#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player {
  int score;
  char *name;
};

struct Team {
  int count;
  struct Player *members;
};

void updateScore(struct Team *t) {
  for (int i = 0; i < t->count; i++) {
    t->members[i].score += 10;
    printf("Increased the score by 10 for player %s to the total of %d\n",
           t->members[i].name, t->members[i].score);
  }
}

int main(void) {
  struct Team *ilam = malloc(sizeof(struct Team));
  if (ilam == NULL)
    return 1;
  ilam->count = 2; // number of players
  ilam->members = malloc(ilam->count * sizeof(struct Player));

  ilam->members[0].name = strdup("Nitesh");
  ilam->members[0].score = 50;

  ilam->members[1].name = strdup("Susil");
  ilam->members[1].score = 50;

  updateScore(ilam);

  for (int i = 0; i < ilam->count; i++) {
    free(ilam->members[i].name);
  }

  free(ilam->members); // the score will be free with the members as it is
                       // inline with the struct not like the name which is
                       // stored in another memory location
  free(ilam);
  return 0;
}
