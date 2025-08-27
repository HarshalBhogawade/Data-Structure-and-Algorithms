#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //unordered_set approach
        // TC:O(2N) SC: O(N)
        // unordered_map<int,int>st;
        // for(int num : nums){
        //     st[num]++;
        // }
        // vector<int>ans;
        // for(auto p : st){
        //     if(p.second>=2){
        //         ans.push_back(p.first);
        //     }
        // }
        // return ans;

        //two pointers
        //tc : O(NlogN) SC:O(1)
        vector<int>ans;
        int n= nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    
    vector<int> duplicates = sol.findDuplicates(nums);
    
    cout << "Duplicates: ";
    for (int d : duplicates) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
