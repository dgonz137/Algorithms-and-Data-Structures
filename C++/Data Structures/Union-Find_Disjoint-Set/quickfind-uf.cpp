#include <iostream>
#include <vector>
#include <exception>

using namespace std;

//Uses a 1D vector array. Usually too slow for huge sets of data. There exist better implementations

class QuickFindUF { //Quick Find - Union Find
	typedef vector<int> vi;
private:
	vi *id;
public:
	QuickFindUF(int n) { // O(n)
		id = new vi(n);
		for (int i = 0; i < n; i++) {
			(*id)[i] = i;
		}
	}
	bool connected(int,int);
	void join(int, int);
};

bool QuickFindUF::connected(int p, int q) { // O(1)
	if (p >= id->size() || q >= id->size() || p < 0 || q < 0) throw new out_of_range("Index out of range");
	return (*id)[p] == (*id)[q];
}

void QuickFindUF::join(int p, int q) { // O(n)
	if (p >= id->size() || q >= id->size() || p < 0 || q < 0) throw new out_of_range("Index out of range");
	int pid = (*id)[p];
	int qid = (*id)[q];
	// set all pids to qids
	for (int i = 0; i < id->size(); i++) { 
		if (pid == (*id)[i]) {
			(*id)[i] = qid;
		}
	}
}

int main() {
	QuickFindUF uf(10);
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
