#include<iostream>
using namespace std;
//abs(n) is the inbuilt function for this
int absolutevalue(int n){
    if(n<0){
        n = n*(-1);
    }
    return n;
}
int main(){
    int n = -2;
    cout<<absolutevalue(n)<<endl;
    return 0;
}