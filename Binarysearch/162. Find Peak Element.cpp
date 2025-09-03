#include <bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return 0;
    }               //these are edge cases
    if (nums[n - 1] > nums[n - 2])
        return n - 1;
    if (nums[0] > nums[1])
        return 0;
    int high = n - 2;
    int low = 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) //checks next and prev element to mid 
            return mid;
        if (nums[mid] > nums[mid - 1]) //checks if prev is smaller
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1; //if prev is not greater , then do this
        }
    }
    return -1;
}
int main() {}