#include <bits/stdc++.h>
using namespace std;

vector<int> getSneakyNumbers(vector<int> &nums)
{
    vector<int> ans;
    unordered_map<int, int> mp;
    for (auto num : nums)
    {
        mp[num]++;
    }

    for (auto &num : mp)
    {
        if (num.second == 2)
        {
            ans.push_back(num.first);
        }
    }

    return ans;
}
int main()
{

    vector<int>nums = {0,3,2,1,3,2};
    getSneakyNumbers(nums);
}