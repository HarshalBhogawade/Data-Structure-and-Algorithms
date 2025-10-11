#include<bits/stdc++.h>
using namespace std;

void selection(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        int minindx = i;
        for(int j = i+1;j<arr.size();j++){
            if(arr[j]<arr[i]){
                minindx = j;
            }
        }
        swap(arr[i],arr[minindx]);
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