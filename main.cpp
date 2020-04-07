#include <iostream>
#include <vector>

using namespace std;

int START;
int END;

struct Edge {
	int src, dest;
};

class Graph
{
public:

	vector<vector<int>> adj_list;

	Graph(vector<Edge> const &edges, int N)
	{
		adj_list.resize(N);
		for (unsigned i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;

			adj_list[src].push_back(dest);
			adj_list[dest].push_back(src);
		}
	}
};

void printAllHamiltonianPaths(Graph const& g, int x, vector<bool>
						visited, vector<int> &path, int N)
{
	// if all the vertices are visited, then
	// Hamiltonian path exists
	if (path.size() == N && *path.begin() == START && path[N-1] == END)
	{

		// print Hamiltonian path
		for (int i : path)
			cout << i << " ";
		cout << endl;

		return;
	}

	// Check if every edge starting from vertex v leads
	// to a solution or not
	for (int w : g.adj_list[x])
	{
		// process only unvisited vertices as Hamiltonian
		// path visits each vertex exactly once
		if (!visited[w])
		{
			visited[w] = true;
			path.push_back(w);

			// check if adding vertex w to the path leads
			// to solution or not
			printAllHamiltonianPaths(g, w, visited, path, N);

			// Backtrack
			visited[w] = false;
			path.pop_back();
		}
	}
}

// Represent a random graph with n vertices of at least degree one (n is at least 100). 
// This graph might be undirected or directed. It could have cycles or no cycles. 
// Randomly select two vertices (x,y) from the graph, and find all of the possible hamiltonian paths in the graph.
int main() {
    // consider complete graph having 4 vertices
	vector<Edge> edges = {
		{0, 1}, {1, 2}, {1, 3}, {2, 3}
	};
	vector<int> vertices = {0,1,2,3};
    cout<<"Choose from the following vertices:\n";
    cout<<"0,1,2,3\n";

    int start,end;

    cout<<"enter starting vertex x:" << endl;
    cin>>start;
	while(true){
		if(find(vertices.begin(), vertices.end(), start)==vertices.end()){
			cout<<"Choose from the following existing vertices:" << endl;
			cin>>start;
		} else {break;}
	}

	cout<<"enter ending vertex y:" << endl;
    cin>>end;
	while(true){
		if(find(vertices.begin(), vertices.end(), end)==vertices.end()){
			cout<<"Choose from the following existing vertices:" << endl;
			cin>>end;
		} else {break;}
	}
    
    cout<<"x: " << start << " y: " << end << endl;

	int N = 4;

	Graph g(edges, N);

	// add starting node to the path
	vector<int> path;
	path.push_back(start);

	// mark start node as visited
	vector<bool> visited(N);
	visited[start] = true;

	START = start;
	END = end;

	printAllHamiltonianPaths(g, start, visited, path, N);

	return 0;
}