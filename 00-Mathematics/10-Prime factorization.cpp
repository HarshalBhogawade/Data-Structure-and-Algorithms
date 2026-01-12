#include<bits/stdc++.h>
using namespace std;
vector<int>factors(int n){
    vector<int>facts;
    //handle 2
    while(n%2 ==0){
        facts.push_back(2);
        n/=2;
    }

    //handle odd nums till sqrt(n)
    for(int i=3;i*i<=n;i+=2){ // i+=2 for skipping even numbers as we doing for odd n
        while(n%i==0){
            facts.push_back(i);
            n/=i;
        }
    }
    if(n>2){
        facts.push_back(n);
    }
    return facts;
}

vector<vector<int>>primefactors(vector<int>nums){
    vector<vector<int>>ans;
    for(int i=0;i<nums.size();i++){
        ans.push_back(factors(nums[i]));
    }
    return ans;
}
int main(){


}