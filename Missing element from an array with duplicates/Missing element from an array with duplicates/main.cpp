#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void missingElement(vector<int> arr) {

		for (int i = 0; i < arr.size() - 1; i++) {
			int index = abs(arr[i]);

			if (arr[index - 1] > 0) {
				arr[index - 1] *= -1;
			}
		}

		for (int i = 0; i < arr.size() - 1; i++) {
			if(arr[i] > 0)
				cout << i + 1 << " ";
		}
	}
};

int main() {

	vector<int> arr = { 1, 3, 5, 5, 6, 6 };
	Solution sol;
	
	sol.missingElement(arr);

	return 0;
}