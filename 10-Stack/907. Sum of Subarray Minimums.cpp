#include <bits/stdc++.h>
using namespace std;


//timecomplexity : O(3N) 2n for pse and nse and computing ||| SC : O(3N) 2n for storing pse and nse indexes , and for monotonic stack used for computing pse , nse
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int> prevs(n), nexts(n);
        stack<int> st;

        // Compute Previous Smaller Element for each index
        // prevs[i] = index of previous element smaller than arr[i]
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            prevs[i] = st.empty() ? -1 : st.top(); // -1 if no smaller element exists
            st.push(i);
        }

        // Clear stack to reuse for next smaller calculation
        while (!st.empty()) st.pop();

        // Compute Next Smaller Element for each index
        // nexts[i] = index of next element smaller than arr[i]
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nexts[i] = st.empty() ? n : st.top(); // n if no smaller element exists
            st.push(i);
        }

        // Calculate sum of contributions of each element
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long L = i - prevs[i];       // Number of elements to the left (including itself)
            long long R = nexts[i] - i;       // Number of elements to the right (including itself)
            sum = (sum + (arr[i] * L % MOD) * R % MOD) % MOD; // Contribution of arr[i]
        }

        return (int)sum; // Return sum modulo 1e9+7
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};

    // Output the sum of subarray minimums
    cout << sol.sumSubarrayMins(arr) << endl; // Expected: 17

    return 0;
}
