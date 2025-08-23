#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
        int k = 0;
        for(int i=0;i<nums.size();i++){
            k ^= nums[i];
        }
        return k;
}

int main(){
    vector<int>nums = {3,2,3,4,4,5,5,6,6,7,7};
    int num = singleNumber(nums);
    cout<<"Single number is : "<<num<<endl;
    return 0;
}