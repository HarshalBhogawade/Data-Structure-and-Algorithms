#include<bits/stdc++.h>
using namespace std;
void reverse(vector<int>&arr,int start , int end){
    if(start<end){
        swap(arr[start],arr[end]);
        reverse(arr,start+1,end-1);
    }
}

int main(){
    vector<int>arr = {1,2,3,4,5};
    int start = 0;
    int end = arr.size()-1;
    reverse(arr,start,end);
    for(int nm : arr){
        cout<<nm<<" ";
    }
}