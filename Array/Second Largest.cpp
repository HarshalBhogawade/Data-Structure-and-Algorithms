#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int getSecondLargest(vector<int> &arr) {
        // code here
        int largest = INT_MIN;
        int secondlargest = INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>largest){
                secondlargest = largest;
                largest = arr[i];
            }
            else if(arr[i]>secondlargest && arr[i]<largest){
                secondlargest = arr[i];
            }
        }
        if(secondlargest ==INT_MIN) return -1;
        return secondlargest;
    }
int main(){
    vector<int>nums = {1,2,3,4,30,29,28};
    int seclarg = getSecondLargest(nums);
    cout<<"Second largest : "<<seclarg<<endl;
    return 0;
}