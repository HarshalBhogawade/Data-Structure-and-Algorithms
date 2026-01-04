#include<bits/stdc++.h>
using namespace std;
    int divisors(int n){
        vector<int>divsrs;
        
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                divsrs.push_back(i);
                if(i!=n/i) divsrs.push_back(n/i);
            }
        }
        int sum = 0;
        for(int nm : divsrs){
            sum+=nm;
        }
        if(divsrs.size()==4) return sum;
        else return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum2 = 0;
        for(int i=0;i<nums.size();i++){
            sum2 += divisors(nums[i]);
        }
        return sum2;
    }
int main(){
    
}