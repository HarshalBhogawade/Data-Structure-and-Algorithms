#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end()); //dont consider duplicates in it , only store uniques even inserting after same nums
        
        vector<int> result;

        for (int num : nums2) {
            if (set.count(num)) {
                result.push_back(num);
                set.erase(num); // ensure uniqueness
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> ans = sol.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
