#include<bits/stdc++.h>
using namespace std;

//recursive
int factorial(int num){
    if(num<=1){
        return 1;
    }
    return num* factorial(num-1);
}

//iterative


int main(){
    cout<<factorial(5);
    
}