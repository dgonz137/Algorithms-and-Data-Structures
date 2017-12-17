#include <iostream>
#include <vector>

using namespace std;

template <typename T> class Powerset {
private:
	vector<T> arr;
public:
	Powerset(const vector<T>& v) {
		arr.assign(v.begin(),v.end());
	}
	void printPowerset();
};

// O(n*2^n)
template <typename T>
void Powerset<T>::printPowerset() {
	size_t n = arr.size();
	size_t powerset_size = pow(2,n);
	
	for (int i = 0; i < powerset_size; i++) {
		cout << "{";
		for (int j = 0; j < n; j++) {
			if (i & (1<<j)) { // if the jth element in i is set
				cout << arr[j] << ",";
			}
		}
		cout << "}" << endl;
	}
}

int main() {
	
	vector<char> vowels = { 'a','e','i','o','u' };
	Powerset<char> powerset(vowels);

	powerset.printPowerset();

	//system("pause");
	return 0;
}