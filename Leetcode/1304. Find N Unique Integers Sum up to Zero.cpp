#include <bits/stdc++.h>
using namespace std;

vector<int> sumZero(int n)
{
    vector<int> ans;

    // Add pairs: 1,-1, 2,-2, ...
    for (int i = 1; i <= n / 2; i++)
    {
        ans.push_back(i);
        ans.push_back(-i);
    }

    // If n is odd, add 0 to make the total count n
    if (n % 2 == 1)
    {
        ans.push_back(0);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> res = sumZero(n);

    for (int x : res)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
