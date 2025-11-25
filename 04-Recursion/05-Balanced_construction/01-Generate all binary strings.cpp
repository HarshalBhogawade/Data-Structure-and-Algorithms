#include<bits/stdc++.h>

using namespace std;

//revursive approach : 
//tc : O(2^N) sc : O(N) 
void binary(int idx, int n , string temp , vector<string>&ans){
    if(idx == n ){
        ans.push_back(temp);
        return;
    }

    //take zero
    temp.push_back('0'); //take 0 again call 0 then string get 00 and idx == n return 00
    binary(idx+1,n,temp,ans);
    temp.pop_back(); //pop back 0 from temp means from 00 rem 0 remaining temp = 0

    //take one
    temp.push_back('1'); //take 1 now string is 01 and after again calling idx == n return ans
    binary(idx+1,n,temp,ans); 
    temp.pop_back(); //pop back 
}
vector<string> generate(int n){
    vector<string>ans;
    string temp = "";
    binary(0,n,temp,ans);
    return ans;
}

int main(){
    vector<string>ans = generate(2);
    for(auto & it : ans){
        for(char ch : it){
            cout<<ch;
        }
        cout<<" ";
    }
}