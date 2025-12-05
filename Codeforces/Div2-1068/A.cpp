#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;  cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        string s; cin>>s;
        int sleepthrough  = 0;
        int awaketill = -1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                awaketill = i+k;
            }else if(s[i]=='0'){
                if(i>awaketill) sleepthrough++;
            }
        }
        cout<<sleepthrough<<endl;
    }
}