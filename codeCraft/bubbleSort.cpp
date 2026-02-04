#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n){
    bool isSwapped;
    for(int i=0;i<n-1;i++){
        isSwapped = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= temp;
                isSwapped = true;            }
        }
        if(!isSwapped){
            return;
        }
    }
}
int main(){
    int arr[6] = {6,5,4,3,2,1};
    bubbleSort(arr,6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}