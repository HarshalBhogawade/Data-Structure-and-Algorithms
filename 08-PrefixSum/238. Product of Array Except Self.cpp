#include <bits/stdc++.h>
using namespace std;

    //tc : O(3N) SC : O(2N)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        // prefix and suffix arrays
        vector<int> pre(n, 0);
        vector<int> suff(n, 0);
        vector<int> ans(n, 0);

        // initialize prefix[0] = 1 and suffix[n-1] = 1
        pre[0] = 1;
        suff[n - 1] = 1;

        // build prefix array
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] * nums[i - 1];
        }

        // build suffix array
        for (int i = n - 2; i >= 0; i--)
        {
            suff[i] = suff[i + 1] * nums[i + 1];
        }

        // final answer: product of prefix and suffix
        for (int i = 0; i < n; i++)
        {
            ans[i] = pre[i] * suff[i];
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = sol.productExceptSelf(nums);

    cout << "Result: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}