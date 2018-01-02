#include <iostream>
#include <vector>
#include <exception>

using namespace std;

// tipically faster than QuickFindUF but still linear in the worst case. Tree can get too tall
class QuickUnionUF { // Lazy approach
	typedef vector<int> vi;
private :
	vi *id;
	int root(int);
public:
	QuickUnionUF(int n) {
		id = new vi(n);
		for (int i = 0; i < n; i++) {
			(*id)[i] = i;
		}
	}
	bool connected(int, int);
	void join(int, int);
};

bool QuickUnionUF::connected(int p, int q) { // O(n)
	if (p >= id->size() || q >= id->size() || p < 0 || q < 0) throw new out_of_range("Index out of range");
	return root(p) == root(q);
}

void QuickUnionUF::join(int p, int q) { // O(n)
	if (p >= id->size() || q >= id->size() || p < 0 || q < 0) throw new out_of_range("Index out of range");
	(*id)[root(p)] = root(q);
}

int QuickUnionUF::root(int x) { // O(n) 
	while (x != (*id)[x]) {
		x = (*id)[x];
	}
	return x;
}

int main() {
	QuickUnionUF uf(10);
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
