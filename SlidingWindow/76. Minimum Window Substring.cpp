#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    // TC: O(n) , SC: O(256) ~ O(1)

    unordered_map<char,int> mp;
    for (char ch : t) mp[ch]++;   // freq of target string

    int count = mp.size();        // distinct chars to match
    int i = 0, j = 0;
    int ans = INT_MAX, start = 0;

    while (j < s.length()) {
        if (mp.find(s[j]) != mp.end()) {
            mp[s[j]]--;
            if (mp[s[j]] == 0) count--; // one char fully matched
        }

        // shrink window if all matched
        while (count == 0) {
            if (j - i + 1 < ans) {  //minimum string
                ans = j - i + 1;
                start = i;
            }
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]]++;
                if (mp[s[i]] == 1) count++; // char requirement restored
            }
            i++;
        }
        j++;
    }
    return (ans == INT_MAX) ? "" : s.substr(start, ans);
}

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t);
    return 0;
}
