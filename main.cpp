#include <iostream>
#include <vector>

using namespace std;

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

// Represent a random graph with n vertices of at least degree one (n is at least 100). 
// This graph might be undirected or directed. It could have cycles or no cycles. 
// Randomly select two vertices (x,y) from the graph, and find all of the possible hamiltonian paths in the graph.
int main() {
    // consider complete graph having 4 vertices
	vector<Edge> edges = {
		{0, 1}, {1, 2}, {1, 3}, {2, 3}
	};
    cout<<"Choose from the following vertices:\n";
    cout<<"0,1,2,3\n";

    int start,end;
    cout<<"enter starting vertex x:" << endl;
    cin>>start;
    cout<<"enter ending vertex y:" << endl;
    cin>>end;
    cout<<"x: " << start << " y: " << end << endl;

	int N = 4;

	Graph g(edges, N);

	// add starting node to the path
	vector<int> path;
	path.push_back(start);

	// mark start node as visited
	vector<bool> visited(N);
	visited[start] = true;

	return 0;

}