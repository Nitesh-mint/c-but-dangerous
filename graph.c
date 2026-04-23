#include <stdio.h>
#include <stdlib.h>

// Imp: This is adjacency matrix
struct Graph {
  int **matrix;
  int V; // nodeCount
  // int edgeCount;
  // int directed; // implement later
  // int weighted; // implement later
};

struct Graph *INIT_GRAPH(int V) {
  struct Graph *graph = malloc(sizeof(struct Graph));

  if (V < 0) {
    return graph;
  }

  // allocate memory for ROW
  graph->matrix = malloc(sizeof(int) * V);

  for (int i = 0; i < V; i++) {
    graph->matrix[i] =
        malloc(V * sizeof(int)); // allocate V numbers cols per row
  }

  graph->V = V;
  printf("Graph initialized with %d Vertices \n", graph->V);
  return graph;
}

int addEdge(struct Graph *g, int src, int dest) {
  if (g == NULL) {
    return -1;
  }

  g->matrix[src][dest] = 1;
  return 0;
}
