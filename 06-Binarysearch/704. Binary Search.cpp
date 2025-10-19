#include <bits/stdc++.h>
using namespace std;

// Binary Search Function
// Time Complexity: O(log n)
// Space Complexity: O(1)
int search(vector<int> &nums, int target)
{
    int i = 0;               // Left boundary
    int j = nums.size() - 1; // Right boundary

    while (i <= j)
    {
        int mid = i + (j - i) / 2; // Middle index (to avoid overflow)

        if (nums[mid] == target)
        { // If target found
            return mid;
        }
        else if (nums[mid] < target)
        { // Search right half
            i = mid + 1;
        }
        else
        { // Search left half
            j = mid - 1;
        }
    }
    return -1; // Target not found
}

int main()
{
    vector<int> nums = {1, 3, 5, 7, 9, 11, 15};
    int target = 7;

    int result = search(nums, target);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}
