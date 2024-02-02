#include<iostream>
using namespace std;

class Solution {
private:
    // Function to calculate the greatest common divisor (GCD) using Euclidean algorithm
    long gcd(long a, long b) {
        if ((a % b) == 0) {
            return b;
        }
        else {
            return gcd(b, (a % b));
        }
    }

public:
    // Binary search function to find the minimum value that satisfies the conditions
    void binarySearch(long l, long h, int divisor1, int divisor2, long lcm, long* ans, int cnt1, int cnt2) {
        if (l <= h) {
            long mid = (l + h) / 2;
            long a = mid - (mid / divisor1);
            long b = mid - (mid / divisor2);

            long c = mid - (mid / divisor1) - (mid / divisor2) + (mid / lcm);

            if (a >= cnt1 && b >= cnt2 && a + b - c >= cnt1 + cnt2) {
                // If conditions are satisfied, update the answer and search in the left half
                (*ans) = mid;
                binarySearch(l, mid - 1, divisor1, divisor2, lcm, ans, cnt1, cnt2);
            }
            else {
                // If conditions are not satisfied, search in the right half
                binarySearch(mid + 1, h, divisor1, divisor2, lcm, ans, cnt1, cnt2);
            }
        }
    }

    // Function to find the minimum set size that satisfies the conditions
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        // Calculate the least common multiple (LCM) of divisor1 and divisor2
        long g = gcd(max(divisor1, divisor2), min(divisor1, divisor2));
        long l = (long(divisor1) * long(divisor2)) / g;

        // Initialize the answer with a large value
        long ans = 1000000000;

        // Perform binary search to find the minimum set size
        binarySearch(2, 1000000000, divisor1, divisor2, l, (&ans), uniqueCnt1, uniqueCnt2);

        // Return the result as an integer
        return int(ans);
    }
};

int main() {
    // Create an instance of the Solution class
    Solution s;

    // Example values for testing
    int divisor1_value = 2;
    int divisor2_value = 5;
    int uniqueCnt1_value = 2;
    int uniqueCnt2_value = 1;

    // Call the minimizeSet function with the provided values
    int result = s.minimizeSet(divisor1_value, divisor2_value, uniqueCnt1_value, uniqueCnt2_value);

    // Display the result
    cout << "Minimum set size: " << result << endl;

    return 0;
}

