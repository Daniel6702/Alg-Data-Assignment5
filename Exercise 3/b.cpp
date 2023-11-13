using namespace std;
#include "graph_class.h"
#include <queue>
#include <climits>
#include <iostream>

void Graph::topologicalSortUtil(int v, std::vector<bool>& visited, std::stack<int>& Stack) {
    visited[v] = true;
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
    Stack.push(v);
}

void Graph::new_dijkstra(int start, int goal, std::vector<int>& path, std::vector<int>& dist) {
    std::stack<int> Stack;
    std::vector<bool> visited(adj.size(), false);
    for (int i = 0; i < adj.size(); i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    path.assign(adj.size(), -1);
    dist.assign(adj.size(), INT_MAX);
    dist[start] = 0;

    while (!Stack.empty()) {
        int u = Stack.top();
        Stack.pop();

        if (dist[u] != INT_MAX) {
            for (int i = 0; i < adj[u].size(); ++i) {
                int neighbor = adj[u][i];
                int weightToNeighbor = weight[u][neighbor];
                if (dist[u] + weightToNeighbor < dist[neighbor]) {
                    dist[neighbor] = dist[u] + weightToNeighbor;
                    path[neighbor] = u;
                }
            }
        }
    }

    // Reconstruct the path
    if (dist[goal] != INT_MAX) {
        std::vector<int> temp_path;
        for (int at = goal; at != -1; at = path[at]) {
            temp_path.push_back(at);
        }
        std::reverse(temp_path.begin(), temp_path.end());
        path = temp_path;
    }
}



//Compile: g++ -o my_program new_dijkstra.cpp graph_class.cpp disjoint_sets.cpp
//run: .\my_program.exe
int main() {
    Graph digraph(7);
    vector<int> path, dist, new_path;
	dist.resize(7);
    path.resize(7);
    digraph.addWeightedEdge(0, 1, 1);
	digraph.addWeightedEdge(0, 2, 5);
    digraph.addWeightedEdge(0, 3, 2);
    digraph.addWeightedEdge(1, 3, 4);
    digraph.addWeightedEdge(1, 4, 3);
    digraph.addWeightedEdge(2, 5, 1);
	digraph.addWeightedEdge(3, 2, 4);
	digraph.addWeightedEdge(3, 5, 2);
	digraph.addWeightedEdge(3, 6, 2);
	digraph.addWeightedEdge(4, 3, 1);
	digraph.addWeightedEdge(4, 6, 10);
    digraph.addWeightedEdge(6, 5, 8);
	digraph.new_dijkstra(0, 6,path, dist);
    cout << "Path: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    return 0;
}