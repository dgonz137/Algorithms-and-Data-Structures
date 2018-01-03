#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

using namespace std;

template <typename T>
class SegmentTree {
private:
	vector<T> arr;
	size_t size;
	size_t original_size;
public:
	SegmentTree(const vector<T>&);
	void update(size_t, const T&);
	const T& minimun(size_t, size_t);
};


template <typename T>
SegmentTree<T>::SegmentTree(const vector<T>& v) : arr(0){
	//index 0 is unused
	size_t n = v.size();
	original_size = n;
	size = 2 * n;
	arr.resize(original_size);
	//copy v to the second half of the array
	arr.insert(arr.end(), v.begin(), v.end()); 
	for (int i = n - 1; i > 0; i--) {
		// parent is equal to min of its two children
		arr[i] = min(arr[2*i],arr[2*i+1]);
	}
}

template <typename T>
void SegmentTree<T>::update(size_t index, const T& val) {
	if (index >= original_size) {
		throw out_of_range("Not a valid index");
	}
	index += original_size; // index = index + (size of original array)
	arr[index] = val;
	//update tree
	while (index > 1) {
		index /= 2;
		arr[index] = min(arr[index*2],arr[index*2+1]);
	}
}

template <typename T>
const T& SegmentTree<T>::minimun(size_t from, size_t to) {
	if (from >= original_size || to >= original_size) {
		throw out_of_range("Index out of bounds");
	}
	if (from > to) {
		throw range_error("from cannot be bigger than to");
	}
	from += original_size;
	to += original_size;
	T m = INT_MAX;
	while (from < to) {
		if (from % 2 != 0) { // if from is right child
			m = min(m,arr[from]);
			from++;
		}
		if (to % 2 == 0) { // if to is a left child
			m = min(m,arr[to]);
			to--;
		}
		to /= 2;
		from /= 2;
	}
	m = (from == to ) ? min(m, arr[from]) : m;

	return m;
}



int main() {
	vector<int> v = {1,2,3,4,5,6,7,8};
	SegmentTree<int> st(v);
	for (int i = 0; i < v.size(); i++) {
		for (int j = v.size()-1; j >= i; j--) {
			
				cout << "min[" << i << "," << j << "] = " << st.minimun(i, j) << endl;
			
			
		}
	}
	
	system("pause");
	return 0;
}