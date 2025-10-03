#include <vector>
#include <stack>
#include <iostream>
using namespace std;


//time complexity : O(4N) SC : O(2n) // worst case

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        // Start from the end of second iteration (circular array simulation)
        int i = 2 * nums.size() - 1;
        vector<int> ans(nums.size());
        
        while(i >= 0) {
            // Remove elements smaller than or equal to current element
            while(!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            // Only store result for first iteration (original array indices)
            if(i < n) {
                ans[i] = st.empty() ? -1 : st.top();
            }
            // Push current element to stack
            st.push(nums[i % n]);
            i--;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 10, 12, 1, 11, 2, 10, 12};
    
    vector<int> result = sol.nextGreaterElements(nums);
    
    // Print the results
    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    
    return 0;
}
