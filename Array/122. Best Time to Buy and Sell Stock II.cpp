#include<bits/stdc++.h>
using namespace std;
int maxprofit(vector<int>nums){
    int buy = nums[0];
    int profit = 0;
    for(int i =0;i<nums.size();i++){
        if(nums[i]>buy){
            profit += nums[i]-buy;
        }
        if(nums[i]<buy){
            buy = nums[i];
        }
    }
    if(profit<0) return 0;
    return profit;
}
int main(){
    vector<int>nums = {7,1,5,3,6,4};
    int profit = maxprofit(nums);
    cout<<"Max profit : "<<profit<<endl;
    return 0;
}