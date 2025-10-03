#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int elem = 0;
        int i = 0;

        while (i < nums.size()) {
            if (count == 0) {
                elem = nums[i];
                count = 1;
            } else if (nums[i] == elem) {
                count++;
            } else {
                count--;
            }
            i++;
        }

        return elem;
        // Optional verification step:
        // Count actual frequency if needed (only required if element may not be majority).
        // In LeetCode Q169, majority is guaranteed.
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,2,1,1,1,2,2};

    cout << "Majority Element is: " << sol.majorityElement(nums) << endl;

    return 0;
}
