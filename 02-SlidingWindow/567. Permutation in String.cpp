#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    // TC: O(n) , SC: O(26) ~ O(1)

    // build frequency map of s1
    unordered_map<char,int> mp;
    for (char ch : s1) mp[ch]++;
    int count = mp.size();   // number of distinct chars still unmatched

    int i = 0, j = 0, k = s1.length();

    while (j < s2.length()) {
        // include current char into the window
        if (mp.find(s2[j]) != mp.end()) {
            mp[s2[j]]--;
            if (mp[s2[j]] == 0) count--;  // one char fully matched
        }

        // if window size < k, expand
        if (j - i + 1 < k) {
            j++;
        }
        // if window size == k
        else if (j - i + 1 == k) {
            if (count == 0) return true;  // all matched → permutation exists

            // shrink window from left
            if (mp.find(s2[i]) != mp.end()) {
                mp[s2[i]]++;
                if (mp[s2[i]] == 1) count++;  // one char requirement restored
            }
            i++;
            j++;
        }
    }
    return false;
}

int main() {
    string s1 = "ab", s2 = "eidbaooo";
    cout << (checkInclusion(s1, s2) ? "true" : "false");
    return 0;
}
