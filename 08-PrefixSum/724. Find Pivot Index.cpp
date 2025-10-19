#include <bits/stdc++.h>
using namespace std;


    //TC -> O(N) SC -> O(N);
int pivotIndex(vector<int> &nums)
{

    int n = nums.size();
    vector<int> pre(n, 0);
    
    pre[0] = nums[0];   //for [i-1]

    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + nums[i];  //stores sum in pre
    }

    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)     //checks if i =0 so that you can get sum from 0 till i-1
        {
            sum1 = 0;
        }
        else
        {
            sum1 = pre[i - 1];  //sum from 0 to i-1 
        }

        sum2 = pre[n - 1] - pre[i]; //sum from i to n-1
        if (sum1 == sum2)   //if sun equals then we can say i is an pivot index
        {
            return i;
        }
    }

    return -1;
}
int main() {
    vector<int>nums={1,7,3,6,5,6};
    cout<<"Answer :"<<pivotIndex(nums);
}