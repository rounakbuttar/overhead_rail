// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 13

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V])
{
	// Array to store constructed MST
	int parent[V];
	
	// Key values used to pick minimum weight edge in cut
	int key[V];
	
	// To represent set of vertices included in MST
	bool mstSet[V];

	// Initialize all keys as INFINITE
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	// Always include first 1st vertex in MST.
	// Make key 0 so that this vertex is picked as first vertex.
	key[0] = 0;
	parent[0] = -1; // First node is always root of MST

	// The MST will have V vertices
	for (int count = 0; count < V - 1; count++)
	{
		// Pick the minimum key vertex from the
		// set of vertices not yet included in MST
		int u = minKey(key, mstSet);

		// Add the picked vertex to the MST Set
		mstSet[u] = true;

		// Update key value and parent index of
		// the adjacent vertices of the picked vertex.
		// Consider only those vertices which are not
		// yet included in MST
		for (int v = 0; v < V; v++)

			// graph[u][v] is non zero only for adjacent vertices of m
			// mstSet[v] is false for vertices not yet included in MST
			// Update the key only if graph[u][v] is smaller than key[v]
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// print the constructed MST
	printMST(parent, graph);
}

// Driver code
int main()
{
	int graph[V][V] = { {0,	34,	40,	33,	8,	39,	45,	20,	14,	20,	17,	30,	22},
                        {34, 0,	39,	6,	19,	41,	47,	37,	30,	11,	41,	45,	9},
                        {40, 39,0,	14,	14,	45,	37,	26,	36,	36,	6,	47,	33},
                        {33, 6,	14,	0,	23,	13,	34,	36,	34,	48,	22,	20,	49},
                        {8,	19,	14,	23,	0,	48,	28,	45,	9,	45,	40,	12,	13},
                        {39,41,	45,	13,	48,	0,	7,	40,	32,	30,	7,	42,	34},
                        {45,47,	37,	34,	28,	7,	0,	38,	34,	24,	47,	48,	14},
                        {20,37,	26,	36,	45,	40,	38,	0,	33,	34,	47,	6,	45},
                        {14,30,	36,	34,	9,	32,	34,	33,	0,	47,	11,	47,	31},
                        {20,11,	36,	48,	45,	30,	24,	34,	47,	0,	49,	33,	46},
                        {17,41,	6,	22,	40,	7,	47,	47,	11,	49,	0,	19,	33},
                        {30,45,	47,	20,	12,	42,	48,	6,	47,	33,	19,	0,	5},
                        {22,9,	33,	49,	13,	34,	14,	45,	31,	46,	33,	5,	0} };

	// Print the solution
	primMST(graph);

	return 0;
}
