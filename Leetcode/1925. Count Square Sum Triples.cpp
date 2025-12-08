#include<bits/stdc++.h>
using namespace std;
int countTriples(int n) {
        int cnt = 0;
        for(int a=1;a<=n;a++){
            for(int b = 1;b<=n;b++){
                int one = a*a;
                int two = b*b;
                int c1 = a*a + b*b;
                int c = sqrt(c1);
                if(c*c==c1 && c<=n) cnt++;
            }
        }
        return cnt;
}
int main(){
    cout<<countTriples(5);
}