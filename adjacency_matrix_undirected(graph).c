/* Implementation of graph:(undirected adjacency matrix)
 * If edges doesn't have direction so then [1,2] means both [1,2] and [2,1]
 */

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  struct Graph *graph = INIT_GRAPH(3);
  // printGraph(graph);
  addEdge(graph, 0, 1);
  printGraph(graph);
  return 0;
}
