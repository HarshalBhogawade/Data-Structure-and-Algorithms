#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //tc = O(N log N) sc = O(1)
        //two pointer (sorting)
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<n-1;i++){   // fixed bound: n-1
        //     if(nums[i]==nums[i+1]){
        //         return nums[i+1];
        //     }
        // }
        // return nums[0];

        //Floyd’s Cycle Detection Algorithm
        //tc = O(N) sc = O(1)
        int slow = nums[0];
        int fast = nums[0];
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2};

    cout << "Duplicate number is: " << sol.findDuplicate(nums) << endl;

    return 0;
}
