#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>
#include<algorithm>
vector<int> relativeSorting(vector<int> &arr, vector<int> &brr, int n, int m)
{
    // Write your code here.
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    vector<int>res;
    for(int i=0;i<brr.size();i++){
        if(mp.find(brr[i])!=mp.end()){
            
            while(mp[brr[i]]>0){
                res.push_back(brr[i]);
                mp[brr[i]]--;
            }
            if(mp[brr[i]]==0) mp.erase(brr[i]);
        }
    }

    vector<int>keys;
    keys.reserve(mp.size());
    for(auto &it : mp) keys.push_back(it.first);
    sort(keys.begin(),keys.end());
    for(int key : keys){
        while(mp[key]>0){
            res.push_back(key);
            mp[key]--;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {15, 20, -9, 9, 4, -20, 15, 21, 11};
    vector<int> brr = {-4, 9, -9, -10, -11};
    int n = arr.size();
    int m = brr.size();
    vector<int> ans = relativeSorting(arr, brr, n, m);
    for(int nm : ans){
        cout<<nm<<" ";
    }
}