#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

using namespace std;

// Uses 1 index notation. The zeroth element in the array is not considered.
// Can be used for sum, substraction, xor, prod, etc. Cannot be used for min/max (use Segment Tree instead)
class FenwickTree {
private:
	vector<int> arr;
public:
	FenwickTree(const vector<int>&);
	int prefixSum(int);
	int rangeSum(int, int);
	void update(int, int);

};

FenwickTree::FenwickTree(const vector<int> & v) { // O(n)
	int size = v.size() + 1;
	arr = vector<int>(size);
	int i, j;
	// copy all elements from vector v to vector arr starting at index 1.
	for (i = 1; i < size; i++) {
		arr[i] = v[i-1];
	}
	for (i = 1; i < size; i++) {
		j = i + (i & -i); // (i & -i) = last bit set in the i-th index
		if (j < size) {
			arr[j] += arr[i];
		}
	}
}

// sum of the first n elements in the array
int FenwickTree::prefixSum(int n) {
	int sum = 0;
	if (n >= arr.size() || n <= 0) {
		throw out_of_range("Index cannot be larger than array size or less than or equal to zero. Use 1 index notation, that is, first element is at index 1, not 0");
	}

	while (n > 0) { // stop when it reaches the 0-th index
		sum += arr[n];
		n -= (n & -n); // substract the last bit set in index corresponding to the nth element
	}
	return sum;
}

// sum from the i-th element to the j-th element in the array (inclusive)
int FenwickTree::rangeSum(int i, int j) {
	if (i >= arr.size() || j >= arr.size() || i <= 0 || j <= 0) {
		throw out_of_range("Index cannot be larger than array size or less than or equal to zero. Use 1 index notation, that is, first element is at index 1, not 0");
	}
	return prefixSum(max(i,j)) - prefixSum(min(i,j)-1);
}

// update/replaces the k-th element value in the array for val
void FenwickTree::update(int k, int val) {
	if (k >= arr.size() || k <= 0) {
		throw out_of_range("Index cannot be larger than array size or less than or equal to zero. Use 1 index notation, that is, first element is at index 1, not 0");
	}
	int diff = val - arr[k];
	// remove diff accross the tree
	while (k < arr.size()) {
		arr[k] += diff;
		k += (k & -k);
	}
}

int main() {
	
	vector<int> arr = {1,7,3,0,5,8,3,2,6,2,1,1,4,5};
	FenwickTree fenwick(arr);
	try {
	cout << "Sum of the whole array = " << fenwick.prefixSum(arr.size()) << endl;
	cout << "Sum of first half of the array = " << fenwick.prefixSum(arr.size()/2) << endl; // sum of first 7 elements
	cout << "Sum of second half of the array = " << fenwick.rangeSum(arr.size()/2 +	1,arr.size()) << endl; // sum of last 7 elements
	cout << "Sum of middle 4 numbers in the array = " << fenwick.rangeSum(6,9) << endl; // sum of the middle 4 numbers
	
		cout << "Attempting to get the prefix sum of the 0th element" << endl;
		fenwick.prefixSum(0);
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	cout << "Printing rangeSum(i,i) of all elements in the array:" << endl;
	for (int i = 1; i <= arr.size(); i++) {
		cout << "rangeSum(" << i << "," << i << ") = " << fenwick.rangeSum(i, i) << endl;;
	}

	cout << "update the 7-th element to 10" << endl;
	fenwick.update(7,10); // update the 7-th element to 10

	try {
		cout << "Sum of the whole array = " << fenwick.prefixSum(arr.size()) << endl;
		cout << "Sum of first half of the array = " << fenwick.prefixSum(arr.size() / 2) << endl; // sum of first 7 elements
		cout << "Sum of second half of the array = " << fenwick.rangeSum(arr.size() / 2 + 1, arr.size()) << endl; // sum of last 7 elements
		cout << "Sum of middle 4 numbers in the array = " << fenwick.rangeSum(6, 9) << endl; // sum of the middle 4 numbers

		cout << "Attempting to get the prefix sum of the 0th element" << endl;
		fenwick.prefixSum(0);
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	cout << "Printing rangeSum(i,i) of all elements in the array:" << endl;
	for (int i = 1; i <= arr.size(); i++) {
		cout << "rangeSum(" << i << "," << i << ") = " << fenwick.rangeSum(i, i) << endl;;
	}

	//system("pause");

	return 0;
}
