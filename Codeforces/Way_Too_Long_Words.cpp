#include<bits/stdc++.h>
using namespace std;

    
int main(){
    int n;  //number of words
    cin>>n;
    while(n>0){
        string word;    
        cin>>word;  //take input word

        if(word.length()<=10){  //if len <= 10 no need to replace by special abbreviation
            cout<<word<<endl;
        }else{      //replace by special abbreviation ie first word + middle count of letters + lastword
            cout<<word[0]
                <<word.length()-2
                <<word.back()<<endl;
        }
        n--;    //decrment n
    }
    return 0;
}