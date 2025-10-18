#include<bits/stdc++.h>
using namespace std;

int maxDistinctElements(vector<int>& nums, int k) {
        //tightly packing elements within the range
        //no need to do x+k just used for checking if we exceed range or not
        sort(nums.begin(),nums.end());
        int cnt = 0;
        int prevsmall = INT_MIN; //prev should be smaller to maintain distinctness
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            int finalval = max(nums[i]-k,prevsmall);//next to prevsmaller must be greater
            if(finalval<=nums[i]+k){
                nums[i]=finalval;
                prevsmall = finalval+1;
                cnt++;
            } 
        }
        return cnt;
    }

int main(){
    vector<int>nums = {1,2,2,3,3,4};
    int k = 2;
    cout<<"Max dist element after operations: "<<maxDistinctElements(nums,2);
    
}