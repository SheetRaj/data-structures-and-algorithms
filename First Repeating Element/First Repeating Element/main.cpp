#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

	int repeatingElement(vector<int> arr) {

		unordered_map<int, int> map;

		// Store element in table form.

		for (int i = 0; i < arr.size(); i++) {
			map[arr[i]]++;
		}

		// Check the 1st repating element

		for (int i = 0; i < arr.size(); i++) {
			if (map[arr[i]] > 1) {
				return i + 1;
			}
		}

		return -1;
	}
};

int main() {

	vector<int> arr = { 1, 9, 3, 4, 6, 3, 5, 7 };
	Solution sol;
	
	int result = sol.repeatingElement(arr);
	cout << "First Repeating element is: " << result << endl;

	return 0;
}
