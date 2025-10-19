#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    queue<int> reverseFirstK(queue<int> q, int k){
        int n = q.size();
        if (k > n) return q;
        if (k == 0) return q;
    
        stack<int> st;
        // Step 1: Push first k elements into stack
        for (int i = 0; i < k; i++) {
            st.push(q.front());
            q.pop();
        }
    
        // Step 2: Push back reversed elements
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
    
        // Step 3: Move remaining elements to the back to maintain order
        int remaining = n - k;
        for (int i = 0; i < remaining; i++) {
            q.push(q.front());
            q.pop();
        }
    
        return q;
    }
};

int main() {
    Solution sol;
    queue<int> q;
    
    // Test case: Queue [1, 2, 3, 4, 5], k = 3
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
    cout << "Original queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    
    int k = 3;
    queue<int> result = sol.reverseFirstK(q, k);
    
    cout << "After reversing first " << k << " elements: ";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;
    
    return 0;
}