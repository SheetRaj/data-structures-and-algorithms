#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	bool search(vector<int> nums, int target) {
		sort(nums.begin(), nums.end());

		int left = 0;
		int right = nums.size() - 1;

		while (left <= right) {
			int mid = left + (right - left) / 2;

			if (target == nums[mid]) {
				return true;
			}

			if (nums[left] < nums[mid]) {
				if (nums[left] <= target && target < nums[mid]) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			else if (nums[right] > nums[mid]) {
				if (nums[mid] < target && target <= nums[right]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			else {
				right--;
			}
		}

		return false;

	}
};

int main() {

	vector<int> nums = { 2,5,6,0,0,1,2 };
	int target = 10;

	Solution sol;
	bool result = sol.search(nums, target);
	cout << "Index is present on array or not: " << result << endl;

	return 0;
}
