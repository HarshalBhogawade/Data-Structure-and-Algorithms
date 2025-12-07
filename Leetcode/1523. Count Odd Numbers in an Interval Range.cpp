#include<bits/stdc++.h>
using namespace std;
    int countOdds(int low, int high) {
        int n = high-low+1;
        if(n%2==0){
            return n/2;
        }else{
            if(low%2 != 0 || high%2 !=0){
                return (n/2)+1;
            }
        }
        return n/2;
    }
int main(){
    int low = 3;
    int high = 7;
    cout<<countOdds(low,high);
}