#include<bits/stdc++.h>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)    //before trimming checks if mid equals target
            return true;
        // due to duplicates-->trim down
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            // shink search space
            // eg:{3,1,2,3,3,3}
            low++;
            high--;
            continue;
        }
        if (nums[mid] == target)
        {
            return true;
        }
        if (nums[low] <= nums[mid])
        {
            // left half: low to mid
            if (nums[low] <= target && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            // right half: mid to high
            if (nums[mid] < target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return false;
}

int main(){
    vector<int>nums={2,5,6,0,0,1,2};
    cout<<"is founded : "<<search(nums,0)<<endl;
    return 0;
}