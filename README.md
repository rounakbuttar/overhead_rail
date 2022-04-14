# overhead_rail

Danblock India Pvt ltd wants to install over-head rail material handling system for transporting brake pad mixture from mixture manufacturing unit to various moulding machines. They want to connect 12 manufacturing units producing different brake pad so that material could be transported to all these locations. If the rails are longer than necessary, then they will have to invest more money to construct the overhead rail, more labour hours and time will be required too. Also, it would take longer to operate the machine. So, all these costs can be minimised if we were to find an optimal path which connects all these places. This problem can be classified as a minimal spanning tree problem and can be solved by both Prim’s and Kruskal’s algorithm. We will be using C++ to implement these algorithms.

The initial nodes were plotted using networkx library in python.

all nodes.jpg is the graph of the initial problem and opt_graph.jpg shows the optimised graph.

node plotting.ipynb shows the code for node plotting

data.xlsx shows the adjacency matrix of the graph

Prims_MST.cpp contains the code for Prim's algorithm.
