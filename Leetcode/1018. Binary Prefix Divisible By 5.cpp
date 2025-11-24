#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
vector<bool> prefixesDivBy5(vector<int> &nums)
{
    long long prev = 0;
    long long x = 0;
    vector<bool> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        prev = x;
        long long mult = (2 * prev);
        x = (mult + nums[i]) % 5;
        if (x % 5 == 0)
        {
            ans.push_back(true);
        }
        else
        {
            ans.push_back(false);
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {0, 1, 1};
    vector<bool> ans = prefixesDivBy5(nums);
}
