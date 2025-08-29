#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    // TC: O(n) , SC: O(256) ~ O(1)

    unordered_map<char,int> mp; // char frequency in window
    int len = 0, i = 0, j = 0;

    while (j < s.size()) {
        mp[s[j]]++;  // include current char

        // if all chars unique in window
        if (mp.size() == j - i + 1) {
            len = max(len, j - i + 1);
        }
        // if duplicate found, shrink from left
        else if (mp.size() < j - i + 1) {
            while (mp.size() < j - i + 1) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    return len;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
    return 0;
}
