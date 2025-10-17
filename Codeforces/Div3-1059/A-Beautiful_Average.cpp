#include<bits/stdc++.h>
using namespace std;
//25 mins
int main(){
    int n;
    cin>>n;
    while(n--){
        int size;
        cin>>size;
        int nums[size];
        for(int i=0;i<size;i++){
            int elem;
            cin>>elem;
            nums[i]=elem;
        }

        int max_elem = INT_MIN;
        for(int i =0;i<size;i++){
            max_elem = max(max_elem , nums[i]);
        }
        cout<<max_elem<<endl;
        
    }
}