#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;

// k is the number of elements that will be chosen out of the list
template <typename T> 
vector<vector<T>> generateAllCombinations(const vector<T>& arr, size_t k) {
	typedef vector<T> vt;
	typedef vector<vt> vvt;

	vt list(arr.begin(),arr.end());
	size_t n = list.size();
	vvt res;
	if (k > n) k = n; // you can't chose more than from what is there. Maybe throw exception instead?
	vb bitmask(k,1); //set the first k bits are set to 1
	bitmask.resize(n,0); // set the lower n-k bits to 0

	sort(list.begin(), list.end()); // sort in ascending order

	do {
		vt tmp;
		for (size_t i = 0; i < n; i++) {
			if (bitmask[i]) {
				tmp.push_back(list[i]);
			}
		}
		res.push_back(tmp);
	} while (prev_permutation(bitmask.begin(),bitmask.end()));

	return res;
}

template <typename T>
void printAllCombinations(const vector<vector<T>>& perm) {
	for (const auto& arr: perm) {
		cout << "{";
		for (const auto& val : arr) {
			cout << val << ",";
		}
		cout << "}" << endl;
	}
}



int main() {

	const int num = 5;
	const int K = 3;
	vi v(num);

	for (int i = 0; i < num; i++) {
		v[i] = i;
	}
	
	vc vowels = {'o','a','e','i','u'};

	auto perm = generateAllCombinations(vowels,K);
	printAllCombinations(perm);
	//system("pause");
	return 0;
}