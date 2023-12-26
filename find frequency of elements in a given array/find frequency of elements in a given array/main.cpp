#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class FrequencyCounter {
private:
    unordered_map<int, int> frequencyMap;

public:
    void countFrequencies(const vector<int>& arr) {
        for (int num : arr) {
            frequencyMap[num]++;
        }
    }

    void printFrequencies() {
        cout << "Element frequencies:\n";
        for (const auto& entry : frequencyMap) {
            cout << entry.first << ": " << entry.second << " times\n";
        }
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    FrequencyCounter counter;
    counter.countFrequencies(arr);
    counter.printFrequencies();

    return 0;
}
