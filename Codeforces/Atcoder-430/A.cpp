#include <bits/stdc++.h>
using namespace std;
string isviolating(int a, int b, int c, int d)
{
    if (c >= a && d < b)
        return "Yes"; // Violation
    else
        return "No";
}


int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << isviolating(a, b, c, d) << endl;
}