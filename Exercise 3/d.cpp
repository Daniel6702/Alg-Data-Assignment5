/*
The topologicalSortUtil function is called once for each vertex that has not been visited,
and it performs a Depth-First Search (DFS). DFS has a time complexity of O(V + E) for a graph with V vertices and E edges
Once the vertices are sorted topologically, the algorithm relaxes the edges of each vertex. Since each edge is considered exactly once, 
the complexity of this part is also O(E).
Combining both parts, the overall complexity of the algorithm is O(V + E) 
*/