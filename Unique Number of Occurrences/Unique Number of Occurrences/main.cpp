#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;


class Solution {
public:
	bool uniqueNumberOfOccurrences(vector<int> arr) {

		unordered_map<int, int> map;
		for (auto nums : arr) {
			map[nums]++;
		}

		unordered_set<int> set;

		for (auto it : map) {
			int feq = it.second;
			set.insert(feq);
		}

		return set.size() == map.size();
	}
};
int main() {
	vector<int> arr = { 1,2,2,1,1,3,3};
	Solution sol;
	bool result = sol.uniqueNumberOfOccurrences(arr);
	cout << result;

	return 0;
}