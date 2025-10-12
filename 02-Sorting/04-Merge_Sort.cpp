#include <bits/stdc++.h>
using namespace std;


//tc O(Nlogn) 
//sc O(N)
class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void ms(vector<int>& arr, int low, int high) {
        if (low >= high) return; // ✅ fixed: should be >= not ==
        int mid = low + (high - low) / 2;
        ms(arr, low, mid);
        ms(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        ms(arr, l, r);
    }
};

int main() {
    vector<int> arr = {5, 2, 3, 1, 4};
    Solution obj;
    obj.mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}
