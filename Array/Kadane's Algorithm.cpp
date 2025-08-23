#include<bits/stdc++.h>
using namespace std;

int kadansalgorithm(vector<int>nums){
    int n = nums.size();
    int sum = 0;
    int maxsum = INT_MIN;
    for(int i =0;i<n;i++){
        sum += nums[i];
        maxsum = max(maxsum , sum);
        if(sum<0){
            sum =0;
        }
    }
    return maxsum;
}
int main(){
    vector<int>nums = {2, 3, -8, 7, -1, 2, 3};
    int maxsm = kadansalgorithm(nums);
    cout<<"Maxsum of the subarrays : "<<maxsm<<endl;
    return 0;
}