/*
In the DAG from part a) with topological order A, B, C, D, E, the modified Dijkstra's algorithm is correct since it relaxes the edges in the correct order. 
starting from A, edges are relaxed in sequence—A to B and C, then B to D, C to D, and D to E—ensuring the shortest paths are determined in a single pass without revisits.
Since there are no cycles, each relaxation step guarantees the shortest path up to that vertex.
*/