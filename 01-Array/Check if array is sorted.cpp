#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isSorted(vector<int>& arr) {
        // code here
        bool ans = true;
        for(int i=0;i<arr.size();i++){
            if(i<arr.size()-1 && arr[i]>arr[i+1]){
                return false;
            }
        }
        return ans;
}
int main(){
    vector<int>arr = {1,2,3,4,5,7,4};
    bool ans = isSorted(arr);
    cout<<"IS array sorted : "<<ans;
    return 0;
}
