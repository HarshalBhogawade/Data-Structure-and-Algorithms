#include<bits/stdc++.h>
using namespace std;
int sumofdigits(int n){
    if(n==0) return 0;
    //n%10 + (n/10)%10 + ((n/10)/10)%10
    return n%10 + sumofdigits(n/10);//n/10 calls recursively on smaller input means removes last digit from n 
}
int main(){
    cout<<sumofdigits(123);

}