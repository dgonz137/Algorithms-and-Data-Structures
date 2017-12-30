#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define VISITED true
#define UNVISITED false

typedef vector<int> vi;
typedef vi::iterator itr;
typedef vector<vi> vvi;


class Graph {

private:
	int V; // number of vertices
	vector<int> *adj; // point to the first vector in the array of vectors
	vector<bool> *visited;
	queue<int> *q;
	vi bfs(int);

public:
	Graph(int V) {
		this->V = V;
		adj = new vector<int>[V]; // array (size V) of vectors
		visited = new vector<bool>(V); // all elements are initialized to false by default
	}
	void addEdge(int v, int w) {
		adj[v].push_back(w);
	}

	vi BFS(int);
	vvi connectedComponents();
};

vvi Graph::connectedComponents() {
	vvi cc;
	for (int i = 0; i < V; i++) {
		if ((*visited)[i] == UNVISITED) {
			cc.push_back(BFS(i));
		}
	}
	return cc;
}

vi Graph::BFS(int v) {
	q = new queue<int>;
	return bfs(v);
}

vi Graph::bfs(int u) {
	vi cc;
	q->push(u);
	(*visited)[u] = VISITED;
	while (!q->empty()) {
		auto item = q->front();
		cc.push_back(item);
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
	cout << endl;
	return cc;
}

int main() {
	Graph g(10);

	g.addEdge(0, 1);
	g.addEdge(0, 6);

	g.addEdge(1,1);
	g.addEdge(1,6);
	g.addEdge(1,0);

	g.addEdge(2, 5);
	g.addEdge(2,7);

	g.addEdge(3,0);
	g.addEdge(3,0);
	g.addEdge(3,6);
	g.addEdge(3,8);

	g.addEdge(4,6);

	g.addEdge(5,2);

	g.addEdge(6,6);

	g.addEdge(7,4);
	g.addEdge(7,5);

	g.addEdge(9,9);
	g.addEdge(9,9);
	g.addEdge(9,8);
	

	cout << "Following is Depth First Traversal (starting from vertex ) \n";
	g.connectedComponents();

	system("pause");
	return 0;
}