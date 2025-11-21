#include <bits/stdc++.h>
using namespace std;


//tem complexity : O(2^N*N)
//2^n calls 
//2^N for each element have two choices take or skip like normal recursion tree size
//N for copy into ans
//sc : depth of tree is N 
void combination(int idx, vector<int> &temp, vector<vector<int>> &ans, vector<int> &nums, int target)
{
    if (target < 0)
        return; // If target already negative, no point exploring further
    // If we've processed all numbers
    if (idx == nums.size())
    {
    // Only valid if target is exactly 0

        if (target == 0)
        {
            ans.push_back(temp);
        }
        return;
    }

    // Stay on same index because this problem allows reuse of nums[idx]

    temp.push_back(nums[idx]);
    combination(idx, temp, ans, nums, target - nums[idx]);

    temp.pop_back(); // pop temp back while backtracking as we are now going to not take branch
                     //  Move to next index, target unchanged

    combination(idx + 1, temp, ans, nums, target);
}

vector<vector<int>> combinationsum(vector<int> nums, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    combination(0, temp, ans, nums, target);
    return ans;
}
int main()
{
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = combinationsum(nums, target);
    for (auto &vp : ans)
    {
        for (int nc : vp)
        {
            cout << nc << " ";
        }
        cout << endl;
    }
}