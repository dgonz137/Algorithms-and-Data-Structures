#include <iostream>
#include <vector>
using namespace std;

template <typename T> class InsertionSort{
private:
	vector<T> items;
	int size;
public:
	
	InsertionSort(const vector<T>& elems) {
		items.assign(elems.begin(),elems.end());
		size = items.size();
	}

	void sort() { // increasing order
		for (int i = 1; i < size; i++) {
			for (int j = i; j > 0; j--) {
				if (items[j] < items[j-1]) { //swap
					swap(items[j],items[j-1]);
				}
				else {
					break;
				}
			}
		}
	}

	void print() {
		for (size_t i = 0; i < items.size(); i++) {
			cout << items[i] << endl;
		}
		cout << endl;
	}

};

int main() {
	vector<int> v = { 5029, -4427, 3696, 4590, 4138, -8315, 1140, -9064, -6519, 677, 7727, 9428, 1100, 8194, 8585, -8672, 900, -8256, 387, 5095, -9586, -5522, -6804, 9717, -2482, 9382, 6178, 5592, -6658, 5993, 6818, 2623, 7395, -7157, -7458, -8116, -1483, -5871, -2925, -3122, -6121, -7276, 9109, 2796, 7328, 3851, 8465, 3100, -1263, 2412, 7481, -6522, -311, -7120, -9702, 8724, -3754, 5130, 3220, -1948, -9931, -277, 9864, 1327, -8325, -7853, 7686, -4739, 4521, 4922, -266, -1221, -7547, -2774, -2819, -7766, -4401, 1201, 2195, 2384
		,-4114, 9289, 8045, -8949, -3704, -3146, -8874, -7942, 9562, -8970, 4136, -5351, -6197, -6978, 3812, -6441, -1123, 2107, 6272, 3335, 604, 660, 6174, 6862, -5794, 7180, 34, 1670, 5279, 8627, 9374, 1800, 2166, 378, -4656, 8767, -3973, 9032, -7728, 6126, -4320, -4583, 6265, -6915, 4064, 5496, -104, 2661, 5708, -6800, -8741, 3773, -7959, -171, -8894, 3192, 6281, 4186, -3248, 4608, 7229, -6872, 3545, -6126, -6799, 9090, -8355, -7319, 1832, -8735, -8189, 9960, -5925, 7225, 6153, -7937, -4894, -5146, 3695, -3535
		,6106, -2793, 5851, -5685, -420, 1773, 7119, -3691, 5065, -1914, 3513, -2699, -6081, 1461, 1049, 400, 2660, -7385, 1496, -3785, 1671, 4172, 6237, -8971, -6040, -1895, 923, 7227, -2718, 4046, -6735, 8918, -1765, 2926, 515, -4525, 4921, 4803, 8232, -1095, 5082, -4104, -7761, -9818, 2664, -795, 2112, 6416, 7751, -2784, 4339, 1364, 6897, 621, 7678, -952, 6934, 6921, 4542, 4428, 596, 5546, -1191, -398, -7150, -4433, -915, 5962, -4234, 4756, -7218, -3396, -1899, -359, -6074, 1674, 3783, 4583, -456, -9746
		,2791, -909, -5534, -2793, -3456, 3742, -4790, 7203, -4334, -8836, -8065, 1521, -6654, -2277, -620, 3318, 7493, -7017, 2257, 7506, 665, -1363, 9756, 2814, -3320, 7253, 6326, -2410, 9278, -3723, -7154, 1407, -3438, -8518, -3021, -7451, -2140, 6054, -5765, -6801, -2925, -937, 2434, -9700, 7578, 7366, 2414, 627, 6105, -2553, -9380, -5020, -1998, 9675, -1316, 9061, 8737, -8086, 8009, 8571, 4433, 9980, 7951, -3157, -6508, -3715, -2002, -9734, -5590, -1592, 8036, -3465, -6242, -8597, 5894, -7856, -6972, -2322, -9326, -6445
		,-9363, -552, 1437, 4411, 8601, -5173, -320, 1190, -1275, -7917, -7319, -768, 5686, 2276, -548, -2497, 6058, 7726, -3598, 9206, -2066, -9253, -489, 6186, -3303, 9214, -1215, -9377, 4873, -5193, 7389, 1567, 8401, -5227, -6014, -2157, 2519, 2490, -5175, -6439, -2877, 5017, 8142, 6520, -297, -2427, -8659, -2359, 7983, 8805, -7387, -8470, -8554, 5634, 9025, -2271, 9034, 5671, 1481, 4945, 8404, 4123, 5413, 2418, -7701, -8006, -5382, -645, 3579, 1036, 7732, 4732, 2928, -7896, -4677, -8786, -9251, -7602, -3138
		,-2968, -1404, -8029, -7254, -3751, -370, 8118, 1524, -4952, 7722, 8998, 4041, -5109, 2711, 4567, -877, 6812, 774, 9235, 2827, 7083, -2826, -1854, 736, 9466, 7715, 1437, -89, 3309, -5735, 554, 2129, 9484, 5935, -6465, 1179, 8185, -5052, 389, -5888, -115, 9187, 7469, 6731, 9389, 7655, 8199, -7178, 8755, -8188, 2401, 1846, 2170, 3823, 3840, -878, 909, 7172, -47, 3371, 8661, 4880, 2409, 4623, -5681, -836, 6001, 7699, 7402, 8261, -7668, -4971, -9279, -51, 1308, 5981, -8633, -8712, 8320, 5153
		,3949, -5657, 8950, 7376, -2865, -7874, 496, -7387, -3018, -4048, -1078, 2258, -9350, 3013, 5207, -306, -2456, 3229, 7156, -8436, -6337, 3293, 2647, 665, 8407, 8615, -6377, -9442, -7268, 8178, -1320, -3728, 9831, 2017, 3033, -5554, 1955, -3069, -6362, 9000, -1021, 9542, 1725, -8175, -9830, -10000, -4670, -3569, 315, -5001, 5304, -3172, 531, -9263, -240, 550, -7714, -8322, 623, -6646, -4977, -2338, -3776, 9188, -919, -7739, -6619, -4725, 5936, 9635, -6321, -6142, 905, -2950, 9236, 7216, 7576, 2853, 2114, -9305
		,-2644, -1843, -3188, -6502, 4627, 3007, -3674, 7642, -5213, -9021, 2735, 3858, 5514, -7073, 617, -485, -8714, 117, -9783, -658, -9051, -3562, 2124, 1674, 1398, -5421, 5203, 6685, -1948, 1012, 3700, 6347, -2989, 9415, 3927, 6038, -4381, 6127, -1782, 6317, 5058, -9425, 4446, -749, -7167, 9935, -3496, 4717, 666, 2878, 8915, 520, -5579, -6979, -2640, -4557, -4577, -4027, -7091, 1939, -1657, -8761, 8644, 4352, -6895, -5174, -611, 1337, -7992, -2864, 6777, -6127, -7028, -8689, 28, 4108, -9060, -7337, -1888, 5582
		,-1468, 6994, -8677, 2325, 5048, -9485, 4138, 4727, -3425, 1788, -2008, 9928, 8092, -8618, 4221, -2501, -6985, -8629, -3251, 6925, 5914, -4005, -4263, 4323, 4541, -9540, 5884, -1391, -6641, -7119, -6676, 1109, 1569, -8458, 5446, -8419, 8904, 1768, -5460, 5995, 5718, -7910, 9160, 2316, -9019, 3360, -465, -1057, 6483, -1367, 4318, 9438, 2908, -2134, -3577, 8751, 9442, -9710, -3706, 1548, -4008, 6840, -4541, -2707, -8672, 7565, 9886, 2584, -2611, -6423, 7597, 3149, -7898, 9014, -9828, 2521, 7236, -4807, -4174, 4704 };
	InsertionSort<int> list = InsertionSort<int>(v);
	list.print();
	list.sort();
	cout << endl << endl;
	list.print();

	//system("pause");
	return 0;
}