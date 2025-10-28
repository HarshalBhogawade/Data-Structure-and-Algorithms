#include<bits/stdc++.h>
using namespace std;
string issquare(int arr[]){
    for(int i = 0;i<4;i++){
        if(arr[i]!=arr[0]) return "NO";
    }
    return "YES";
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int arr[4];
        for(int i = 0;i<4;i++){
            cin>>arr[i];
        }
        cout<<issquare(arr);
        cout<<endl;
    }
}