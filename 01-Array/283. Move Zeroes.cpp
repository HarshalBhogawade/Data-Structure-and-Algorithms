#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for(int fast=0;fast<nums.size();fast++){
            if(nums[fast]!=0){
                swap(nums[slow],nums[fast]);
                slow++;
            }
        }
}

int main(){
    vector<int>nums = {0,0,1,2,3,4};
    moveZeroes(nums);
    for(int num : nums){
        cout<<num<<" ";
    }
    return 0;

}