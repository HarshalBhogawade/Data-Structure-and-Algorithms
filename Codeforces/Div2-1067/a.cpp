#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,r,y;
        cin>>n;
        cin>>y>>r;
        int cnt = 0;
        cnt+=r;
        
        int remaining = n-r;
        int ylo = y/2;
        cnt += min(remaining,ylo);
        cout<<cnt<<endl;
    }
}