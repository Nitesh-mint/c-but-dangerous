#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

struct Graph *INIT_GRAPH(int V) {
  if (V <= 0) {
    return NULL;
  }

  struct Graph *graph = malloc(sizeof(struct Graph));

  graph->V = V;

  // allocate memory for ROW
  graph->matrix = malloc(sizeof(int *) * V);

  for (int i = 0; i < V; i++) {
    graph->matrix[i] =
        malloc(V * sizeof(int)); // allocate V numbers cols per row

    for (int j = 0; j < V; j++) {
      graph->matrix[i][j] = 0;
    }
  }
  return graph;
}

int addEdge(struct Graph *g, int src, int dest) {
  if (g == NULL) {
    return -1;
  }

  g->matrix[src][dest] = 1;
  // undirect
  g->matrix[dest][src] = 1;
  return 0;
}

void printGraph(struct Graph *g) {
  if (g == NULL) {
    printf("The Graph is empty!");
  }
  for (int i = 0; i < g->V; i++) {
    for (int j = 0; j < g->V; j++) {
      printf("%d \t", g->matrix[i][j]);
    }
    printf("\n");
  }
}
