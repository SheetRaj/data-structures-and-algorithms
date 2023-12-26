#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	void moveAllNegative(vector<int> &arr) {
		int left = 0;
		int right = arr.size() - 1;

		while (left <= right) {
			if (arr[left] < 0) {
				left++;
			}
			else if (arr[right] >= 0) {
				right--;
			}
			else {
				swap(arr[left], arr[right]);
			}
		}

	}
};

int main() {

	vector<int> arr = { 1, -1, 3, 2, -7, -5, 11, 6 };
	Solution sol;
	sol.moveAllNegative(arr);

	cout << "Negative element to the left side of an array: ";

	for (int i = 0; i < arr.size() - 1; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "Negative element move to the end: ";

	for (int i = arr.size() - 1; i >= 0; i--) {
		cout << arr[i] << " ";
	}

	return 0;
}