#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    bool checkFrequency(vector<int>& s, vector<int>& t) {
        bool allPresent = true;

        // Loop through all possible characters (assuming ASCII characters)
        for (int i = 0; i < 256; i++) {
            // Check if the frequency of character i in vector t is greater than in vector s
            if (t[i] > s[i]) {
                allPresent = false;
                break; // Break out of the loop if a character in t has a higher frequency than in s
            }
        }

        // Return the result (true if all characters in t have equal or lower frequency in s)
        return allPresent;
    }

    /*
    * If the length of string t is greater than the length of string s, the function returns an empty string since it's not possible for s to contain a substring with all characters of t.

    * Initialize vectors tCount and sCount to keep track of character frequencies in t and the current substring of s. The vectors are of size 256 to cover all possible ASCII characters.

    * Loop through each character in string t and update the frequency count in the tCount vector.

    * Use two pointers, start and end, to iterate over the characters of string s. The goal is to find the minimum substring that contains all characters of t.

    * Inside the outer loop, increment the frequency count of the current character at the end pointer in the sCount vector.

    *  an inner loop to move the start pointer forward as long as the current substring still contains all the characters of t. Update the minimum substring (ans) if the current substring is smaller and meets the frequency criteria.
   
    * the frequency of the current character at the start pointer becomes equal to the required frequency, break out of the inner loop.
    
    * rement the frequency count of the character at the start pointer in the sCount vector and move the start pointer forward.
    
    * tinue moving the end pointer forward in the outer loop until the end of string s.
    
    * return the minimum substring found.
    */
	string minimumSubstring(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }

        vector<int> tCount(256, 0);
        vector<int> sCount(256, 0);

        for (int i = 0; i < t.size(); i++) {
            tCount[t[i]]++;
        }
        int start = 0;
        int end = 0;
        string ans = "";

        while (start <= end && end < s.size()) {
            sCount[s[end]]++;

            while (start <= end && sCount[s[start]] >= tCount[s[start]]) {
                string temp = s.substr(start, end - start + 1);

                if (checkFrequency(sCount, tCount) && (ans.size() > temp.size() || ans == "")) {
                    ans = temp;
                }

                if (sCount[s[start]] == tCount[s[start]]) {
                    break;
                }
                sCount[s[start]]--;
                start++;
            }
            end++;
        }

        return ans;
	}
};

int main() {
	Solution s;
	string str = "ADOBECODEBANC";
	string t = "ABC";

	string minSubstring = s.minimumSubstring(str, t);
	cout << "Minimum Window Substring: " << minSubstring << endl;

	return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(1)