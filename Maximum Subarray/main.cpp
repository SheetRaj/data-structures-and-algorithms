#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

	// Brute Force Solution
	// Space complexity is : O(1)
	// Time complexity is : O(n^3) 
	int maxSubarray(vector<int>& nums) {
		int n = nums.size();

		int maxSub = INT_MIN;

		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int sum = 0;

				for (int k = i; k <= j; k++) {
					sum += nums[k];
				}

				maxSub = max(maxSub, sum);
			}
		}

		return maxSub;
	}

	// Better Solution
	// Time complexity is : O(n^3)
	int maxSubarray_better(vector<int> nums) {
		int n = nums.size();
		int maxSub = INT_MIN;

		for (int i = 0; i < n; i++) {
			int sum = 0;

			for (int j = i; j < n; j++) {
				sum += nums[j];
				maxSub = max(maxSub, sum);
			}
		}

		return maxSub;
	}

	// Optimal Solution (Kadane,s Algorithms)
	/*
	* Kadane's algorithm, which is an optimal solution for finding the maximum subarray sum. Kadane's algorithm has a time complexity of O(n).
	*/
	int maxiSubarray(vector<int>& nums) {
		int n = nums.size();
		int maxSub = INT_MIN;

		int sum = 0;

		for (int i = 0; i < n; i++) {
			sum = max(nums[i], sum + nums[i]);
			maxSub = max(maxSub, sum);
		}

		return maxSub;
	}

	// Dynamic Programming 

	int maxSubarraySum(vector<int>& nums) {
		int n = nums.size();

		vector<int> dp(n, 0);

		dp[0] = nums[0];
		//int ans = dp[0];

		for (int i = 1; i < n; i++) {
			// The maximum subarray sum ending at index i is either the current element or the sum of the previous subarray ending at i-1 plus the current element.
			dp[i] = max(nums[i], dp[i - 1] + nums[i]);

			// ans = max(ans, dp[i]);
		}

		//return ans;
		return *max_element(dp.begin(), dp.end()); // The final result is the maximum value in the dp array
	}
};

int main() {
	Solution s;
	vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };

	int maxSub = s.maxSubarray(nums);
	cout <<"Brute Force Solution for maximum subarray: " << maxSub << endl;

	int maxSuba = s.maxSubarray_better(nums);
	cout << "Better Solution for maximum subarray: " << maxSuba << endl;

	int maxSubaa = s.maxiSubarray(nums);
	cout << "Kadane's algorithm solution: " << maxSubaa << endl;

	int dpReturn = s.maxSubarraySum(nums);
	cout << "Dynamic Programming: " << dpReturn << endl;

	return 0;
}
