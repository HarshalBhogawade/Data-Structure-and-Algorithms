#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, int n, vector<int>& nums2, int m) {
    int i = n - 1;      // Last index of original nums1 elements
    int j = m - 1;      // Last index of nums2
    int k = n + m - 1;  // Last index of merged nums1 (nums1 has extra space at end)

    nums1.resize(n + m); // Make sure nums1 can hold all elements

    // Merge nums2 into nums1 from the end
    while(i >= 0 && j >= 0) {
        if(nums1[i] >= nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }

    // Copy remaining nums2 elements if any
    while(j >= 0) nums1[k--] = nums2[j--];

    // Calculate median
    int total = n + m;
    if(total % 2 == 0) {
        // Even length → average of middle two elements
        return (nums1[total / 2] + nums1[total / 2 - 1]) / 2.0;
    } else {
        // Odd length → middle element
        return nums1[total / 2];
    }
}

// Test
int main() {
    vector<int> nums1 = {1, 3}; // Original elements
    vector<int> nums2 = {2};
    int n = 2, m = 1;

    cout << "Median: " << findMedianSortedArrays(nums1, n, nums2, m) << endl;
}
