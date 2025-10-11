#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;              // stores elements in decreasing order
        vector<int> ans;
        int n = nums.size();
        int i = 0, j = 0;

        while (j < n) {
            // remove all smaller elements from back (keep deque decreasing)
            while (!q.empty() && q.back() < nums[j]) {
                q.pop_back();
            }
            q.push_back(nums[j]);  // push current element

            // if window size < k, expand window
            if (j - i + 1 < k) {
                j++;
            }
            // if window size == k, record answer
            else if (j - i + 1 == k) {
                ans.push_back(q.front());   // front is max element

                // before sliding window, remove outgoing element
                if (q.front() == nums[i]) {
                    q.pop_front();
                }
                i++; // slide left
                j++; // slide right
            }
        }
        return ans;
    }
};

// Example usage
int main() {
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = s.maxSlidingWindow(nums, k);

    for (int x : result) cout << x << " ";
    return 0;
}
