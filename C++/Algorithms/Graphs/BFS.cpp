#include <iostream>
#include <vector>
#include <queue>

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
	queue<int> *q;
	void bfs(int);

public:
	Graph(int V) {
		this->V = V;
		adj = new vector<int>[V]; // array (size V) of vectors
	}
	void addEdge(int v, int w) {
		adj[v].push_back(w);
	}

	void BFS(int);
};

void Graph::BFS(int v) {
	visited = new vector<bool>(V); // all elements are initialized to false by default
	q = new queue<int>;
	bfs(v);
}

void Graph::bfs(int u) {
	q->push(u);
	(*visited)[u] = VISITED;
	while (!q->empty()) {
		auto item = q->front();
		cout << item << " ";
		q->pop();
		for (itr it = adj[item].begin(); it != adj[item].end(); it++) {
			if ((*visited)[*it] ==  UNVISITED) {
				q->push(*it);
				// as soon as it is added to the queue marked it as visited so that no other 
				//node can push it again to queue before it is processed
				(*visited)[*it] = VISITED; 
			}
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
	g.BFS(0);

	system("pause");
	return 0;
}