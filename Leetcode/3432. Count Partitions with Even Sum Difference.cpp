#include<bits/stdc++.h>
using namespace std;
  int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int>lsm(n);
        vector<int>rsm(n);
        lsm[0]=nums[0];
        rsm[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            lsm[i]=lsm[i-1]+nums[i];
        }

        for(int i=n-2;i>=0;i--){
            rsm[i]=rsm[i+1]+nums[i];
        }

        int cnt = 0;
        for(int i=0;i<n-1;i++){
            int leftsum = lsm[i];
            int rightsum = rsm[i+1];
            int diff = leftsum  - rightsum;
            if(diff%2==0) cnt++;
        }

        return cnt;
    }
int main(){
    vector<int>nums  = {10,10,3,7,6};
    cout<<countPartitions(nums);
}