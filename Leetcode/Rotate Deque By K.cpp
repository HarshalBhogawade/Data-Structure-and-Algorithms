#include <bits/stdc++.h>
using namespace std;

// Rotate deque: type 2 = left, else right
void rotateDeque(deque<int>& dq, int type, int k) {
    int n = dq.size();
    if (n == 0) return;
    k %= n;

    if (type == 2) {
        // Left rotation
        reverse(dq.begin(), dq.begin() + k);
        reverse(dq.begin() + k, dq.end());
        reverse(dq.begin(), dq.end());
    } else {
        // Right rotation
        reverse(dq.begin(), dq.end());
        reverse(dq.begin(), dq.begin() + k);
        reverse(dq.begin() + k, dq.end());
    }
}

int main() {
    deque<int> dq = {1, 2, 3, 4, 5};

    cout << "Original deque: ";
    for (int x : dq) cout << x << " ";
    cout << "\n";

    rotateDeque(dq, 2, 2);  // left rotate by 2
    cout << "After left rotation by 2: ";
    for (int x : dq) cout << x << " ";
    cout << "\n";
    
    rotateDeque(dq, 1, 2);  // right rotate by 2
    cout << "After right rotation by 2: ";
    for (int x : dq) cout << x << " ";
    cout << "\n";

    return 0;
}
