#include<bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
        int left =0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return left;
}
int main(){
    vector<int>nums={1,3,5,6};
    cout<<"Insert position :"<<searchInsert(nums,5)<<endl;  //2
    cout<<"Insert position :"<<searchInsert(nums,2)<<endl;  //1
    cout<<"Insert position :"<<searchInsert(nums,7)<<endl;  //5
    return 0;
}