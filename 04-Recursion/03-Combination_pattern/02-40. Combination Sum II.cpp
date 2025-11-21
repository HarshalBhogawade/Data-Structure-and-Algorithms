#include <bits/stdc++.h>
using namespace std;

// time ocmplexity : O(2^N) as include exclude
// sc : O(N)
void combination(int idx, vector<int> &temp, vector<vector<int>> &ans, vector<int> nums, int target)
{

    if (target < 0)
        return; // stop as no need to go below 0
    if (idx >= nums.size())
    {
        if (target == 0)
        { // found subsequence with sum equals the target
            ans.push_back(temp);
        }
        return;
    }
    temp.push_back(nums[idx]); // take current elem
    combination(idx + 1, temp, ans, nums, target - nums[idx]);
    temp.pop_back(); // as returning pop the back element //means we are backtracking

    int nextidx = idx + 1; // moving ahead if there is a duplicate
    while (nextidx < nums.size() && nums[nextidx] == nums[idx])
    {
        nextidx++;
    } // again call
    combination(nextidx, temp, ans, nums, target);
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    combination(0, temp, ans, candidates, target);
    return ans;
}

// can be optimized by using for loop inside the recursive function ,
// means we make less recursive calls resulting in low time compleixty

// optimal solution

// time ocmplexity : O(2^N) as include exclude
// sc : O(N)
void combination(int idx, vector<int> &temp, vector<vector<int>> &ans, vector<int> nums, int target)
{

    if (target == 0)
    { // found subsequence with sum equals the target
        ans.push_back(temp);
        return;
    }

    //for loop replaces the not take and results in low complexity
    for (int i = idx; i < nums.size(); i++)
    {
        if(i>idx && nums[i]==nums[i-1]) continue;
        if(nums[i]>target) break;

        temp.push_back(nums[i]);
        combination(i+1,temp,ans,nums,target-nums[i]);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    combination(0, temp, ans, candidates, target);
    return ans;
}

// can be optimized by using for loop inside the recursive function ,
// means we make less recursive calls resulting in low time compleixty
int main()
{
    vector<int>candi = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>>ans = combinationSum2(candi , target);
    for(auto &it : ans){
        for(int a : it){
            cout<<a<<" ";
            
        }
        cout<<endl;
    }
}  