#include <bits/stdc++.h>
using namespace std;

// tc: O(3N)+OK , sc : O(2N)
string removeKdigits(string num, int k) {
    stack<char> st;

    // build a monotonic increasing stack
    for (int i = 0; i < num.size(); i++) {
        while (!st.empty() && k > 0 && st.top() > num[i]) {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    //Edge case 1 : if still have k , remove remaining k digits 
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }
    
    //Edge case 2 : if empty means no num str return 0;
    if (st.empty()) return "0";

    // build result string
    string res;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    //Edge case 3 remove leading zeros 
    while (!res.empty() && res.back() == '0') {
        res.pop_back();
    }

    reverse(res.begin(), res.end());
    return res.empty() ? "0" : res;
}

int main() {
    string num = "1432219";
    int k = 3;
    cout << "Result: " << removeKdigits(num, k) << endl;
    return 0;
}
