#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

class Solution {
public:

    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void printArray(vector<int> arr, int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void performExperiment(int size) {
        vector<int> arr(size);

        // Generate a random array with values between 1 and 99
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100;
        }

        cout << "Original Array (Size " << size << "):" << endl;
        printArray(arr, size);

        // Measure the time taken to sort the array
        clock_t start_time = clock();
        quickSort(arr, 0, size - 1);
        clock_t end_time = clock();
        double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

        cout << "Sorted Array (Size " << size << "):" << endl;
        printArray(arr, size);

        cout << "Time taken to sort: " << elapsed_time << " seconds" << endl;
    }
};

int main() {
    Solution sol;
    int sizes = 10;

    sol.performExperiment(sizes);
    
    return 0;
}
