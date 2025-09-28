#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (char ch : s) {
            // If current character and stack top form "AB" or "CD", pop the stack
            if (!st.empty() && 
               ((st.top() == 'A' && ch == 'B') || (st.top() == 'C' && ch == 'D'))) {
                st.pop();
            } 
            else {
                // Otherwise push the current character
                st.push(ch);
            }
        }
        // Remaining stack size is the answer
        return st.size();
    }
};

int main() {
    Solution sol;

    // Example usage:
    string s1 = "ABCD";
    cout << "Min length after removals (\"" << s1 << "\") = " 
         << sol.minLength(s1) << endl;

    string s2 = "CABD";
    cout << "Min length after removals (\"" << s2 << "\") = " 
         << sol.minLength(s2) << endl;

    string s3 = "ACBD";
    cout << "Min length after removals (\"" << s3 << "\") = " 
         << sol.minLength(s3) << endl;

    return 0;
}
