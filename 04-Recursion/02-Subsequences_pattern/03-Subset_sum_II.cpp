#include<bits/stdc++.h>
using namespace std;

//brute : use set , if not in set, insert in set and also push in ans vector ,
// if in set do nothing means skip
//tc : O(log(2^n)*2^n) == O(N*2^N)
//sc : O(2^N*N)
void subset2(int idx ,vector<int>&temp ,set<vector<int>>&st , vector<vector<int>>&ans,vector<int>&nums){
    if(idx>=nums.size()){
        
        if(!st.count(temp)){
            st.insert(temp);
            ans.push_back(temp);
        }
        return;
    }
    //take
    temp.push_back(nums[idx]);
    subset2(idx+1,temp,st,ans,nums);
    //not take
    temp.pop_back();
    subset2(idx+1,temp,st,ans,nums);
}
vector<vector<int>> subsetswithDupli(vector<int>nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    vector<int>temp;//temp for storing subsequences
    set<vector<int>>st;//handling duplicates
    subset2(0,temp,st,ans,nums);
    return ans;
}

//optimized : remove set and just check for duplicate value in adjacent,
//if yes then skip using loop , if no pass that indx after we skipped loop
//tc: O(n*2^N)
//sc O(N) depth of tree
void subset(int idx , vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums){
    if(idx>=nums.size()){
        ans.push_back(temp);
        return;
    }

    temp.push_back(nums[idx]);
    subset(idx+1,temp,ans,nums);
    temp.pop_back();
    //not take  , duplicate handling
    int nextid = idx+1;
    while(nextid < nums.size() && nums[nextid]==nums[idx]){
        nextid++;
    }
    subset(nextid,temp,ans,nums);
}

vector<vector<int>> subsetswithDupli1(vector<int>nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans1;
    vector<int>temp1;//temp for storing subsequences
    subset(0,temp1,ans1,nums);
    return ans1;
}

int main(){
    vector<int>nums = {1,2,2};
    vector<vector<int>>ans = subsetswithDupli(nums);
    for(auto &vp : ans){
        for(int vc : vp){
            cout<<vc;
        }
        cout<<" ";
    }

    cout<<endl;

    //optiaml
    vector<vector<int>>ans1 = subsetswithDupli1(nums);
    for(auto &vp : ans1){
        for(int vc : vp){
            cout<<vc;
        }
        cout<<" ";
    }
}
