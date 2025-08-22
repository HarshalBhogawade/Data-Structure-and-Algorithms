#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int> nums){
    int n = nums.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[nums[i]]++;
        if(mp[nums[i]]>1){
            return true;
        }
    }
    return false;
    

}
int main(){
    vector<int>nums={1,1,1,3,3,4,3,2,4,2};
    bool isdupli = containsDuplicate(nums);
    cout<<"if true duplicate else not duplicates: "<<isdupli<<endl;
    
}