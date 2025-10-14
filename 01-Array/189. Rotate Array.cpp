#include<bits/stdc++.h>
using namespace std;

//optimal  tc : O(3N) SC: O(1) reversing using buildin function : reverse()
// void reversebyksteps(vector<int>&arr , int k){
//     int n = arr.size();

//     k %=n;     // Handle cases where k > n

//     //1-rotate 0 to 2
//     reverse(arr.begin(),arr.begin()+k);   
//     //2-roatate 3 to n-1
//     reverse(arr.begin()+k,arr.end());
//     //now reverse whole array
//     reverse(arr.begin(),arr.end()); 

// }


//if they ask to write the reverse function
void reverse(vector<int>& arr , int start , int end){
    while(start<=end){
        int temp = arr[start];
        arr[start]=arr[end];
        arr[end]= temp;
        start++;
        end--;
    }
}

void reversebyk(vector<int>&arr , int k){
    int n= arr.size();
    k %= n;
    //right rotate
    // reverse(arr,0,k-1);
    // reverse(arr,k,n-1);
    // reverse(arr,0,n-1);

    //left rotate
    reverse(arr,0,n-1);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    for(int num : arr){
        cout<<num<<" ";
    }
}

// function for reverse
int main(){
    vector<int>num = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    reversebyk(num,k);
    return 0;
}