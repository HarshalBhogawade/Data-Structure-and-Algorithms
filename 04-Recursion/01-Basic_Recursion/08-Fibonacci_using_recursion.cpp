#include<bits/stdc++.h>
using namespace std;
//recursive

//excessive recursion - recursive fucntion calling iteself for multiple times for same values
// this  happens in this one

//time complexity => 2fibo(n-1) => O(2^n)
int fibo(int n){
    if(n<=1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}


//iterative
int fibonacci(int n){
    if(n<=1) return n;
    int curr = 0;
    int prev0 = 0;
    int prev1 = 1;
    for(int i=2;i<=n;i++){
        curr = prev0 + prev1;
        prev0 = prev1;
        prev1 = curr;
    }
    return prev1;
}


int main(){
    cout<<fibo(5)<<endl;
    cout<<fibonacci(5);
}