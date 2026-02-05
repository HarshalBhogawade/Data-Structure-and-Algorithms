#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i=low-1;
    int j = high-1;
    while(true){
        do{i++;} while(arr[i]>arr[low]);
        do{j--;} while(arr[j]<arr[low]);

        if(i>=j) return j;
        swap(arr[j],arr[i]);
    }
}

void quickSort(int arr[], int low , int high){
    if(low<high){
        int pivotidx = partition(arr,low,high);
        quickSort(arr,low,pivotidx);
        quickSort(arr,pivotidx+1,high);
    }
}


int main(){
    int arr[6] = {1,2,4,3,7,6};
    quickSort(arr,0,6);
}