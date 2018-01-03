#include <iostream>
#include <vector>
#include <exception>
#include <unordered_map>

using namespace std;

template <typename T> class DisjointSet {
	typedef long long ll;
private:
	struct Node {
		Node() {}
		Node(const T& x) : rank(0), data(x), parent(this) {}
		ll rank;
		T data;
		Node *parent;
	};
	unordered_map<T, Node*> map;

	Node* findRoot(Node*);
public:
	
	DisjointSet(){}
	~DisjointSet();
	void makeSet(const T&);
	void join(const T&, const T&);
	bool connected(const T&, const T&);
	void printTreeAddresses();
};

template <typename T>
void DisjointSet<T>::makeSet(const T& data) {
	Node *node =  new Node(data);
	map[data] = node;
}

template <typename T>
void DisjointSet<T>::join(const T& d1, const T& d2) {
	if (!map.count(d1) || !map.count(d2)) { // if either d1 or d2 hasn't been created yet
		throw new domain_error("Data has not been set. Try calling makeSet(data) before attempting to use it.");
	}

	Node* node1 = map[d1];
	Node* node2 = map[d2];

	Node *root1 = findRoot(node1);
	Node *root2 = findRoot(node2);

	if (root1 == root2) { // if they are already joined, no need to join
		return;
	}

	if (root1->rank > root2->rank) {
		root2->parent = root1;
	}
	else if (root1->rank == root2->rank) {
		root2->parent = root1;
		(root1->rank)++;
	}
	else { // node1->rank < node2->rank
		root1->parent = root2;
	}
}

template <typename T>
typename DisjointSet<T>::Node* DisjointSet<T>::findRoot(typename DisjointSet<T>::Node* node){
	if (node == node->parent) { // if this is the root element of a specific subtree
		return node;
	}
	// while recursively traversing the subtree upwards, make all the nodes along the way point to the root. This will compress/flat the tree
	node->parent = findRoot(node->parent); 
	return node->parent;
}

template <typename T>
bool DisjointSet<T>::connected(const T& d1, const T& d2) {
	if (!map.count(d1) || !map.count(d2)) { // if either d1 or d2 hasn't been created yet
		throw new domain_error("Data has not been set. Try calling makeSet(data) before attempting to use it.");
	}

	Node* node1 = map[d1];
	Node* node2 = map[d2];
	return findRoot(node1) == findRoot(node2);
}

template <typename T>
void DisjointSet<T>::printTreeAddresses() {
	unordered_map<T, Node*>::iterator itr;
	for (itr = map.begin(); itr != map.end(); itr++) {
		cout << "Node: " << itr->first << " addr: " << itr->second << "  paddr: " << itr->second->parent << endl;
	}
	cout << endl << endl;
}

template <typename T>
DisjointSet<T>::~DisjointSet() {
	for (auto itr = map.begin(); itr != map.end(); itr++) {
		delete itr->second;
	}
}

int main() {
	
	DisjointSet<int> ds;
	for (int i = 1; i <= 7; i++) {
		ds.makeSet(i);
	}

	ds.printTreeAddresses();
	cout << ds.connected(2,6) << endl; //false
	cout << "Join 2 & 6" << endl;
	ds.join(2,6);
	cout << ds.connected(2, 6) << endl; //true
	cout << ds.connected(1, 6) << endl; //false
	ds.printTreeAddresses();
	cout << "Join 6 & 1" << endl;
	ds.join(6,1);
	ds.printTreeAddresses();
	cout << ds.connected(1, 6) << endl; //true
	cout << "Join 3 & 4 twice" << endl;
	ds.join(3, 4);
	ds.join(4, 3);
	ds.printTreeAddresses();
	cout << "Join 7 & 5" << endl;
	ds.join(7, 5);
	ds.printTreeAddresses();
	cout << "Join 4 & 5" << endl;
	ds.join(4, 5);
	ds.printTreeAddresses();
	cout << "Is 1 and 5 connected? Expected answer 0: actual answer: " << ds.connected(1,5) << endl;
	cout << "Reprint tree to check if path is actually compressed." << endl;
	ds.printTreeAddresses();
	cout << "Join 2 & 3. Here 2 is expected to point to 3 because of rank (weighted)." << endl;
	ds.join(2,3);
	ds.printTreeAddresses();

	//system("pause");

	return 0;
}
