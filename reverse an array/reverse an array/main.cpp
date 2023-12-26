#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& arr) {  // Pass vector by reference to modify it
        int start = 0;
        int end = arr.size() - 1;

        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    void printArray(const vector<int>& arr) {  // Pass vector by const reference
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5 };
    Solution sol;  // Use uppercase for class names
    sol.reverseArray(arr);

    cout << "Reverse array is: ";
    sol.printArray(arr);
    return 0;
}
