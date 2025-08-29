#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        int sum = 0;
        while (j < nums.size())
        {
            sum = sum + nums[j]; // as window is expanding we add the num to sum var
            while (sum >= target)
            { // as we satisfied condition of sum = target this now gets smallest subarray whoste sum = target
                ans = min(ans, j - i + 1);
                sum = sum - nums[i]; // also this step moves the window from back side by removing elem of ith position  once sum < target we exit loop
                i++;                 // and again start expanding the window from right side
            }
            j++;
        }
        if (ans == INT_MAX)
        {
            return 0;
        }
        return ans;
    }
};
int main()
{
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    Solution s;
    int answer = s.minSubArrayLen(target, nums);
    cout << "MINIMUM SIZE IS : " << answer << endl;

    return 0;
}
