#include <bits/stdc++.h>
using namespace std;


//tc : O(logn) 
int search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (target == nums[mid]) // if mid equal target
        {
            return mid;
        }
        if (nums[mid] >= nums[left]) // checks if mid is greater than or equal to left , this means that target is in between mid and left
        {
            if (nums[left] <= target && nums[mid] > target) // checks if target is between mid and left
            {
                right = mid - 1;
            }
            else // not between mid and left
            {
                left = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && nums[right] >= target) // checks if target is between mid and right
            {
                left = mid + 1;
            }
            else // not between mid and right
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << "Answer index :" << search(nums, target);
    return 0;
}