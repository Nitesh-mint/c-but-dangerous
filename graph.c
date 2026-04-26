#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

struct Graph *INIT_GRAPH(int V) {
  if (V <= 0) {
    return NULL;
  }

  struct Graph *graph = malloc(sizeof(struct Graph));

  graph->V = V;

  // allocate all of the required space including (row and col).
  graph->matrix = malloc(sizeof(int) * V * V);

  for (int i = 0; i < V * V; i++) {
    graph->matrix[i] = 0;
  }

  return graph;
}

int addEdge(struct Graph *g, int src, int dest) {
  if (g == NULL) {
    return -1;
  }

  if (src < 0 || dest < 0 || src > g->V || dest > g->V) {
    return -1;
  }

  g->matrix[src * g->V + dest] = 1;
  g->matrix[dest * g->V + src] = 1; // undriected

  return 0;
}

void printGraph(struct Graph *g) {
  if (g == NULL) {
    printf("The Graph is empty!\n");
    return;
  }

  for (int i = 0; i < g->V; i++) {
    for (int j = 0; j < g->V; j++) {
      printf("%d ", g->matrix[i * g->V + j]);
    }
    printf("\n");
  }
}

void destroyGraph(struct Graph *g) {
  if (g == NULL) {
    printf("The Graph is empty");
    return;
  }

  free(g->matrix);
  free(g);
  g = NULL;
  printf("The memory freed succesfully");
  return;
}
