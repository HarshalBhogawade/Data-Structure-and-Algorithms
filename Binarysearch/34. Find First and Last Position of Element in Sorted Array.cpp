#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> ans(2, -1); // Initialize answer to [-1,-1] if target not found

    // Find first occurrence
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2; // Safe midpoint
        if(nums[mid] == target) {
            ans[0] = mid;       // Update first occurrence
            right = mid - 1;    // Move left to find earlier occurrence
        }
        else if(nums[mid] < target) left = mid + 1;  // Search right half
        else right = mid - 1;                        // Search left half
    }

    // Find last occurrence
    left = 0; right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            ans[1] = mid;       // Update last occurrence
            left = mid + 1;     // Move right to find later occurrence
        }
        else if(nums[mid] < target) left = mid + 1;  // Search right half
        else right = mid - 1;                        // Search left half
    }

    return ans; // Return first and last positions of target
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
}
