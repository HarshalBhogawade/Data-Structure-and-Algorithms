#include <bits/stdc++.h>
using namespace std;

// TC : O(LogN) SC  : O(1)
// nums=[1,1,2,3,3,4,4,8,8]
//   0 1 2 3 4 5 6 7 8
//   E     O
// pattern recognized
// first element index of pair before the single element is always  even
// and element after the single element is always odd index
int singleNonDuplicate(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // calculate mid index

        if (mid % 2 == 0) // mid is even
        {
            if (nums[mid] == nums[mid + 1]) // pair starts at mid → move right
                left = mid + 2;
            else // pair breaks → single element at mid or before
                right = mid - 1;
        }
        else // mid is odd
        {
            if (nums[mid] == nums[mid - 1]) // pair ends at mid → move right
                left = mid + 1;
            else // pair breaks → single element before mid
                right = mid - 1;
        }
    }
    return nums[left]; // left points to the single element
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Single element in sorted array is : " << singleNonDuplicate(nums) << endl;
    return 0;
}