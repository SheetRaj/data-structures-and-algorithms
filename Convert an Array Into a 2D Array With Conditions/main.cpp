/*
* Convert an Array Into a 2D Array With Conditions:
	The 2D array should contain only the elements of the array nums.
	Each row in the 2D array contains distinct integers.
	The number of rows in the 2D array should be minimal.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

	vector<vector<int>> findMatrix(vector<int>& nums) {
		vector<int> freq(nums.size() + 1);
		vector<vector<int>> ans;

		for (int num : nums) {
			if (freq[num] >= ans.size()) {
				ans.push_back({});
			}

			ans[freq[num]].push_back(num);
			freq[num]++;

		}
		return ans;
	}

	void printValue(const vector<vector<int>>& matrix) {
		for (const auto& row : matrix) {
			for (int num : row) {
				cout << num << " ";
			}
			cout << endl;
		}
	}
};


int main() {
	Solution s;
	vector<int> nums = { 1, 2, 3, 1, 2, 4, 5, 6 , 1, 4, 5, 1, 4, 5};
	vector<vector<int>> resultMatrxi = s.findMatrix(nums);
	s.printValue(resultMatrxi);

	return 0;
}