#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), c(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        ll sumC = 0;
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
            sumC += c[i];
        }

        vector<ll> dp(n, 0);
        ll bestKeep = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = c[i];
            for (int j = 0; j < i; ++j) {
                if (a[j] <= a[i]) {
                    dp[i] = max(dp[i], dp[j] + c[i]);
                }
            }
            bestKeep = max(bestKeep, dp[i]);
        }

        cout << (sumC - bestKeep) << "\n";
    }
    return 0;
}
