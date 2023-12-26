#include<iostream>
using namespace std;

class Solution {
public:
	int methodOne(string str, char key) {

		for (int i = str.size(); i > 0; i--) {
			if (key == str[i]) {
				return i;
			}
		}
		return -1;
	}

	void recursionMethod(string &str, char key, int i, int& ans) {

		//Base case

		if (i >= str.size()) {
			return;
		}

		if (str[i] == key) {
			ans = i;
		}

		recursionMethod(str, key, i + 1, ans);

	}
};

int main() {

	string str = "abgrbdjdfjgkyt";
	char key = 'j';
	int ans = -1;

	Solution sol;
	int result = sol.methodOne(str, key);
	int second_method = sol.recursionMethod(str, key, 0, ans);

	cout << "Result index is: " << result << endl;

	cout << "Secod method is : " << second_method << endl;

	return 0;
}