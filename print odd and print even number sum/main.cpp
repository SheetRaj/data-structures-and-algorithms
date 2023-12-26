#include<iostream>
#include<vector>
#include <cstdlib>
using namespace std;

/*

int main() {

	vector<int> number = {5, 4, 3, 2};
	int sum = 0;

	for (int i = 0; i < number.size(); i++) {
		if (number[i] % 2 == 0) {
			sum = sum + number[i + 1];
		}
		else {
			cout << number[i] << " ";
		}
	}
	cout << sum;

	return 0;
}

*/

//WAP to print X AND 0 in such a manner in which whene we enter a input a random value then the x and 0 place in such a manner if we print output then they not print 0 or x in group  take 5X5 matrix


// Write a program to print factorial using function


int factorial(int num) {
	if (num == 0 || num == 1) {
		return 1;
	}

	return num * factorial(num + 1);

}

int main() {
	int num;
	cout << "Enter the number to calculate the factorial : ";
	cin >> num;

	cout << factorial(num);

	return 0;
}


