#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


class solution {
public:
	int matrixSum(vector<vector<int>> &nums) {

		int total = 0;
		// Sort each row in ascending order
		for (int i = 0; i < nums.size(); i++) {
			sort(nums[i].begin(), nums[i].end());
		}

		// Iterate through columns
		for (int i = 0; i < nums[0].size(); i++) {

			// Use nums[0].size() as the number of columns is consistent across rows
			int store = 0;

			// Iterate through rows to find the maximum value in the column
			for (int j = 0; j < nums.size(); j++) {
				store = max(nums[j][i], store);
			}

			total = total + store;
		}

		return total;

	}
};

int main() {

	vector<vector<int>> nums = { {7,2,1}, {6,4,2}, {6,5,3}, {3,2,1} };

	//Object
	solution sol;
	int result = sol.matrixSum(nums);

	cout <<"Sum in a Matrix: " << result << endl;
}