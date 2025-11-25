#include<bits/stdc++.h>
using namespace std;
int smallestRepunitDivByK(int k) {
        int len = 0;
        long long  num = 0; //as digit 1 no number can be divisible by 2 and 5,
        //as they need unit place to be multiple of 2 or 5
        if(k%2 ==0 || k%5 == 0) return -1;
        long long prev= 0;
        while(true){
            len++;
            num = ((num*10)+1)%k; //keeps in range 0 to k no overflow
            if(num == 0){
                break;
            }
        }
        return len;
    }
int main(){
    cout<<smallestRepunitDivByK(12);
}