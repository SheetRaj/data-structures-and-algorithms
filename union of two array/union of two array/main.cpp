#include<iostream>
#include<vector>;
using namespace std;


int main() {
	int num1, num2;
	cout << "Enter the size of the array: ";
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

	for (int i = 0; i < num1; i++) {
		ans.push_back(arr1[i]);
	}

	for (int i = 0; i < num2; i++) {
		ans.push_back(arr2[i]);
	}

	cout << "Union of the two element is: ";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}


	return 0;
}
