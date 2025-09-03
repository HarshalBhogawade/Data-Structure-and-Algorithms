#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    // O(n)
    //  int minimum = nums[0];
    //  for(int i =0;i<nums.size();i++){
    //      if(nums[i]<minimum){
    //          minimum = nums[i];
    //      }
    //  }
    //  return minimum;
    int left = 0;
    int n = nums.size();
    int right = n - 1;
    while (left < right)
    {       
        //approach is that we find which side is  smaller then divide the arry to get min elemnet
        
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])    //this condition checks if one half is smaller , if yes then check for min in that half
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return nums[left];
}
int main()
{
    vector<int>nums={3,4,5,1,2};
    cout<<"Answer minnum: "<<findMin(nums);
    return 0;
}