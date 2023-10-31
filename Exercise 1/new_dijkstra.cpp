using namespace std;
#include "graph_class.h"
#include <queue>
#include <climits>
#include <iostream>

void Graph::new_dijkstra(int start, int goal, std::vector<int>& path, std::vector<int>& dist) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    dist.assign(adj.size(), INT_MAX);
    std::vector<bool> visited(adj.size(), false);
    path.assign(adj.size(), -1); 
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        pq.pop();

        if (visited[current]) {
            continue;
        }
        visited[current] = true; 

        if (current == goal) {
            break; // Early exit if the goal is reached
        }

        for (int i = 0; i < adj[current].size(); ++i) {
            int neighbor = adj[current][i];
            int weightToNeighbor = weight[current][neighbor];
            int cost = dist[current] + weightToNeighbor;

            if (!visited[neighbor] && cost < dist[neighbor]) {
                dist[neighbor] = cost;
                pq.push({cost, neighbor});
                path[neighbor] = current;
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