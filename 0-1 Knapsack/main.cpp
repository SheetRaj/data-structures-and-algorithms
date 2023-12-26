#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int knapSack(vector<int>& wt, vector<int>& p, int w, int n) {
        // Base case
        if (n == 0 || w == 0) {
            return 0;
        }

        if (wt[n - 1] > w) {
            return knapSack(wt, p, w, n - 1);
        }
        else {
            return max(p[n - 1] + knapSack(wt, p, w - wt[n - 1], n - 1), knapSack(wt, p, w, n - 1));
        }
    }
};

int main() {
    vector<int> wt = { 2, 3, 4, 5 };
    vector<int> p = { 1, 2, 5, 6 };
    int w = 8;
    int n = 4;
    Solution s;
    cout << "Maximum profit is: " << s.knapSack(wt, p, w, n);
    return 0;
}
