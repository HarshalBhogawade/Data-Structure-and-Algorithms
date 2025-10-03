#include<bits/stdc++.h>
using namespace std;
bool validMountainArray(vector<int>& arr) {
        int left = 0;
        int n = arr.size();
        int right = n-1;
        while(left + 1 < n && arr[left]<arr[left+1]){
            left++;
        }
        while(right - 1 >= 0 && arr[right-1]>arr[right]){
            right--;
        }
        return left==right && left != 0 && right != n-1;
}
int main(){
    vector<int>nums = {0,3,2,1};
    cout<<"Is valid mountain array : "<<validMountainArray(nums);
    return 0;
}