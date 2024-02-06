#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;

        for (const string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }

        for (auto it = map.begin(); it != map.end(); ++it) {
            ans.push_back(it->second);
        }

        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<string> input = { "eat", "tea", "tan", "ate", "nat", "bat" };
    vector<vector<string>> result = solution.groupAnagrams(input);

    // Displaying the result
    for (const auto& group : result) {
        cout << "[";
        for (const string& str : group) {
            cout << str << ", ";
        }
        cout << "]";
    }

    return 0;
}
