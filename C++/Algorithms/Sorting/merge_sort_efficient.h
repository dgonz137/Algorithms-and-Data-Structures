void merge(vector<int> &arr, int low, int mid, int high, vector<int> &aux) {
	for (int i = low, j = mid + 1, k = low; i <= mid || j <= high; k++) {
		if (i > mid) {
			arr[k] = aux[j++];
		}
		else if (j > high) {
			arr[k] = aux[i++];
		}
		else if (aux[i] <= aux[j]) {
			arr[k] = aux[i++];
		}
		else {
			arr[k] = aux[j++];
		}
	}
}

void mergeSort(vector<int> &arr, int low, int high, vector<int> &aux) {
	if (low >= high) {
		return;
	}
	int mid = (low + high) / 2;
	mergeSort(aux, low, mid, arr);
	mergeSort(aux, mid + 1, high, arr);
	merge(arr, low, mid, high, aux);
}

void mergeSort(vector<int> &arr) {
	int n = arr.size();
	vector<int> aux(arr.begin(), arr.end());
	mergeSort(arr, 0, n-1, aux);
}