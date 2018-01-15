#include <iostream>
#include <vector>
#include <exception>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int longestCommonSubsequence(const string &s1, const string &s2, vector<char> &res) {
	int n = s1.size();
	int m = s2.size();

	vector<vector<int>> T(m + 1, vector<int>(n + 1, 0)); // contains an additional col and row

														 // O(n*m)
	for (int row = 1; row <= m; row++) {
		for (int col = 1; col <= n; col++) {
			if (s1[col - 1] == s2[row - 1]) {
				T[row][col] = T[row - 1][col - 1] + 1;
			}
			else {
				T[row][col] = max(T[row - 1][col], T[row][col - 1]);
			}
		}
	}

	// populate res with longest common subsequence
	int index = T[m][n];
	int i = m, j = n; // i is the row and j the col
	res.resize(index--); // set the res arr to the size of longest common subseq
	while (index >= 0) {
		if (s1[j - 1] == s2[i - 1]) {
			res[index--] = s1[j - 1];
			i--; j--;
		}
		else if (T[i - 1][j] >= T[i][j - 1]) {
			i--;
		}
		else {
			j--;
		}
	}

	return T[m][n];
}



int longestCommonSubsequenceRec(const string &s1, int i, int n, const string &s2, int j, int m) {
	if (i == n || j == m) {
		return 0;
	}
	int len = 0;
	if (s1[i] == s2[j]) {
		len = longestCommonSubsequenceRec(s1, i + 1, n, s2, j + 1, m) + 1;
	}
	else {
		len = max(longestCommonSubsequenceRec(s1, i + 1, n, s2, j, m),
			longestCommonSubsequenceRec(s1, i, n, s2, j + 1, m));
	}
	return len;
}

int longestCommonSubsequenceRec(const string &s1, const string &s2) {
	return longestCommonSubsequenceRec(s1, 0, s1.size(), s2, 0, s2.size());
}

int main() {

	string s1 = "1000101011101";
	string s2 = "1011101010001";
	vector<char> seq;

	cout << "Length of longest common subsequence: " << longestCommonSubsequence(s1, s2, seq) << endl;
	cout << "Longest common subsequence: " << string(seq.begin(), seq.end()) << endl;
	cout << "Length of longest common subsequence (recursive): " << longestCommonSubsequenceRec(s1, s2) << endl;

	system("pause");
	return 0;
}