#include <bits/stdc++.h>
using namespace std;
/*Example 1:
n = 5
Analysis:

Binary of 5: 101 (not all ones)
Check 5: 5 & 6 = 101 & 110 = 100 ≠ 0 → continue
Check 6: 6 & 7 = 110 & 111 = 110 ≠ 0 → continue
Check 7: 7 & 8 = 0111 & 1000 = 0000 = 0 ✓
Answer: 7*/
int smallestNumber(int n)
{
    int x = n;
    while ((x & (x + 1)) != 0)
    {
        x++;
    }
    return x;
}
int main()
{
    cout<<smallestNumber(5);
    //op : 7 
}