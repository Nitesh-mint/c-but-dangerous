/* Implementation of graph:(undirected adjacency matrix)
 * The edges doesn't have direction so [1,2] means both [1,2] and [2,1]
 */

#include <stdio.h>
#include <stdlib.h>

int **INIT_EMPTY_MATRIX(int V) {

  int **matrix = malloc(V * sizeof(int *));

  for (int i = 0; i < V; i++) {

    matrix[i] = malloc(V * sizeof(int));

    for (int j = 0; j <= V; j++) {
      matrix[i][j] = 0;
    }
  }

  printf("Empty matrix initialized!\n");
  return matrix;
}

int main(void) { return 0; }
