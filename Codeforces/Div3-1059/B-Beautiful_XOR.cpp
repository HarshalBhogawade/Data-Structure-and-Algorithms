#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>

using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << "\n\n";
        return;
    }
    
    // Check for 1 operation case
    if ((a ^ b) < a) {
        cout << 1 << "\n";
        cout << (a ^ b) << "\n";
        return;
    }

    // Find the smallest power of 2, p, such that p > max(a, b)
    long long p = 1;
    while (p <= a || p <= b) {
        p <<= 1;
    }
    long long y = p - 1;

    // Calculate the two x values for the 2-operation sequence
    long long x1 = y ^ a;
    long long x2 = y ^ b;

    // Check if the operations are valid (x <= current a)
    if (x1 > a || x2 > y) {
        cout << -1 << "\n";
    } else {
        cout << 2 << "\n";
        cout << x1 << " " << x2 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}