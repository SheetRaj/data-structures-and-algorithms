#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void subArray_util(vector<int> num, int start, int end) {

		//base case 
		if (end == num.size()) {
			return;
		}

		for (int i = start; i <= end; i++) {
			cout << num[i] << " ";
		}
		cout << endl;

		// Recursive call with an incremented end index
		subArray_util(num, start, end + 1);
	}

	void printSubArray(vector<int> arr) {
		for (int start = 0; start <= arr.size(); start++) {
			int end = start;
			subArray_util(arr, start, end);
		}
	}
};

int main() {

	Solution sol;

	vector<int> arr = { 1, 2, 3, 4, 5 };
	sol.printSubArray(arr);

	return 0;
}
