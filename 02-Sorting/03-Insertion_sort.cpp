#include<bits/stdc++.h>
using namespace std;
void insertion(vector<int>&arr){
    int n = arr.size();
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void print(vector<int> arr){
    for(int n : arr){
        cout<<n<<" ";
    }
}

int main(){
    vector<int>arr={7,9,5,2,6};
    insertion(arr);
    print(arr);
}