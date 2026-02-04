#include<bits/stdc++.h>
using namespace std;
void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int minidx = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[minidx]){
                minidx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minidx];
        arr[minidx] = temp;
    }
    
}


int main(){
    int arr[6] = {5,3,2,3,1,4};
    selectionSort(arr,6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" "<<endl;
    }
}
