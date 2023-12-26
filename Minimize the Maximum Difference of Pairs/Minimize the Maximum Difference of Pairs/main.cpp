#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minimizeMax(vector<int> nums, int p) {
		sort(nums.begin(), nums.end());

		int n = nums.size();

		int left = 0;
		int right = nums[n - 1] - nums[0];

		while (left < right) {
			int mid = (left + right) / 2;
			int j = 0;

			for (int i = 1; i < n && j < p; i++) {
				if (nums[i] - nums[i - 1] <= mid) {
					j++;
					i++;
				}
			}

			if (j >= p) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
};

int main() {
	Solution sol;
	vector<int> nums = { 3,4,2,3,2,1,2 };
	int p = 3;

	int result = sol.minimizeMax(nums, p);
	cout << " Minimize the Maximum Difference of Pairs: " << result << endl;

	return 0;
}