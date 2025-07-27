import networkx as nx
import matplotlib.pyplot as plt

# Adjacency list as in your C++ example
adjLs = {
    1: [2, 3],
    2: [1, 5],
    3: [4, 1, 6],
    4: [3],
    5: [2, 7],
    6: [3, 7],
    7: [5, 6]
}

# Create the graph
G = nx.Graph()
for node, neighbors in adjLs.items():
    for neighbor in neighbors:
        G.add_edge(node, neighbor)

# Try to find a cycle (returns list of edges)
try:
    cycle_edges = nx.find_cycle(G, orientation='ignore')
    cycle_nodes = set(x[0] for x in cycle_edges).union(set(x[1] for x in cycle_edges))
except nx.exception.NetworkXNoCycle:
    cycle_edges = []
    cycle_nodes = []

# Draw the graph
pos = nx.spring_layout(G)
plt.figure(figsize=(8, 6))

# Draw all nodes and edges
nx.draw(G, pos, with_labels=True, node_color='lightblue', edge_color='gray', node_size=800, width=2)

# Highlight the cycle
if cycle_edges:
    nx.draw_networkx_edges(G, pos, edgelist=cycle_edges, edge_color='red', width=3)
    nx.draw_networkx_nodes(G, pos, nodelist=cycle_nodes, node_color='red')
    plt.title("Graph with Cycle Highlighted", fontsize=14)
else:
    plt.title("Graph with No Cycle Found", fontsize=14)

plt.savefig("graph_cycle_output.png")
print("Graph image saved as graph_cycle_output.png")
