#include<bits/stdc++.h>
using namespace std;
bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        bool isonebit = true;
        int i=0;
        if(n==1) return true;
        while(i<n-1){
            if(bits[i]==0){
                i++;
            }else{
                i+=2;
            }
        }
        return i==n-1;
}
int main(){
    vector<int>bits = {1,0,0};
    cout<<isOneBitCharacter(bits);
}