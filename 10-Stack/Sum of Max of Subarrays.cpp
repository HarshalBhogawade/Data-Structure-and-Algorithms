#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(5n)
Space Complexity: O(2n)
*/

class Solution {
public:
    long long sumOfMax(vector<int> &arr) {
        int n = arr.size();
        vector<int> prevs(n), nexts(n);
        stack<int> st;

        // Previous greater element
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            prevs[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        // Clear stack for next greater computation
        while(!st.empty()) st.pop();

        // Next greater element
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            nexts[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            long long L = i - prevs[i];  // Number of subarrays ending at i with arr[i] as max
            long long R = nexts[i] - i;  // Number of subarrays starting at i with arr[i] as max
            sum += (long long)arr[i] * L * R;  // Contribution of arr[i]
        }
        return sum; // total sum of maximums of all subarrays
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 2};
    cout << "Sum of max of all subarrays: " << sol.sumOfMax(arr) << endl; // Expected: 15

    vector<int> arr2 = {1000000000, 1};
    cout << "Sum of max of all subarrays: " << sol.sumOfMax(arr2) << endl; // Expected: 2000000001

    return 0;
}
