import matplotlib.pyplot as plt
import networkx as nx

'''
The graph consists of five vertices (A, B, C, D, E) and directed edges that do not form any cycles.
The vertices are arranged according to a topological order
'''

edges = [("A", "B"), ("A", "C"), ("B", "D"), ("C", "D"), ("D", "E")]

G = nx.DiGraph(edges)

if not nx.is_directed_acyclic_graph(G):
    raise ValueError("The graph must be a DAG.")

topological_order = list(nx.topological_sort(G))

pos = nx.spring_layout(G)  

plt.figure(figsize=(8, 5))
nx.draw_networkx_nodes(G, pos, node_size=700)
nx.draw_networkx_edges(G, pos, edgelist=edges, arrowstyle="->", arrowsize=20)
nx.draw_networkx_labels(G, pos, font_size=20, font_family="sans-serif")
plt.title("Example of a Directed Acyclic Graph (DAG)")
plt.axis("off")
plt.show()
