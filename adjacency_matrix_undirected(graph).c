/* Implementation of graph:(undirected adjacency matrix)
 * The edges doesn't have direction so [1,2] means both [1,2] and [2,1]
 */

#include <stdio.h>
#include <stdlib.h>

// I think try to implement the graph elsewhere and use it here. Define header
// -> and use it with include
struct Graph {
  int *node;
  int nodeCount;
  int edgeCount;
  // int directed; // implement later
  // int weighted; // implement later
};

int main(void) { return 0; }
