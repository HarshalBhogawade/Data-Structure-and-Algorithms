#include <bits/stdc++.h>
using namespace std;


//tc : O(6N) SC: O(4N) 
class Solution {
public:
    // Sum of subarray maximums using contribution + monotonic stack
    long long sumOfMax(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevs(n), nexts(n);
        stack<int> st;

        // Previous greater for each element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            prevs[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next greater for each element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            nexts[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long L = i - prevs[i];       // Number of subarrays ending at i with arr[i] as max
            long long R = nexts[i] - i;       // Number of subarrays starting at i with arr[i] as max
            sum += (long long)arr[i] * L * R; // Contribution
        }

        return sum;
    }

    // Sum of subarray minimums using contribution + monotonic stack
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevs(n), nexts(n);
        stack<int> st;

        // Previous smaller for each element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            prevs[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next smaller for each element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nexts[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long L = i - prevs[i];       // Number of subarrays ending at i with arr[i] as min
            long long R = nexts[i] - i;       // Number of subarrays starting at i with arr[i] as min
            sum += (long long)arr[i] * L * R; // Contribution
        }

        return sum;
    }

    // Main function: sum of all subarray ranges = sum of max - sum of min
    long long subArrayRanges(vector<int>& nums) {
        long long largest = sumOfMax(nums);
        long long smallest = sumSubarrayMins(nums);
        return largest - smallest;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 2};
    cout << "Sum of subarray ranges: " << sol.subArrayRanges(arr) << endl; // Expected output: 5

    vector<int> arr2 = {1000000000, 1};
    cout << "Sum of subarray ranges: " << sol.subArrayRanges(arr2) << endl; // Expected output: 999999999

    return 0;
}
