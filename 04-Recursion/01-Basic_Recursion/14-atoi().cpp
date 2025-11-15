#include<bits/stdc++.h>
using namespace std;
int atoi_iterative(string &s){
    int n = s.size();
    int i =0;   //one pointer to iterating string
    int sign = 1; // to manage -ve numbers
    int num = 0;

    //ignoring spaces
    while(s[i]==' '){
        i++;
    }

    //hangling positive and -ve signs
    if(s[i]=='-'){
        sign  = -1;
        i++;
    }else if(s[i]=='+'){
        i++;
    }

    //converting string to integers as remaining string is number
    while(s[i]>='0' && s[i]<='9'){
        int digit = s[i]-'0';
        num = num * 10 + digit;

        //handling the case where num exceeds 32bit signed integer
        if(num>INT_MAX && sign == 1) return INT_MAX;
        if(num<INT_MIN && sign == -1) return INT_MIN;
        i++;
    }

    return num*sign;
}

//recursive approach 

int atoi(string s, int n){
    //basce case empty string means 0
    if(n==0){
        return s[n]-'0';
    }
    // Recursive call on remaining string
    int smallernumber = atoi(s,n-1);

    //get last character numeric value
    int digit = s[n]-'0';

    //combin
    return smallernumber * 10 + digit;
}
int atoi_recursive(string &s){
    int sign = 1;
    int n = s.size()-1;
    int i =0;
    if(s[0]=='-'){
        sign = -1;
        i++;
    }else if(s[0]=='+'){
        i++;
    }

    string numpart = s.substr(i);

    return  sign * atoi(numpart,numpart.size()-1);
}
int main(){
    string s = "1337c0d3";
    cout<<atoi_iterative(s)<<endl;
    string s1 = "-42";
    cout<<atoi_recursive(s1);
}