#include <bits/stdc++.h>   // Includes all standard C++ libraries (used in competitive programming)
using namespace std;

// Time Complexity: O(N log N)
// Space Complexity: O(N) auxiliary space + O(log N) recursion stack
class Solution {
public:

    // This function merges two sorted subarrays of arr
    // First subarray: arr[low ... mid]
    // Second subarray: arr[mid+1 ... high]
    void merge(vector<int>& arr, int low, int mid, int high) {

        vector<int> temp;   // Temporary array to store merged result

        int left = low;     // Pointer for left subarray
        int right = mid + 1; // Pointer for right subarray

        // Compare elements from both subarrays and insert the smaller one
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]); // Take from left subarray
                left++;
            } else {
                temp.push_back(arr[right]); // Take from right subarray
                right++;
            }
        }

        // Copy remaining elements from left subarray (if any)
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // Copy remaining elements from right subarray (if any)
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy merged elements back into original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low]; // Offset because temp starts at index 0
        }
    }

    // Recursive merge sort function
    void ms(vector<int>& arr, int low, int high) {

        // Base case: array of size 0 or 1 is already sorted
        if (low >= high) return;

        // Find the middle index safely (prevents overflow)
        int mid = low + (high - low) / 2;

        // Recursively sort left half
        ms(arr, low, mid);

        // Recursively sort right half
        ms(arr, mid + 1, high);

        // Merge the two sorted halves
        merge(arr, low, mid, high);
    }

    // Public function to start merge sort
    void mergeSort(vector<int>& arr, int l, int r) {
        ms(arr, l, r); // Call recursive merge sort
    }
};

int main() {

    // Input array
    vector<int> arr = {5, 2, 3, 1, 4};

    Solution obj;

    // Perform merge sort on the entire array
    obj.mergeSort(arr, 0, arr.size() - 1);

    // Print sorted array
    cout << "Sorted Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}