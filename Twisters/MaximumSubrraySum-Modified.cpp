/* Problem statement
You are given an integer array nums of length n.

Your task is to find the contiguous subarray (containing at least one element) which has the maximum possible sum, and return both:

The maximum sum.

The starting and ending indices of the subarray that yields this maximum sum.

If multiple subarrays yield the same maximum sum, return the one with the smallest starting index. If there’s still a tie, choose the one with the smallest ending index.*/

#include <bits/stdc++.h>
using namespace std;
void MaximumSubarray(vector<int> &arr)
{
    int largest = INT_MIN;
    int sum = 0;
    int start = 0;
    int tempstart = 0;
    int end = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (largest < sum)
        {
            largest = sum;
            start = tempstart;  //this gives the start index of subarray with maxsum
            end = i;        //STORES ending index of max sum  subarray;
        }
        if (sum < 0)    //kadans prop
        {
            sum = 0;
            tempstart = i + 1;  //stores the start of new subarray which may give next max sub subarray
        }
    }
    cout << "Maximum subarray sum : " << largest << endl;
    for (int i = start; i <= end; i++)  //printing subarry that gives max sum 
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5};
    MaximumSubarray(nums);
}