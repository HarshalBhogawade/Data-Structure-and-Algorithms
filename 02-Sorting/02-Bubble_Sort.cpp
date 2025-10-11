#include<bits/stdc++.h>
using namespace std;


void selection(vector<int>& arr){
    int n = arr.size();
    bool swapped;
    for(int i=0;i<n-1;i++){
        swapped = false;
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) return;
    }
}
void print(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int>arr={7,5,9,2,8};
    selection(arr);
    print(arr);
}