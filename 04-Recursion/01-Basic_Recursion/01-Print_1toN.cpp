#include<bits/stdc++.h>
using namespace std;
void print(int n){
    if(n==0) return; //base 
    print(n-1);  //hypothesis 
    cout<<n; //induction
} 
int main(){
    print(5);
}
