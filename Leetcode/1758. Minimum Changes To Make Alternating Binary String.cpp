#include<bits/stdc++.h>
using namespace std;
    int minOperations(string s) {
        int n = s.size();
        int p1=0;
        int p2= 0;
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                if(s[i]!='1'){
                    p1++;
                }
                if(s[i]!='0') p2++;
            }else if(i%2 == 1){
                if(s[i]!='0'){
                    p1++;
                }
                if(s[i]!='1') p2++;
            }
        }
        return min(p1,p2);
    }
int main(){
    string s = "0011101";
    int operations = minOperations(s);
    cout<<operations<<endl;
}