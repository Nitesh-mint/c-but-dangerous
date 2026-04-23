/* Implementation of graph:(undirected adjacency matrix)
 * The edges doesn't have direction so [1,2] means both [1,2] and [2,1]
 */

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  struct Graph *graph = INIT_GRAPH(3);
  printf("The Grap is created %d", graph->nodeCount);
  return 0;
}
