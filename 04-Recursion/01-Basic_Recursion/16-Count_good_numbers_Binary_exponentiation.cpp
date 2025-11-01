#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

//time complexity : O(Logn)
long long Pow(long long x, long nn)
{

    // base case
    if (nn == 0)
    {
        return 1;
    }
    // smaller input
    long long half = Pow(x, nn / 2);

    // retruning based on even odd
    if (nn % 2 == 1)
    {
        return (x * half * half) % MOD;
    }
    else
    {
        return (half * half) % MOD;
    }
}
int countGoodNumbers(long long n)
{
    /*
           Index positions (0-based):
           Example: n = 5 → indices = [0,1,2,3,4]
                     Even indices → 0,2,4  (3 positions)
                     Odd indices  → 1,3    (2 positions)

           Observation:
           - Even indices count = (n + 1) / 2
             (because for odd length, last index is even)
           - Odd indices count = n / 2
        */
    // there are only 5 even and 4 odd indices
    long long even = (n + 1) / 2;  // even indices in given n
    long long odd = n / 2;         // odd indices in given n
    long long ans1 = Pow(5, even); // for even indices
    long long ans2 = Pow(4, odd);  // for odd indices
    return (ans1 * ans2) % MOD;
}
int main()
{
    long long n = 50;
    cout<<countGoodNumbers(n);

}