#include <bits/stdc++.h>
using namespace std;
int minimumOperations(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 3 != 0)
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    vector<int>nums = {1,2,3,4};
    cout<<minimumOperations(nums);
}