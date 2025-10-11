#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n; // Subarrays of length 1 or 2 are always valid

        int currentLen = 2;  // Current Fibonacci-like subarray length
        int maxLen = 2;      // Maximum length found so far

        for(int i = 2; i < n; i++) {
            if(nums[i] == nums[i-1] + nums[i-2]) {
                currentLen++; // Continue current subarray
            } else {
                currentLen = 2; // Reset length
            }
            maxLen = max(maxLen, currentLen);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,1,1,1,2,3,5,1};
    cout << "Longest Fibonacci subarray length: " << sol.longestSubarray(nums1) << endl;

    vector<int> nums2 = {5,2,7,9,16};
    cout << "Longest Fibonacci subarray length: " << sol.longestSubarray(nums2) << endl;

    return 0;
}
