#include<bits/stdc++.h>
using namespace std;
 int minOperations(vector<int>& nums, int k) {
        int totalSum = 0;
        for(int i =0;i<nums.size();i++){
            totalSum +=nums[i];
        }
        return totalSum%k;
    }
int main(){
    vector<int>nums= {3,9,7};
    cout<<minOperations(nums,5);
}