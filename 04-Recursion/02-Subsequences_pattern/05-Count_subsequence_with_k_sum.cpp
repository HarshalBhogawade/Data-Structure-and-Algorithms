#include <bits/stdc++.h>
using namespace std;
void subsequence(int idx, int currentSum, int &count, vector<int> &arr, int k)
{
    if (idx >= arr.size())
    {
        if (currentSum == k)
        {
            count++;
        }
        return;
    }
    // take curr elem
    subsequence(idx + 1, currentSum + arr[idx], count, arr, k);

    // not take curr elem
    subsequence(idx + 1, currentSum, count, arr, k);
}

int checkSubsequenceSum(int n, vector<int> &arr, int k)
{
    // Code here
    int count = 0;
    subsequence(0, 0, count, arr, k);
    return count;
}
int main()
{
    vector<int>nums = {10,1,2,7,6,1,5};

    int k = 8;
    cout<<checkSubsequenceSum(nums.size(),nums,k);
    //true;
}