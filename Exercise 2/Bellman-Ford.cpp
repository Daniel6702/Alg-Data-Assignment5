#include <iostream>
#include <climits>

using namespace std;

// a structure to represent a weighted edge in the graph
struct Edge {
    int src, dest, weight;
};

// a structure to represent a connected, directed, and weighted graph
struct Graph {
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges.
    struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

// A utility function used to print the solution
void printArr(int dist[], int n) {
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

// The main function that finds shortest distances from src
// to all other vertices using the Bellman-Ford algorithm.
// The function also detects a negative weight cycle.
void BellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;	
    // Use dynamic memory allocation for the dist array
    int* dist = new int[V];

    // Initialize distances from src to all other vertices as infinite
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // A simple shortest path from src to any other vertex can have
    // at-most |V| - 1 edges
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // The above step guarantees shortest distances if the graph doesn't
    // contain a negative weight cycle. If we get a shorter path, then there is a cycle.
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains a negative weight cycle");
            return; // If a negative cycle is detected, simply return
        }
    }

    printArr(dist, V);
	delete[] dist;
    return;
}

// Driver's code
int main() {
    /* Let us create the graph given in the above example */
    int V = 4; // Number of vertices in the graph
    int E = 4; // Number of edges in the graph
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1 (or A-B in the above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 1;

    // add edge 1-2 (or B-C in the above figure)
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = -2;

    // add edge 2-3 (or C-D	 in the above figure)
    graph->edge[2].src = 2;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 4;

    // add edge 3-0 (or D-A in the above figure)
    graph->edge[3].src = 3;
    graph->edge[3].dest = 0;
    graph->edge[3].weight = 3;

    // Function call
    BellmanFord(graph, 0);

    return 0;
}
