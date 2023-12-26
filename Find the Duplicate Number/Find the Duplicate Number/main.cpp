#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int duplicateNumber(vector<int> &arr) {
		unordered_map<int, int> map;

		for (int num : arr) {
			if (map.find(num) != map.end()) {
				return num;
			}
			map[num] = 1;
		}
		return -1;
	}
};

int main() {
	vector<int> arr = { 1, 3, 4, 2, 2 };
	Solution sol;
	int result = sol.duplicateNumber(arr);
	cout << "Duplicate element in the array is: " << result;

	return 0;
}