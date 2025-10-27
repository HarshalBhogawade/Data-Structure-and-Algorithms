#include<bits/stdc++.h>
using namespace std;
int digitalroot(int n)
{
    if(n<10){
        return n;
    }
    return digitalroot(n%10 + n/10);
}
int main(){
    cout<<digitalroot(457);
}