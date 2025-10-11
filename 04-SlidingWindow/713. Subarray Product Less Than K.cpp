#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    // TC: O(n) , SC: O(1)

    int count = 0, i = 0, j = 0, prod = 1, n = nums.size();

    while (j < n) {
        prod *= nums[j];                 // expand window
        while (prod >= k && i <= j) {    // shrink if product invalid
            prod /= nums[i];
            i++;
        }
        count += j - i + 1;              // add all valid subarrays ending at j
        j++;
    }
    return count;
}

int main() {
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << numSubarrayProductLessThanK(nums, k);
    return 0;
}
