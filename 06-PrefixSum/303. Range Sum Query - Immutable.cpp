#include <bits/stdc++.h>
using namespace std;

// Time complexity :
// preprocessing : O(N)
// each query : O(1)
// Sc : O(N)
int sumRange(vector<int> nums, int left, int right)
{
    vector<int> pre; // to store prefix sum for later calculations
    int n = nums.size();

    pre.resize(n);    // resizing the pre vector to size of nums given array
    pre[0] = nums[0]; // for [i-1] else outofbounds
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + nums[i]; // calculates the prefix sums
    }

    if (left == 0)
    {
        return pre[right];
    }
    else
    {
        return pre[right] - pre[left - 1]; // calculates the range of sum required
    }
    return -1;
}

int main()
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};

    cout << "Answer 1: " << sumRange(nums, 0, 2) << endl; // sum of [-2,0,3] = 1
    cout << "Answer 2: " << sumRange(nums, 2, 5) << endl; // sum of [3,-5,2,-1] = -1
    cout << "Answer 3: " << sumRange(nums, 0, 5) << endl; // sum of whole array = -3

    return 0;
}
