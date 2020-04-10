#include <iostream>
#include <vector>

using namespace std;

int START;
int END;
vector<vector<int> > paths;

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

void printAllHamiltonianPaths(Graph const& g, int x, vector<bool>visited, vector<int> &path, int N) {
	// if a path is found such taht it starts 
	if (path.size() == N && *path.begin() == START && path[N-1] == END)
	{
		paths.push_back(path);
		return;
	}

	// Check if every edge starting from starting vertex x leads to a solution or not
	for (int w : g.adj_list[x]) {
		// process only unvisited vertices as Hamiltonian
		// path visits each vertex exactly once
		if (!visited[w]) {
			visited[w] = true;
			path.push_back(w);

			// check if adding vertex w to the path leads to solution or not
			printAllHamiltonianPaths(g, w, visited, path, N);

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
		{0, 2},
{0, 4},
{0, 5},
{1, 4},
{1, 5},
{2, 3},
{2, 4},
{4, 5},
{5, 6},
{6, 7},
{7, 8},
{8, 9},
{9, 10},
{10, 11},
{11, 12},
{12, 13},
{13, 14},
{14, 15},
{15, 16},
{16, 17},
{17, 18},
{18, 19},
{19, 20},
{20, 21},
{21, 22},
{22, 23},
{23, 24},
{24, 25},
{25, 26},
{26, 27},
{27, 28},
{28, 29},
{29, 30},
{30, 31},
{31, 32},
{32, 33},
{33, 34},
{34, 35},
{35, 36},
{36, 37},
{37, 38},
{38, 39},
{39, 40},
{40, 41},
{41, 42},
{42, 43},
{43, 44},
{44, 45},
{45, 46},
{46, 47},
{47, 48},
{48, 49},
{49, 50},
{50, 51},
{51, 52},
{52, 53},
{53, 54},
{54, 55},
{55, 56},
{56, 57},
{57, 58},
{58, 59},
{59, 60},
{60, 61},
{61, 62},
{62, 63},
{63, 64},
{64, 65},
{65, 66},
{66, 67},
{67, 68},
{68, 69},
{69, 70},
{70, 71},
{71, 72},
{72, 73},
{73, 74},
{74, 75},
{75, 76},
{76, 77},
{77, 78},
{78, 79},
{79, 80},
{80, 81},
{81, 82},
{82, 83},
{83, 84},
{84, 85},
{85, 86},
{86, 87},
{87, 88},
{88, 89},
{89, 90},
{90, 91},
{91, 92},
{92, 93},
{93, 94},
{94, 95},
{95, 96},
{96, 97},
{97, 98},
{98, 99}
	};
	
	vector<int> vertices = {0, 1,2,3,4,5,6,
7,
8,
9,
10,
11,
12,
13,
14,
15,
16,
17,
18,
19,
20,
21,
22,
23,
24,
25,
26,
27,
28,
29,
30,
31,
32,
33,
34,
35,
36,
37,
38,
39,
40,
41,
42,
43,
44,
45,
46,
47,
48,
49,
50,
51,
52,
53,
54,
55,
56,
57,
58,
59,
60,
61,
62,
63,
64,
65,
66,
67,
68,
69,
70,
71,
72,
73,
74,
75,
76,
77,
78,
79,
80,
81,
82,
83,
84,
85,
86,
87,
88,
89,
90,
91,
92,
93,
94,
95,
96,
97,
98,
99};
    cout<<"Hamiltonion path starting at 0 and ending at 99:\n";

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
	
	if(paths.empty()){
		cout<<"Hamiltonion path does not exist starting at x: " << start << " and y: "<< end <<endl;
		return 0;
	}
	for(vector<int> p : paths) {
		for(int i : p){
			cout<< i << " ";
		}
		cout<<endl;
	}

	return 0;
}