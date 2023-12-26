#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int duplicatesNumber(vector<int> arr) {
        int n = arr.size();

        if (n == 0 || n == 1)
            return n;

        int temp[1000];

        // Start traversing elements
        int j = 0;

        // If current element is not equal to next element
        // then store that current element
        for (int i = 0; i < n - 1; i++)
            if (arr[i] != arr[i + 1])
                temp[j++] = arr[i];

        // Store the last element as whether it is unique or
        // repeated, it hasn't stored previously
        temp[j++] = arr[n - 1];

        // Modify original array
        for (int i = 0; i < j; i++)
            arr[i] = temp[i];

        return j;
    }
};
int main() {
    vector<int> arr = { 1, 2, 2, 3, 4, 4, 4, 5, 5 };
    Solution sol;
    int newSize = sol.duplicatesNumber(arr);

    cout << "New size of array without duplicates: " << newSize << endl;
    cout << "Modified array contents: ";
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }

	return 0;
}