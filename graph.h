// Imp: This is adjacency matrix
struct Graph {
  int *matrix;
  int V; // nodeCount
  // int edgeCount;
  // int directed; // implement later
  // int weighted; // implement later
};

struct Graph *INIT_GRAPH(int V);
int addEdge(struct Graph *g, int src, int dest);
void printGraph(struct Graph *g);
void destroyGraph(struct Graph *g);
