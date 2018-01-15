#include <iostream>
#include <vector>
#include <exception>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;


int longestPalindromicSubsequenceRec(const string &s, int i, int j) {
	if (i == j) {
		return 1;
	}
	else if (i > j) {
		return 0;
	}

	int len = 0;
	if (s[i] == s[j]) {
		len = longestPalindromicSubsequenceRec(s, i + 1, j - 1) + 2;
	}
	else {
		len = max(longestPalindromicSubsequenceRec(s, i + 1, j),
			longestPalindromicSubsequenceRec(s, i, j - 1));
	}

	return len;
}

int longestPalindromicSubsequence(const string& s, int n) {
	vector<vector<int>> memo(n, vector<int>(n,0));
	int len = 1;
	for(int i = 0; i < n; i++) {
		memo[i][i] = len;
	}
	for (len = len + 1; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;
			if (s[i] == s[j]) {
				memo[i][j] = memo[i + 1][j - 1] + 2;
			}
			else {
				memo[i][j] = max(memo[i][j-1], memo[i+1][j]);
			}
		}
	}
	
	return memo[0][n-1];
}

int longestPalindromicSubsequence(const string& s) {
	return longestPalindromicSubsequence(s, s.size());
}


int longestPalindromicSubsequenceRec(const string &s) {
	int n = s.size();
	return longestPalindromicSubsequenceRec(s, 0, n - 1);
}

int main() {

	string s1 = "1000101011101";

	cout << "Length of Longest palindrome sequence (recursive): " << longestPalindromicSubsequenceRec(s1) << endl;
	cout << "Length of Longest palindrome sequence: " << longestPalindromicSubsequence(s1) << endl;

	//system("pause");
	return 0;
}