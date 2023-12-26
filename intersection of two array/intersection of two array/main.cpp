#include<iostream>
#include<vector>
using namespace std;

int main() {

	int num1, num2;

	cout << "Enter the size of array1 and array2: ";
	cin >> num1;
	cin >> num2;

	vector<int> arr1(num1);
	vector<int> arr2(num2);

	for (int i = 0; i < num1; i++) {
		cin >> arr1[i];
	}
	
	for (int i = 0; i < num2; i++) {
		cin >> arr2[i];
	}

	vector<int> ans;

	for (int i = 0; i < arr1.size(); i++) {
		for (int j = 0; j < arr2.size(); j++) {
			if (arr1[i] == arr2[j]) {
				arr2[j] = -1;
				ans.push_back(arr1[i]);
			}
		}
	}

	// Print all the element

	for (auto value : ans) {
		cout << value << " ";
	}


	return 0;
}