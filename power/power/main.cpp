#include<iostream>
using namespace std;

class Solution {
public:
    double power(double num1, int num2) {
        if (num2 == 0) {
            return 1;
        }

        if (num2 == 1) {
            return num1;
        }

        double p = power(num1, num2 / 2);
        if (num2 % 2 == 0) {
            return p * p;
        }
        else {
            if (num2 > 0) {
                return p * p * num1;
            }
            else {
                return (p * p) / num1;
            }
        }
    }
};

int main() {
    cout << "Enter the two numbers to find the power: ";
    double num1;
    int num2;
    cin >> num1 >> num2;

    Solution sol;
    double result = sol.power(num1, num2);
    cout << "Power of the two numbers is: " << result << endl;
    return 0;
}
