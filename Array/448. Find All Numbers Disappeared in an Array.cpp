#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Mark numbers as visited by flipping their index positions negative
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;      // Map value → index (1-based → 0-based)
            if (nums[index] > 0) {             // If not already marked
                nums[index] = -nums[index];    // Mark as visited (make negative)
            }
        }

        // Step 2: Any index left positive means (i+1) was missing
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {                 // Still positive → number never visited
                ans.push_back(i + 1);          // (i+1) is missing from array
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    // Find disappeared numbers
    vector<int> result = sol.findDisappearedNumbers(nums);

    // Print result
    cout << "Missing numbers: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
