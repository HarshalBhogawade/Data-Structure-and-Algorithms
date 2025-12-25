#include<bits/stdc++.h>
using namespace std;
bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    
    string reverseWords(string s) {
        int vowelcnt = 0;
        int n = s.size();
        //cnt vowels in first word
        int i=0;
        while(i<n){
            if(isVowel(s[i])){
                vowelcnt++;   
            }
            if(s[i]==' ') break;
            i++;
        }

        //reverse the word which having same vowels count 
        //as in first word
        
        int start =i+1 ;
        int end = 0;
        while(start<n){
            int vowelcount = vowelcnt;
            while(start<n && s[start] ==' ')start++;
            end = start;
            while(end<n && s[end]!=' '){
                if(isVowel(s[end])){
                    vowelcount--;
                }
                end++;
            }
            if(vowelcount==0){
                reverse(s.begin()+start,s.begin()+end);
            }
            start=end;
        }
        return s;
        
    }
int main(){
    string s = "cat and mice";
    string ans = reverseWords(s);
    for(char ch :ans){
        cout<<ch;
    } 
}