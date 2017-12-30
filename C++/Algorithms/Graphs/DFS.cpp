#include <iostream>
#include <vector>

using namespace std;

#define VISITED true
#define UNVISITED false

typedef vector<int> vi;
typedef vi::iterator itr;


class Graph {

private:
	int V; // number of vertices
	vector<int> *adj; // point to the first vector in the array of vectors
	vector<bool> *visited;
	void dfs(int);

public:
	Graph(int V) {
		this->V = V;
		adj = new vector<int>[V]; // array (size V) of vectors
	}
	void addEdge(int v, int w) {
		adj[v].push_back(w);
	}

	void DFS(int);
};

void Graph::DFS(int v) {
	visited = new vector<bool>(V); // all elements are initialized to false by default
	dfs(v);
}

void Graph::dfs(int u) {
	cout << u << " ";
	(*visited)[u] = VISITED;
	for (itr it = adj[u].begin(); it != adj[u].end(); it++) { //iterate through all element adjacent to u
		if ((*visited)[*it] == UNVISITED) { // for all the adjacent vertex that have not been visited recursively traverse its adjs vertex
			dfs(*it);
		}
	}
}

int main() {
	Graph g(10);

	g.addEdge(0, 1);
	g.addEdge(0, 6);
	g.addEdge(0, 3);

	g.addEdge(1,1);
	g.addEdge(1,2);
	g.addEdge(1,6);
	g.addEdge(1,0);

	g.addEdge(2, 5);
	g.addEdge(2,7);

	g.addEdge(3,0);
	g.addEdge(3,0);
	g.addEdge(3,6);
	g.addEdge(3,8);

	g.addEdge(4,6);
	g.addEdge(4,9);

	g.addEdge(5,2);
	g.addEdge(5,9);

	g.addEdge(6,6);
	g.addEdge(6,4);

	g.addEdge(7,4);
	g.addEdge(7,1);
	g.addEdge(7,5);

	g.addEdge(8,4);
	g.addEdge(8,9);

	g.addEdge(9,9);
	g.addEdge(9,9);
	g.addEdge(9,8);
	

	cout << "Following is Depth First Traversal (starting from vertex ) \n";
	g.DFS(0);

	
	return 0;
}