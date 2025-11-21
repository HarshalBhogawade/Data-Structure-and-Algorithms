#include <bits/stdc++.h>
using namespace std;

/*problem says : Find all valid combinations of k numbers
//that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
basically they mean
return the unique subsequences of size k that sums to n*/

void combination(int idx, vector<int> &temp, vector<vector<int>> &ans, vector<int> &nums, int k, int n)
{
    if (temp.size() == k)
    { // base case
        if (n == 0)
        { // only push when sum satify
            ans.push_back(temp);
        }
        return;
    }
    // optimized little bit
    for (int i = idx; i < nums.size(); i++)
    {
        if (i > idx && nums[i] == nums[i - 1])
            continue; // duplicate handles
        if (nums[i] > n)
            break;               // no need to call the nums which are greater than n as they will not sums to n
        temp.push_back(nums[i]); // take
        combination(i + 1, temp, ans, nums, k, n - nums[i]);
        temp.pop_back(); // backtrack
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> ans;
    vector<int> temp;
    combination(0, temp, ans, nums, k, n);
    return ans;
}

int main()
{
    combinationSum3(3,9);
}