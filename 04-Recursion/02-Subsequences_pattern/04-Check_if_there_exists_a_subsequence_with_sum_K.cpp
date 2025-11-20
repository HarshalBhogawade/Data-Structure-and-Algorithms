#include <bits/stdc++.h>
using namespace std;
void subsequence(int idx, int currentSum, bool &istrue, vector<int> &arr, int k)
{
    if (istrue)
        return;
    if (idx >= arr.size())
    {
        if (currentSum == k)
        {
            istrue = true;
        }
        return;
    }
    // take curr elem
    subsequence(idx + 1, currentSum + arr[idx], istrue, arr, k);

    // not take curr elem
    subsequence(idx + 1, currentSum, istrue, arr, k);
}
bool checkSubsequenceSum(int n, vector<int> &arr, int k)
{
    // Code here
    bool istrue = false;
    subsequence(0, 0, istrue, arr, k);
    return istrue;
}
int main()
{
    vector<int>nums = {10,1,2,7,6,1,5};

    int k = 8;
    cout<<checkSubsequenceSum(nums.size(),nums,k);
    //true;
}