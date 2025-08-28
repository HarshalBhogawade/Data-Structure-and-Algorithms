#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &arr) {
    int n = arr.size();
    int k = arr[n - 1];        // store last element
    for (int i = n - 2; i >= 0; i--) {
        arr[i + 1] = arr[i];   // shift elements right
    }
    arr[0] = k;                // put last element at front
}

// Time Complexity: O(n)  (each element shifted once)
// Space Complexity: O(1)  (no extra space used)

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    rotate(arr);

    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}