#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string nw = "";
            for (int i = 0; i < s.size() - 1; i++) {
                int sm = ((s[i] - '0') + (s[i + 1] - '0')) % 10;
                nw += to_string(sm);
            }
            s = nw;
        }
        return s[0] == s[1];
    }
};

int main() {
    Solution obj;
    string s;
    cin >> s;
    cout << (obj.hasSameDigits(s) ? "True" : "False");
    return 0;
}