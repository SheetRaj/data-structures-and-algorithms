#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// This function are only for the single unique value.
int uniqueValue(vector<int> arr) {
	int ans = 0;

	for (int i = 0; i < arr.size(); i++) {

		// Check the unique value using XOR if value is same they cancle each other using XOR truth table.
		ans = ans ^ arr[i];
	}
	return ans;
}

// This function are For multiple unique value.

vector<int> multiUniqueVal(vector<int> arr) {
	unordered_map<int, int> frequencyMap;
	vector<int> result;

	for (int num : arr) {
		frequencyMap[num]++;
	}

	for (const auto& pair : frequencyMap) {
		if (pair.second == 1) {
			result.push_back(pair.first);
		}

	}

	return result;
}

int main() {
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int result = uniqueValue(arr);
	vector<int> multiVal = multiUniqueVal(arr);

	if (multiVal.empty()) {
		cout << "single Unique value of this array is: " << result << endl;
	}
	else {
		cout << "Multi unique value are: ";
		for (int num : multiVal) {
			cout << num << " ";
		}
	}

	return 0;
}