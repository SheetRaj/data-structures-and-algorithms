#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void setZero(vector<vector<int>>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                if (nums[i][j] == 0) {
                    for (int col = 0; col < nums[i].size(); col++) {
                        if (nums[i][col] != 0) {
                            nums[i][col] = -1;
                        }
                    }
                    for (int row = 0; row < nums.size(); row++) {
                        if (nums[row][j] != 0) {
                            nums[row][j] = -1;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                if (nums[i][j] == -1) {
                    nums[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = { {1, 2, 3},
                                   {4, 0, 6},
                                   {7, 8, 9} };

    sol.setZero(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
