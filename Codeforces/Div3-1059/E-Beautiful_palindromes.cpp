#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int last = a[n - 1]; // last element of original array
        for (int i = 0; i < k; i++) {
            int x = (last % n) + 1; // pick a number different from last
            cout << x << " ";
            last = x; // update last
        }
        cout << "\n";
    }
}
