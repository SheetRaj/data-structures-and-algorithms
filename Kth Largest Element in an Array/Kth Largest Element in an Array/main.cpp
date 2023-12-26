#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int findKthLargest(vector<int> nums, int k) {

		// 1st Approach
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];

		// 2nd Approach

	}

	int findKthSmallest(vector<int> nums, int k) {
		sort(nums.begin(), nums.end());
		return nums[k - 1];
	}
};

int main() {
	vector<int> arr = { 7, 10, 4, 3, 20, 15 };
	int k = 3;

	Solution sol;
	int result = sol.findKthLargest(arr, k);
	cout << "Kth largest element is: " << result <<endl;

	int smallest = sol.findKthSmallest(arr, k);
	cout << "Kth Smallest element is: " << smallest << endl;

	return 0;
}
