#include<bits/stdc++.h>
using namespace std;
bool kLengthApart(vector<int>& nums, int k) {
        int last =  -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(last!=-1 && i-last-1<k){
                    return false;
                }
                last = i;
            }
            
        }
        return true;
}
int main(){
    vector<int>nums = {1,0,0,0,1,0,0,1};
    cout<<"ISAway: "<<kLengthApart(nums,2);
}