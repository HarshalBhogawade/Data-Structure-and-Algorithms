#include <bits/stdc++.h>
using namespace std;


//time complexity is O(Logn) in each iteration of loop divides nn by 2 by nn = nn /2
double myPow(double x, int n)
{

    double ans = 1.0; // storing answer
    long nn = n;      // may exceed 32 bit

    // if n is -ve then store -ve make positive , to perform power operation
    if (nn < 0)
    {
        nn = -1 * nn;
    }

    // Binary exponentiation loop
    while (nn > 0)
    {
        // if curr expo odd , mult by curr base
        if (nn % 2 == 1)
        {
            ans = ans * x;
            nn = nn - 1; // Decrease exponent by 1 (make it even)
        }
        // if curr expo is even
        else
        {
            x = x * x;
            nn = nn / 2;
        }
    }
    // If original exponent was negative, take reciprocal of answer
    if (n < 0)
    {
        ans = double(1.0) / double(ans);
    }
    return ans;
}

//Recursive Approach tc => O(logn) as every call divides n to n/2 then n/4 then n/8
double Pow(double x , long nn){

    //base case
    if(nn == 0){
        return 1.0;
    }
    //smaller input
    double half = Pow(x,nn/2);

    //retruning based on even odd 
    if(nn%2==1){
        return x * half* half;
    }else{
        return half*half;
    }
}

double pow1(double x, int n){
    long nn = n;
    if(nn<0){
         nn = -1 * nn;
        return 1.0/Pow(x,nn);
    }
    return Pow(x,nn);
}


int main()
{
    double x = 2.100;
    int n = 3;
    cout<<Pow(x,n);
    cout<<endl;
    cout<<myPow(x,n);
}