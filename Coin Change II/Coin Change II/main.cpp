#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int change(int amount, vector<int> coins) {
		vector<int> ans(amount + 1, 0);
		ans[0] = 1;

		for (int coin : coins) {
			for (int i = coin; i <= amount; i++) {
				ans[i] += ans[i - coin];
			}
		}

		return ans[amount];
	}
};

int main() {
	vector<int> coin = { 1, 2, 5 };
	int amount = 5;

	Solution sol;
	int result = sol.change(amount, coin);
	cout << "there are " << result << " ways to make up the amount.";

	return 0;
}