#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int search(vector<int> nums, int target) {
		int left = 0;
		int right = nums.size() - 1;

		while (left <= right) {
			int mid = left + (right - left) / 2;

			if (nums[mid] == target) {
				return mid;
			}

			if (nums[left] <= nums[mid]) {
				if (target >= nums[left] && target < nums[mid]) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			else {
				if (target > nums[mid] && target <= nums[right]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}

		// Return -1 only when the search range is empty
		return -1;

	}
};

int main() {

	int n;
	cout << "Size of array: ";
	cin >> n;

	vector<int> arr(n);
	int target;
	cout << "Enter the target to search in a array: ";
	cin >> target;

	for (int i = 0; i < arr.size(); i++) {
		//arr.push_back(arr[i]);
		cin >> arr[i];
	}

	Solution sol;
	int find = sol.search(arr, target);
	cout << "Target element find on index: " << find << endl;

	return 0;
}

