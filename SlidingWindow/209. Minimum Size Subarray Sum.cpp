#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i =0;
        int j =0;
        int ans = INT_MAX;
        int sum = 0;
        while(j<nums.size()){
            sum = sum + nums[j];
            while(sum>=target){
                ans = min(ans , j-i+1);
                sum = sum - nums[i];
                i++;
            } 
            j++;
        }
        if(ans == INT_MAX){
            return 0;
        }
        return ans;
    }
};
int main(){
    int target = 7;
    vector<int>nums = {2,3,1,2,4,3};
    Solution s;
    int answer = s.minSubArrayLen(target , nums);
    cout<<"MINIMUM SIZE IS : "<<answer<<endl;
    
    return 0;
}