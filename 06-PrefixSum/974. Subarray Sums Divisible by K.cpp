#include <bits/stdc++.h>
using namespace std;

//tc : O(N) ANd SC: O(N) for map;
int subarraysDivByK(vector<int> &nums, int k)
{
    int cnt = 0;
    int sum = 0;
    int mod = 0;
    unordered_map<int, int> mp; //to store frequencies of remainder
    mp[0] = 1;  //because sum starting from zero should be counted
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i]; 
        mod = sum % k;  //remainder
        if (mod < 0)
        {   //-2%5 == -2 is same as after doing -2 + 5 = 7 tneh get 3 
            mod += k;
        }
        if (mp.find(mod) != mp.end())   //if mod is already in the map menas mod has already occured and divisible by k 
        {
            cnt += mp[mod];
        }
        mp[mod]++;  //increments mod frequency
    }
    return cnt;
}
int main() {
    vector<int>nums = {
        4,5,0,-2,-3,1
    };
    cout<<"Answwer : "<<subarraysDivByK(nums,5);
}