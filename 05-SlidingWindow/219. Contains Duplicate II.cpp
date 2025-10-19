#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    // Time Complexity: O(n), each element added/removed once
    // Space Complexity: O(k), at most k elements in the set

    unordered_set<int> st;
    int i = 0, j = 0;
    while (j < nums.size())
    {
        if (st.count(nums[j]))
            return true;
        st.insert(nums[j]);
        while (st.size() > k)
        {
            st.erase(nums[i]);
            i++;
        }
        j++;
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    cout << (containsNearbyDuplicate(nums, k) ? "true" : "false");
    return 0;
}
