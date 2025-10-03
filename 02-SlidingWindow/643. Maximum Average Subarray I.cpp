#include <bits/stdc++.h>
using namespace std;

//time complexity : O(N) space : O(1)
double findMaxAverage(vector<int> &nums, int k)

{
    double sum = 0;
    double maxavg = INT_MIN;
    int n = nums.size();
    int j = 0, i = 0;
    while (j < n)
    {
        sum += nums[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            double avg = sum / k;   //avg of current window sum
            maxavg = max(maxavg, avg);
            sum -= nums[i];
            i++;
            j++;
        }
    }
    return maxavg;
}
int main()
{
    vector<int>nums = {1,12,-5,-6,50,3};
    cout<<"Max average :"<<findMaxAverage(nums,4);
    return 0;
}