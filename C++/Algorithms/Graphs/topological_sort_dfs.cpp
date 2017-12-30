#include <iostream>
#include <vector>
#include <stack>

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
	stack<int> *ts;
	void dfs(int);
	void DFS(int);

public:
	Graph(int V) {
		this->V = V;
		adj = new vector<int>[V]; // array (size V) of vectors
	}
	void addEdge(int v, int w) {
		adj[v].push_back(w);
	}

	stack<int>& topologicalSortDFS();
};

stack<int>& Graph::topologicalSortDFS() {
	ts = new stack<int>;
	DFS(0);
	return *ts;
}

void Graph::DFS(int v) {
	visited = new vector<bool>(V); // all elements are initialized to false by default
	for (int i = 0; i < V; i++) {
		if ((*visited)[i] == UNVISITED) {
			dfs(i);
		}
	}
	
}

void Graph::dfs(int u) {
	(*visited)[u] = VISITED;
	for (itr it = adj[u].begin(); it != adj[u].end(); it++) { //iterate through all element adjacent to u
		if ((*visited)[*it] == UNVISITED) { // for all the adjacent vertex that have not been visited recursively traverse its adjs vertex
			dfs(*it);
			
		}
	}
	ts->push(u);
}

int main() {
	Graph g(7);

	g.addEdge(0, 1);
	g.addEdge(1, 4);
	g.addEdge(0, 5);
	g.addEdge(5, 2);
	g.addEdge(0, 2);
	g.addEdge(3, 6);
	g.addEdge(3, 5);
	g.addEdge(3, 4);
	g.addEdge(6, 4);
	g.addEdge(6, 0);
	g.addEdge(3, 2);

	cout << "Topological sort using dfs traversal. Return vertices in reverse postorder" << endl;
	stack<int> sorted = g.topologicalSortDFS();

	while (!sorted.empty()) {
		auto item = sorted.top();
		sorted.pop();
		cout << item << " ";
	}
	cout << endl;

	return 0;
}