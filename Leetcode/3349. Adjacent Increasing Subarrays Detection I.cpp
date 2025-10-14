#include <bits/stdc++.h>
using namespace std;

bool isIncreasing(vector<int>& nums, int start, int k) {
    for (int i = start; i < start + k - 1; i++) {
        if (nums[i] >= nums[i + 1]) return false;
    }
    return true;
}

bool hasTwoAdjacentIncreasingSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    for (int i = 0; i + 2 * k <= n; i++) {
        if (isIncreasing(nums, i, k) && isIncreasing(nums, i + k, k))
            return true;
    }
    return false;
}

int main() {
    vector<int> nums = {2,5,7,8,9,2,3,4,3,1};
    int k = 3;
    cout << (hasTwoAdjacentIncreasingSubarrays(nums, k) ? "true" : "false");
}
