#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll lgcd(ll a, ll b) {
    if (a == 0) return b;
    if (b == 0) return a;
    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // compute gcd of all elements
        ll g = a[0];
        for (int i = 1; i < n; ++i) g = lgcd(g, a[i]);

        if (g == 1) {
            cout << 2 << "\n";
            continue;
        }

        // find smallest x >= 2 such that gcd(x, g) == 1
        ll x = 2;
        while (true) {
            if (lgcd(x, g) == 1) {
                cout << x << "\n";
                break;
            }
            ++x;
            // in practice x will be small; but you could add a safe upper bound if needed
        }
    }
    return 0;
}
