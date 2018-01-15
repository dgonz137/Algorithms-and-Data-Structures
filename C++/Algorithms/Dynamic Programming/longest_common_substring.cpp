#include <iostream>
#include <vector>
#include <exception>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int longestCommonSubstring(const string &s1, const string &s2, vector<char> &res) {
	int n = s1.size();
	int m = s2.size();
	int max = 0;
	int max_col = 0, max_row = 0;

	vector<vector<int>> T(m + 1, vector<int>(n + 1, 0)); // contains an additional col and row

														 // O(n*m)
	for (int row = 1; row <= m; row++) {
		for (int col = 1; col <= n; col++) {
			if (s1[col - 1] == s2[row - 1]) {
				T[row][col] = T[row - 1][col - 1] + 1;
				if (T[row][col] > max) {
					max = T[row][col];
					max_row = row;
					max_col = col;
				}
			}
		}
	}

	// populate res with longest common substring
	res.resize(max); // set the res arr to the size of longest common subseq
	for (int k = max - 1, i = max_col - 1; k >= 0; k--, i--) {
		res[k] = s1[i];
	}

	return max;
}

int longestCommonSubstringRec(const string &s1, int i, int n, const string &s2, int j, int m, bool equal) {
	if (i == n || j == m) {
		return 0;
	}
	int len = 0;
	if (s1[i] == s2[j]) {
		len = longestCommonSubstringRec(s1, i + 1, n, s2, j + 1, m, true) + 1;
	}
	else if(!equal) {
		len = max(longestCommonSubstringRec(s1, i + 1, n, s2, j, m, false),
			longestCommonSubstringRec(s1, i, n, s2, j + 1, m, false));
	}
	return len;
}

int longestCommonSubstringRec(const string &s1, const string &s2) {
	return longestCommonSubstringRec(s1, 0, s1.size(), s2, 0, s2.size(), false);
}

int main() {

	string s1 = "abcdaf";
	string s2 = "zbcdf";
	vector<char> seq;

	cout << "Length of longest common subsequence: " << longestCommonSubstring(s1, s2, seq) << endl;
	cout << "Longest common subsequence: " << string(seq.begin(), seq.end()) << endl;
	cout << "Length of longest common subsequence (recursive): " << longestCommonSubstringRec(s1, s2) << endl;

	//system("pause");
	return 0;
}