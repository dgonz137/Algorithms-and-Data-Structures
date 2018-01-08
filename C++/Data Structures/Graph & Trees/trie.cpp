#include <iostream>
#include <vector>
#include <exception>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Trie {
private:
	struct TrieNode {
		unordered_map<char, TrieNode*> children;
		bool endOfWord;
		TrieNode() {
			children = unordered_map<char, TrieNode*>();
			endOfWord = false;
		}
	};
	TrieNode *root;

	void insertRec(TrieNode*, string&, int);
	bool searchRec(TrieNode*, string&, int);
	bool deleteRec(TrieNode*, string&, int);
	void deleteTrie(TrieNode*);
	int countWithPrefix(TrieNode*);
public:
	Trie() {
		root = new TrieNode();
	}
	~Trie();
	void insert(string);
	void insertRec(string);
	bool search(string);
	bool searchRec(string);
	void deleteRec(string);
	bool searchPrefix(string);
	int countWithPrefix(string);
};

void Trie::insert(string s) {
	TrieNode * curr = root;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		// if current TrieNode does not contain letter in the string, add it to the map 
		if (!curr->children.count(c)) { 
			curr->children[c] = new TrieNode();
		}
		curr = curr->children[c]; // current TrieNode becomes the new TrieNode created.
	}
	// current TrieNode points to the last TrieNode added. This serves as a reference that a string/word ends.
	curr->endOfWord = true;
}

void Trie::insertRec(string s){
	insertRec(root, s, 0);
}

void Trie::insertRec(TrieNode* curr, string &s, int i) {
	if (i == s.size()) {
		curr->endOfWord = true;
		return;
	}
	char &c = s[i];
	// if current TrieNode does not contain letter in the string, add it to the map 
	if (!curr->children.count(c)) {
		curr->children[c] = new TrieNode();
	}
	curr = curr->children[c]; // current TrieNode becomes the new TrieNode created.

	insertRec(curr, s, i+1);
}

/* Looks for an entire word*/
bool Trie::search(string s) {
	TrieNode *curr = root;
	for (int i = 0; i < s.size(); i++) {
		char &c = s[i];
		if (!curr->children.count(c)) {
			return false;
		}
		curr = curr->children[c];
	}
	return curr->endOfWord; // only if the end of the word is set (true) return true, o.w. false
}

bool Trie::searchRec(string s) {
	return searchRec(root, s, 0);
}

bool Trie::searchRec(TrieNode* curr, string &s, int i) {
	if (i == s.size()) {
		return curr->endOfWord;
	}
	char &c = s[i];
	if (!curr->children.count(c)) {
		return false;
	}
	return searchRec(curr->children[c], s, i+1);
}

void Trie::deleteRec(string s) {
	deleteRec(root, s, 0);
}

bool Trie::deleteRec(TrieNode *curr, string &s, int i) {
	if (i == s.size()) { // last TrieNode is reached
		if (!curr->endOfWord) { // check if TrieNode reached marks the end of the word
			return false; 
		}
		curr->endOfWord = false;
		// returns true iff map is empty. Signals the parent to delete child TrieNode
		return curr->children.size() == 0; // delete condition
	}

	char &c = s[i];
	if (!curr->children.count(c)) { // no char found in the sequence
		return false;
	}
	bool deleteChild = deleteRec(curr->children[c], s, i+1);

	if (deleteChild) {
		// deallocate pointer memory
		delete curr->children[c];
		//remove character from map
		curr->children.erase(c);
		return curr->children.size() == 0;
	}

	//Return false because we do not want to delete parent TrieNode unless it meets the condition
	return false;
}

// Traverse the whole Trie and deallocate memory
Trie::~Trie() {
	deleteTrie(root);
}

void Trie::deleteTrie(TrieNode *curr) {
	for (unordered_map<char, TrieNode*>::iterator itr = curr->children.begin(); itr != curr->children.end(); itr++) {
		deleteTrie(itr->second);
	}
	delete curr;
}

bool Trie::searchPrefix(string s) {
	TrieNode *curr = root;
	for (int i = 0; i < s.size(); i++) {
		char &c = s[i];
		if (!curr->children.count(c)) {
			return false;
		}
		curr = curr->children[c];
	}
	return true;
}

int Trie::countWithPrefix(string s) {
	TrieNode *curr = root;
	// check first if Trie contains prefix s
	for (int i = 0; i < s.size(); i++) {
		char &c = s[i];
		if (!curr->children.count(c)) { // if map does not contain character c
			return 0; // Trie does not contain prefix s
		}
		curr = curr->children[c]; // traverse Trie
	}
	return countWithPrefix(curr);
}

// Traverse all paths and count the number of endOfWord = true
int Trie::countWithPrefix(TrieNode* curr) {
	int sum = 0;
	if (curr->endOfWord) {
		sum++;
	}
	for (unordered_map<char, TrieNode*>::iterator itr = curr->children.begin(); itr != curr->children.end(); itr++) {
		sum += countWithPrefix(itr->second);
	}
	return sum;
}



int main() {
	
	Trie trie;
	trie.insertRec("abc");
	trie.insertRec("abgl");
	trie.insertRec("cdf");
	trie.insertRec("abcd");
	trie.insertRec("lmn");

	//cout << trie.searchRec("abc") << endl; // true
	//cout << trie.searchRec("abcd") << endl; // true
	//cout << trie.searchRec("abcdl") << endl; // false
	//cout << trie.searchRec("ab") << endl; // false
	//cout << trie.searchRec("lmnn") << endl; // false
	//cout << trie.searchRec("lmn") << endl; // true
	//cout << trie.searchRec("lm") << endl; // false

	cout << "Number of words containing substring 'a': " << trie.countWithPrefix("a") << endl;
	cout << "Number of words containing substring 'ab': " << trie.countWithPrefix("ab") << endl;
	cout << "Number of words containing substring 'abc': " << trie.countWithPrefix("abc") << endl;
	cout << "Number of words containing substring 'abcd': " << trie.countWithPrefix("abcd") << endl;
	cout << "Number of words containing substring 'abcl': " << trie.countWithPrefix("abcl") << endl;
	cout << "Number of words containing substring 'b': " << trie.countWithPrefix("b") << endl;
	cout << "Number of words containing substring 'abgl': " << trie.countWithPrefix("abgl") << endl;

	cout << trie.searchPrefix("a") << endl; // true
	cout << trie.searchPrefix("ab") << endl; // true
	cout << trie.searchPrefix("abc") << endl; // true
	cout << trie.searchPrefix("abcd") << endl; // true
	cout << trie.searchPrefix("abcdl") << endl; // false
	cout << trie.searchPrefix("lmn") << endl; // true
	cout << trie.searchPrefix("lm") << endl; // true
	cout << trie.searchPrefix("alm") << endl; // false
	cout << trie.searchPrefix("abcd") << endl; // true
	cout << trie.searchPrefix("abg") << endl; // true
	trie.deleteRec("abgl");
	cout << trie.searchPrefix("abg") << endl; // false


	trie.deleteRec("abc");
	trie.deleteRec("abgl");
	trie.deleteRec("abcd");
	trie.deleteRec("lmn");
	trie.deleteRec("cdf");

	//system("pause");

	return 0;
}
