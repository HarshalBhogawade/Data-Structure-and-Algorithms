/*
s1-push all elements of nums in the hashmap
s2- check in map if the original = original *2 is in map (use mp.find(original)!=mp.end())
s3-above step will check until  2*original present in the map 
 one can find in map it will return the final original value
*/


class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int>mp;
        for(int num : nums){
            mp[num]++;
        }
        
            while(mp.find(original)!=mp.end()){
                original = original*2;
            }    

        return original;
    }
};
