#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<long long> a(n + 1);
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        long long ans = 0;

        if(a[1] != -1 && a[n] != -1)
        {
            ans = llabs(a[n] - a[1]);
        }
        else
        {
            if(a[1] == -1 && a[n] == -1)
            {
                a[1] = a[n] = 0;
            }
            else if(a[1] == -1)
            {
                a[1] = a[n];
            }
            else if (a[n] == -1)
            {
                a[n] = a[1];
            }
            ans = 0;
        }

        for(int i = 2; i <= n - 1; i++)
        {
            if (a[i] == -1)
                a[i] = 0;
        }

        cout << ans <<endl;
        for(int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout <<endl;
    }
}