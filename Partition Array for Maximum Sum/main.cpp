#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

	// Using Dp
	int maxSumAfterPartition(vector<int>& arr, int k) {
		int n = arr.size();
		vector<int> dp(n + 1);

		for (int i = 1; i <= n; i++) {
			int maxSum = INT_MIN;

			for (int j = 1; j <= min(i, k); j++) {
				maxSum = max(maxSum, arr[i - j]);
				dp[i] = max(dp[i], dp[i - j] + maxSum * j);
			}
		}

		return dp[n];
	}

};

int main() {
	Solution s;
	int k = 3;
	vector<int> arr{ 1,15,7,9,2,5,10 };
	int result = s.maxSumAfterPartition(arr, k);

	cout << "Partition Array for Maximum Sum: " << result;

	return 0;
}