#include <bits/stdc++.h>
using namespace std;

bool haszero(int x) //checks if number have zero if have do calculations 
{
    while (x)
    {
        if (x % 10 == 0)
            return true;
        x = x / 10;
    }
    return false;
}

vector<int> getnonzeroint(int n)
{
    for (int a = 1; a < n; a++)
    {
        int b = n - a;  //mathematical formula
        if (!haszero(a) && !haszero(b)) //if no zero return vector
        {
            return {a, b};
        }
    }
    return {};
}
int main()
{
    vector<int> ans = getnonzeroint(2948);
    cout << "Non zero pair for 2948 : " << " ";
    for (int n : ans)
    {
        cout << n << ", ";
    }

    return 0;
}