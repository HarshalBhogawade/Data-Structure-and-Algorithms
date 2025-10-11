/*
s1- create an array and insert all elements with their frequency 
s2- loop through map and check if we have any element with occurance of only one and check if (x-1)s and (x+1)s count is zero 
s3- if above condition satisfy then push the lonely element in to the array of answers
s4- return ans array at the end 
basically this is easy question but leetcode tagged it as an medium 
*/

class Solution {
public:
    
    vector<int> findLonely(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int num : nums){
            mp[num]++;
        }
        for(auto it : mp){
            int x = it.first;
            if(it.second==1 && mp.count(x-1)==0 && mp.count(x+1) == 0){
                ans.push_back(x);
            }
        }
        return ans;
    }
};
