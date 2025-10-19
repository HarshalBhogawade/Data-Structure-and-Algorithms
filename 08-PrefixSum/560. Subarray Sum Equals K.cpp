/*Maintain a running prefix sum sum.
If sum == k → we found a subarray from 0..i.
If sum - k was seen before at some index j, then subarray (j+1..i) sums to k.
Use a hashmap mp to store counts of prefix sums. */
#include<bits/stdc++.h>
using namespace std;

//tc : O(N) and Sc : O(N) for hashmp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int sum = 0, count = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if (sum == k) count++;  // subarray from 0..i

        if (mp.find(sum - k) != mp.end()) {
            count += mp[sum - k];  // subarrays ending here
        }

        mp[sum]++;  // store prefix sum frequency
    }
    return count;
}

int main(){
    vector<int>nums = {1,2,3};
    int k =3;
    cout<<"Cnt :"<<subarraySum(nums,k);
    return 0;
}