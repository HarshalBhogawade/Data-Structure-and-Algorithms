#include<bits/stdc++.h>
using namespace std;
//longest balanced substring 1
int longestBalanced(string s) {
        int n = s.size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            int maxfreq = INT_MIN;
            int distinct = 0;
            for(int j=i;j<n;j++){
                if(mp[s[j]]==0) distinct++;
                mp[s[j]]++;
                maxfreq= max(maxfreq,mp[s[j]]);
                if(maxfreq*distinct == (j-i+1)){
                    ans = max(ans,(j-i+1));
                }
            }
        }
        return ans;
    }

    //longest balanced substring 2
//prefix difference is the core idea here : a[i]- b[i]  ==  a[i]-c[i]  means pair is balanced
int longestBalanced(string s) {
    map<pair<int,int> , int> mp;
    int a ,b,c=0;
    int ans = 0;
    mp[{0,0}]=-1;
    int n = s.size();
    int ans = INT_MIN;
    for(int i=0;i<n;i++){

        if(s[i]=='a'){
            a++;
        }else if(s[i]== 'b'){
            b++;
        }else{
            c++;
        }

        int d1 = a-b;
        int d2 = a-c;

        pair<int,int>key = {d1,d2};
        if(mp.count(key)){
            ans = max(ans , i-mp[key]);
        }else{}
            mp[key]=i;
        }
    }
    return ans;
}
int main(){

}