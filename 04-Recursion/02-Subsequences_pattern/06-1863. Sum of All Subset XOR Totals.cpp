#include <bits/stdc++.h>
using namespace std;

//tc : O(2^N) SC: O(N)
void subset(int idx, int currSum, int &total, vector<int> &nums)
{
    if (idx >= nums.size())
    {
        total += currSum;
        return;
    }

    subset(idx + 1, currSum ^ nums[idx], total, nums);
    subset(idx + 1, currSum, total, nums);
}

int subsetXORSum(vector<int> &nums)
{
    int total = 0;
    subset(0, 0, total, nums);
    return total;
}
int main()
{
    vector<int>nums = {5,1,6};
    cout<<"Xor totals: "<<subsetXORSum(nums);
}