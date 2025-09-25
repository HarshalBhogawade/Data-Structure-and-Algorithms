#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int si;
        cin>>si;
        int arr[si];
        int s = 0;
        while(s<si){
            int elem;
            cin>>elem;
            arr[s]=elem;
            s++;
        }
        sort(arr,arr+s);
        //aftersorting they are directly arranged in pairing of min diff
        int maxval = INT_MIN;
        //looping only half array coz we need pairs so in each i we calculating two elements , considering them as a pairs
        for(int i=0;i<s/2;i++){
            int diff = arr[2*i+1]-arr[2*i];
            maxval = max(diff,maxval);
        }
        cout<<maxval<<endl;
    }
}