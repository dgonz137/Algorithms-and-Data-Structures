#include <iostream>
#include <vector>
#include <exception>

using namespace std;

// Modify QuickUnionUF to avoid tall trees
// Keep track of size of each tree (number of objects)
// Balance by linking root of smaller tree to root of larger tree

class WeightedQuickUnionUF { 
	typedef vector<int> vi;
private :
	vi *id;
	int root(int);
	vi *size;
public:
	WeightedQuickUnionUF(int n) { // O(n)
		id = new vi(n);
		size = new vi(n,1); // initially all nodes in the tree are of size 1
		for (int i = 0; i < n; i++) {
			(*id)[i] = i;
		}
	}
	bool connected(int, int);
	void join(int, int);
};

bool WeightedQuickUnionUF::connected(int p, int q) { // O(log n)
	if (p >= id->size() || q >= id->size() || p < 0 || q < 0) throw new out_of_range("Index out of range");
	return root(p) == root(q);
}

void WeightedQuickUnionUF::join(int p, int q) { // O(log n)
	if (p >= id->size() || q >= id->size() || p < 0 || q < 0) throw new out_of_range("Index out of range");
	if (p == q) return;
	int p_root = root(p);
	int q_root = root(q);
	if (size->at(p_root) < size->at(q_root)) {
		id->at(p_root) = id->at(q_root); // set smaller tree to taller tree
		size->at(q_root) += size->at(p_root);
	}
	else { // also set smaller tree to taller tree
		id->at(q_root) = id->at(p_root);
		size->at(p_root) += size->at(q_root);
	}
}

int WeightedQuickUnionUF::root(int x) { // O(log n) 
	while (x != (*id)[x]) {
		x = (*id)[x];
	}
	return x;
}

int main() {
	WeightedQuickUnionUF uf(10);
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

	//system("pause");

	return 0;
}
