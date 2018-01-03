#include <iostream>
#include <vector>
#include <exception>

using namespace std;

// Modify QuickUnionUF to avoid tall trees
// Keep track of size of each tree (number of objects)
// Balance by linking root of smaller tree to root of larger tree

// The idea of path compression is that when looking at the root  of an element
// set the parent of that element to point to its grandparent. This will make the tree even flatter

class WeightedQuickUnionPathCompressionUF { // O(N + M log* N) ... log* (2^65536) = 5
	typedef vector<int> vi;
private :
	vi *id;
	int root(int);
	vi *size;
public:
	WeightedQuickUnionPathCompressionUF(int n) { // O(n)
		id = new vi(n);
		size = new vi(n,1); // initially all nodes in the tree are of size 1
		for (int i = 0; i < n; i++) {
			(*id)[i] = i;
		}
	}
	bool connected(int, int);
	void join(int, int);
};

bool WeightedQuickUnionPathCompressionUF::connected(int p, int q) { // O(log n)
	if (p >= id->size() || q >= id->size() || p < 0 || q < 0) throw new out_of_range("Index out of range");
	return root(p) == root(q);
}

void WeightedQuickUnionPathCompressionUF::join(int p, int q) { // O(log n)
	if (p >= id->size() || q >= id->size() || p < 0 || q < 0) throw new out_of_range("Index out of range");
	if (p == q) return;
	int p_root = root(p);
	int q_root = root(q);
	// Weighted condition
	if (size->at(p_root) < size->at(q_root)) {
		id->at(p_root) = id->at(q_root); // set smaller tree to taller tree
		size->at(q_root) += size->at(p_root);
	}
	else { // also set smaller tree to taller tree
		id->at(q_root) = id->at(p_root);
		size->at(p_root) += size->at(q_root);
	}
}

int WeightedQuickUnionPathCompressionUF::root(int x) { // O(log n) 
	while (x != id->at(x)) {
		// path compression
		id->at(x) = id->at(id->at(x)); // set 
		x = id->at(x);
	}
	return x;
}

int main() {
	WeightedQuickUnionPathCompressionUF uf(10);
	uf.join(4, 3);
	uf.join(3, 8);
	uf.join(6, 5);
	uf.join(9, 4);
	uf.join(2, 1);
	cout << uf.connected(8, 9) << endl; // true
	cout << uf.connected(5, 0) << endl; // false
	uf.join(5, 0);
	cout << uf.connected(5, 0) << endl; // true
	uf.join(7, 2);
	uf.join(6, 1);
	cout << uf.connected(6, 9) << endl; // false
	cout << uf.connected(7, 0) << endl; // true
	cout << uf.connected(0, 9) << endl; // false

	system("pause");

	return 0;
}
