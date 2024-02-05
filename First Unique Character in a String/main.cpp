#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> count(26);

		for (const char c : s) {
			++count[c - 'a'];
		}

		for (int i = 0; i < s.size(); i++) {
			if (count[s[i] - 'a'] == 1) {
				return i;
			}
		}
		return -1;
	}

	// Using Hash table

	int uniqChar(string s) {
		vector<int> count(256, -1);

		// Store the index of the first occurrence of each character
		for (int i = 0; i < s.size(); i++) {
			char ch = s[i];

			if (count[ch] == -1) {
				count[ch] = i;
			}
			else {
				count[ch] = -2;
			}
		}

		int minIndex = s.size();

		// Find the minimum index of non-repeating characters
		for (int i : count) {
			if (i >= 0 && i < minIndex) {
				minIndex = i;
			}
		}
		// If no non-repeating character is found, return -1
		return minIndex == s.size() ? -1 : minIndex;
	}

};

int main() {
	string s = "loveleetcode";
	Solution obj;
	int result = obj.firstUniqChar(s);
	int sol = obj.uniqChar(s);
	cout << "First Unique Character in a String: " << result << endl;
	cout << "First Unique Character in a String using hash table: " << sol << endl;
	return 0;
}