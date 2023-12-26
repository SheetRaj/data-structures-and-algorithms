#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

	vector<int> sortArray(vector<int> arr) {
		sort(arr.begin(), arr.end());
		return arr;
	}


};

int main() {

	vector<int> arr = { 4, 5, 2, 5, 7, 1, 8, 9, 0, 4, 9 };
	Solution sol;
	vector<int> result = sol.sortArray(arr);
	cout << "Sorted Array is : ";
	for (int num : result) {
		std::cout << num << " ";
	}

	return 0;
}