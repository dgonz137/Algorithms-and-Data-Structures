#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;

// O(n*n!)
template <typename T> 
vector<vector<T>> generateAllPermutations(const vector<T>& items) {
	typedef vector<T> vt;
	typedef vector<vt> vvt;

	vt arr(items.begin(),items.end());
	int n = arr.size();
	vvt res;

	sort(arr.begin(), arr.end());

	do {
		vt tmp(arr.begin(),arr.end());
		res.push_back(tmp);
	} while (next_permutation(arr.begin(),arr.end()));

	return res;
}

template <typename T>
void printAllPermutations(const vector<vector<T>>& perm) {
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
	vi v(num);

	for (int i = 0; i < num; i++) {
		v[i] = i;
	}
	
	vc vowels = {'o','a','e','i','u'};

	auto perm = generateAllPermutations(vowels);
	printAllPermutations(perm);
	//system("pause");
	return 0;
}