#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low < high){  // change >= to < for proper recursion
            int pivotidx = partition(arr, low, high);
            quickSort(arr, low, pivotidx);       // note: pivotidx, not pivotidx-1
            quickSort(arr, pivotidx + 1, high);
        }
    }

    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int i = low - 1;
        int j = high + 1;

        while(true){
            do { i++; } while(arr[i] < pivot);   // move i until arr[i] >= pivot
            do { j--; } while(arr[j] > pivot);   // move j until arr[j] <= pivot

            if(i >= j) return j;                 // partition point reached
            swap(arr[i], arr[j]);                // swap i and j
        }
    }
};

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    Solution sol;
    sol.quickSort(arr, 0, arr.size() - 1);

    for(int x : arr) cout << x << " ";
    cout << endl;
}
