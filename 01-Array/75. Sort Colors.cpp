#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0;         // boundary for 0s
        int mid = 0;          // current element pointer
        int right = n - 1;    // boundary for 2s

        while (mid <= right) {
            if (nums[mid] == 0) {
                swap(nums[left], nums[mid]);
                left++;
                mid++;        // safe to move mid forward
            }
            else if (nums[mid] == 2) {
                swap(nums[mid], nums[right]);
                right--;      // don't move mid, need to re-check new element
            }
            else { // nums[mid] == 1
                mid++;        // 1 is already in correct region
            }
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution s;
    s.sortColors(nums);

    for (int x : nums) cout << x << " ";
    return 0;
}
