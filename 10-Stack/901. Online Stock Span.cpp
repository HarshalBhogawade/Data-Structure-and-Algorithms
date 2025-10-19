#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        // Stack will store pairs: {price, span}
        stack<pair<int,int>> st;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            int price = arr[i];
            int span = 1; // Minimum span is always 1 (itself)

            // Pop all previous prices which are <= current price
            while (!st.empty() && st.top().first <= price) {
                span += st.top().second; // Add their span to current span
                st.pop();
            }

            // Push current price with its calculated span
            st.push({price, span});

            // Store result for current day
            ans.push_back(span);
        }

        return ans;
    }
};

int main() {
    // Example input
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};

    Solution obj;
    vector<int> res = obj.calculateSpan(arr);

    // Print result
    cout << "Stock Span values: ";
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

