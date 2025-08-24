#include<iostream>
#include<vector>
using namespace std;

int removeduplicates(vector<int>nums){
    int slow = 0;
    for(int fast = 0;fast<nums.size();fast++){
        if(nums[slow]!=nums[fast]){
            slow++;
            nums[slow]=nums[fast];
        }

    }
    return slow+1;
}
int main(){
    vector<int>nums={1,2,2,3,3,3,5,6,7,7,8};
    int num = removeduplicates(nums);
    cout<<num<<endl;
    return 0;
}