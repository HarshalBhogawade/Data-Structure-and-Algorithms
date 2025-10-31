#include<bits/stdc++.h>
using namespace std;
int digits(int num){
    if(num==0){
        return 0;
    }

    return 1+digits(num/10);

}
int main(){
    cout<<digits(123456);
}